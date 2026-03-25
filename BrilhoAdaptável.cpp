#include <iostream>
#include <windows.h>
#include <wbemidl.h>

// Função auxiliar para converter string comum em BSTR (substitui o _bstr_t)
BSTR ToBSTR(const wchar_t* text) {
    return SysAllocString(text);
}

bool SetBrightness(int brightness) {
    if (brightness < 0) brightness = 0;
    if (brightness > 100) brightness = 100;

    HRESULT hr;
    IWbemLocator* pLoc = NULL;
    IWbemServices* pSvc = NULL;

    CoInitializeEx(0, COINIT_MULTITHREADED);
    CoInitializeSecurity(NULL, -1, NULL, NULL, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE, NULL);
    
    hr = CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID*)&pLoc);
    if (FAILED(hr)) return false;

    BSTR path = ToBSTR(L"ROOT\\WMI");
    hr = pLoc->ConnectServer(path, NULL, NULL, 0, NULL, 0, 0, &pSvc);
    SysFreeString(path);
    if (FAILED(hr)) { pLoc->Release(); return false; }

    CoSetProxyBlanket(pSvc, RPC_C_AUTHN_DEFAULT, RPC_C_AUTHZ_DEFAULT, NULL, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, NULL, EOAC_NONE);

    IWbemClassObject* pClass = NULL;
    BSTR className = ToBSTR(L"WmiMonitorBrightnessMethods");
    pSvc->GetObject(className, 0, NULL, &pClass, NULL);
    SysFreeString(className);

    IWbemClassObject* pInParamsDefinition = NULL;
    pClass->GetMethod(L"WmiSetBrightness", 0, &pInParamsDefinition, NULL);

    IWbemClassObject* pInParams = NULL;
    pInParamsDefinition->SpawnInstance(0, &pInParams);

    VARIANT var;
    VariantInit(&var);
    var.vt = VT_UI4;
    var.uiVal = brightness;
    pInParams->Put(L"Brightness", 0, &var, 0);
    var.uiVal = 0; // Timeout
    pInParams->Put(L"Timeout", 0, &var, 0);

    // Nota: O InstanceName varia por PC. O ideal é enumerar instâncias primeiro.
    BSTR instance = ToBSTR(L"WmiMonitorBrightnessMethods.InstanceName='ACPI\\ControlMethodBattery\\0_0'"); // Exemplo genérico
    hr = pSvc->ExecMethod(instance, ToBSTR(L"WmiSetBrightness"), 0, NULL, pInParams, NULL, NULL);
    SysFreeString(instance);

    // Limpeza
    if(pInParams) pInParams->Release();
    if(pInParamsDefinition) pInParamsDefinition->Release();
    if(pClass) pClass->Release();
    pSvc->Release();
    pLoc->Release();
    CoUninitialize();

    return SUCCEEDED(hr);
}

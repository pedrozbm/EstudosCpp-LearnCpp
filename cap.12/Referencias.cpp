#include <iostream>

//aqui estamos chamando o parametro por referencia,
//alteramos diretamente o valor, não uma cópia dele
//assim conseguimos um cod mais eficiente. 
void addOne(int& z){
    ++z;
}

main(){

    // Uma var de ref lvalue atua comoo uma ref a um lvalue(geralmente outra var)
    int x{4};
    int& ref{x}; // 

    std::cout << x << ref << '\n';

    // Refs, não podem ser alteradas para referenciar outro objeto
    const int y {4};
    [[maybe_unusued]] const int& ref2 {y};
    //Refs podem referenciar consts, contanto que tenham 
    //a abordagem correta 
    addOne(x);
    std::cout << x << '\n'; 

}
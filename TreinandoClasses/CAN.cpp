#include <iostream>

class CAN{
    private:
        int baudRate_int;
        int Can_int;

    public:
        CAN(int baudRate, int Can){
            baudRate_int = baudRate,
            Can_int = Can;
        };  

    int getbaudRate(){
        return baudRate_int;
    }

    int getCan(){
        return Can_int;
    }
};

class IDCan : CAN{

    private:

    public:

};

int main(){
    CAN CAN1(200, 2);
    CAN CAN2(500, 1);

    std::cout << CAN1.getbaudRate() << " " << CAN1.getCan(); 

}
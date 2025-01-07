#include <iostream>
#include <cassert>
#include <cstddef>

// Destruidores são projetados para ajudar a limpar 
// Para classes simples(as que inicializam valores de var de mebros normais), um destruidor nao é necessario
class intArray{
    private:
        int* m_array;
        int m_length{};

    public:
        intArray(int length){
            assert(length > 0);

            m_array = new int[static_cast<std::size_t>(length)]{};
            m_length = length;
        } 
    // o destruidor deve ter o mesmo nome da classe
    // nao recebe argumentos
    // nao tem tipo de retorno       
    ~intArray(){
        delete[] m_array;
    }      
    void setValue(int index, int value){m_array[index] = value;}
    int getValue(int index){ return m_array[index];}

    int getLength(){return m_length;}
};


int main(){
    intArray ar(10);
    for(int count{0}; count < ar.getLength(); ++count)
        ar.setValue(count, count+1);
    
    std::cout << "O valor do elemento 5 eh: " << ar.getValue(5) << '\n';

    return 0;
}
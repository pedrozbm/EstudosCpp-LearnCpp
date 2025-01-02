#include <iostream> 

// Tanto a alocação estática e automática tem coisas em comum
// -> O tamanho deve ser conhecido em tempo de compilação
// -> A alocação e desalocação acontecem automaticamente


    // Vazamentos de memória: 
        // A memoria alocada dinamicamente permanece alocada até que seja liberada
void doSomething(){
    int* ptr{ new int };
    // Alocamos um ptr dinamicamente, porém nunca liberamos usando o delete
    // Como ptr sao var normais, ao terminar a função ele sai do escopo
    // Como ptr é a unica var que sabia o endereco da memoria alocada
    // Quando ele é destruido o programa "perde" o endereço alocado 
    // Como resultado, não conseguimos excluir... 
    // Isso é chamado de Vazamento de memoria 

    // Existem outras formas de se obter vazamento de memoria
    int value = 5;
    ptr = &value;
    // Como estamos fazendo o ptr apontar a um novo endereco
    // Perdemos a memoria antiga
    // Também poe se obter vazamento com a alocação dupla:
    ptr = new int{};
    // lembre-se que já alocamos na linha 11
}

int main(){
    // para alocar uma única var dinamicamente usamos a forma escalar do novo operador
    int* ptr{ new int };
    // o operador new cria o objeto usando essa memoria e retorna um ponteiro contendo o endereço que foi alocada
    *ptr = 7;

    // Assim que terminamos com uma var alocada, precisamos dizer explicitamente para liberar
    // para var unicas, usamos delete
    delete ptr;
    // O operador delete não apaga nada de fato, apenas devolve ao SO a memoria

    std::cout << *ptr;
    // Um ponteiro que aponta para memoria desalocada é chamado de ponteiro pendente 
    delete ptr;
    // Deletar ou desferenciar um ponteiro pendente pode causar erros indefinidos

    // Se new falhar, uma exceção bad_alloc é lançada
    // Podemos usar nothrow para contornar
    int* value { new (std::nothrow) int };
    // Se new, não coseguir alocar, ele retornara um ponteiro nulo
    // Um ponteiro nulo basicamente diz: Nenhuma memoria foi alocada para esse ponteiro
    if(!ptr)
        ptr = new int;
    
    // Excluir um ponteiro nulo não tem efeito, portanto não é necessáario um condicional
        
    return 0;
}
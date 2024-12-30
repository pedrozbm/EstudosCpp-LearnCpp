#include <iostream> 
#include <array>
#include <functional>

// Matrizxes bidimensionais são complexas e podem causar confusão
// Para facilitar, poderiamos tranformar em um array com dimensões menores, chamado Achatar um array
// Por exemplo, no lugar de linhas e colunas(2 dimensões), usamos apenas uma (linha * coluna)

// Esse modelo permite transformar a matriz
template <typename T, std::size_t linha, std::size_t coluna>
using ArrayFlat2d = std::array<T, linha * coluna>;

template <typename T, std::size_t linha, std::size_t coluna> 
class ArrayView2d
{
private:
    std::reference_wrapper<ArrayFlat2d<T, linha, coluna>> m_arr{};
public:
    ArrayView2d(ArrayFlat2d<T, linha, coluna>& arr):
    m_arr{arr}{};

    T& operator [](int i){return m_arr.get()[static_cast<std::size_t>(i)];}
    const T& operator[](int i) const { return m_arr.get()[static_cast<std::size_t>(i)];}

    T& operator()(int row,int col){return m_arr.get()[static_cast<std::size_t>(row * cols() + col)];}
    const T& operator()(int row, int col) const {return m_arr.get[static_cast<std::size_t>(row * cols() + col)];}

    int linhas() const{ return static_cast<int>(linha);}
    int cols() const {return static_cast<int>(coluna);}
    int tamanho() const {return static_cast<int>(linha * coluna);}
};

int main(){
    ArrayFlat2d<int, 3, 4> arr{
        1,2,3,4,
        5,6,7,8,
        9,10,11,12};

    ArrayView2d<int, 3, 4> arrView{ arr };

    std::cout << "Linhas: " << arrView.linhas() << '\n';
    std::cout << "Colunas: " << arrView.cols() << '\n';

    for(int i = 0; i < arrView.tamanho(); ++i)
        std::cout << arrView[i] << ' ';
    
    std::cout << '\n'; 

    for(int linha = 0; linha < arrView.linhas(); ++linha){
        for(int coluna = 0; coluna < arrView.cols(); ++coluna){
            std::cout << arrView(linha, coluna) << ' ';
        }
        std::cout << '\n';
    }

    return 0; 
}



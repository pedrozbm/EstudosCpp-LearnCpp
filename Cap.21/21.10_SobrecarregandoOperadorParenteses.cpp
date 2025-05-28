// Todos os crédittos a https://www.learncpp.com/cpp-tutorial/overloading-the-parenthesis-operator/

// Até agora, todos os operadores sobreccaregados que vimos
// Tem um número de parâmetros fixos ou limitados
// Já o operador de parênteses permite variar tanto tipo, como o numero de parâmetros

// O operador de parenteses deve ser usado como uma função membro

// Matrizes são componentes chaves da algebra linear
// E são frequentemente usadas em computação gráfica, machine learning, etc.
// Na lição passada, vimos como sobrecarregar [], assim acessamos uma matriz unidimensional
// Agora teremos um acesso bidimensional:

#include <iostream>
#include <cassert>

class Matrix
{
private:
    double m_data[4][4]{};

public:
    double &operator()(int row, int col);
    double operator()(int row, int col) const;
    double operator()();
};

double &Matrix::operator()(int row, int col)
{
    assert("numero invalido" && row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_data[row][col];
}

double Matrix::operator()(int row, int col)const
{
    assert("numero invalido" && row >= 0 && row < 4);
    assert(col >= 0 && col < 4);

    return m_data[row][col];
}

double Matrix::operator()(){
    //resetando todos os elementos:
    for(int row{0}; row < 4; ++row){
        for(int col{0}; col < 4; ++col){
            m_data[row][col] = 0.0;
        }
    }
    return 0;
}

int main(){
    Matrix matrix;
    matrix(1, 2) = 4.5;
    std::cout << matrix(1,2) << '\n';
    matrix();// Isso zera a matrix
    std::cout << matrix(1,2) << '\n';
}
// OBS: A partir do cpp23 já podemos usar o operator[] com
// varios indices, isso funciona exatamente como o operator()

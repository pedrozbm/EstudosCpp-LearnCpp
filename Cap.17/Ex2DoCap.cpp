#include <iostream>
#include <array>
#include <string>
#include <C:\Repositorios\Estudos\c++\Cap.8\Random.h>

namespace Pocao
{
    enum tipo
    {
        cura,
        mana,
        velocidade,
        invisibilidade,
        max_pocoes
    };

    constexpr std::array <int, tipo::max_pocoes> types {cura, mana, velocidade, invisibilidade};

    constexpr std::array<int, max_pocoes> custos{20, 30, 12, 50};
    const std::array<std::string, max_pocoes> nomes{{"cura","mana", "velocidade", "invisibilidade"}};

    // Aqui é garantido que todos os arrays possuem o mesmo tamanho 
    static_assert( sizeof(types) / sizeof(types[0]) == max_pocoes);
    static_assert(sizeof(custos) / sizeof(custos[0]) == max_pocoes);
    static_assert(sizeof(nomes) / sizeof(nomes[0]) == max_pocoes);

    void shop()
    {
        for (int i = 0; i < tipo::max_pocoes; ++i)
        {
            std::cout << static_cast<tipo>(i) << ") " << nomes[i] << " custa " << custos[i] << '\n';
        }
    }
}
class Player{
        private: 
            std::string m_nome{};
            int m_gold{};
            std::array<int, Pocao::max_pocoes> m_inventario{};

        public:
             Player(std::string nome): 
             m_nome{nome}, m_gold{Random::get(80, 120)}
            {};            

        int gold() const {return m_gold;}
        int inventario(Pocao::tipo p) const {return m_inventario[p];}
    };

int main()
{
    std::cout << "Bem vindo ao emporio das pocoes Roscoe "<< '\n';
    std::cout << "Digite seu nome: " ;
    std::string name{};
    std::cin >> name;
    Player player {name};
    
    std::cout << "Ola " << name << ", voce tem " << player.gold() << " gold. \n\n";

    Pocao::shop();

    std::cout << "\nObrigado por comprar na Roscoe's \n";
}
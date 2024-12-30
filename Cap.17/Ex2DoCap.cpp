#include <iostream>
#include <array>

namespace Pocao{
    enum tipo{
        cura,
        mana,
        velocidade, 
        invisibilidade,
        max_pocoes
    };

    constexpr std::array<int, 4> custos{20, 30, 12, 50};
    const  std::array<std::string, 4> nomes {tipo::cura, tipo::mana, tipo::velocidade, tipo::invisibilidade};

    

    void shop(std::array<int, 4>& custos, std::array<int, 4>& nomes){
        for (auto const& e: custos){
            custos[e] = 

        }
    }

}



int main(){



}
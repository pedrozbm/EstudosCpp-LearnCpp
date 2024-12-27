#include <iostream>
#include <array>

struct Item{
    std::string name{};
    int gold{};
};

template <std::size_t N>
void printItem(const std::array<Item, N>& arr){ 
    for(const auto& item: arr){
        std::cout << "A " << item.name << " costs " << item.gold << " gold.\n";
    }
}

int main(){
    const std::array<Item, 4> store{
        Item{ "Sword", 5},
        Item{ "dagger", 3},
        Item{ "club", 2},
        Item{"spear", 7}
    };
    printItem(store);
}
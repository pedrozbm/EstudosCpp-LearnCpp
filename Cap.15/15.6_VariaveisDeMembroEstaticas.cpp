#include <iostream>

int generateID(){
    static int s_id{0};
    return ++s_id;
}
// struct Something{
//     static int s_value;
// };
// int Something::s_value{1};

class Something{
    public: 

        static int s_value;
};
int Something::s_value{1};

// int Something::s_value{1};

int main(){
Something::s_value = 2;
std::cout << Something::s_value << '\n';

return 0;

// Something first{};
// Something second{};

// first.s_value = 2;

// std::cout << first.s_value << '\n';
// std::cout << second.s_value<< '\n';

// std::cout << generateID() << '\n';
// std::cout << generateID() << '\n';
// std::cout << generateID() << '\n';

}
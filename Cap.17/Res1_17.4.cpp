#include <iostream>
#include <array>

struct Student{
    int id{};
    std::string name{};
};
const std::array<Student, 3> students{ Student{0, "Alex"}, Student{1, "Joe"}, Student{2, "Bob"} };

const Student* findStudentById(int id){
    for(auto& s: students){
        if(s.id == id)return &s;
    }
    return nullptr;
}
int main(){
    const std::string nobody{"Nobody"};
    
    const Student* s1 {findStudentById(1)};
    std::cout << "You found: " << (s1 ? s1 -> name : nobody) << '\n';

    const Student* s2 {findStudentById(3)};
    std::cout << "You found: " << (s2 ? s2-> name: nobody) << '\n';

    return 0;
}
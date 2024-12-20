#include <iostream>
#include <vector>
#include <type_traits>
// namespace Students{
enum class StudentsNames
{
    kenny,
    kyle,
    stan,
    butters,
    cartman,
    max_students
};

constexpr auto operator+(StudentsNames a) noexcept
{
    return static_cast<std::underlying_type_t<StudentsNames>>(a);
}

int main()
{

    // std::vector<int> testScores{78, 94, 66, 77, 14};
    // Students::SudentsNames name{};
    std::vector<int> testScores(+StudentsNames::max_students);
    
    testScores[+StudentsNames::stan] = 76;

    // testScores[Students::stan] = 76;
    std::cout << "The class has " << +StudentsNames::max_students << " students ";

    return 0;
}

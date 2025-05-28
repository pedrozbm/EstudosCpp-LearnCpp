#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

struct StudentGrade
{
    std::string name{};
    char grade{};

    StudentGrade(std::string name_) : name{std::move(name_)}, grade{} {}
};

class GradeMap
{
private:
    std::vector<StudentGrade> m_map{};

public:
    char &operator[](std::string_view name);
};

char &GradeMap::operator[](std::string_view name)
{
    auto found{std::find_if(m_map.begin(), m_map.end(),
                            [name](const auto &student) {      // this is a lambda that captures name from the surrounding scope
                                return (student.name == name); // so we can use name here
                            })};

    if (found != m_map.end())
    {
        return found->grade;
    }

    // otherwise create a new StudentGrade for this student and add
    // it to the end of our vector.  Then return the grade.

    // emplace_back version (C++20 onward)
    // StudentGrade is an aggregate and emplace_back only works with aggregates as of C++20
    return m_map.emplace_back(StudentGrade{std::string{name}}).grade;

    // push_back version (C++17 or older)
    // m_map.push_back(StudentGrade{std::string{name}});
    // return m_map.back().grade;
}

int main()
{
    GradeMap grades{};

    grades["Joe"] = 'A';
    grades["Frank"] = 'B';

    std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
    std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

    return 0;
}
#include <iostream>
#include <list>

struct Student {
    int rollNo;
    std::string name;
};

struct Course {
    int rollNo;
    std::string courseName;
};

struct CGPA {
    int rollNo;
    float cgpa;
};

void findCommonRollNumbers(const std::list<Student>& students, const std::list<Course>& courses, const std::list<CGPA>& cgpaList) {
    auto it1 = students.begin();
    auto it2 = courses.begin();
    auto it3 = cgpaList.begin();

    while (it1 != students.end() && it2 != courses.end() && it3 != cgpaList.end()) {
        if (it1->rollNo == it2->rollNo && it1->rollNo == it3->rollNo) {
            std::cout << "Common Roll Number: " << it1->rollNo << std::endl;
            ++it1;
            ++it2;
            ++it3;
        } else if (it1->rollNo < it2->rollNo || it1->rollNo < it3->rollNo) {
            ++it1;
        } else if (it2->rollNo < it1->rollNo || it2->rollNo < it3->rollNo) {
            ++it2;
        } else {
            ++it3;
        }
    }
}

int main() {
    std::list<Student> students = {{101, "John"}, {105, "Alice"}, {110, "Bob"}, {120, "Eva"}};
    std::list<Course> courses = {{101, "BE"}, {105, "BCA"}, {110, "BBA"}, {125, "BSc"}};
    std::list<CGPA> cgpaList = {{100, 8.5}, {105, 9.2}, {110, 7.8}, {120, 8.9}};

    findCommonRollNumbers(students, courses, cgpaList);

    return 0;
}

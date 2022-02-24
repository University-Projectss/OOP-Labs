#include <iostream>
using namespace std;

class Student {
public:
    const char *name;
    int group;
    int grade;

    Student(const char *name_, int group_, int grade_) {
        name = name_;
        group = group_;
        grade = grade_;
    }
};

int main() {
    Student s("Robert", 133, 9);

   cout << s.name << endl;
}
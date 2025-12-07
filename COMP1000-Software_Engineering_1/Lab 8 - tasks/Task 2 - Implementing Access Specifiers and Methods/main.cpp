#include <iostream>
#include <string>

class Student {
    private:
        std::string name;
        int age;
        char grade;

    public:
        void setName(std::string n) {name = n;}
        void setAge(int a) {age = a;}
        void setGrade(char g) {grade = g;}

        std::string getName() {return name;}
        int getAge() {return age;}
        char getGrade() {return grade;}
};
int main()
{
    Student student;
    student.setName("Alice");
    student.setAge(20);
    student.setGrade('A');
    std::cout << "student name: " << student.getName() << std::endl;
    std::cout << "student age: " << student.getAge() << std::endl;
    std::cout << "student grade: " << student.getGrade() << std::endl;

    return 0;
}

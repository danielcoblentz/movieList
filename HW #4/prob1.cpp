#include "School.h"
#include "Student.h"
#include <iostream>

int main() {
    School school;

    // Student objects using the provided names
    Student* student1 = new Student("Alice");
    Student* student2 = new Student("Bob");
    Student* student3 = new Student("Charlie");



    //add student
    if (school.addStudent(student1)) std::cout << "student added: Alice" << std::endl;
    if (school.addStudent(student2)) std::cout << "student added: Bob" << std::endl;
    if (school.addStudent(student3)) std::cout << "student added: Charlie" << std::endl;

    // message displaying all students
    std::cout << "Students in the school:" << std::endl;
    school.displayStudents();

    // destructor of School
    return 0;
}

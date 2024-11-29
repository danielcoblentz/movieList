// Student.h


#ifndef STUDENT_H
#define STUDENT_H

#include <string>



class Student { // private class Student
private:
    std::string name; //name of student

public:
    //constructor to initializes the student's name
    Student(const std::string& name) : name(name) {}

    // retrieves the name of the student
    std::string getName() const {return name;}
};

#endif // STUDENT_H

//
// Created by Dan Coblentz on 10/29/24.
//
// School.h
#ifndef SCHOOL_H
#define SCHOOL_H

#include "Student.h"
#include <iostream>

class School {
    private:
    static const int MAX_STUDENTS = 3; // max capacity of students
    Student* students[MAX_STUDENTS];
    int studentCount; // num of enrolled students

public:
    School() : studentCount(0) { // set the student count  to zero
        for (int i = 0; i < MAX_STUDENTS; ++i) {
            students[i] = nullptr; // make sure it potints ot nothing intially
        }
    }
// method to add student if there is capacity
    bool addStudent(Student* student) {
        if (studentCount < MAX_STUDENTS) {
            students[studentCount++] = student;
            return true;
        }
        return false;
    }
// method to display all names of the nerolled students
    void displayStudents() const {
        for (int i = 0; i < studentCount; ++i) {
            std::cout << students[i]->getName() << std::endl;
        }
    }
//destructor to clean up dynamically allocated student objects
    ~School() {
        for (int i = 0; i < studentCount; ++i) {
            delete students[i];
        }
    }
};

#endif // School.h

//
// Created by Dan Coblentz on 10/21/24.
//

#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
using namespace std;


//
class Car {
public:
    std::string brand; // brand of car
    std::string model; // model of car
    int year; // year of car
//defualt constructor
    Car();

    Car(std::string brand, std::string model, int year);
    void displayCarInfo() const; // function to display car information


//overloading assignment operator
    Car& operator=(const Car& car);

};
#endif //CAR_H
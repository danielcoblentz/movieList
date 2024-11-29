//
// Created by Dan Coblentz on 10/21/24.
//
#include "Car.h"

// default constructor
Car::Car() : brand("unknown brand"), model("unknown model"),year(0) {} // defualt vals

// parameters
Car::Car(std::string b, std::string m, int y) : brand(b), model(m), year(y) {}

void Car::displayCarInfo() const { // function to display car inofrmation
    std::cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << std::endl;
}
//overloading assignment operator
Car& Car::operator=(const Car& otherCar) {
    if (this != &otherCar) {
        brand = otherCar.brand;
        model = otherCar.model;
        year = otherCar.year;

    }
    return *this;
}
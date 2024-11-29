//
// Created by Dan Coblentz on 10/29/24.
//

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
# include <string>


// base call for all types of vehicles
class Vehicle {
    protected:
    std::string make;
    std::string model;
    int speed;

    public:
    //constructor for vehicle attributes
    Vehicle(const std::string& make, const std::string model, int speed)
        : make(make), model(model), speed(speed) {}

        // virtual funciton to show vehicle details
    virtual void showDetails() const {
        std::cout << "Car Make: " << make <<", model: " << model << ", speed: " << speed << " km/h";
    }
//make sure derived class destructors are called
    virtual ~Vehicle() {}
};

#endif //VEHICLE_H



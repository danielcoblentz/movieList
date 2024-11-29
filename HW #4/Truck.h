//
// Created by Dan Coblentz on 10/29/24.
//

#ifndef TRUCK_H
#define TRUCK_H
//add Vehicle file
# include "Vehicle.h"

//derived class from vehicle
class Truck : public Vehicle {
    protected:
    int payload_capacity; // payload capacity in kg

    public:
    Truck(const std::string& make,const std::string& model, int speed, int capacity)
        : Vehicle(make, model, speed), payload_capacity(capacity) {}



    //override show details to include truck information

    void showDetails() const override {
        std::cout << "truck Make: " << make << ", model: " << model << ", speed: " << speed << " km/h, payload capacity: " << payload_capacity << " kg" << std::endl;
    }
};



#endif //TRUCK_H

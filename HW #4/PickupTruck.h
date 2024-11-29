// Created by Dan Coblentz on 10/29/24.
//

#ifndef PICKUPTRUCK_H
#define PICKUPTRUCK_H
#include "Truck.h"

// derived class from truck header file, make private
class PickupTruck : public Truck {
private:
    bool offroad_capability;

public:
    // constructor to intalize pickup truck spec and inherited attributes
    PickupTruck(const std::string& make, const std::string& model, int speed, int capacity, bool offroad)
        : Truck(make, model, speed, capacity), offroad_capability(offroad) {}


    //override showdetails to include pickupTruck information to user
    void showDetails() const override {
        std::cout << "pickup Truck Make: " << make << ", model: " << model << ", speed: " << speed << " km/h, payload capacity: " << payload_capacity << " kg, offroad capable: " << (offroad_capability ? "Yes" : "No") << std::endl;
    }
};

#endif //PICKUPTRUCK_H

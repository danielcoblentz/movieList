#include <iostream>
// include the header files
#include "Car.h"
#include "Vehicle.h"
#include "Truck.h"
#include "PickupTruck.h"

int main() {
 Vehicle* vehicles[3]; //array of Vehicle pointers

 // initializing the array with different types of vehicles per instucitons
 vehicles[0] = new Car("Toyota", "Corolla", 170, 4);
 vehicles[1] = new Truck("Ford", "F-150", 110, 1000);
 vehicles[2] = new PickupTruck("Ram", "1500", 130, 1200, true);


 //loop through the array and show details of each vehicle
 for (int i = 0; i < 3; i++) {
  vehicles[i]->showDetails();
 }



 // clean up memory
 for (int i = 0; i < 3; i++) {
  delete vehicles[i];
 }

 return 0;
}

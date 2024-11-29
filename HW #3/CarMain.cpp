// CarMain.cpp
#include "Car.h"

int main() {
    //  Car objects using default and parameterized constructors
    Car car1("Toyota", "Camry", 2020);   // car 1: toyota camry, 2020
    Car car2("Honda", "Accord", 2018);   // car 2: honda accord, 2018
    Car car3; //cCar 3 ssing default constructor

    cout << "Before assignment:" << endl;
    cout << "Car 1: ";
    car1.displayCarInfo();  // details of car 1
    cout << "Car 2: ";
    car2.displayCarInfo();  //details of car 2
    cout << "Car 3 (default): ";
    car3.displayCarInfo();  //details of car 3



    // assignment operator to copy details from car2 to car1 and car3
    car1 = car2;
    car3 = car1;

    cout << "\nafter assignment:" << endl;
    cout << "Car 1: ";
    car1.displayCarInfo();  // show details of car 1 after assignment
    cout << "Car 2: ";
    car2.displayCarInfo();  //how details of car 2
    cout << "Car 3 (assigned from Car 1): ";
    car3.displayCarInfo();  //show details of car 3 after assignment

    // test self-assignment
    car1 = car1;
    cout << "\nAfter self-assignment of Car 1:" << endl;
    car1.displayCarInfo(); //show details of car 1 to ensure it is unchanged

    return 0;
}

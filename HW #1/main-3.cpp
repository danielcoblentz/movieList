#include <iostream>

int main() {
    //initial varibles needed for conversion (source google for values)
    float litersPerGallon = 3.78541;
    float kilometersPerMile = 1.609344;

    // Conversion factor calculation
    float conversionFactor = 100.0 * litersPerGallon / kilometersPerMile;

    // Store the input mpg value from user
    double mpg;

    // Get user input for fuel efficiency in mpg
    std::cout << "Please enter the fuel efficiency in miles per gallon (mpg): ";
    std::cin >> mpg;

    // conversion making sure its in double data type
    double litersPer100km = static_cast<double>(conversionFactor) / mpg;

    // Output
    std::cout << mpg << " mpg is " << litersPer100km << " liters per 100 kilometers." << std::endl;

    return 0;
}

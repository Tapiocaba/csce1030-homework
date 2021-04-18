#include <iostream>
#include <cmath>
using namespace std;

int main() {

    cout << "+----------------------------------------------+" << endl;
    cout << "|        Computer Science and Engineering      |" << endl;
    cout << "|       CSCE 1030.002 - Computer Science I     |" << endl;
    cout << "|   Jennifer Ai jla0325 JenniferAi@my.unt.edu  |" << endl;
    cout << "|   Cindy Liang cl0822 CindyLiang@my.unt.edu   |" << endl;
    cout << "|      Lisa Lin ll0484 LisaLin@my.unt.edu      |" << endl;
    cout << "+----------------------------------------------+" << endl;

    // defining constants
    const double GRAVITATION_CONSTANT = 6.67e-11; // in m^3/kg/sec^2
    const double MULTIPLIER_CONSTANT = 1609.34;

    // variable declariations
    double radius; //in miles
    double planetMass; //in kg
    double velocity; //in meters per second
    int objectMass; //in kg

    // prompting user to enter values
    cout << "Enter the radius of the planet (in miles): "; cin >> radius;
    cout << "Enter the mass of the planet (in kg): "; cin >> planetMass;

    // converting the radius from miles to meters
    radius *= MULTIPLIER_CONSTANT;

    // calculating the escape velocity of the planet
    velocity = sqrt((2*GRAVITATION_CONSTANT*planetMass)/radius);

    // setting 3 decimal places after calculating escape velocity
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    // displaying escape velocity of the planet to the user
    cout << "The escape velocity of the planet is " << velocity << " meters per second." << endl;

    // prompting user for mass
    cout << "Enter mass of the object (in kg): ";
    cin >> objectMass;

    // setting 4 decimal places after the calculated kinetic energy
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    // displaying and calculating the kinetic energy
    cout << "The kinetic energy required by the object to escape the planet is " << (1.0/2.0)*(objectMass)*(pow(velocity,2.0)) << " Joules." << endl;

    return 0;
}

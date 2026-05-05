#include "car.h"

// Constructor
Car::Car(string br, string mo, string fuel, string cat,
         string usage, string trans, double pr,
         double mil, int seats, int yr)
    : brand(br), model(mo), fuelType(fuel), category(cat),
      usageType(usage), transmission(trans),
      price(pr), mileage(mil),
      seatingCapacity(seats), year(yr) {}

string Car::getBrand() const { return brand; }
string Car::getModel() const { return model; }
string Car::getFuelType() const { return fuelType; }
string Car::getCategory() const { return category; }
string Car::getUsageType() const { return usageType; }
string Car::getTransmission() const { return transmission; }
double Car::getPrice() const { return price; }
double Car::getMileage() const { return mileage; }
int Car::getSeats() const { return seatingCapacity; }
int Car::getYear() const { return year; }

void Car::showInfo() const {
    cout << brand << " " << model << " | Rs." << price << "L" << endl;
}

// Implement ALL derived class functions here
// (copy from your original code directly)

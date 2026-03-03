#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car {
protected:
    string brand;
    string model;
    string fuelType;
    string category;
    double price;
    double mileage;
    int seatingCapacity;
    string usageType;
    string transmission;
    int year;

public:
    Car(string br, string mo, string fuel, string cat,
        double pr, double mil, int seats, string usage, string trans, int yr)
        : brand(br), model(mo), fuelType(fuel), category(cat),
          price(pr), mileage(mil), seatingCapacity(seats),
          usageType(usage), transmission(trans), year(yr) {}

    virtual ~Car() {}


    virtual void displayDetails() const = 0;
    virtual string getCategoryDescription() const = 0;
    virtual double getComfortScore() const = 0;
    virtual double getFuelEfficiencyRating() const = 0;

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    string getFuelType() const { return fuelType; }
    string getCategory() const { return category; }
    double getPrice() const { return price; }
    double getMileage() const { return mileage; }
    int getSeatingCapacity() const { return seatingCapacity; }
    string getUsageType() const { return usageType; }
    string getTransmission() const { return transmission; }
    int getYear() const { return year; }

    void displayBasicInfo() const {
        cout << "  Brand       : " << brand << endl;
        cout << "  Model       : " << model << endl;
        cout << "  Year        : " << year << endl;
        cout << "  Category    : " << category << endl;
        cout << "  Fuel Type   : " << fuelType << endl;
        cout << "  Price       : Rs. " << price << " Lakhs" << endl;
        cout << "  Mileage     : " << mileage << " km/l" << endl;
        cout << "  Seating     : " << seatingCapacity << " persons" << endl;
        cout << "  Usage       : " << usageType << endl;
        cout << "  Transmission: " << transmission << endl;
    }
};

#endif

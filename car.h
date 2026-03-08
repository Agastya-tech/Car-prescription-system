#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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

    // Version 2 - Display only basic identity (bool parameter)
    void displayBasicInfo(bool shortVersion) const {
        if (shortVersion) {
            cout << "  " << brand << " " << model
                 << " (" << year << ") - Rs. "
                 << price << " Lakhs - "
                 << fuelType << " - "
                 << category << endl;
        } else {
            displayBasicInfo();
        }
    }

    void displayBasicInfo(const string& label) const {
        cout << "\n  --- " << label << " ---" << endl;
        cout << "  " << brand << " " << model << endl;
        cout << "  Price    : Rs. " << fixed << setprecision(2) << price << " Lakhs" << endl;
        cout << "  Fuel     : " << fuelType << endl;
        cout << "  Mileage  : " << mileage << " km/l" << endl;
        cout << "  Seating  : " << seatingCapacity << " persons" << endl;
    }

    bool operator<(const Car& other) const {
        return this->price < other.price;
    }

    bool operator>(const Car& other) const {
        return this->price > other.price;
    }

    bool operator==(const Car& other) const {
        return (this->brand == other.brand && this->model == other.model);
    }

    bool operator!=(const Car& other) const {
        return !(this->brand == other.brand && this->model == other.model);
    }

    friend ostream& operator<<(ostream& os, const Car& car) {
        os << car.brand << " " << car.model
           << " | Rs. " << car.price << " Lakhs"
           << " | " << car.fuelType
           << " | " << car.category
           << " | " << car.mileage << " km/l";
        return os;
    }
};

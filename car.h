#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string brand, model, fuelType, category, usageType, transmission;
    double price, mileage;
    int seatingCapacity, year;

public:
    Car(string br, string mo, string fuel, string cat,
        string usage, string trans, double pr,
        double mil, int seats, int yr);

    virtual ~Car() {}

    virtual void displayDetails() const = 0;
    virtual string getDescription() const = 0;
    virtual double getComfortScore() const = 0;
    virtual double getEfficiencyScore() const = 0;

    // Getters
    string getBrand() const;
    string getModel() const;
    string getFuelType() const;
    string getCategory() const;
    string getUsageType() const;
    string getTransmission() const;
    double getPrice() const;
    double getMileage() const;
    int getSeats() const;
    int getYear() const;

    void showInfo() const;
};

// Derived Classes
class Hatchback : public Car {
    bool hasSunroof;
    string safetyRating;
public:
    Hatchback(string, string, string, string, string,
              double, double, int, int, bool, string);

    void displayDetails() const override;
    string getDescription() const override;
    double getComfortScore() const override;
    double getEfficiencyScore() const override;
};

class Sedan : public Car {
    string interiorQuality;
    bool hasADAS;
public:
    Sedan(string, string, string, string, string,
          double, double, int, int, string, bool);

    void displayDetails() const override;
    string getDescription() const override;
    double getComfortScore() const override;
    double getEfficiencyScore() const override;
};

class SUV : public Car {
    bool is4WD;
    int groundClearance;
public:
    SUV(string, string, string, string, string,
        double, double, int, int, bool, int);

    void displayDetails() const override;
    string getDescription() const override;
    double getComfortScore() const override;
    double getEfficiencyScore() const override;
};

class MUV : public Car {
    int bootSpace;
    bool hasSliderDoors;
public:
    MUV(string, string, string, string, string,
        double, double, int, int, int, bool);

    void displayDetails() const override;
    string getDescription() const override;
    double getComfortScore() const override;
    double getEfficiencyScore() const override;
};

#endif

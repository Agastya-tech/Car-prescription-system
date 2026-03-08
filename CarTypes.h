#pragma once

#include "Car.h"

class Hatchback : public Car {
private:
    bool hasSunroof;
    string safetyRating;

public:
    Hatchback(string br, string mo, string fuel, double pr,
              double mil, int seats, string usage, string trans,
              int yr, bool sunroof, string safety)
        : Car(br, mo, fuel, "Hatchback", pr, mil, seats, usage, trans, yr),
          hasSunroof(sunroof), safetyRating(safety) {}

    void displayDetails() const override {
        cout << "\n .-.HATCHBACK DETAILS.-. " << endl;
        displayBasicInfo();
        cout << "  Sunroof     : " << (hasSunroof ? "Yes" : "No") << endl;
        cout << "  Safety Rating: " << safetyRating << endl;
        cout << "  Description : " << getCategoryDescription() << endl;
    }

    string getCategoryDescription() const override {
        return "Compact and fuel-efficient, ideal for city driving and daily commute.";
    }

    double getComfortScore() const override {
        double score = 6.0;
        if (hasSunroof) score += 1.0;
        if (transmission == "Automatic") score += 0.5;
        if (safetyRating == "5-Star") score += 1.5;
        else if (safetyRating == "4-Star") score += 1.0;
        return score;
    }

    double getFuelEfficiencyRating() const override {
        if (mileage >= 20) return 10.0;
        else if (mileage >= 16) return 8.0;
        else if (mileage >= 12) return 6.0;
        else return 4.0;
    }
};

class Sedan : public Car {
private:
    string interiorQuality;
    bool hasADAS;

public:
    Sedan(string br, string mo, string fuel, double pr,
          double mil, int seats, string usage, string trans,
          int yr, string interior, bool adas)
        : Car(br, mo, fuel, "Sedan", pr, mil, seats, usage, trans, yr),
          interiorQuality(interior), hasADAS(adas) {}

    void displayDetails() const override {
        cout << "\n .-.SEDAN DETAILS.-. " << endl;
        displayBasicInfo();
        cout << "  Interior    : " << interiorQuality << endl;
        cout << "  ADAS        : " << (hasADAS ? "Yes" : "No") << endl;
        cout << "  Description : " << getCategoryDescription() << endl;
    }

    string getCategoryDescription() const override {
        return "Stylish and comfortable, perfect for families and professionals.";
    }

    double getComfortScore() const override {
        double score = 7.5;
        if (interiorQuality == "Premium") score += 1.5;
        else if (interiorQuality == "Standard") score += 0.5;
        if (hasADAS) score += 1.0;
        if (transmission == "Automatic") score += 0.5;
        return score;
    }

    double getFuelEfficiencyRating() const override {
        if (mileage >= 18) return 9.0;
        else if (mileage >= 14) return 7.0;
        else if (mileage >= 10) return 5.0;
        else return 3.0;
    }
};

class SUV : public Car {
private:
    bool is4WD;
    int groundClearance;
    string terrainType;

public:
    SUV(string br, string mo, string fuel, double pr,
        double mil, int seats, string usage, string trans,
        int yr, bool fourWD, int gClear, string terrain)
        : Car(br, mo, fuel, "SUV", pr, mil, seats, usage, trans, yr),
          is4WD(fourWD), groundClearance(gClear), terrainType(terrain) {}

    void displayDetails() const override {
        cout << "\n  ---- SUV DETAILS ----" << endl;
        displayBasicInfo();
        cout << "  4WD         : " << (is4WD ? "Yes" : "No") << endl;
        cout << "  Ground Clear: " << groundClearance << " mm" << endl;
        cout << "  Terrain Type: " << terrainType << endl;
        cout << "  Description : " << getCategoryDescription() << endl;
    }

    string getCategoryDescription() const override {
        return "Powerful and spacious, suited for highways, rough terrain and large families.";
    }

    double getComfortScore() const override {
        double score = 7.0;
        if (is4WD) score += 1.5;
        if (groundClearance >= 200) score += 1.0;
        if (seatingCapacity >= 7) score += 0.5;
        if (transmission == "Automatic") score += 0.5;
        return score;
    }

    double getFuelEfficiencyRating() const override {
        if (mileage >= 16) return 8.5;
        else if (mileage >= 12) return 6.5;
        else if (mileage >= 9)  return 4.5;
        else return 3.0;
    }
};

class MUV : public Car {
private:
    int bootSpace;
    bool hasSliderDoors;

public:
    MUV(string br, string mo, string fuel, double pr,
        double mil, int seats, string usage, string trans,
        int yr, int boot, bool slider)
        : Car(br, mo, fuel, "MUV", pr, mil, seats, usage, trans, yr),
          bootSpace(boot), hasSliderDoors(slider) {}

    void displayDetails() const override {
        cout << "\n  ---- MUV DETAILS ----" << endl;
        displayBasicInfo();
        cout << "  Boot Space  : " << bootSpace << " litres" << endl;
        cout << "  Slider Doors: " << (hasSliderDoors ? "Yes" : "No") << endl;
        cout << "  Description : " << getCategoryDescription() << endl;
    }

    string getCategoryDescription() const override {
        return "High capacity and utility-focused, great for large families and long trips.";
    }

    double getComfortScore() const override {
        double score = 6.5;
        if (bootSpace >= 300) score += 1.0;
        if (hasSliderDoors) score += 1.0;
        if (seatingCapacity >= 7) score += 1.0;
        if (transmission == "Automatic") score += 0.5;
        return score;
    }

    double getFuelEfficiencyRating() const override {
        if (mileage >= 15) return 8.0;
        else if (mileage >= 12) return 6.0;
        else if (mileage >= 9)  return 4.0;
        else return 2.5;
    }
};



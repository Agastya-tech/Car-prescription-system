#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================= BASE CLASS =================
class Car {
protected:
    string brand, model, fuelType, category;
    double price, mileage;
    int seats;

public:
    Car(string b, string m, string f, string c, double p, double mil, int s) {
        brand = b;
        model = m;
        fuelType = f;
        category = c;
        price = p;
        mileage = mil;
        seats = s;
    }

    virtual void displayDetails() {
        cout << "----------------------------------\n";
        cout << "Brand    : " << brand << endl;
        cout << "Model    : " << model << endl;
        cout << "Fuel     : " << fuelType << endl;
        cout << "Category : " << category << endl;
        cout << "Price    : Rs. " << price << " Lakhs" << endl;
        cout << "Mileage  : " << mileage << " km/l" << endl;
        cout << "Seats    : " << seats << endl;
    }

    double getPrice() { return price; }
    string getFuel() { return fuelType; }
    string getCategory() { return category; }
    int getSeats() { return seats; }
};

// ================= DERIVED CLASSES =================
class Hatchback : public Car {
public:
    Hatchback(string b, string m, string f, double p, double mil, int s)
        : Car(b, m, f, "Hatchback", p, mil, s) {}

    void displayDetails() override {
        cout << "\n[HATCHBACK]\n";
        Car::displayDetails();
    }
};

class Sedan : public Car {
public:
    Sedan(string b, string m, string f, double p, double mil, int s)
        : Car(b, m, f, "Sedan", p, mil, s) {}

    void displayDetails() override {
        cout << "\n[SEDAN]\n";
        Car::displayDetails();
    }
};

class SUV : public Car {
public:
    SUV(string b, string m, string f, double p, double mil, int s)
        : Car(b, m, f, "SUV", p, mil, s) {}

    void displayDetails() override {
        cout << "\n[SUV]\n";
        Car::displayDetails();
    }
};

// ================= USER PREFERENCES =================
struct UserPreferences {
    double minBudget;
    double maxBudget;
    string fuel;
    string category;
    int minSeats;
};

// ================= SHOW MENU =================
void showMenu() {
    cout << "\n====== CAR PRESCRIPTION SYSTEM ======\n";
    cout << "1. Get Recommendation\n";
    cout << "2. Show All Cars\n";
    cout << "3. Exit\n";
    cout << "Enter choice: ";
}

// ================= SHOW ALL =================
void showAllCars(vector<Car*>& cars) {
    for (int i = 0; i < cars.size(); i++) {
        cout << "\nCar #" << i + 1 << endl;
        cars[i]->displayDetails();
    }
}

// ================= GET USER INPUT =================
UserPreferences getUserInput() {
    UserPreferences user;

    cout << "Enter minimum budget: ";
    cin >> user.minBudget;

    cout << "Enter maximum budget: ";
    cin >> user.maxBudget;

    cout << "Enter fuel type (Petrol/Diesel/Any): ";
    cin >> user.fuel;

    cout << "Enter category (Hatchback/Sedan/SUV/Any): ";
    cin >> user.category;

    cout << "Enter minimum seats: ";
    cin >> user.minSeats;

    return user;
}

// ================= RECOMMENDATION =================
void recommendCars(vector<Car*>& cars, UserPreferences user) {
    cout << "\nRecommended Cars:\n";

    bool found = false;

    for (int i = 0; i < cars.size(); i++) {

        if (cars[i]->getPrice() >= user.minBudget &&
            cars[i]->getPrice() <= user.maxBudget &&
            cars[i]->getSeats() >= user.minSeats) {

            if ((user.fuel == "Any" || cars[i]->getFuel() == user.fuel) &&
                (user.category == "Any" || cars[i]->getCategory() == user.category)) {

                cars[i]->displayDetails();
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No cars match your preferences.\n";
    }
}

// ================= MAIN =================
int main() {

    vector<Car*> cars;

    // Adding sample data
    cars.push_back(new Hatchback("Maruti", "Swift", "Petrol", 6.5, 22, 5));
    cars.push_back(new Hatchback("Hyundai", "i20", "Petrol", 7.0, 20, 5));
    cars.push_back(new Sedan("Honda", "City", "Petrol", 11, 18, 5));
    cars.push_back(new Sedan("Skoda", "Slavia", "Petrol", 11.5, 19, 5));
    cars.push_back(new SUV("Tata", "Nexon", "Petrol", 8, 17, 5));
    cars.push_back(new SUV("Mahindra", "XUV700", "Diesel", 14, 16, 7));

    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {

        case 1: {
            UserPreferences user = getUserInput();
            recommendCars(cars, user);
            break;
        }

        case 2:
            showAllCars(cars);
            break;

        case 3:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}

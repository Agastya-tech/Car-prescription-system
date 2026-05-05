#include "database.h"

void CarDatabase::loadCars() {
    cars.push_back(new Hatchback("Maruti","Swift","Petrol",
        "City","Manual",6.49,23.2,5,2023,false,"4-Star"));

    // ADD ALL OTHER CARS HERE (copy paste)
}

vector<Car*>& CarDatabase::getCars() { return cars; }

int CarDatabase::getTotal() { return cars.size(); }

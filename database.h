#ifndef DATABASE_H
#define DATABASE_H

#include "car.h"
#include <vector>

class CarDatabase {
private:
    vector<Car*> cars;

public:
    void loadCars();
    vector<Car*>& getCars();
    int getTotal();
};

#endif

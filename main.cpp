#include "database.h"
#include "engine.h"
#include <iostream>
using namespace std;

int main() {
    CarDatabase db;
    RecommendationEngine engine;

    db.loadCars();

    engine.showRecommendations(
        db.getCars(),
        5, 15, "Petrol", "SUV",
        "City", "Manual", 5
    );

    return 0;
}

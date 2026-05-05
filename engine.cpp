#include "engine.h"
#include <iostream>
using namespace std;

void RecommendationEngine::showRecommendations(
    vector<Car*>& cars,
    double minBudget, double maxBudget,
    string fuel, string category,
    string usage, string transmission,
    int seats)
{
    cout << "\nTop Recommendations:\n";

    for (Car* c : cars) {
        if (c->getPrice() >= minBudget &&
            c->getPrice() <= maxBudget) {
            c->displayDetails();
        }
    }
}

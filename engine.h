#ifndef ENGINE_H
#define ENGINE_H

#include "car.h"
#include <vector>

class RecommendationEngine {
public:
    void showRecommendations(std::vector<Car*>& cars,
        double minBudget, double maxBudget,
        std::string fuel, std::string category,
        std::string usage, std::string transmission,
        int seats);
};

#endif

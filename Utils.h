#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

template <typename T, typename Comparator>
void sortCars(vector<T*>& cars, Comparator comp)
{
    sort(cars.begin(), cars.end(), comp);
}

template <typename T, typename Condition>
vector<T*> filterCars(const vector<T*>& cars, Condition cond)
{
    vector<T*> result;
    for (auto* car : cars)
        {
        if (cond(car))
         {
            result.push_back(car);
        }
    }
    return result;
}

template <typename T>
T findMin(const vector<T>& values)
{
    if (values.empty()) throw runtime_error("Empty list provided.");
    T minVal = values[0];
    for (const T& v : values) {
        if (v < minVal) minVal = v;
    }
    return minVal;
}

template <typename T>
T findMax(const vector<T>& values)
{
    if (values.empty()) throw runtime_error("Empty list provided.");
    T maxVal = values[0];
    for (const T& v : values) {
        if (v > maxVal) maxVal = v;
    }
    return maxVal;
}

template <typename T>
double calculateAverage(const vector<T>& values)
{
    if (values.empty()) throw runtime_error("Empty list for average.");
    double sum = 0;
    for (const T& v : values) sum += v;
    return sum / values.size();
}

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

template <typename T, typename Comparator>
void sortCars(vector<T*>& cars, Comparator comp) {
    sort(cars.begin(), cars.end(), comp);
}

template <typename T, typename Condition>
vector<T*> filterCars(const vector<T*>& cars, Condition cond) {
    vector<T*> result;
    for (auto* car : cars) {
        if (cond(car)) {
            result.push_back(car);
        }
    }
    return result;
}

template <typename T>
T findMin(const vector<T>& values) {
    if (values.empty()) throw runtime_error("Empty list provided.");
    T minVal = values[0];
    for (const T& v : values) {
        if (v < minVal) minVal = v;
    }
    return minVal;
}

template <typename T>
T findMax(const vector<T>& values) {
    if (values.empty()) throw runtime_error("Empty list provided.");
    T maxVal = values[0];
    for (const T& v : values) {
        if (v > maxVal) maxVal = v;
    }
    return maxVal;
}

template <typename T>
double calculateAverage(const vector<T>& values) {
    if (values.empty()) throw runtime_error("Empty list for average.");
    double sum = 0;
    for (const T& v : values) sum += v;
    return sum / values.size();
}

class InvalidInputException : public exception {
    string message;
public:
    InvalidInputException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class NoCarsFoundException : public exception {
public:
    const char* what() const noexcept override {
        return "No cars found matching your criteria. Please try different preferences.";
    }
};

class InvalidBudgetException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid budget entered. Budget must be a positive number.";
    }
};

void printDivider(char ch = '=', int len = 60) {
    cout << string(len, ch) << endl;
}

void printHeader(const string& title) {
    printDivider();
    int padding = (60 - title.size()) / 2;
    cout << string(padding, ' ') << title << endl;
    printDivider();
}

void printSubHeader(const string& title) {
    printDivider('-', 60);
    cout << "  " << title << endl;
    printDivider('-', 60);
}

void printCarNumber(int num) {
    cout << "\n  [Recommendation #" << num << "]" << endl;
}

string getValidatedChoice(const vector<string>& options, const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;
        for (const string& opt : options) {
            if (input == opt) return input;
        }
        throw InvalidInputException("Invalid choice: '" + input + "'. Please enter one of the listed options.");
    }
}

double getValidatedDouble(const string& prompt, double minVal, double maxVal) {
    double value;
    string raw;
    cout << prompt;
    cin >> raw;
    try {
        value = stod(raw);
    } catch (...) {
        throw InvalidInputException("Input must be a numeric value.");
    }
    if (value < minVal || value > maxVal) {
        throw InvalidInputException("Value out of accepted range (" +
            to_string((int)minVal) + " - " + to_string((int)maxVal) + ").");
    }
    return value;
}

void displayScoreBar(double score, double maxScore = 10.0) {
    int filled = (int)((score / maxScore) * 20);
    cout << "  Match Score : [";
    for (int i = 0; i < 20; i++) cout << (i < filled ? "#" : "-");
    cout << "] " << fixed << setprecision(1) << score << "/" << maxScore << endl;
}
void printDivider(char ch = '=', int len = 60) {
    cout << string(len, ch) << endl;
}

void printHeader(const string& title) {
    printDivider();
    int padding = (60 - title.size()) / 2;
    cout << string(padding, ' ') << title << endl;
    printDivider();
}

void printSubHeader(const string& title) {
    printDivider('-', 60);
    cout << "  " << title << endl;
    printDivider('-', 60);
}

void printCarNumber(int num) {
    cout << "\n  [Recommendation #" << num << "]" << endl;
}

void displayScoreBar(double score, double maxScore = 10.0) {
    int filled = (int)((score / maxScore) * 20);
    cout << "  Match Score : [";
    for (int i = 0; i < 20; i++) cout << (i < filled ? "#" : "-");
    cout << "] " << fixed << setprecision(1) << score << "/" << maxScore << endl;
}

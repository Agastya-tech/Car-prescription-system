# 🚗 Car Prescription System

A decision-based car recommendation system built in **C++** that helps users identify the most suitable vehicle based on their budget, fuel preference, usage needs, and car category.

---

## 👥 Developed By

| Name   | Contribution |
|--------|-------------|
| Neerav  | System flow design and decision-making logic |
| Agastya | Core C++ functionalities, file handling, and data processing |
| Arnav |refined the user interface, tested the program, and ensured
clarity, consistency, and usability in the system's output |

---

## 📌 About the Project

Choosing the right car is often overwhelming due to the sheer number of models and features available in the market. This system simplifies the process by asking the user a few structured questions and generating personalized car recommendations through a logic-based engine.

The system currently holds a database of **35 real Indian car models** across four categories.

---

## ✨ Features

- 🔍 Personalized car recommendations based on user preferences
- 📂 Browse cars by category (Hatchback, Sedan, SUV, MUV)
- ⚖️ Compare any two cars side by side
- 📊 View database statistics (average price, mileage, category breakdown)
- ✅ Robust input validation and exception handling

---

## 🛠️ Advanced C++ Concepts Used

- **Abstract Base Class** with pure virtual functions
- **Inheritance & Polymorphism** across 4 derived car types
- **Templates** for generic sorting, filtering, and data operations
- **Custom Exception Classes** for clean error handling
- **File Handling** for external car data storage
- **Custom Header Files** for modular code architecture

---

## 📁 Project Structure

```
CarPrescriptionSystem/
├── main.cpp                  # Main program, UI, menus, exception handling
├── Car.h                     # Abstract base class with core attributes
├── CarTypes.h                # Derived classes: Hatchback, Sedan, SUV, MUV
├── Utils.h                   # Templates, exceptions, UI helper functions
├── CarDatabase.h             # File handling and car data storage
├── RecommendationEngine.h    # Scoring logic and recommendation engine
└── README.md

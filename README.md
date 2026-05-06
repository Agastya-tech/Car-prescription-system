# 🚗 Car Prescription System

A decision-based car recommendation system built in **C++** that helps users identify the most suitable vehicle based on their budget, fuel preference, usage needs, and car category.

---

## 👥 Developed By

| Name   | Contribution |
|--------|-------------|
| Agastya  | System flow design and decision-making logic |
| Arnav | Core C++ functionalities, file handling, and data processing |
| Neerav |refined the user interface, tested the program, and ensured
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
├── car.h                     # Abstract base class with core attributes
├── car.cpp                # Derived classes: Hatchback, Sedan, SUV, MUV
├── database.h             # File handling and car data storage
├── database.cpp    # Scoring logic and recommendation engine
├── engine.cpp
├── engine.h
└── README.md

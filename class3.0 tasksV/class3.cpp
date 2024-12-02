#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> // for std::setprecision

using namespace std;

// Task 1: Inheritance of objects
class Person {
protected:
    string name;

public:
    // Constructor
    Person(string name) : name(name) {}

    // Method to get name
    string GetName() const {
        return name;
    }

    // Method to convert to string (toString equivalent)
    virtual string ToString() const {
        return "Person: " + name;
    }
};

class Student : public Person {
public:
    // Constructor
    Student(string name) : Person(name) {}

    // Method to study
    void Study() {
        cout << name << " is studying." << endl;
    }
};

class Teacher : public Person {
public:
    // Constructor
    Teacher(string name) : Person(name) {}

    // Method to explain
    void Explain() {
        cout << name << " is explaining." << endl;
    }
};

// Task 2: Abstract classes
class Animal {
protected:
    string name;

public:
    // Method to set name
    void SetName(string name) {
        this->name = name;
    }

    // Method to get name
    string GetName() const {
        return name;
    }

    // Abstract method to eat
    virtual void Eat() = 0;
};

class Dog : public Animal {
public:
    // Method to eat
    void Eat() override {
        cout << name << " is eating dog food." << endl;
    }
};

// Smoothie class
class Smoothie {
private:
    vector<string> ingredients;

public:
    // Constructor
    Smoothie(vector<string> ingredients) : ingredients(ingredients) {}

    // Method to get cost
    string GetCost() const {
        double cost = 0.0;
        for (const string& ingredient : ingredients) {
            if (ingredient == "banana" || ingredient == "strawberry" || ingredient == "blueberry")
                cost += 1.50;
            else if (ingredient == "mango" || ingredient == "pineapple")
                cost += 2.00;
            else
                cost += 0.50; // Default cost for unknown ingredients
        }
        return "$" + to_string(cost);
    }

    // Method to get price
    string GetPrice() const {
        double cost = 0.0;
        for (const string& ingredient : ingredients) {
            if (ingredient == "banana" || ingredient == "strawberry" || ingredient == "blueberry")
                cost += 1.50;
            else if (ingredient == "mango" || ingredient == "pineapple")
                cost += 2.00;
            else
                cost += 0.50; // Default cost for unknown ingredients
        }
        double price = cost * 2.5;
        return "$" + to_string(price);
    }

    // Method to get name
    string GetName() const {
        string result = "";
        for (size_t i = 0; i < ingredients.size(); i++) {
            result += ingredients[i];
            if (i < ingredients.size() - 1) {
                result += " ";
            }
        }
        result += " Smoothie";
        return result;
    }
};

int main() {
    // Implement input and function calls for testing here

    Student student("Alice");
    student.Study();
    cout << student.ToString() << endl;

    Teacher teacher("Bob");
    teacher.Explain();
    cout << teacher.ToString() << endl;

    Dog dog;
    dog.SetName("Buddy");
    dog.Eat();

    vector<string> ingredients = {"banana", "strawberry", "mango"};
    Smoothie smoothie(ingredients);
    cout << smoothie.GetName() << endl;
    cout << "Cost: " << smoothie.GetCost() << endl;
    cout << "Price: " << smoothie.GetPrice() << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    // Task 1: Check for Even or Odd
    int number1 = 15;

    // Use an if statement to check if 'number1' is even or odd.
    // Print a message indicating whether it's even or odd.
    if (number1%2 == 0){
            cout << "even";
        }else{
            cout << "odd";
        }

    // Task 2: Check for a Leap Year
    int year = 2024;

    // Use an if statement to check if 'year' is a leap year.
    // Print a message indicating whether it's a leap year or not.
    if(year%4 == 0){
        cout << "Leap Year";
    }else{
        cout << "Not a leap Year";
    }

    // Task 3: Determine the Largest Number
    int num1 = 25;
    int num2 = 30;

    // Use an if statement to determine which of 'num1' and 'num2' is larger.
    // Print the largest number.
    if (num1 > num2){
        cout << "num1 bigger";
    }else{
        cout << "num2 bigger";
    }

    // Task 4: Check for Eligibility
    int age = 17;
    bool isStudent = true;

    // Use an if statement to check if a person is eligible for a student discount.
    // A person is eligible if their age is less than 18 and they are a student.
    // Print whether the person is eligible or not.
    if (age >= 18 && isStudent == true){
        cout << "is eligible";
    }else{
        cout << "not eligible";
    }

    return 0;
}
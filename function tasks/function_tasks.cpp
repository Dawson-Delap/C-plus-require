#include <iostream>
#include <string>
using namespace std;

void task1() {
    // Task 1: Create a user-defined method
    // Expected Output:
    // Welcome EVIT Friends!
    // Have a nice Tuesday!
    cout << "Welcome EVIT Friends!\nHave a nice Tuesday!\n";
}

void task2(string name) {
    // Task 2: Create a user-defined method with parameters
    // Test Data:
    // Please input a name: John
    // Expected Output:
    // Welcome friend John!
    // Have a nice holiday!
    cout << "Welcome friend " << name << "!\nHave a nice holiday!\n";
}

int countSpaces(const string &inputString) {
    // Task 3: Create a method to input a string and count the number of spaces within the string
    // Test Data:
    // Please input a string: This is a test string.
    // Expected Output:
    // "This is a test string." contains 4 spaces
    int spaces = 0;
    for(char i:inputString){
        if (i == ' '){
            spaces +=1;
        }
    }
    cout << "\"" << inputString << "\" contains " << spaces << " spaces\n";
}

void swapNumbers(int num1, int num2) {
    // Task 4: Create a method to swap two integer numbers
    // Test Data:
    // Enter a number: 5
    // Enter another number: 6
    // Expected Output:
    // Now the 1st number is: 6, and the 2nd number is: 5
    int numsv = num1;
    num1 = num2;
    num2 = numsv;
    cout << "Now the 1st number is: " << num1 << ", and the 2nd number is: " << num2;
}

int main() {
    task1();
    task2("John");
    countSpaces("This is a test string.");
    swapNumbers(5 , 6);
    return 0;
}
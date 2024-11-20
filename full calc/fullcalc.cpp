#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <random>
#include <windows.h>
#include <algorithm>
using namespace std;

int main(){
    int num1;
    int num2;
    cout << "First Number: ";
    cin >> num1;
    cout << "Second Number: ";
    cin >> num2;
    cout << "Division: " << num1 / num2 << '\n';
    cout << "Multiplication: " << num1 * num2 << '\n';
    cout << "Addition: " << num1 + num2 << '\n';
    cout << "Subtraction: " << num1 - num2 << '\n';
    main();
}
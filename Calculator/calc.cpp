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
    char opp;
    cin >> num1;
    cin >> opp;
    cin >> num2;
    switch (opp){
        case '/':
            cout << num1 / num2;
            break;
        case '*':
            cout << num1 * num2;
            break;
        case '+':
            cout << num1 + num2;
            break;
        case '-':
            cout << num1 - num2;
            break;
    }
    main();
}
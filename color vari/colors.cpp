#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <random>
#include <windows.h>
#include <algorithm>
#include <thread>
#include <mutex>
using namespace std;

int main(){
    string a = "red";
    string b = "white";
    string c = "blue";
    cout << "The colors of the American flag are " << a << ", " << b << ", " << "and " << c << ".\n";
    a = "black";
    b = "green";
    c = "purple";
    cout << "My favorite colors are " << a << ", " << b << ", " << "and " << c << ".";
    system("pause");
}
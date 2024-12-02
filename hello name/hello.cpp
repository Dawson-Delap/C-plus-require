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
    string name;
    cout << "What is your name ";
    cin >> name;
    cout << "\nHello " << name << '\n';
    system("pause");
}
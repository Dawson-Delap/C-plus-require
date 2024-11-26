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
    string v;
    string n;
    string a;
    cout << "Verb: ";
    cin >> v;
    cout << "Noun: ";
    cin >> n;
    cout << "Adverb: ";
    cin >> a;
    cout << "The " << n << ' ' << a << ' ' << v << ' ' << '!';
    system("pause");

}
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
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> upord(0, 100);
    int win = 0;
    int num = upord(rng);
    int guess;
    while(win == 0){
        cout << "Guess the number (0 - 100) :";
        cin >> guess;
        if (guess > num){
            cout << "Lower!";
        }else if (guess < num){
            cout << "Higher!";
        }else if (guess == num){
            win = 1;
        }
    }
    cout << "3";
    Sleep(1000);
    cout << "2";
    Sleep(1000);
    cout << "1";
    Sleep(1000);
    while(win == 1){
        
        cout << "YOU WIN!!!!";
    }
}
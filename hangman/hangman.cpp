#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <map>
#include <random>
#include <algorithm>
#include <thread>
#include <mutex>
#include <chrono> 
using namespace std;

string post =   "   -----  \n"
                "   |      \n"
                "   |      \n"
                "   |      \n"
                "   |      \n"
                "----------\n";
vector<string> words = {"butter"};
string blank = "______\n";
void body(string part){
    if (part == "head") {
        post[18] = 'O';
    } else if (part == "body") {
        post[29] = '|';
    } else if (part == "leftarm") {
        post[28] = '/';
    } else if (part == "rightarm") {
        post[30] = '\\';
    } else if (part == "leftleg") {
        post[39] = '/';
    } else if (part == "rightleg") {
        post[41] = '\\';
    }
}
random_device dev;
mt19937 rng(dev());
uniform_int_distribution<mt19937::result_type> randword(0, words.size()-1);
char guess;
string str = words[randword(rng)];
int wrongnum = 0;
int main(){
    while (true){
        cout << post;
        cout << blank;
        cout << "Guess a letter";
        cin >> guess;
        if (str.find(guess) == string::npos){
            wrongnum += 1;
            if (wrongnum == 1) {
                body("head");
            }else if (wrongnum == 2) {
                body("body");
            }else if (wrongnum == 3) {
                body("leftarm");
            }else if (wrongnum == 4) {
                body("rightarm");
            }else if (wrongnum == 5) {
                body("leftleg");
            }else if (wrongnum == 6) {
                body("rightleg");
                cout << post;
                cout << '3';
                this_thread::sleep_for(chrono::seconds(1));
                cout << '2';
                this_thread::sleep_for(chrono::seconds(1));
                cout << '1';
                this_thread::sleep_for(chrono::seconds(1));
                while(true){
                    cout << "You Lose!!!!!!";
                }
            }
            
        }
        while (str.find(guess) != string::npos){
            blank[str.find(guess)] = guess;
            str[str.find(guess)] = ' ';
        }
        
        if (str == "      "){
            cout << '3';
                this_thread::sleep_for(chrono::seconds(1));
                cout << '2';
                this_thread::sleep_for(chrono::seconds(1));
                cout << '1';
                this_thread::sleep_for(chrono::seconds(1));
            while(true){
                cout << "You Win!!!!";
            }
        }
    }
    
}

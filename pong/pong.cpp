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
                //ABCDEFGHIJKLMNOPQRSTUVWXYZ
string board =  "[                          ]\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n";
vector<string> paddlemove = {"L1","L2","L3","L4","L5","L6","L7","L8",
                             "R1","R2","R3","R4","R5","R6","R7","R8",};
string numplace = "12345678";
string abcplace = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<string, int> spots = {
    {"Left1", 0}, {"A1", 1}, {"B1", 2}, {"C1", 3}, {"D1", 4}, {"E1", 5}, {"F1", 6}, {"G1", 7}, {"H1", 8}, {"I1", 9}, {"J1", 10}, {"K1", 11}, {"L1", 12}, {"M1", 13}, {"N1", 14}, {"O1", 15}, {"P1", 16}, {"Q1", 17}, {"R1", 18}, {"S1", 19}, {"T1", 20}, {"U1", 21}, {"V1", 22}, {"W1", 23}, {"X1", 24}, {"Y1", 25}, {"Z1", 26}, {"Right1", 27},
    {"Left2", 29}, {"A2", 30}, {"B2", 31}, {"C2", 32}, {"D2", 33}, {"E2", 34}, {"F2", 35}, {"G2", 36}, {"H2", 37}, {"I2", 38}, {"J2", 39}, {"K2", 40}, {"L2", 41}, {"M2", 42}, {"N2", 43}, {"O2", 44}, {"P2", 45}, {"Q2", 46}, {"R2", 47}, {"S2", 48}, {"T2", 49}, {"U2", 50}, {"V2", 51}, {"W2", 52}, {"X2", 53}, {"Y2", 54}, {"Z2", 55}, {"Right2", 56},
    {"Left3", 58}, {"A3", 59}, {"B3", 60}, {"C3", 61}, {"D3", 62}, {"E3", 63}, {"F3", 64}, {"G3", 65}, {"H3", 66}, {"I3", 67}, {"J3", 68}, {"K3", 69}, {"L3", 70}, {"M3", 71}, {"N3", 72}, {"O3", 73}, {"P3", 74}, {"Q3", 75}, {"R3", 76}, {"S3", 77}, {"T3", 78}, {"U3", 79}, {"V3", 80}, {"W3", 81}, {"X3", 82}, {"Y3", 83}, {"Z3", 84}, {"Right3", 85},
    {"Left4", 87}, {"A4", 88}, {"B4", 89}, {"C4", 90}, {"D4", 91}, {"E4", 92}, {"F4", 93}, {"G4", 94}, {"H4", 95}, {"I4", 96}, {"J4", 97}, {"K4", 98}, {"L4", 99}, {"M4", 100}, {"N4", 101}, {"O4", 102}, {"P4", 103}, {"Q4", 104}, {"R4", 105}, {"S4", 106}, {"T4", 107}, {"U4", 108}, {"V4", 109}, {"W4", 110}, {"X4", 111}, {"Y4", 112}, {"Z4", 113}, {"Right4", 114},
    {"Left5", 116}, {"A5", 117}, {"B5", 118}, {"C5", 119}, {"D5", 120}, {"E5", 121}, {"F5", 122}, {"G5", 123}, {"H5", 124}, {"I5", 125}, {"J5", 126}, {"K5", 127}, {"L5", 128}, {"M5", 129}, {"N5", 130}, {"O5", 131}, {"P5", 132}, {"Q5", 133}, {"R5", 134}, {"S5", 135}, {"T5", 136}, {"U5", 137}, {"V5", 138}, {"W5", 139}, {"X5", 140}, {"Y5", 141}, {"Z5", 142}, {"Right5", 143},
    {"Left6", 145}, {"A6", 146}, {"B6", 147}, {"C6", 148}, {"D6", 149}, {"E6", 150}, {"F6", 151}, {"G6", 152}, {"H6", 153}, {"I6", 154}, {"J6", 155}, {"K6", 156}, {"L6", 157}, {"M6", 158}, {"N6", 159}, {"O6", 160}, {"P6", 161}, {"Q6", 162}, {"R6", 163}, {"S6", 164}, {"T6", 165}, {"U6", 166}, {"V6", 167}, {"W6", 168}, {"X6", 169}, {"Y6", 170}, {"Z6", 171}, {"Right6", 172},
    {"Left7", 174}, {"A7", 175}, {"B7", 176}, {"C7", 177}, {"D7", 178}, {"E7", 179}, {"F7", 180}, {"G7", 181}, {"H7", 182}, {"I7", 183}, {"J7", 184}, {"K7", 185}, {"L7", 186}, {"M7", 187}, {"N7", 188}, {"O7", 189}, {"P7", 190}, {"Q7", 191}, {"R7", 192}, {"S7", 193}, {"T7", 194}, {"U7", 195}, {"V7", 196}, {"W7", 197}, {"X7", 198}, {"Y7", 199}, {"Z7", 200}, {"Right7", 201},
    {"Left8", 203}, {"A8", 204}, {"B8", 205}, {"C8", 206}, {"D8", 207}, {"E8", 208}, {"F8", 209}, {"G8", 210}, {"H8", 211}, {"I8", 212}, {"J8", 213}, {"K8", 214}, {"L8", 215}, {"M8", 216}, {"N8", 217}, {"O8", 218}, {"P8", 219}, {"Q8", 220}, {"R8", 221}, {"S8", 222}, {"T8", 223}, {"U8", 224}, {"V8", 225}, {"W8", 226}, {"X8", 227}, {"Y8", 228}, {"Z8", 229}, {"Right8", 230}
};
int leftscore = 0;
int rightscore = 0;

int leftnum = 0;
int rightnum = 0;
string leftspot = "Left1";
string currentSpot;

int ballabcnum = 25;
int ballnumnum = 7;
int usd = 1;
int slopecount = 0;
string ballspot;
string lastbounce = "right";
random_device dev;
mt19937 rng(dev());
uniform_int_distribution<mt19937::result_type> upord(-1, 1);
// 1 is up, 0 is straight, -1 is down
mutex mtx;
void ball(){
    while(true){
        if(usd == 1){
            if (lastbounce == "right"){
                unique_lock<mutex> lock(mtx);
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = ' ';
                if (ballnumnum > 0 && ballnumnum <= 7){
                    if (slopecount >= 5){
                        ballnumnum --;
                        slopecount = 0;
                    }else{
                        slopecount ++;
                    }
                }
                if(ballabcnum >= 0 && ballabcnum <= 25){
                    ballabcnum --;
                }
                
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = 'O';

                if (board[spots[ballspot]-1] == '['){
                    usd = upord(rng);
                    lastbounce = "left";
                  if(ballnumnum == 0){
                        while(usd == 1){
                            usd = upord(rng);
                        }
                    }else if(ballnumnum == 7){
                        while(usd == -1){
                            usd = upord(rng);
                        }
                    }
                }else if (board[spots[ballspot]-1] == '|'){
                    rightscore ++;
                    ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                    board[spots[ballspot]] = ' ';
                    ballabcnum = 25;
                    ballnumnum = 7;
                    usd = 1;
                }
                cout << board;
                lock.unlock();
                Sleep(100);
                
            }
        }
        if (lastbounce == "left"){
                unique_lock<mutex> lock(mtx);
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = ' ';
                if (ballnumnum > 0 && ballnumnum <= 7){
                    if (slopecount >= 5){
                        ballnumnum --;
                        slopecount = 0;
                    }else{
                        slopecount ++;
                    }
                }
                if(ballabcnum >= 0 && ballabcnum <= 25){
                    ballabcnum ++;
                }
                
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = 'O';

                if (board[spots[ballspot]+1] == ']'){
                    usd = upord(rng);
                    lastbounce = "right";
                    if(ballnumnum == 0){
                        while(usd == 1){
                            usd = upord(rng);
                        }
                    }else if(ballnumnum == 7){
                        while(usd == -1){
                            usd = upord(rng);
                        }
                    }
                }else if (board[spots[ballspot]+1] == '|'){
                    rightscore ++;
                    ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                    board[spots[ballspot]] = ' ';
                    ballabcnum = 25;
                    ballnumnum = 7;
                    usd = 1;
                    lastbounce = "right";
                }
                cout << board;
                lock.unlock();
                Sleep(100);
                
            }
//down
        if(usd == -1){
            if (lastbounce == "right"){
                unique_lock<mutex> lock(mtx);
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = ' ';
                if (ballnumnum >= 0 && ballnumnum <= 7){
                    if (slopecount >= 5){
                        ballnumnum ++;
                        slopecount = 0;
                    }else{
                        slopecount ++;
                    }
                }
                if(ballabcnum >= 0 && ballabcnum <= 25){
                    ballabcnum --;
                }
                
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = 'O';

                if (board[spots[ballspot]-1] == '['){
                    usd = upord(rng);
                    lastbounce = "left";
                    if(ballnumnum == 0){
                        while(usd == 1){
                            usd = upord(rng);
                        }
                    }else if(ballnumnum == 7){
                        while(usd == -1){
                            usd = upord(rng);
                        }
                    }
                }else if (board[spots[ballspot]-1] == '|'){
                    rightscore ++;
                    ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                    board[spots[ballspot]] = ' ';
                    ballabcnum = 25;
                    ballnumnum = 7;
                    usd = 1;
                }
                cout << board;
                lock.unlock();
                Sleep(100);
                
            }
        }
        if (lastbounce == "left"){
                unique_lock<mutex> lock(mtx);
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = ' ';
                if (ballnumnum > 0 && ballnumnum <= 7){
                    if (slopecount >= 5){
                        ballnumnum ++;
                        slopecount = 0;
                    }else{
                        slopecount ++;
                    }
                }
                if(ballabcnum >= 0 && ballabcnum <= 25){
                    ballabcnum ++;
                }
                
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = 'O';

                if (board[spots[ballspot]+1] == ']'){
                    usd = upord(rng);
                    lastbounce = "right";
                    if(ballnumnum == 0){
                        while(usd == 1){
                            usd = upord(rng);
                        }
                    }else if(ballnumnum == 7){
                        while(usd == -1){
                            usd = upord(rng);
                        }
                    }
                }else if (board[spots[ballspot]+1] == '|'){
                    rightscore ++;
                    ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                    board[spots[ballspot]] = ' ';
                    ballabcnum = 25;
                    ballnumnum = 7;
                    usd = 1;
                    lastbounce = "right";
                }
                cout << board;
                lock.unlock();
                Sleep(100);
                
            }
        if(usd == 0){
            if (lastbounce == "right"){
                unique_lock<mutex> lock(mtx);
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = ' ';
                if(ballabcnum >= 0 && ballabcnum <= 25){
                    ballabcnum --;
                }
                
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = 'O';

                if (board[spots[ballspot]-1] == '['){
                    usd = upord(rng);
                    lastbounce = "left";
                    if(ballnumnum == 0){
                        while(usd == 1){
                            usd = upord(rng);
                        }
                    }else if(ballnumnum == 7){
                        while(usd == -1){
                            usd = upord(rng);
                        }
                    }
                }else if (board[spots[ballspot]-1] == '|'){
                    rightscore ++;
                    ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                    board[spots[ballspot]] = ' ';
                    ballabcnum = 25;
                    ballnumnum = 7;
                    usd = 1;
                }
                cout << board;
                lock.unlock();
                Sleep(100);
                
            }
        }
        if (lastbounce == "left"){
                unique_lock<mutex> lock(mtx);
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = ' ';
                if(ballabcnum >= 0 && ballabcnum <= 25){
                    ballabcnum ++;
                }
                
                ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                board[spots[ballspot]] = 'O';

                if (board[spots[ballspot]+1] == ']'){
                    usd = upord(rng);
                    lastbounce = "right";
                    if(ballnumnum == 0){
                        while(usd == 1){
                            usd = upord(rng);
                        }
                    }else if(ballnumnum == 7){
                        while(usd == -1){
                            usd = upord(rng);
                        }
                    }
                }else if (board[spots[ballspot]+1] == '|'){
                    rightscore ++;
                    ballspot = abcplace.substr(ballabcnum,1) + numplace.substr(ballnumnum,1);
                    board[spots[ballspot]] = ' ';
                    ballabcnum = 25;
                    ballnumnum = 7;
                    usd = 1;
                    lastbounce = "right";
                }
                cout << board;
                lock.unlock();
                Sleep(100);
                
            }
        }
}
void leftside() {
    while (true) {
        if (GetAsyncKeyState('W') & 0x8000) {
            if (leftnum > 0) {
                unique_lock<mutex> lock(mtx);
                currentSpot = "Left" + numplace.substr(leftnum, 1);
                board[spots[currentSpot]] = '|'; 
                leftnum--; 
                currentSpot = "Left" + numplace.substr(leftnum, 1);
                board[spots[currentSpot]] = '['; 
                cout << board;
                lock.unlock();
                Sleep(100);  
            }
        }

        if (GetAsyncKeyState('S') & 0x8000) {
            if (leftnum < 7) {  
                unique_lock<mutex> lock(mtx);
                currentSpot = "Left" + numplace.substr(leftnum, 1);
                board[spots[currentSpot]] = '|'; 
                leftnum++;  
                currentSpot = "Left" + numplace.substr(leftnum, 1);
                board[spots[currentSpot]] = '['; 
                cout << board;
                lock.unlock();
                Sleep(100);  
            }
        }
        Sleep(50);
    }
}

void rightside() {
    while (true) {
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            if (rightnum > 0) {
                unique_lock<mutex> lock(mtx);
                currentSpot = "Right" + numplace.substr(rightnum, 1);
                board[spots[currentSpot]] = '|';  
                rightnum--;  
                currentSpot = "Right" + numplace.substr(rightnum, 1);
                board[spots[currentSpot]] = ']';  
                cout << board;
                lock.unlock();
                Sleep(100);  
            }
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            if (rightnum < 7) {  
                unique_lock<mutex> lock(mtx);
                currentSpot = "Right" + numplace.substr(rightnum, 1);
                board[spots[currentSpot]] = '|';  
                rightnum++;  
                currentSpot = "Right" + numplace.substr(rightnum, 1);
                board[spots[currentSpot]] = ']';  
                cout << board;
                lock.unlock();
                Sleep(100);  
            }
        }
        Sleep(50);
    }
}
int main(){
    cout << "shrink window until you cant see this\n";
    cout << board;
    system("pause");
    thread leftthread(leftside);
    thread rightthread(rightside);
    thread ballthread(ball);
    cout << board;
    leftthread.join();
    rightthread.join();
    ballthread.join();
}
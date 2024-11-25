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

string board =  //ABCDEFGHIJKLMNOPQRSTUVWXYZ
                "|--------------------------|\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|                          |\n"
                "|--------------------------|";

map<string, int> spots = {
    {"A1", 30}, {"B1", 31}, {"C1", 32}, {"D1", 33}, {"E1", 34}, {"F1", 35}, {"G1", 36}, {"H1", 37}, {"I1", 38}, {"J1", 39}, {"K1", 40}, {"L1", 41}, {"M1", 42}, {"N1", 43}, {"O1", 44}, {"P1", 45}, {"Q1", 46}, {"R1", 47}, {"S1", 48}, {"T1", 49}, {"U1", 50}, {"V1", 51}, {"W1", 52}, {"X1", 53}, {"Y1", 54}, {"Z1", 55},
    
    {"A2", 59}, {"B2", 60}, {"C2", 61}, {"D2", 62}, {"E2", 63}, {"F2", 64}, {"G2", 65}, {"H2", 66}, {"I2", 67}, {"J2", 68}, {"K2", 69}, {"L2", 70}, {"M2", 71}, {"N2", 72}, {"O2", 73}, {"P2", 74}, {"Q2", 75}, {"R2", 76}, {"S2", 77}, {"T2", 78}, {"U2", 79}, {"V2", 80}, {"W2", 81}, {"X2", 82}, {"Y2", 83}, {"Z2", 84},
    
    {"A3", 88}, {"B3", 89}, {"C3", 90}, {"D3", 91}, {"E3", 92}, {"F3", 93}, {"G3", 94}, {"H3", 95}, {"I3", 96}, {"J3", 97}, {"K3", 98}, {"L3", 99}, {"M3", 100}, {"N3", 101}, {"O3", 102}, {"P3", 103}, {"Q3", 104}, {"R3", 105}, {"S3", 106}, {"T3", 107}, {"U3", 108}, {"V3", 109}, {"W3", 110}, {"X3", 111}, {"Y3", 112}, {"Z3", 113},
    
    {"A4", 117}, {"B4", 118}, {"C4", 119}, {"D4", 120}, {"E4", 121}, {"F4", 122}, {"G4", 123}, {"H4", 124}, {"I4", 125}, {"J4", 126}, {"K4", 127}, {"L4", 128}, {"M4", 129}, {"N4", 130}, {"O4", 131}, {"P4", 132}, {"Q4", 133}, {"R4", 134}, {"S4", 135}, {"T4", 136}, {"U4", 137}, {"V4", 138}, {"W4", 139}, {"X4", 140}, {"Y4", 141}, {"Z4", 142},
    
    {"A5", 146}, {"B5", 147}, {"C5", 148}, {"D5", 149}, {"E5", 150}, {"F5", 151}, {"G5", 152}, {"H5", 153}, {"I5", 154}, {"J5", 155}, {"K5", 156}, {"L5", 157}, {"M5", 158}, {"N5", 159}, {"O5", 160}, {"P5", 161}, {"Q5", 162}, {"R5", 163}, {"S5", 164}, {"T5", 165}, {"U5", 166}, {"V5", 167}, {"W5", 168}, {"X5", 169}, {"Y5", 170}, {"Z5", 171},
    
    {"A6", 175}, {"B6", 176}, {"C6", 177}, {"D6", 178}, {"E6", 179}, {"F6", 180}, {"G6", 181}, {"H6", 182}, {"I6", 183}, {"J6", 184}, {"K6", 185}, {"L6", 186}, {"M6", 187}, {"N6", 188}, {"O6", 189}, {"P6", 190}, {"Q6", 191}, {"R6", 192}, {"S6", 193}, {"T6", 194}, {"U6", 195}, {"V6", 196}, {"W6", 197}, {"X6", 198}, {"Y6", 199}, {"Z6", 200},
    
    {"A7", 204}, {"B7", 205}, {"C7", 206}, {"D7", 207}, {"E7", 208}, {"F7", 209}, {"G7", 210}, {"H7", 211}, {"I7", 212}, {"J7", 213}, {"K7", 214}, {"L7", 215}, {"M7", 216}, {"N7", 217}, {"O7", 218}, {"P7", 219}, {"Q7", 220}, {"R7", 221}, {"S7", 222}, {"T7", 223}, {"U7", 224}, {"V7", 225}, {"W7", 226}, {"X7", 227}, {"Y7", 228}, {"Z7", 229},
    
    {"A8", 233}, {"B8", 234}, {"C8", 235}, {"D8", 236}, {"E8", 237}, {"F8", 238}, {"G8", 239}, {"H8", 240}, {"I8", 241}, {"J8", 242}, {"K8", 243}, {"L8", 244}, {"M8", 245}, {"N8", 246}, {"O8", 247}, {"P8", 248}, {"Q8", 249}, {"R8", 250}, {"S8", 251}, {"T8", 252}, {"U8", 253}, {"V8", 254}, {"W8", 255}, {"X8", 256}, {"Y8", 257}, {"Z8", 258},
    
    {"A9", 262}, {"B9", 263}, {"C9", 264}, {"D9", 265}, {"E9", 266}, {"F9", 267}, {"G9", 268}, {"H9", 269}, {"I9", 270}, {"J9", 271}, {"K9", 272}, {"L9", 273}, {"M9", 274}, {"N9", 275}, {"O9", 276}, {"P9", 277}, {"Q9", 278}, {"R9", 279}, {"S9", 280}, {"T9", 281}, {"U9", 282}, {"V9", 283}, {"W9", 284}, {"X9", 285}, {"Y9", 286}, {"Z9", 287},
    
    {"A10", 291}, {"B10", 292}, {"C10", 293}, {"D10", 294}, {"E10", 295}, {"F10", 296}, {"G10", 297}, {"H10", 298}, {"I10", 299}, {"J10", 300}, {"K10", 301}, {"L10", 302}, {"M10", 303}, {"N10", 304}, {"O10", 305}, {"P10", 306}, {"Q10", 307}, {"R10", 308}, {"S10", 309}, {"T10", 310}, {"U10", 311}, {"V10", 312}, {"W10", 313}, {"X10", 314}, {"Y10", 315}, {"Z10", 316},
    
    {"A11", 320}, {"B11", 321}, {"C11", 322}, {"D11", 323}, {"E11", 324}, {"F11", 325}, {"G11", 326}, {"H11", 327}, {"I11", 328}, {"J11", 329}, {"K11", 330}, {"L11", 331}, {"M11", 332}, {"N11", 333}, {"O11", 334}, {"P11", 335}, {"Q11", 336}, {"R11", 337}, {"S11", 338}, {"T11", 339}, {"U11", 340}, {"V11", 341}, {"W11", 342}, {"X11", 343}, {"Y11", 344}, {"Z11", 345},
    
    {"A12", 349}, {"B12", 350}, {"C12", 351}, {"D12", 352}, {"E12", 353}, {"F12", 354}, {"G12", 355}, {"H12", 356}, {"I12", 357}, {"J12", 358}, {"K12", 359}, {"L12", 360}, {"M12", 361}, {"N12", 362}, {"O12", 363}, {"P12", 364}, {"Q12", 365}, {"R12", 366}, {"S12", 367}, {"T12", 368}, {"U12", 369}, {"V12", 370}, {"W12", 371}, {"X12", 372}, {"Y12", 373}, {"Z12", 374}
};

vector<string> spotvec = {
    "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", "I1", "J1", "K1", "L1", "M1", "N1", "O1", "P1", "Q1", "R1", "S1", "T1", "U1", "V1", "W1", "X1", "Y1", "Z1",
    "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "I2", "J2", "K2", "L2", "M2", "N2", "O2", "P2", "Q2", "R2", "S2", "T2", "U2", "V2", "W2", "X2", "Y2", "Z2",
    "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", "I3", "J3", "K3", "L3", "M3", "N3", "O3", "P3", "Q3", "R3", "S3", "T3", "U3", "V3", "W3", "X3", "Y3", "Z3",
    "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "I4", "J4", "K4", "L4", "M4", "N4", "O4", "P4", "Q4", "R4", "S4", "T4", "U4", "V4", "W4", "X4", "Y4", "Z4",
    "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "I5", "J5", "K5", "L5", "M5", "N5", "O5", "P5", "Q5", "R5", "S5", "T5", "U5", "V5", "W5", "X5", "Y5", "Z5",
    "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "I6", "J6", "K6", "L6", "M6", "N6", "O6", "P6", "Q6", "R6", "S6", "T6", "U6", "V6", "W6", "X6", "Y6", "Z6",
    "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "I7", "J7", "K7", "L7", "M7", "N7", "O7", "P7", "Q7", "R7", "S7", "T7", "U7", "V7", "W7", "X7", "Y7", "Z7",
    "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "I8", "J8", "K8", "L8", "M8", "N8", "O8", "P8", "Q8", "R8", "S8", "T8", "U8", "V8", "W8", "X8", "Y8", "Z8",
    "A9", "B9", "C9", "D9", "E9", "F9", "G9", "H9", "I9", "J9", "K9", "L9", "M9", "N9", "O9", "P9", "Q9", "R9", "S9", "T9", "U9", "V9", "W9", "X9", "Y9", "Z9",
    "A10", "B10", "C10", "D10", "E10", "F10", "G10", "H10", "I10", "J10", "K10", "L10", "M10", "N10", "O10", "P10", "Q10", "R10", "S10", "T10", "U10", "V10", "W10", "X10", "Y10", "Z10",
    "A11", "B11", "C11", "D11", "E11", "F11", "G11", "H11", "I11", "J11", "K11", "L11", "M11", "N11", "O11", "P11", "Q11", "R11", "S11", "T11", "U11", "V11", "W11", "X11", "Y11", "Z11",
    "A12", "B12", "C12", "D12", "E12", "F12", "G12", "H12", "I12", "J12", "K12", "L12", "M12", "N12", "O12", "P12", "Q12", "R12", "S12", "T12", "U12", "V12", "W12", "X12", "Y12", "Z12"
};
vector<string> numplace = {"1","2","3","4","5","6","7","8","9","10","11","12"};
string abcplace = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
mutex mtx;
random_device dev;
mt19937 rng(dev());
uniform_int_distribution<mt19937::result_type> ran(0, spotvec.size() - 1);
int ranspot = 46;
int numnum = 9;
int abcnum = 15;
int w,a,s,d = 0;
int score = 0;
string currentspot;
string lastspot;
vector<string> tail;
int length;
void coli(){

}
void apple(){
    while (true){
        unique_lock<mutex> lock(mtx);
        if (board[spots[spotvec[ranspot]]] == '^' || board[spots[spotvec[ranspot]]] == 'V' || board[spots[spotvec[ranspot]]] == '<' || board[spots[spotvec[ranspot]]] == '>'){
            score += 1;
            ranspot = ran(rng);
        }
        board[spots[spotvec[ranspot]]] = 'O';
        lock.unlock();
        cout << '\n' << board;
        Sleep(300);
    }
}
void snake(){
    numnum = 0;
    abcnum = 0;
    while (true){
        unique_lock<mutex> lock(mtx);
        int cnt = count(tail.begin(), tail.end(), currentspot);
        if (board[0] == 'V' || board[0] == '^' || board[0] == '<' || board[0] == '>' || cnt > 0){
            while(true){
                cout << "YOU LOSE!!!!!!!!!!!!!!!";
            }
        }
        if (GetAsyncKeyState('W') & 0x8000){
            if (w != 2){
                w = 1;
                a = 0;
                d = 0;
                s = 2;
            }
        }
        if (GetAsyncKeyState('A') & 0x8000){
            if (a != 2){
                a = 1;
                w = 0;
                s = 0;
                d = 2;
            }
        }
        if (GetAsyncKeyState('S') & 0x8000){
            if (s != 2){
                s = 1;
                a = 0;
                d = 0;
                w = 2;
            }
        }
        if (GetAsyncKeyState('D') & 0x8000){
            if (d != 2){
                d = 1;
                w = 0;
                s = 0;
                a = 2;
            }
        }
        if (w == 1){
            if (numnum < 12){
                lastspot = abcplace[abcnum] + numplace[numnum];
                length = tail.size();
                tail.insert(tail.begin(),lastspot);
                for(int i = 0; i <= length; i++){
                        board[spots[tail[i]]] = 'X';
                }
                board[spots[tail.back()]] = ' ';
                if (length == score){
                    tail.pop_back();
                }
                numnum -= 1;
                currentspot = abcplace[abcnum] + numplace[numnum];
                board[spots[currentspot]] = '^';
                
            }
        }else if (a == 1){
            if (abcnum >= 0){
                lastspot = abcplace[abcnum] + numplace[numnum];
                length = tail.size();
                tail.insert(tail.begin(),lastspot);
                for(int x = 0; x <= length; x++){
                        board[spots[tail[x]]] = 'X';
                }
                board[spots[tail.back()]] = ' ';
                if (length == score){
                    tail.pop_back();
                }
                abcnum -= 1;
                currentspot = abcplace[abcnum] + numplace[numnum];
                board[spots[currentspot]] = '<';
                
            }
        }else if (s == 1){
            if (numnum >= 0){
                lastspot = abcplace[abcnum] + numplace[numnum];
                length = tail.size();
                tail.insert(tail.begin(),lastspot);
                for(int i = 0; i <= length; i++){
                        board[spots[tail[i]]] = 'X';
                }
                board[spots[tail.back()]] = ' ';
                if (length == score){
                    tail.pop_back();
                }
                numnum += 1;
                currentspot = abcplace[abcnum] + numplace[numnum];
                board[spots[currentspot]] = 'V';
                
            }
        }else if (d == 1){
            if (abcnum < 26){
                lastspot = abcplace[abcnum] + numplace[numnum];
                length = tail.size();
                tail.insert(tail.begin(),lastspot);
                for(int i = 0; i <= length; i++){
                        board[spots[tail[i]]] = 'X';
                }
                board[spots[tail.back()]] = ' ';
                if (length == score){
                    tail.pop_back();
                }
                abcnum += 1;
                currentspot = abcplace[abcnum] + numplace[numnum];
                board[spots[currentspot]] = '>';
                
            }
        }
        lock.unlock();
        Sleep(300);
    }
}
int main(){
    cout << "shrink window until you cant see this\n";
    cout << board;
    system("pause");
    thread applethread(apple);
    thread snakethread(snake);
    cout << board;
    applethread.join();
    snakethread.join();
}
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

string row1 = "|               |";
string row2 = "}////// /////// |"; 
string row3 = "|               |";
string row4 = "[ ////////  ////|";
string row5 = "|               |";
string row6 = "]//// ////   ///|"; 
string row7 = "|               |";
string row8 = "|               |";
string row9 = "|               |";
string board = row1 + '\n' + row2 + '\n' + row3 + '\n' + row4 + '\n' + row5 + '\n' + row6 + '\n' + row7 + '\n' + row8 + '\n' + row9;

int movenum = 1;
void place(){
    
}

void seeboard(){
    board = row1 + '\n' + row2 + '\n' + row3 + '\n' + row4 + '\n' + row5 + '\n' + row6 + '\n' + row7 + '\n' + row8 + '\n' + row9;
    cout << '\n' << board;
}

void movechar(){
    while (true){
        if (GetAsyncKeyState('A') & 0x8000){
            if (movenum > 1){
                row9[movenum] = ' ';
                movenum -= 1;
                row9[movenum] = 'T';
            }
            
        }
        if (GetAsyncKeyState('D') & 0x8000){
            if (movenum < 15){
                row9[movenum] = ' ';
                movenum += 1;
                row9[movenum] = 'T';
            }
        }
        row9[movenum] = 'T';
        seeboard();
        Sleep(200);
    }
    
}
string rowsave;
void scroll(){
    while (true){
        rowsave = row9;
        if (rowsave[0] == '}'){
            rowsave = "}////// /////// |";
        }else if(rowsave[0] == '['){
            rowsave = "[ ////////  ////|";
        }else if(rowsave[0] == ']'){
            rowsave = "]//// ////   ///|";
        }else if (rowsave[0] == '|'){
            rowsave = "|               |";
        }
        row9 = row8;
        row8 = row7;
        row7 = row6;
        row6 = row5;
        row5 = row4;
        row4 = row3;
        row3 = row2;
        row2 = row1;
        row1 = rowsave;
        board = row1 + '\n' + row2 + '\n' + row3 + '\n' + row4 + '\n' + row5 + '\n' + row6 + '\n' + row7 + '\n' + row8 + '\n' + row9;
        
        Sleep(2000);
        if (row8[movenum] == '/'){
            while(true){
                cout << "you lose!!!!!!";
            }
        }
    }
}

int main(){
    cout << "get rid\n";
    cout << '\n' << board;
    system("pause");
    thread movethread(movechar);
    thread scrollthread(scroll);
    thread placethread(place);
    seeboard();
    movethread.join();
    scrollthread.join();
    placethread.join();
}
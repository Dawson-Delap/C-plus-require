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
    string layer;
    int levels;
    cin >> levels;
    layer = "*\n";
    cout << string(levels, ' ') << "*\n";
    int outs = levels-1;
    for (int i = 0; i < levels; i++){
        cout << string(outs, ' ') << '*' << string((i*2)+1, ' ') << "*\n";
        outs -= 1;
    }
    system("pause");
}
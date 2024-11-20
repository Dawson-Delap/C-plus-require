#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <windows.h> 
using namespace std;

int main() {
    string x;
    const string rps[3] = {"Rock", "Paper", "Scissors"};
    srand (time(NULL));
    int num = rand() % 3;
    string player;
    cout << "Choose Rock Paper or Scissors: ";
    cin >> player;
    player[0] = toupper(player[0]);

    if (player == "Rock" || player == "Paper" ||player == "Scissors"){
    
    cout << player << "\n" << "VS \n";
    cout << rps[num] << "\n";
    if (player == "Rock" && rps[num] == "Scissors"){
        cout << "Player Wins!!\n";
    }
    else if (player == "Paper" && rps[num] == "Rock"){
        cout << "Player Wins!!\n";
    }
    else if (player == "Scissors" && rps[num] == "Paper"){
        cout << "Player Wins!!\n";
    }
    else if (player == rps[num]){
        cout << "Tie!\n";
    }else{
        cout << "Bot Wins ;(\n";
    }
    }else{
        cout << "Invalid answer\n";
    }
    
    system("pause");
    main();
    
    
}

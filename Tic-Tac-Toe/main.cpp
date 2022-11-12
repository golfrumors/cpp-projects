#include <iostream>

using namespace std;

void printBoard(int a[]);
bool isTwoPlayers();
bool gameOver(int a[]); //change this fun to a char to check who won
bool gameTie(int a[]);

// Tic-Tac-Toe driver code
int main(){
    int board[9] = {1,2,3,4,5,6,7,8,9};
    bool twoPlayers = isTwoPlayers();
    printBoard(board);

    return 0;
}

// Tic-Tac-Toe functions
void printBoard(int board[]){
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

bool isTwoPlayers(){
    char n;
    bool twoPlayers = false;

    do{
        cout << "Would you like to play against another player? (y/n): ";
        cin >> n;

        if(n == 'y' || n == 'Y'){
            twoPlayers = true;
        } else if(n == 'n' || n == 'N'){
            twoPlayers = false;
        } else {
            cout << "Invalid input. Please try again." << endl;
        }

    }while(n != 'y' && n != 'Y' && n != 'n' && n != 'N');

    return twoPlayers;
}

//this function will check if the game is won
bool gameOver(int a[]){
    bool won = false;
    int l = sizeof(a) / sizeof(*a);

    //check for horizontal win
    for(int i = 0; i < l; i += 3){
        if(a[i] == a[i+1] && a[i+1] == a[i+2]){
            won = true;
            break;
        }
    }

    //check for vertical win
    for(int i = 0; i < 3; i++){
        if(a[i] == a[i+3] && a[i+3] == a[i+6]){
            won = true;
            break;
        }
    }

    //check for diagonal win
    if(a[0] == a[4] && a[4] == a[8] || a[2] == a[4] && a[4] == a[6]){
        won = true;
    }

    return won;
}

//check if game is tied
bool gameTied(int a[]){
    bool tied = true;
    int l = sizeof(a) / sizeof(*a);

    for(int i = 0; i < l; i++){
        if(a[i] != 'X' && a[i] != 'O'){
            tied = false;
            break;
        }
    }

    return tied;
}
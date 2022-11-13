#include <iostream>

using namespace std;

void printBoard(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j != 2){
                cout << " " << board[i][j] << " |";
            }else{
                cout << " " << board[i][j];
            }
        }
        cout << endl;
        if(i != 2){
            cout << "---+---+---" << endl;
        }
    }
}

bool isTwoPlayer(){
    char answer;
    
    cout << "Do you want to play against another player? (y/n): ";
    cin >> answer;

    do{
        if(answer == 'y' || answer == 'Y'){
            return true;
        }else if(answer == 'n' || answer == 'N'){
            return false;
        }else{
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin >> answer;
        }
    }while(answer != 'y' || answer != 'Y' || answer != 'n' || answer != 'N');

    return false;
}

//this function checks if someone won the game
bool checkWin(char board[3][3]){
    //check rows
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return true;
        }
    }

    //check columns
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return true;
        }
    }

    //check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return true;
    }else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return true;
    }

    return false;
}

void playGamePvP(char board[3][3]){
    int row, col;
    char player = 'X';
    bool isWinner = false;

    while(!isWinner){
        printBoard(board);
        cout << player << "'s turn. Enter row and column: ";
        cin >> row >> col;

        if(board[row][col] == ' '){
            board[row][col] = player;
            if(player == 'X'){
                player = 'O';
            }else{
                player = 'X';
            }
        }else{
            cout << "That space is already taken. Please try again." << endl;
        }

        isWinner = checkWin(board);
    }
}

int main(){
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    bool twoPlyer = isTwoPlayer();
    
    playGamePvP(board);

    return 0;
}
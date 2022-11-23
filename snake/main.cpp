// Snake Game
// golfrumors & jahjah
// Start date - 12/11/2022
// Trello board link: https://trello.com/b/ahhWsMHu/snake
// ASCII value for character: https://theasciicode.com.ar
// WANNA CUM??: https://pornhub.com <- this one is my favourite - golfඞඞඞඞඞඞඞඞ

#include <iostream>
#include <ctime>
#include <curses.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <map>
#include <limits>
#include <string>

#include "macros.hpp"
#include "colours.hpp"

using namespace std;

template<typename T>
void pop_front(std::vector<T>& vec){
    assert(!vec.empty());
    vec.erase(vec.begin());
}

void setup();
void input();
void logic();
void logic(int dir);
void displayMenu();
void options();
void foodColor();
void keybinds();
void backgroundColor();
void Draw();
string chooseColor(string elem);

//global variables
int FOOD_X, FOOD_Y;
int SNAKE_LENGTH;
int snake_head_x, snake_head_y;
int score;
int gameover;
int x, y;

vector<int> snakeX, snakeY; //snake coords

char charUp = 'w', charDown = 's', charLeft = 'a', charRight = 'd', charQuit = 'q';

string SNAKE_COLOR = colourNtoStr.find(GREEN)->second;
string FOOD_COLOR = colourNtoStr.find(RED)->second;
string WALL_COLOR = colourNtoStr.find(WHITE)->second;
string BKG_COLOR = colourNtoStr.find(BLACK)->second;

//driver code for snake game
int main(){
    //hide the cursor
    printf("\e[?25l");
    //enable the cursor
    //printf("\e[?25h");

    //setup default values
    setup();
    int i = 0;

    while(i != 10){
        Draw();
        _sleep(1000);
        i++;
    }

    //display the menu
    //displayMenu();
    
    // Loads until game is over
     while(!gameover) {
        Draw();
        input();
        logic();
    }
    
    return 0;
}

void displayMenu(){
    int choice;
    bool firstPass = true;

    do{
        system(consClear);
        cout << " ______     __   __     ______     __  __     ______    \n";
        cout << "/\\  ___\\   /\\ \"-.\\ \\   /\\  __ \\   /\\ \\/ /    /\\  ___\\   \n";
        cout << "\\ \\___  \\  \\ \\ \\-.  \\  \\ \\  __ \\  \\ \\  _\"-.  \\ \\  __\\   \n";
        cout << " \\/\\_____\\  \\ \\_\\\" \\_\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\ \n";
        cout << "  \\/_____/   \\/_/ \\/_/   \\/_/\\/_/   \\/_/\\/_/   \\/_____/ \n";
        cout << "                                                        \n\n";

        cout << "Welcome to Snake! \n";
        cout << "Select an option: \n";
        cout << "1. Start a new game \n";
        cout << "2. Load a saved game \n";
        cout << "3. Options \n";
        cout << "4. Exit \n";

        if(firstPass == false){
            cout << "Invalid choice. Please try again retard: \n";
        }
        
        try{
            cin >> choice;
            if (cin.fail())
                throw 1;

        } catch (int err){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch(choice) {
            case 1: Draw(); logic(); input(); break;
            case 2: break;
            case 3: options(); break;
            case 4: exit(0); break;
            default : firstPass = false;
        }
    } while(choice < 1 || choice > 4);
}

void options(){
    
    int choice;
    
    do {
    //select color of snake
    cout << "1. Choose snake color\n";
    //select color of food
    cout << "2. Choose food color\n";
    //select color of background
    cout << "3. Choose background color\n";
    //select color of the walls
    cout << "4. Choose wall color \n";
    //set custom keybinds
    cout << "5. Change keybinds\n";
    cout << "6 to return\n";
    
    cin >> choice;

    switch(choice) {
        case 1: //SNAKE_COLOR = chooseColor("snake"); 
            break;
        case 2: //FOOD_COLOR = chooseColor("food"); 
            break;
        case 3: //BKG_COLOR = chooseColor("background"); 
            break;
        case 4: //WALL_COLOR = chooseColor("wall"); 
            break;
        case 5: keybinds(); break;
        case 6: displayMenu(); break;
    }
    } while(choice < 1 || choice > 5);

}

void Draw(){
    system(consClear);

    for(int i = 0; i < WIDTH + 2; i++){
        cout << WALL_COLOR << char(219);
    }
    cout << endl;

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(j == 0){
                cout << WALL_COLOR << char(219);
            }
            if(i == snake_head_y && j == snake_head_x){
                cout << SNAKE_COLOR << char(219);
            } else if(i == FOOD_Y && j == FOOD_X){
                cout << FOOD_COLOR << char(219);
            } else {
                bool print = false;
                for(int k = 0; k < snakeX.size(); k++){
                    if(snakeX[k] == j && snakeY[k] == i){
                        cout << SNAKE_COLOR << char(219);
                        print = true;
                    }
                }
                if(!print){
                    cout << BKG_COLOR << char(219);
                }
            }
            if(j == WIDTH - 1){
                cout << WALL_COLOR << char(219);
            }
        }
        cout << endl;
    }

    for(int i = 0; i < WIDTH + 2; i++){
        cout << WALL_COLOR << char(219);
    }
    cout << endl;

}

string chooseColor(string element) {

    int choice;
    string changeColor = colourNtoStr.find(WHITE)->second;

    do {
        system(consClear);
        cout << "Choose a color for the " << element << ": \n";
        for(int i = 0; i < 8; i++) {
            cout << i + 1 << ". " << colourNtoStr.find(colour(i))->second << colours.find(i)->second << endl;
            cout << colourNtoStr.find(WHITE)->second;
        }
    
        cin >> choice;

        if(choice >= 1 && choice <= 8) {
            changeColor = colourNtoStr.find(colour(choice - 1))->second;
        } else { 
            cout << "Enter a correct value: ";
        }

    } while(choice < 1 || choice > 8);
    
    return changeColor;
}

void setup() {
    // Default Setup when starting a game
    score = 0;
    snake_head_x = WIDTH/2;
    snake_head_y = HEIGHT/2;
    srand(time(NULL));
    FOOD_X = (rand()%WIDTH) + 1;
    FOOD_Y = (rand()%HEIGHT) + 1;
    gameover = 0;
    SNAKE_LENGTH = 3;
}

void keybinds() {
    //prompt user to change default keybinds (w, a, s, d)

    int choice;

    do {
        cout << "1. Move Up\n";
        cout << "2. Move Left\n";
        cout << "3. Move Down\n";
        cout << "4. Move Right\n";
        cout << "5. Quit\n";

    cin >> choice;
    
    if (choice == 1) {
        cout << "Press any key to bind it to UP: ";
        charUp = getch();
    } else if (choice == 2) {
        cout << "Press any key to bind it to LEFT: ";
        charLeft = getch();
    } else if (choice == 3) {
        cout << "Press any key to bind it to DOWN: ";
        charDown = getch();
    } else if (choice == 4) {
        cout << "Press any key to bind it to RIGHT: ";
        charRight = getch();
    } else if (choice == 5) {
        cout << "Press any key to bind it to QUIT: ";
        charQuit = getch();
    } else {
        cout << "Please enter a correct value\n";
    }

    } while(choice < 1 || choice > 5);
}

//handling user inputs
void input() {
    //by default we want the snake to go upwards
    //so we set the direction to 1
    /* 
        this is how the directions will be mapped

        1

    3   +   4

        2

    */

    vector<char> charBuffer;
    charBuffer.resize(2);
    int direction = 1;

    //loop while game is not over
    while(1){
       if(kbhit()){
            charBuffer.push_back(getch());
       }
       if(charBuffer.size() > 0){
            if(charBuffer[0] == charUp){ direction = 1; } 
            else if (charBuffer[0] == charDown){ direction = 2; }
            else if (charBuffer[0] == charLeft){ direction = 3; } 
            else if (charBuffer[0] == charRight){ direction = 4; }
        }
        logic(direction);
        pop_front(charBuffer);
    }
       
}

void logic() {
    // if snake is on top of fruit, change fruit coords and increment score
    if (snake_head_x == FOOD_X && snake_head_y == FOOD_Y) {
        score++;
        SNAKE_LENGTH++;
        FOOD_X = (rand()%WIDTH) + 1;
        FOOD_Y = (rand()%HEIGHT) + 1;
    } else if (snake_head_x == 0 || snake_head_y == 0 || snake_head_x == WIDTH || snake_head_x == WIDTH || snake_head_x == HEIGHT || snake_head_x == HEIGHT) {
        gameover = 1;
    }
}


 void logic(int direction) { 
    //make sure to only change direction if new direction isn't oppo
    switch(direction){
        case 1:
            //going up
            snake_head_y = 1;            
            break;
        case 2:
            //going down
            snake_head_y = -1; 
            break;
        case 3:
            //going left
            snake_head_x = -1; 
            break;
        case 4:
            //going right
            snake_head_x = 1; 
            break;
    }
    Draw();
}

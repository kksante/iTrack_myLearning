/*This program allows two people to play the tic-tac-toe game*/
/*kksante*/
/*9Mar15*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>


using namespace std;



char gamePiece1 = 'X';
char gamePiece2 = 'O';
char players_Turn; //used to assign player's turn to play.
bool gameOver; //checks status of the game
char winner = '0';

int grid_size = 3;
int num_squares = grid_size * grid_size; // number of squares on game board


vector<char> board(num_squares); //data structure for the game board


void instructions(); //displays game board and game rules

void load_gameBoard (int n); // populates the game board

void display_gameBoard (); // prints game setup

void update_playerturn(); //updates the turns for each player

int record_playersMove();

void update_gameBoard(int n); //updates board with inputs from players

void play_Game(); //runs procedure to play the game

void check_Win(); //checks for a win

bool check_gameOver(); // checks if all spots on the gameBoard are occupied

bool validate_Input(int input);// ensures inputs are valid


void instructions (){
  cout << "Welcome to the game of Tic_Tac_Toe." << endl;
  cout << "There are two game pieces for two players." << endl; 
  cout << "First player has an [X] and second play an [O]." << endl;
  cout << "Make a play by choosing an unoccupied cell number to placee your game piece" << endl;
  cout << "Goal: Win the game by three of your game pieces in a row on the game board" << endl;
  cout << "| 0 | 1 | 2 |" << endl;
  cout << "| 3 | 4 | 5 |" << endl;
  cout << "| 6 | 7 | 8 |" << endl;
  cout << "-------------" << endl;
  cout << "Start of New Game." << endl;
  cout << "-------------" << endl;
}


void load_gameBoard (int n) {
        
        
        for (int row = 0; row < n; row++) {

                 board[row] = char (row + '0');                
        
}

        display_gameBoard(); 
}


void display_gameBoard (){        

        
        for (int row = 0; row < grid_size; row++) {
                cout << "|";
                for (int col  = 0; col < grid_size; col++) {
                        
                        cout << " " << board[row*grid_size + col] << " |";
                }
                cout << endl;
        }
}

void  update_playerturn(){
 
        if (players_Turn == gamePiece1){
                
                players_Turn = gamePiece2;
        }
        else {
                players_Turn = gamePiece1;
        }
}



bool validate_Input(string string_Input){

  int input = 0;
  regex cell_number("[0-8]");
  
  if (regex_match(string_Input, cell_number) == true){
    
    stringstream myStream(string_Input);
    myStream >> input;

                               
                if(board[input] == 'X' || board[input] == 'O'){
                 cout << "This cell is already selected. Select another cell Yo!" << endl;                  
                }
                else return true;
            }
    else {
      cout << "You did not enter a number. Enter a number between 0 and 8 for an unselected cell" << endl;
    }
  return false;
}

int record_playersMove(){

    string  num_choosen;
   
    cout << "Enter the number of an unselected cell you wish to select: ";
    getline(cin, num_choosen);
           
    
    
    while (validate_Input(num_choosen) == false){

            cout << "Enter the number of an unselected cell you wish to select: ";
            getline(cin, num_choosen);
    } 

    int num = stoi(num_choosen, nullptr, 10);
           
    
     
return num;

}


void update_gameBoard(int n){
       

        if (players_Turn == gamePiece1){
                board[n] = 'X';
        }
        else {
                board[n] = 'O';
        }
        display_gameBoard();
}

void play_Game(){
          
                int move = record_playersMove();
                update_gameBoard(move);
                
}


bool check_gameOver(){
        
        
        
        for (int i = 0; i < num_squares; i++){
                gameOver = true; 
                if (!(board[i] == 'X' || board[i] == 'O')){
                        gameOver = false;
                        break;
                }
               
        }
        check_Win();
        if (gameOver == true && winner == '0') {
                                cout << "This game is a TIE!";
                        }
        return gameOver;
}

void check_Win(){
        
        
        const int win_states[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},
                                       {1,4,7},{2,5,8},{2,4,6},{0,4,8}};
        
        int num_winStates = 8;
        
        for (int row = 0; row < num_winStates; row++){
                if(board[win_states[row][0]] == 
                   board[win_states[row][1]] && board[win_states[row][1]] ==
                   board[win_states[row][2]]){
                        
                        cout << " Player with gamePiece " << players_Turn
                             << " has WON! ";
                        winner = players_Turn;
                        gameOver = true;
                         return;
                }
        }
}



int main(){

        instructions();
        load_gameBoard (num_squares);
        
        gameOver = false;
        
        if (players_Turn == 0) players_Turn = gamePiece1;

        while (gameOver == false){
                play_Game();
                check_gameOver();
                if (gameOver == false){
                update_playerturn();
                }
        }
        return 0;
}




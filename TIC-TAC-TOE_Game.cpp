#include<iostream>
#include<vector>
using namespace std;
//In first approch we are using the vector 
//This is the function which dispaly the vector 

void display_game(vector<vector<char>> &Game_board){
    for (int i = 0; i < Game_board.size(); i++){
        for(int j= 0; j <Game_board[i].size(); j++){
            cout<< Game_board[i][j]<<" ";
        }
        cout<<endl;
    }
}

// This is the function which check the board weather it is empty or not 
bool check_completet_board(vector<vector<char>> &Game_board){
    for(int i = 1; i<=3; i++){
        for(int j= 1;j <=3; j++){
            if(Game_board[i][j] == ' ')return false;
        }
    }
    return true;
}
// This is the function which check wearther the player win or  default.
bool checkwin( const vector<vector<char>> &board ,char player){
    for(int i = 1; i<=3; i++){
       if(board[i][0] == player && board[i][1] == player && board[i][2] == player )return true;
       if(board[0][i] == player && board[1][i] == player && board[2][i] == player )return true;
    }
if(board[0][0] == player && board[1][1] == player && board[2][2] == player )return true;
if(board[0][2] == player && board[1][1] == player && board[2][0] == player )return true;
return false;
}

//This is the function which start the game
void Tic_Tak_Game(){
      vector<vector<char>> Game_board(3,vector<char>(3,' '));
      char player = 'x';
      bool match_win = false;
      bool match_draw = false;
      cout<<"welcome to  Silki Tic-Tac-Toe Game"<<endl;
      while(!match_win && !match_draw){
        display_game(Game_board);
        cout<<"Player "<< player <<" enter the position where you want to place your Mark [ row, column]:";
        int row;
        int column;
        cin>> row >>column;
        if (row < 1 || row > 3 || column < 1 || column > 3 || Game_board[row-1][column -1]!= ' ')
        {
            cout<<"Invalid input the given input does not satisfied the game  rules , try another :"<< endl;
            continue;
        }
        Game_board[row-1][column -1]= player ;
        match_win = checkwin(Game_board,player);
        match_draw = check_completet_board(Game_board);
        if(!match_win)player = (player == 'x')? 'o': 'x';
        display_game(Game_board);
      }
      if(!match_win )cout<<"player"<<player<<"wins! congratulation!" <<endl;
      else cout<<" It's a draw "<<endl;      
    }

// In this approach we are using array 
int main(){
    Tic_Tak_Game();
    return 0;
}


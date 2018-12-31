

#include <iostream>
#include <tic-tac-toe/playMove.h>

using namespace std;

void playMove(int board[3][3], int row, int col, bool& turn, bool& validMove, bool& gameOver, int& winCode) {
  
    // If the game is over, do nothing, the function returns
    if (gameOver) return;
    
    // To check if the board is full, we create a bool known as "emptyBoard" and loop through the board, if any 1, or -1 element is
    // found, then emptyBoard changes to false. 
    
    bool emptyBoard=true;
    
    for (int i=0; i<=2; i++){
        for (int j=0; j<=2; j++){
          if(board[i][j]==1 || board[i][j]==-1){
              emptyBoard=false;
              break;
            }  
          }
        if(emptyBoard==false){
            break;
        }
    }
    
    //If "emptyBoard" is true, it means the desired move is the first move to be played on the board. X always goes first, so "turn" is set to true and winCode to 0
    
    if(emptyBoard==true){
        gameOver=false;
        winCode=0;
        turn= true; 
    }
    
    //If the board row and column clicked upon already contains -1 or 1, validMove becomes false, otherwise, it is true.

    if ((board[row][col] == -1) || board[row][col] == 1){
        validMove= false;
    }
    
    else {
        validMove= true;
    }
    
    //If move is valid, place the value of the player on the board row and col, 1 for X and -1 for O, and switch turns 
    //for opposite player to play next move 
    
    if (validMove){
        
        if (turn == true){
            //true: means X made the move, so specified row and col element becomes 1
            board[row][col]= 1;
            turn=false;
        }
 
        
        else if (turn ==false){
            //false: means Y made the move, so specified row and col element becomes -1
            board[row][col]=-1;
            turn= true;
        }
        
     //Now checking, is the game over after the above move? Going through different combinations of winCodes. 
     //If any combination is matched, winCode is set accordingly, and gameOver is set to true. 
        
       
        if (((board[0][0] ==1) && (board[0][1] == 1) && (board[0][2]== 1)) || ((board[0][0] == -1)&& (board[0][1] == -1) &&(board[0][2]  == -1))){
            winCode= 1;
            gameOver= true; 
        }
      
        else if (((board[1][0] ==1) && (board[1][1] == 1) && (board[1][2]== 1)) || ((board[1][0] == -1)&& (board[1][1] == -1) &&(board[1][2]  == -1))){
            winCode= 2;
            gameOver= true; 
        } 
       
        else if (((board[2][0] ==1) && (board[2][1] == 1) && (board[2][2]== 1)) || ((board[2][0] == -1)&& (board[2][1] == -1) &&(board[2][2]  == -1))){
            winCode= 3;
            gameOver= true; 
        }
        
        else if (((board[0][0] ==1) && (board[1][0] == 1) && (board[2][0]== 1)) || ((board[0][0] == -1)&& (board[1][0] == -1) &&(board[2][0]  == -1))){
            winCode= 4;
            gameOver= true; 
        }
 
        else if (((board[0][1] == 1) && (board[1][1] == 1) && (board[2][1]== 1)) || ((board[0][1] == -1)&& (board[1][1] == -1) &&(board[2][1]  == -1))){
            winCode= 5;
            gameOver=true; 
        }
       
        else if (((board[0][2] ==1) && (board[1][2] == 1) && (board[2][2]== 1)) || ((board[0][2] == -1)&& (board[1][2] == -1) &&(board[2][2]  == -1))){
            winCode= 6;
            gameOver= true; 
        }
    
        else if (((board[0][0] ==1) && (board[1][1] == 1) && (board[2][2]== 1)) || ((board[0][0] == -1)&& (board[1][1] == -1) &&(board[2][2]  == -1))){
            winCode= 7;
            gameOver= true; 
        }
        
        else if (((board[2][0] ==1) && (board[1][1] == 1) && (board[0][2]== 1)) || ((board[2][0] == -1)&& (board[1][1] == -1) &&(board[0][2]  == -1))){
            winCode= 8;
            gameOver= true; 
            
        }
        
        //If none of the combinations match, the winCode is 0, then check if the board is full. If it is full, gameOver
        //is set to true. 
                    
        else {
            winCode= 0;
            
            gameOver=true;
 
            for (int i=0; i<=2; i++){
                for (int j=0; j<=2; j++){
                  if(board[i][j]==0){
                      gameOver=false;
                      break;
                    }  
                  }
                if(gameOver==false){
                    break;
                }
            }
            
        }
      
    }
    
    // The function must always print the output specified in the handout before it exits
    // Use the standard output (i.e., cout) to print the output

    // Insert code to print the output below
    
    //Printing the sequence of the board, then row, col, turn, validMOve value, gameOver value, winCode value. 

    for(int i=0; i<=2; i++){
        for (int j=0; j<=2; j++ ){
            cout << board[i][j] << " ";
        }
    }
    
    cout << row << " " << col << " " << turn << " " << validMove << " " << gameOver << " " << winCode<<endl;
            
    return;
}

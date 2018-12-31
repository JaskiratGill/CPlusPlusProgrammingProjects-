﻿

#ifndef playMove_h
#define playMove_h

// Some basic definitions for the game
#define X     1
#define O    -1
#define Empty 0

// The is the board size: the board is 3 by 3 cells
#define boardSize 3

// Function prototype
void playMove(int gameBoard[3][3], int row, int col, bool& turn, bool& validMove, bool& gameOver, int& winCode);

#endif /* playMove_h */

#include "gameboard.h"

/**
 * Initialise the game board to be consistent with the screenshot provided
 * in your assignment specification. 
 *
 * All squares should be initialised to be blank other than the four
 * squares in the middle of the board. In that case they are initialised to 
 * appropriate colored tokens.
 **/
void initBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
/*
 * assign BLANK to all position of game board
 */
   int i, j;
   for (i = 0; i < BOARD_HEIGHT; i++){
      for (j = 0; j < BOARD_WIDTH; j++){
         board[i][j] = BLANK;
      }
   }
/*
 * set the center 4 tokens 
 */
   board[3][3] = RED;
   board[4][3] = CYAN;
   board[3][4] = CYAN;
   board[4][4] = RED;


}

/**
 * Display the board as specified in the assignment specification. You should 
 * make every effort to create a board consistent with the screenshots in the 
 * assignment specification.
 **/
void displayBoard(
    Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * first, Player * second)
{
   int i, j;
   printf("     1   2   3   4   5   6   7   8\n");
   printf("====================================\n");

   for (i = 0; i < BOARD_HEIGHT; i++) {
      printf(" %d ", i + 1);
      for (j = 0; j < BOARD_WIDTH; j++) {
         if (board[i][j] == BLANK) {
           /*  printf("|%s O ", COLOR_RED); */
            printf("|   ");
         } else if (board[i][j] == RED) {
            printf("|%s O ", COLOR_RED);
         } else if (board[i][j] == CYAN) {
            printf("|%s O ", COLOR_CYAN);
         }
         printf(COLOR_RESET);
         /* printf("| %d ", board[i][j]); */
      }
      printf("|\n------------------------------------\n");
   }

}

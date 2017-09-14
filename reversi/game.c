#include "game.h"

/*
* function to apply change
*/
void applyChange(Cell board[BOARD_HEIGHT][BOARD_WIDTH], int y, int x, int tempY, int tempX,  Cell token, Direction d)
{
   /*
    * assign row to the value of y, and col to the value of x
    * change the position of the x and y in board to token
    */
   int row = y;
   int col = x;
   board[y][x] = token;
   /*
    * change token in different direction according to Direction value
    */ 
   if (d == NORTH) {
      for (row = y - 1; row > tempY; row--) {
         board[row][x] = token;
      }
   } else if (d == SOUTH) {
      for (row = y + 1; row < tempY; row++) {
         board[row][x] = token;
      }
   } else if (d == EAST) {
      for (col = x + 1; col < tempX; col++) {
         board[y][col] = token;
      }
   } else if (d == WEST) {
      for (col = x - 1; col > tempX; col--) {
         board[y][col] = token;
      }
   } else if (d == NORTH_EAST) {
      for (col = x + 1, row = y - 1; col < tempX && row > tempY; col++, row--) {
         board[row][col] = token;
      }
   } else if (d == NORTH_WEST) {
      for (col = x - 1, row = y - 1; col > tempX && row > tempY; col--, row--) {
         board[row][col] = token;
      }
   } else if (d == SOUTH_EAST) {
      for (col = x + 1, row = y + 1; col < tempX && row < tempY; col++, row++) {
         board[row][col] = token;
      }
   } else if (d == SOUTH_WEST) {
      for (col = x - 1, row = y + 1; col > tempX && row < tempY; col--, row++) {
         board[row][col] = token;
      }
   }
   
}

Boolean checkMoveValidation(Cell board[BOARD_HEIGHT][BOARD_WIDTH], int y, int x, Cell token)
{
   /*
    * col and row is the value that user input
    * tempX and tempY is piece that already on the board
    * if board[row][col] and board[tempY][tempX] in the same line, then call applyChange()
    * method and pass those two token coordinate and Direction as parameter
    */
   int col = x;
   int row = y;
   int tempX = 0;
   int tempY = 0;
   Boolean validMove = FALSE;
   Direction d;
   /* check North */
   for (row = y - 1; row > 0; row--) {
      if (board[row][x] == BLANK) {
         break;
        /*if player's token just next to one of his token, then no token can be captured, so break as well */
      } else if (board[y - 1][x] == token) {
         break;
      } else {
         if (board[row][x] != token) {
            continue;
         } else {
            validMove = TRUE;
            d = NORTH;
            tempY = row;
            tempX = col;
            applyChange(board, y, x, tempY, tempX, token, d);
            break;
         }
      }
   }
   /* check South */
   for (row = y + 1; row < BOARD_HEIGHT; row++) {
      if (board[row][x] == BLANK) {
         break;
      } else if (board[y + 1][x] == token) {
         break;
      } else {
         if (board[row][x] != token) {
            continue;
         } else {    
            validMove = TRUE;
            d = SOUTH;
            tempY = row;
            tempX = col;
            applyChange(board, y, x, tempY, tempX, token, d);
            break;
         }
      }
   }
   /* check East */
   for (col = x + 1; col < BOARD_WIDTH; col++) {
      if (board[y][col] == BLANK) {
         break;
      } else if (board[y][x + 1] == token) {
         break;
      } else {
         if (board[y][col] != token) {
            continue;
         } else {
            validMove = TRUE;
            d = EAST;
            tempY = row;
            tempX = col;
            applyChange(board, y, x, tempY, tempX, token, d);
            break;
         }
      }
   }
   /* check West */
   for (col = x - 1; col > 0; col--) {
      if (board[y][col] == BLANK) {
         break;
      } else if (board[y][x - 1] == token) {
         break;
      } else {
         if (board[y][col] != token) {
            continue;    
         } else {
            validMove = TRUE;       
            d = WEST;
            tempY = row;
            tempX = col;
            applyChange(board, y, x, tempY, tempX, token, d);
            break;
         }
      }
   }
   /* check North East */
   for (col = x + 1, row = y - 1; col < BOARD_WIDTH || row > 0; col++, row--) {
      if (board[row][col] == BLANK) {
         break;
      } else if (board[y - 1][x + 1] == token) {
         break;
      } else {
         if (board[row][col] != token) {
            continue;
         } else {
            validMove = TRUE;
            d = NORTH_EAST;
            tempY = row;
            tempX = col;
            applyChange(board, y, x, tempY, tempX, token, d);
            break;
         }
      }
   }
   /* check North West */
   for (col = x - 1, row = y - 1; col > 0 || row > 0; col--, row--) {
      if (board[row][col] == BLANK) {
         break;
      } else if (board[y - 1][x - 1] == token) {
         break;
      } else {
         if (board[row][col] != token) {
            continue;
         } else {
            validMove = TRUE;
            d = NORTH_WEST;
            tempY = row;
            tempX = col;
            applyChange(board, y, x, tempY, tempX, token, d);
            break;
         }
      }
   }
   /* check South East */
   for (col = x + 1, row = y + 1; col < BOARD_WIDTH || row < BOARD_HEIGHT; col++, row++) {
      if(board[row][col] == BLANK) {
         break;
      } else if (board[y + 1][x + 1] == token) {
         break;
      } else {
         if (board[row][col] != token) {
            continue;
         } else {
            validMove = TRUE;
            d = SOUTH_EAST;
            tempY = row;
            tempX = col;
            applyChange(board, y, x, tempY, tempX, token, d);
            break;
         }
      }
   }
   /* check South West */
   for (col = x - 1, row = y + 1; col > 0 || row < BOARD_HEIGHT; col--, row++) {
      if(board[row][col] == BLANK) {
         break;
      } else if (board[y + 1][x - 1] == token) {
         break;
      } else {
         if (board[row][col] != token) {
            continue;
         } else {
            validMove = TRUE;
            d = SOUTH_WEST;
            tempY = row;
            tempX = col;
            applyChange(board, y, x, tempY, tempX, token, d);
            break;
         }
      }
   }

   if (validMove == FALSE) {
      printf("Invalid Move, try again!\n");
   }

   return validMove;
}

void printDetail(Player * player)
{
   printf("Name: %s", player->name);
   printf("\tScore: %d",player->score);
   if (player->token == RED) {
      printf("\tToken: %sO\n",COLOR_RED);
   } else {
      printf("\tToken: %sO\n",COLOR_CYAN);
   }
   printf(COLOR_RESET);

   printf("=========================================\n");
}


/**
 * The heart of the game itself. You should do ALL initialisation required
 * for the game in here or call function required for that purpose. For example
 * both players should be initialised from here, you should seed the random
 * number generator, etc...
 * 
 * Next, you should set the initial player - the initial player is the player
 * whose token was set to RED.
 * 
 * Next you will need to manage the game loop in here. In each loop of the
 * game, you should display the game board, including player scores
 * display whose turn it is, etc... in the format from the assignment
 * specification. Finally at the end of each turn you will calculate the score
 * for each player and store it and then you will need to swap the current player
 * and other player using the swapPlayer() function.
 * 
 * A game will end when either player presses enter on a newline.
 * 
 * When you detect a request to end the game you should do a final calculation
 * of the scores for the two players and return the player with the highest
 * score - if its a draw return NULL.
 **/
Player * playGame(Player * first, Player * second)
{

   /*
    * initialize variables
    */
   Boolean isRunning = TRUE;

   Player *currentPlayer = first;
   Player *otherPlayer = second;
   /*
    * create and initialize gameboard
    */
   Cell gameBoard[BOARD_HEIGHT][BOARD_WIDTH];
   initBoard(gameBoard);

   /*
    * initialize first player and assign a token to first player
    */
   initFirstPlayer(first);
   if (first->token == CYAN){
      initSecondPlayer(second,RED);
   } else {
      initSecondPlayer(second,CYAN);
   }

   /*
    * if second player has RED token, then swap second player to make first move
    */
   if (second->token == RED) {
      swapPlayers(&currentPlayer, &otherPlayer);
   }

   while(isRunning){
      /*
       * update score and print out players detail
       */
      first->score = gameScore(gameBoard, first->token);
      second->score = gameScore(gameBoard, second->token);
      printf("First Player Detail:\n"); 
      printDetail(first);
      printf("Second Player Detail:\n");
      printDetail(second);
      displayBoard(gameBoard, first, second);

      printf("%s's turn\n", currentPlayer -> name);
      /*
       * if player input nothing, exit the game and print out winning result
       */
      if (!makeMove(currentPlayer, gameBoard)) {
         isRunning = FALSE;
      }

      swapPlayers(&currentPlayer, &otherPlayer);
   }
   /*
    * print out winning result
    */
   if (first->score > second->score) {
      printf("Winner is %s!\n", first->name);
      return first;
   } else if (second->score > first->score) {
      printf("Winner is %s!\n", second->name);
      return second;
   } else {
      printf("Good game! It's a draw!\n");
      return NULL;
   }
}

/**
 * Prompts the user for a comma-separate pair of coordinates for a move in the
 * game. Each move, if valid, must capture at least one enemy piece by
 * surrounding a sequence of one or more enemy pieces with two pieces of our
 * own: one being the new piece to be placed and the other a piece already
 * on the board. This function then validates that a valid move has been entered
 * and calls the applyMove() function to do the actual work of capturing pieces.
 * 
 * FALSE is returned if an empty line is entered (to end the game), otherwise
 * the prompt will continue until a valid move is entered and then TRUE is returned.
 **/
Boolean makeMove(Player * player, Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{

   char coordinateInput[3 + EXTRA_SPACES];
   int x = 0;
   int y = 0;
   char *tokenIndicator = ",";

   Boolean inputValid = FALSE;
   
   do {
      printf("Please enter a coordinate separte by a comma(x,y):");
      fgets(coordinateInput, sizeof(coordinateInput), stdin);
      /*
       *  return to main menu if user input nothing for coordinate
       */
      if (strlen(coordinateInput) <= NULL_SPACE) {
         printf("Returning to Main Menu...\n");
         return FALSE;
      }
      /*
       *  if user input some thing two number before comma
       */  
      else if (coordinateInput[1] != *tokenIndicator) {
         printf("No comma, Invalid!\n");
         readRestOfLine();
         continue;
      }
      /*
       *  if user input some number too large
       */
      else if (coordinateInput[strlen(coordinateInput) - 1] != '\n') {
         printf("Invalid option, type only two number separated by a comma(x,y)\n");
         readRestOfLine();
      }
      /*
       * if user input is valid
       */ 
      else {
         coordinateInput[strlen(coordinateInput) - 1] = '\n';
         x = strtol(strtok(coordinateInput,tokenIndicator), NULL, 10);
         y = strtol(strtok(NULL,tokenIndicator), NULL, 10);

         if ((x > 8 || x < 1) || (y > 8 || y < 1)) {
            printf("Please make sure that you place a piece on the range of the board!\n");
            continue;
         } else if (board[y - 1][x - 1] != BLANK) {
            printf("Invalid Move, You can't place a piece on another!\n");
            continue;
         }

         inputValid = applyMove(board, y - 1, x - 1, player->token);
 
      }
   } while (!inputValid);
  
   return inputValid; 
}

/**
 * Applys the move requested by the user to the game board.
 * 
 * It iterates over all the directions from the coordinate specified to see
 * whether there are any pieces that can be captured.
 * 
 * If there are no pieces that can be captured in any direction it is an
 * invalid move and FALSE is returned (with no changes to the board occurring),
 * otherwise TRUE is returned, the pieces are captured and the token is
 * placed on the board.
 **/
Boolean applyMove(Cell board[BOARD_HEIGHT][BOARD_WIDTH], int y, int x, Cell token)
{

   /*
    * call checkMoveValidation function to check 8 directions
    * return true if move can be made, return false otherwise
    */  
   if (checkMoveValidation(board, y, x, token)) {
      printf("x:%d, y:%d\n", x + 1, y + 1);
      printf("Move Applied!\n");
      return TRUE;
   } else {
      return FALSE;
   }
}

/**
 * Simply counts how many locations contain the token specified on board.
 **/
unsigned gameScore(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Cell token)
{

   /*
    * calculate score of different player
    */
   unsigned score = 0;
   int i, j;
   for (i = 0; i < BOARD_HEIGHT; i++) {
      for (j = 0; j < BOARD_WIDTH; j++) {
         if (board[i][j] == token) {
            score++;
         }
      }
   }   

   return score;
}

/**
 * Swaps the two player pointers so that first points to second and vice versa.
 **/
void swapPlayers(Player ** first, Player ** second)
{
   Player *temp = *first;
   *first = *second;
   *second = temp;
}

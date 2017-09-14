#include "player.h"

/**
 * These two functions initialise the player structure at the beginning of the
 * game. In both cases, you should initialise the whole structure to known safe
 * values and then prompt the user for their name. In the initFirstPlayer()
 * function you should then select a color at random for this player using the
 * rand() function. This token should be assigned to the first player's token.
 * In initSecondPlayer() you should just test the value of token and assign the
 * opposite color to the second player.
 * 
 * Note that an empty name is not valid and the user should be re-prompted.
 **/
void initFirstPlayer(Player * player)
{
   char firstName[20 + EXTRA_SPACES]; 
   Boolean nameValid = FALSE;
   int tokenSelection = 0;
/*
 * generate a random number to assgin first player's token
 */
   srand(time(NULL));
   tokenSelection = rand() % 2;

   if (tokenSelection == 0){
      player -> token = RED;
   } else {
      player -> token = CYAN;
   }

   do {
      printf("Please enter first player's name: ");
      fgets(firstName, sizeof(firstName), stdin);
/*
 * if user input nothing, let them input again
 */
      if (strlen(firstName) <= NULL_SPACE){
         printf("Blank name is invalid, try again!\n");
/*
 * if user input something too long
 */
      } else if(firstName[strlen(firstName) - 1] != '\n') {
         printf("Too long, type less\n");
         readRestOfLine();
      } else {
         nameValid = TRUE;
         firstName[strlen(firstName) - 1] = '\0';
         strcpy(player->name, firstName);
      } 
   } while (!nameValid);
}

void initSecondPlayer(Player * player, Cell token)
{
   char secondName[20 + EXTRA_SPACES];
   Boolean nameValid = FALSE;
   do {
      printf("Please enter second player's name: ");
      fgets(secondName, sizeof(secondName), stdin);
      if (strlen(secondName) <= NULL_SPACE){
         printf("Blank name is invalid, try again!\n"); 
      } else if (secondName[strlen(secondName) - 1] != '\n'){
         printf("Too long, type less\n");
         readRestOfLine();
      } else {
         nameValid = TRUE;
         secondName[strlen(secondName) - 1] = '\0';
         strcpy(player->name, secondName);
      }
   } while (!nameValid);
   player->token = token;
}

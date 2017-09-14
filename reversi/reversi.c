#include "reversi.h"

void menu(){
/*
 * print out menu
 */
   printf("Welcome to Reversi!\n");
   printf("====================\n");
   printf("Select an option:\n");
   printf("1. Play a game\n");
   printf("2. Quit the program\n");
   printf("Please enter your choice:");
}


int main()
{
   char optionInput[3 + EXTRA_SPACES];
   int option = 0;
   Boolean optionChoice = FALSE;
   Player first;
   Player second;
 
   do {

      menu();
      fgets(optionInput, sizeof(optionInput), stdin);
/*
 * check input validation
 */
      if (optionInput[strlen(optionInput) - 1] != '\n') {
         printf("Invalid option, try again\n");
         readRestOfLine();
      } else {
         
         option = strtol(optionInput, NULL, 10);
         if (option == 1) {
            printf("Game Start\n");
            playGame(&first, &second);
         } else if (option == 2) {   
            printf("\nGoodbye. \n\n");
            break;
         } else {
            printf("Invalid option, try again\n");
         }  

         optionInput[strlen(optionInput) - 1] = '\n'; 
      }

   } while (!optionChoice);
  
   return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void getComputerChoice(char* choice) {
    int randomNum = rand() % 3;  
    if (randomNum == 0)
        strcpy(choice, "rock");
    else if (randomNum == 1)
        strcpy(choice, "paper");
    else
        strcpy(choice, "scissors");
}

void determineWinner(char* userChoice, char* computerChoice) {
    if (strcmp(userChoice, computerChoice) == 0) {
        printf("It's a draw! Both chose %s.\n", userChoice);
    } else if ((strcmp(userChoice, "rock") == 0 && strcmp(computerChoice, "scissors") == 0) ||
               (strcmp(userChoice, "paper") == 0 && strcmp(computerChoice, "rock") == 0) ||
               (strcmp(userChoice, "scissors") == 0 && strcmp(computerChoice, "paper") == 0)) {
        printf("You win! %s beats %s.\n", userChoice, computerChoice);
    } else {
        printf("You lose! %s beats %s.\n", computerChoice, userChoice);
    }
}

int main() {
    char userChoice[10], computerChoice[10];
    char playAgain;

    srand(time(0));  

    do {
        
        printf("Enter rock, paper, or scissors: ");
        scanf("%s", userChoice);

       
        getComputerChoice(computerChoice);
        printf("Computer chose: %s\n", computerChoice);

     
        determineWinner(userChoice, computerChoice);

       
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

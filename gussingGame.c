#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, guess, attempts = 0;

   
    srand(time(0));  
    randomNumber = rand() % 100 + 1;

    printf("Welcome to the number guessing game!\n");
    printf("You have chosen a random number between 1 and 100. Try to guess it!\n");

   
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < randomNumber) {
            printf("Guess low!\n");
        } else if (guess > randomNumber) {
            printf("Guess high!\n");
        } else {
            printf("Congratulations! You have guessed the correct number.%d in %d attempt.\n", randomNumber, attempts);
        }
    } while (guess != randomNumber);

    return 0;
}

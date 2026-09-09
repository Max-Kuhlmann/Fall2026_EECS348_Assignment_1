/*
Name: EECS 348 Assignment 1.c
Description: Program where user gets 3 guesses to guess a secret number
Inputs: User inputs up to 3 ints
Outputs: Tells user if their guess is correct, too low, or too high, and tells them the answer after guesses are exhausted
Sources: Gemini
Author: Max Kuhlmann
Creation date: 9/8/26
Revision date: 9/8/26
Revisions: Made Gemini code more efficient
*/


// Allows input/output (Gemini)
#include <stdio.h>

// Sets secret and max_tries using macros (Max)
#define secret 7
#define max_tries 3

// Opens main function (Gemini)
int main() {
    // Declare guess and has_won, and set has_won (Gemini)
    int guess;
    int has_won = 0;

    // Prints line setting bounds for user guess (Gemini)
    printf("Guess a number between 1 and 10.\n");

    // For loop makes sure guesses don't exceed max_tries (Gemini)
    for (int i = 1; i <= max_tries; i++) {
        // Prints prompt for user input (Gemini)
        printf("Attempt %d/%d. Enter your guess: ", i, max_tries);
        
        // Checks if input is a valid int (Gemini)
        if (scanf("%d", &guess) != 1) {
            // Tells user input is invalid (Gemini)
            printf("Invalid input. Please enter a valid number.\n");
            // Clears input buffer (Gemini)
            while (getchar() != '\n');
            // Sets back guess, so user is not punished for invalid guess (Gemini)
            i--;
            // Makes for loop reset (Gemini)
            continue;
        // Closes if statement (Gemini)
        }

        // Checks to make sure guess is within the bounds set (Gemini)
        if (guess < 1 || guess > 10) {
            // Tells user input is out of range (Gemini)
            printf("Out of range! Please guess a number between 1 and 10.\n");
            // Sets back guess, so user is not punished for invalid guess (Gemini)
            i--;
            // Makes for loop reset (Gemini)
            continue;
        // Closes if statement (Gemini)
        }

        // Checks if the guess is equal to the secret (Gemini)
        if (guess == secret) {
            // Tells user their guess was correct (Gemini)
            printf("Correct! You win!\n");
            // Sets has_won to 1 for later reference (Gemini)
            has_won = 1;
            // Breaks out of for loop (Gemini)
            break;
        // // Closes if statement and checks if the guess is less than the secret (Gemini)
        } else if (guess < secret) {
            // Makes sure user still has more tries (Gemini)
            if (i < max_tries) {
                // Tells user their guess was too low (Gemini)
                printf("Too low! Try again.\n");
            // Closes if statement (Gemini)
            }
        // Closes else if statement and checks if the guess is greater than the secret (Gemini)
        } else {
            //Makes sure user still has more tries (Gemini)
            if (i < max_tries) {
                // Tells user their guess was too high (Gemini)
                printf("Too high! Try again.\n");
            // Closes if statement (Gemini)
            }
        // Closes else statement (Gemini)
        }
    // Closes for loop (Gemini)
    }

    // Checks if the user has ran out of guesses without being correct (Gemini)
    if (!has_won) {
        // Tells user they've used all of their attempts, and what the secret number was (Gemini)
        printf("Game over! You've used all %d attempts. The secret number was %d.\n", max_tries, secret);
    // Closes if statement (Gemini)
    }

    // Return value (Gemini)
    return 0;
// Closes main (Gemini)
}
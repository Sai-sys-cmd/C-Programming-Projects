#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game(int lower, int upper, int max_guesses) 
{
    int guess, number, attempts = 0;
    number = rand() % (upper - lower + 1) + lower;

    printf("\n--- Game Started ---\n");
    printf("I'm thinking of a number between %d and %d.\n", lower, upper);
    printf("Try to guess it in %d attempts!\n", max_guesses);
    printf("---------------------\n");

    while (attempts < max_guesses) 
    {
        printf("\nEnter your guess: ");
        
        if (scanf("%d", &guess) != 1) 
        {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        attempts++;

        if (guess > number) 
        {
            printf("Too high! Try again.\n");
        } 
        else if (guess < number) 
        {
            printf("Too low! Try again.\n");
        } 
        else 
        {
            printf("\nCorrect! You guessed the number in %d attempts.\n", attempts);
            return;
        }

        printf("You have %d guesses left.\n", max_guesses - attempts);
    }

    printf("\nSorry, you've run out of guesses! The correct number was %d.\n", number);
}

int main() 
{
    int choice, play_again;
    int lower, upper, max_guesses;

    srand(time(0));

    do 
    {
        printf("\n==== Welcome to the Number Guessing Game! ====\n");
        printf("Choose a difficulty level:\n");
        printf("1. Easy (1 to 10)\n");
        printf("2. Medium (1 to 100)\n");
        printf("3. Hard (1 to 1000)\n");
        printf("4. Very Hard (1 to 10000)\n");
        printf("5. Extreme (1 to 100000)\n");
        printf("6. Insane (1 to 1000000)\n");
        printf("--------------------------------------------\n");

        while (1) 
        {
            printf("Enter your choice (1-6): ");
            
            if (scanf("%d", &choice) != 1) 
            {
                printf("Invalid input! Please enter a number between 1 and 6.\n");
                while (getchar() != '\n');
                continue;
            }

            if (choice == 1) 
            {
                lower = 1;
                upper = 10;
                max_guesses = 5;
                break;
            } 
            else if (choice == 2) 
            {
                lower = 1;
                upper = 100;
                max_guesses = 7;
                break;
            } 
            else if (choice == 3) 
            {
                lower = 1;
                upper = 1000;
                max_guesses = 10;
                break;
            } 
            else if (choice == 4) 
            {
                lower = 1;
                upper = 10000;
                max_guesses = 12;
                break;
            } 
            else if (choice == 5) 
            {
                lower = 1;
                upper = 100000;
                max_guesses = 15;
                break;
            } 
            else if (choice == 6) 
            {
                lower = 1;
                upper = 1000000;
                max_guesses = 20;
                break;
            } 
            else 
            {
                printf("Invalid choice! Please enter a valid number between 1 and 6.\n");
                while (getchar() != '\n');
            }
        }

        play_game(lower, upper, max_guesses);

        printf("\n--------------------------------------------\n");
        printf("Do you want to play again? (1 for Yes, 0 for No): ");
        
        if (scanf("%d", &play_again) != 1) 
        {
            printf("Invalid input! Exiting...\n");
            break;
        }

    } 
    while (play_again == 1);

    printf("\n==== Thanks for playing! Goodbye! ====\n");

    return 0;
}

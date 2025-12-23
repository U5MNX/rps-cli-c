#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

const char *choiceToString(int choice)
{
    switch (choice)
    {
    case ROCK:
        return "Rock";
    case PAPER:
        return "Paper";
    case SCISSORS:
        return "Scissors";
    default:
        return "Invalid";
    }
}

int determineWinner(int player, int computer)
{
    if (player == computer)
        return 0;

    if ((player == ROCK && computer == SCISSORS) ||
        (player == PAPER && computer == ROCK) ||
        (player == SCISSORS && computer == PAPER))
        return 1; // player wins

    return -1; // computer wins
}

int main()
{
    int playerChoice;
    char playAgain;

    srand(time(NULL));

    do
    {
        printf("\nChoose an option:\n");
        printf("0 - Rock\n1 - Paper\n2 - Scissors\n");
        printf("Your choice: ");

        if (scanf("%d", &playerChoice) != 1 || playerChoice < 0 || playerChoice > 2)
        {
            printf("Invalid input! Please enter 0, 1, or 2.\n");
            while (getchar() != '\n')
                ;
            continue;
        }

        int computerChoice = rand() % 3;

        printf("\nYou chose: %s\n", choiceToString(playerChoice));
        printf("Computer chose: %s\n", choiceToString(computerChoice));

        int result = determineWinner(playerChoice, computerChoice);

        if (result == 0)
            printf("Result: It's a tie!\n");
        else if (result == 1)
            printf("Result: You win! \n");
        else
            printf("Result: Computer wins! \n");

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}

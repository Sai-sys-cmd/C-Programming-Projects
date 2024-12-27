#include <stdio.h>

char board[3][3];
char currentPlayer;
int player1Wins = 0, player2Wins = 0, draws = 0;

void initializeBoard() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard() 
{
    printf("\nTic-Tac-Toe Board:\n");
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            printf(" %c ", board[i][j]);
            if (j < 2) 
                printf("|");
        }
        printf("\n");
        if (i < 2) 
            printf("---|---|---\n");
    }
}

int checkWin() 
{
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') 
        {
            return 1;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') 
        {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') 
    {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') 
    {
        return 1;
    }

    return 0;
}

int checkDraw() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] == ' ') 
            {
                return 0;
            }
        }
    }
    return 1;
}

void switchPlayer() 
{
    if (currentPlayer == 'X') 
    {
        currentPlayer = 'O';
    } 
    else 
    {
        currentPlayer = 'X';
    }
}

void playGame() 
{
    int row, col;
    int validInput;
    int gameRunning = 1;
    
    initializeBoard();
    currentPlayer = 'X';
    
    while (gameRunning) 
    {
        printBoard();
        printf("\nPlayer %c's turn. Enter row (1-3) and column (1-3): ", currentPlayer);
        
        validInput = 0;
        while (!validInput) 
        {
            if (scanf("%d %d", &row, &col) != 2) 
            {
                printf("Invalid input! Please enter two numbers (1-3).\n");
                while(getchar() != '\n');
            } 
            else 
            {
                row -= 1;
                col -= 1;

                if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') 
                {
                    validInput = 1;
                } 
                else 
                {
                    printf("Invalid move! Please try again.\n");
                }
            }
        }

        board[row][col] = currentPlayer;

        if (checkWin()) 
        {
            printBoard();
            printf("\nPlayer %c wins!\n", currentPlayer);
            if (currentPlayer == 'X') 
                player1Wins++;
            else 
                player2Wins++;
            gameRunning = 0;
        } 
        else if (checkDraw()) 
        {
            printBoard();
            printf("\nIt's a draw!\n");
            draws++;
            gameRunning = 0;
        } 
        else 
        {
            switchPlayer();
        }
    }
}

void showStats() 
{
    printf("\nGame Stats:\n");
    printf("Player X Wins: %d\n", player1Wins);
    printf("Player O Wins: %d\n", player2Wins);
    printf("Draws: %d\n", draws);
}

int main() 
{
    int choice;
    
    while (1) 
    {
        printf("\nWelcome to Tic-Tac-Toe!\n");
        printf("1. Play Game\n");
        printf("2. View Stats\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        
        if (scanf("%d", &choice) != 1) 
        {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');
        } 
        else 
        {
            if (choice == 1) 
            {
                playGame();
            } 
            else if (choice == 2) 
            {
                showStats();
            } 
            else if (choice == 3) 
            {
                printf("Goodbye!\n");
                break;
            } 
            else 
            {
                printf("Invalid option! Please try again.\n");
            }
        }
    }
    
    return 0;
}

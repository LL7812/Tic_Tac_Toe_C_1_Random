/*
C  is an imperative procedual language


*/



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Global variables
//Globale Variablen

//Board Array
//Brett Array
char board[3][3];

const char PLAYER = 'X';
const char COMPUTER = 'O';


//Functions prototypes
//Funktionen Prototypen
void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);




int main()
{

    printf("Tic Tac Toe");
    printf("\n");

    //Local variable
    //Lokale Variable
    char winner = ' '; //is an empty space and means no winner
    // ist ein Leerzeichen und bedeutet, dass es keinen Gewinner gibt

    char response;

    do{
        winner = ' ';
        response = ' ';


        //Functions call
        //Funktionsaufruf
        resetBoard();
        printBoard();

        while(winner == ' ' && checkFreeSpaces() != 0)
        {


            playerMove();


            computerMove();

            printBoard();

            winner = checkWinner();

            if(winner != ' ' || checkFreeSpaces() == 0)
            {
                break;
            }

        }

        printBoard();

        printWinner(winner);

        printf("\n Would you like to play again? (Y/N): ");
        scanf("%c");
        scanf("%c", &response);
        response = toupper(response);




    }while(response == 'Y');

    printf("Thanks for playing!");

    return 0;
}

//Functions
//Funktionen

//Set the board in an Array
//Legen Sie das Board in ein Array
void resetBoard()
{
    //Loop for rows
    //Schleife für Zeilen
    for(int i= 0; i<3 ; i++)
    {
        //Loop for columns
        //Schleife für Spalten
        for(int j= 0; j<3 ; j++)
        {
            board[i][j]=' ';
        }
    }

}

void printBoard()
{

    printf("  %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n ---|---|---\n");
    printf("  %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n ---|---|---\n");
    printf("  %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
    printf("\n");

}

int checkFreeSpaces()
{
    //Local variable
    //Lokale Variable
    int freeSpaces = 9;

    for(int i= 0; i<3 ; i++)
    {
        for(int j= 0; j<3 ; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }

    return freeSpaces;

}

void playerMove()
{
    //Row
    int x;
    //Column
    int y;

    //If the space is occupied he must enter a new one
    //Wenn das Feld belegt ist, muss er ein neues eingeben
    do{
        printf("Enter row #(1-3): ");
        scanf("%d", &x);
        //Decrement by one because of the array index
        // Aufgrund des Array-Index um eins verringern
        x--;

        printf("Enter column #(1-3): ");
        scanf("%d", &y);
        y--;



        //Check if the space is not empty
        //Überprüfen Sie, ob der Platz nicht leer ist

        if( board[x][y] != ' ')
        {
           printf("Invalid move!\n");
        }
        else
        {

            //Save in this place the character of the player "X"
            //Speichern Sie an dieser Stelle den Charakter des Spielers „X“
            board[x][y] = PLAYER;

            break;
        }


    }while( board[x][y] != ' ');




}

void computerMove()
{
    //Creates a seed based on current time
    srand(time(0));

    //Local variables
    int x;
    int y;

    if(checkFreeSpaces() > 0)
    {
        do
        {

            x = rand() % 3;
            y = rand() % 3;

        }while(board[x][y] != ' ');

        board[x][y] = COMPUTER;


    }else
    {
        printWinner(' ');
    }



}

char checkWinner()
{
    //Checks rows
    //Überprüft Zeilen
    for(int i=0; i<3; i++)
    {
        if( board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }

    }



    //Checks columns
    //Überprüft Spalten
    for(int i=0; i<3; i++)
    {
        if( board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }

    }


    //Checks diagonals
    //Überprüft Diagonalen
    if( board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
            return board[0][0];
    }

    if( board[0][2] == board[1][1] && board[0][0] == board[2][0])
    {
            return board[0][2];
    }


    return ' ';

}

void printWinner(char winner)
{
    if(winner == PLAYER)
    {
        printf("YOU WIN!");
    }
    else if(winner == COMPUTER)
    {
        printf("YOU LOSE!");
    }
    else
    {
        printf("IT´S A TIE");
    }


}









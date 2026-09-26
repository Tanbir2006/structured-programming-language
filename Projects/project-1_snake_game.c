#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

int x = 10, y = 10;
int foodX = 20, foodY = 10;

int gameOver = 0;
int score = 0;

char direction = 'd';


void draw()
{
    system("cls");


    for(int i = 0; i < 30; i++)
        printf("#");

    printf("\n");


    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 30; j++)
        {
            if(i == 0 || i == 19 || j == 0 || j == 29)
            {
                printf("#");
            }
            else if(i == y && j == x)
            {
                printf("O");
            }
            else if(i == foodY && j == foodX)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    printf("Score: %d\n", score);
    printf("W = Up | S = Down | A = Left | D = Right\n");
}


void input()
{
    if(_kbhit())
    {
        char key = _getch();

        if(key == 'w')
            direction = 'w';

        else if(key == 's')
            direction = 's';

        else if(key == 'a')
            direction = 'a';

        else if(key == 'd')
            direction = 'd';

        else if(key == 'x')
            gameOver = 1;
    }
}


void move()
{
    if(direction == 'w')
        y--;

    else if(direction == 's')
        y++;

    else if(direction == 'a')
        x--;

    else if(direction == 'd')
        x++;
}


void checkCollision()
{
    if(x <= 0 || x >= 29 || y <= 0 || y >= 19)
    {
        gameOver = 1;
    }
}


void checkFood()
{
    if(x == foodX && y == foodY)
    {
        score += 10;

        foodX = rand() % 28 + 1;
        foodY = rand() % 18 + 1;
    }
}


int main()
{
    while(gameOver == 0)
    {
        draw();

        input();

        move();

        checkCollision();

        checkFood();

        Sleep(150);
    }

    system("cls");

    printf("GAME OVER!\n");
    printf("Your Score: %d\n", score);

    return 0;
}

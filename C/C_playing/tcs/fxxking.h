#ifndef __tcshead_H__
#define __tcshead_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

#define random(x) (rand()%x)
#define size 25
#define originLenth 4
#define baseTime 2

typedef struct
{
    int stepNumber;
    int totalPoint;
    int snakeLength;
    int rank;
    int isOver;
}base;
typedef struct
{
    int x;
    int y;
}point;
typedef struct
{
    point path[size*size];
    int head;
    int tail;
}path_define;
typedef struct
{
    point loca;
    int value;
}food_define;


int map[size][size];
int direct;
point directIndex[4] = {{0,-1},{1,0},{0,1},{-1,0}};
food_define food;
path_define snakePath;
point snakeHead;
base game;

point legalPointRandom();
int eat(point newHead);
int addLenth(int number);
int Initialization();
int refreshingSnake();
int refreshingRank();
point refreshPath(point newHead);
int output();
void sleepInput();

void sleepInput(int s)
{
    time_t tmp1=time(NULL);
    time_t tmp2=tmp1;
    while(difftime(tmp2,tmp1)<s)//延时s秒后结束
    {
        if (kbhit != 0)
        {
            char temp = getchar();
            switch (temp)
            {
            case 'w':
                direct = 0;
                break;
            
            case 'a':
                direct = 3;
                break;

            case 's':
                direct = 2;
                break;
            
            case 'd':
                direct = 1;

            default:
                break;
            }
        }
        tmp2=time(NULL);
    }
}

point legalPointRandom()
{
    point result;
    result.x = random(size);
    result.y = random(size);
    while(map[result.x][result.y] != 0)
    {
        result.x = random(size);
        result.y = random(size);
    }
    return result;
}

int Initialization()
{
    for (int i = 0; i < size; i++)
    {   
        snakePath.path[i].x = 0;
        snakePath.path[i].y = 0;
        for (int j = 0; j < size; j++)
        {
            map[i][j] = 0;
        }
    }

    snakePath.head = 0;
    snakePath.tail = 0;

    direct = 0;

    game.totalPoint = 0;
    game.stepNumber = 0;
    game.isOver = 0;
    game.rank = 1;
    
    snakeHead.x = random(size);
    snakeHead.y = random(size);

    food.loca = legalPointRandom();

    addLenth(originLenth);

    return 0;
}

point refreshPathPop(point newHead)
{
    snakePath.head++;
    if (snakePath.head >= size)
        snakePath.head -= size;
    
    snakePath.path[snakePath.head] = newHead;
    point temp = snakePath.path[snakePath.tail];
    snakePath.tail++;
    if (snakePath.tail >= size)
        snakePath.tail -= size;

    return temp;
}

int addLenth(int number)
{
    for (int i = 0; i < number; i++)
    {
        snakePath.head++;
        if (snakePath.head >= size)
            snakePath.head -= size;
        snakePath.path[snakePath.head].x = snakeHead.x + directIndex[direct].x;
        snakePath.path[snakePath.head].y = snakeHead.y + directIndex[direct].y;
        map[snakeHead.x][snakeHead.y] = 1;
    }
}

int eat(point newHead)
{
    snakePath.head++;
    if (snakePath.head >= size)
        snakePath.head -= size;
    snakePath.path[snakePath.head] = newHead;
    food.loca = legalPointRandom();
    return 0;
}

int refreshingSnake()
{
    map[food.loca.x][food.loca.y] = 2;
    point next;
    point oldPoint;
    next.x = (directIndex[direct].x + snakeHead.x) % size;
    next.y = (directIndex[direct].y + snakeHead.y) % size;

    switch(map[next.x][next.y])
    {
    case 0:
        oldPoint = refreshPathPop(next);
        map[next.x][next.y] = 1;
        map[oldPoint.x][oldPoint.y] = 0;
        game.stepNumber++;
        break;

    case 1:
        game.isOver = 1;
        break;

    case 2:
        eat(next);
        map[next.x][next.y] = 1;
        game.snakeLength++;
        game.stepNumber++;
        game.totalPoint += game.rank;
        break;
    }
    snakeHead = next;

    refreshingRank();
}

int refreshingRank()
{
    game.rank = (game.totalPoint / game.rank + game.stepNumber / 4) / 10 + 1;
    return 0; 
}

int output()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (map[j][i] == 0) printf("  ");
            if (map[j][i] == 1)
            {
                if (snakeHead.x == j && snakeHead.y == i) printf("00");
                else printf("11");
            }
            if (map[j][i] == 2) printf("22");
        }
        printf("\n");
    }
    return 0;
}

#endif
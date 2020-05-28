#include "fxxking.h"

int main()
{
    Initialization();
    while(!game.isOver)
    {
        output();
        sleepInput(baseTime/game.rank);
        refreshingSnake();
    }
    return 0;
}


#include <bits/stdc++.h>
#ifndef __SNAKE__H__
#define __SNAKE__H__
using namespace std;

class snake {
private:
    int length;
    deque<pair<int, int>> path;
    pair<int, int> head;
    int dirc;//0l 1u 2r 3d

    void left() { head.second--; }
    void up() { head.first--; }
    void down() { head.first++; }
    void right() { head.second++; }
public:
    snake(int lengthIn) : length(lengthIn) {
        dirc = rand() % 4;
        head.first
    }
    pair<int, int> growth() {
        length++;
        switch (dirc)
        {
        case 0:
            left();
            break;
        case 1:
            up();
            break;
        case 2:
            right();
            break;
        default:
            down();
            break;
        }

    }
};

#endif
#ifndef SNAKE_CLS_H
#define SNAKE_CLS_H
#include <iostream>
#include <windows.h>
#include "food_cls.hpp"
#include "position.hpp"

using namespace std;

class snake_cls {
    enum {UP, DOWN, LEFT, RIGHT} dir;
    char symbol, head_symbol;
    position pos[10000];
    position & head;
    int speed, size;
    bool can_turn;
public:
    snake_cls(int x, int y):
        symbol('#'),
		head_symbol('@'),
		pos(),
        speed(1),
		size(1),
		dir(RIGHT),
        head(pos[0]),
		can_turn(true)
    {
        pos[0].x = x;
        pos[0].y = y;
    }

    bool check_food(const food_cls & food) {
        if(food.get_x() == head.x && food.get_y() == head.y) {
            size += 1;
            return true;
        }
        return false;
    }

    void get_input(const field_cls & field, bool ready) {
        if(GetAsyncKeyState(VK_UP) && dir != DOWN && ready) {
            dir = UP;
            ready=0;
        }
        if(GetAsyncKeyState(VK_DOWN) && dir != UP && ready) {
            dir = DOWN;
            ready=0;
        }
        if(GetAsyncKeyState(VK_LEFT) && dir != RIGHT && ready) {
            dir = LEFT;
            ready=0;
        }
        if(GetAsyncKeyState(VK_RIGHT) && dir != LEFT && ready) {
            dir = RIGHT;
            ready=0;
        }
    }

    void move(field_cls & field) {
        position next = {0, 0};
        switch(dir) {
        case LEFT:
            next.y = -speed; // LEFT
            break;
        case RIGHT:
            next.y = speed; // RIGHT
            break;
        case UP:
            next.x = -speed; // DOWN
            break;
        case DOWN:
            next.x = speed; //UP
            break;
        }
        for(int c = size - 1; c > 0; --c) {
            pos[c] = pos[c-1];
        }

        head.x += next.x;
        head.y += next.y;

        if(head.x < 0 || head.y < 0 || head.x >= field.get_width() || head.y >= field.get_height()) {
            throw "Game Over";
        }

    }

    void draw(field_cls & field) {
        for(int c = 0; c < size; ++c) {
            if(c == 0) {
                field.draw(pos[c].y, pos[c].x, head_symbol);
            } else {
            	if((pos[c].y==head.y)&&(pos[c].x==head.x)) throw "Game Over";
                field.draw(pos[c].y, pos[c].x, symbol);
            }
        }
    }

    int get_x() const { return head.x; }
    int get_y() const { return head.y; }
    char get_symbol() const { return symbol; }
} snake(1, 1);

#endif

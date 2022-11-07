#ifndef FOOD_CLS_H
#define FOOD_CLS_H
#include <iostream>
#include <windows.h>
#include "snake_cls.hpp"
#include "position.hpp"

class food_cls {
    position pos;
    char symbol;
public:
    food_cls(): symbol('X'), pos() {
        pos.x = pos.y = -1;
    }

    void set_pos(int x, int y) {
        pos.x = x;
        pos.y = y;
    }

    void reposition(const field_cls & field) {
        pos.x = rand() % field.get_width();
        pos.y = rand() % field.get_height();
    }

    int get_x() const {return pos.x;}
    int get_y() const {return pos.y;}
    char get_symbol() const {return symbol;}
} food;

#endif

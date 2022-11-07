#include <iostream>
#include <windows.h>
#include "field_cls.hpp"
#include "snake_cls.hpp"
#include "food_cls.hpp"
#include "graphic_cls.hpp"

void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void ShowConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}
const int field_cls::height = 100;
const int field_cls::width = 100;

const int graphic_cls::height = 100;
const int graphic_cls::width = 100;

int main( int argc, char* args[] ) {
	bool ran=0;
	bool ready;
    field.clear();

    food.set_pos(5, 5);

    graphic.init();
    HideConsole();
    while(1) {
        if(graphic.eventHandling()){
            field.clear();
            ShowConsole();
            graphic.close();
            return -1;
        }
        //graphic.clear();
        field.clear();
        ready=1;
        snake.get_input(field,ready);
        try {
            snake.move(field);
        } catch (const char * er) {
            field.clear();
            ShowConsole();
            cerr << er << endl;
            graphic.close();
            system("pause");
            return -1;
        }
        try{

        snake.draw(field);
		}catch (const char * er) {
            field.clear();
            ShowConsole();
            cerr << er << endl;
            graphic.close();
            system("pause");
            return -1;
        }

        field.draw(food.get_y(), food.get_x(), food.get_symbol());


        if(snake.check_food(food)) {
			bool ran=1;
        	while (ran){
        		food.reposition(field);
        		field.check(food.get_y(),food.get_x());
        		if(field.check(food.get_y(),food.get_x())) ran=0;
        	}
        }
        graphic.gen(field);
        //field.print();
        graphic.update();
        Sleep((1000/20));
        //system("cls");
    }

    return 0;
}

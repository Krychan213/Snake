#ifndef FIELD_CLS_H
#define FIELD_CLS_H
#include <iostream>
#include <windows.h>
#include <vector>



class field_cls {
    static const int height;
    static const int width;
    std::vector < std::vector<char> > field;
    field_cls( field_cls &);
    field_cls operator=( field_cls &);
public:
	char temp;
    field_cls() {
        this->field.assign(field_cls::height, std::vector<char> (field_cls::width,'~') );
    }
    ~field_cls() {

    }

    void print() { // Zamieniæ to na generowanie kwadratów
    	using namespace std;
        for(int c = 0; c < height; ++c) { //wys
            for(int r = 0; r < width; ++r) { //szer
                cout << field[c][r];
            }
            cout << endl;
        }
    }


    void clear() {
        for(int c = 0; c < height; ++c) {
            for(int r = 0; r < width; ++r) {
                field[c][r] = '~';
            }
        }
    }

    int get_width() const {return width;}
    int get_height() const {return height;}


    void draw(int y, int x, char what) {
        //y = (y < 0) ? 0 : (y >= height ? height - 1 : y);
        //x = (x < 0) ? 0 : (x >= width ? width - 1 : x);

        field[y][x] = what;
    }

    bool check(int y, int x){
    	if(field[y][x]=='~'){
    		return 1;
		}
    	else return 0;
	}
	char get(int y,int x){
		return field[y][x];
	}

} field;

#endif

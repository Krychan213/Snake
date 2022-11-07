#ifndef GRAPHIC_CLS_H
#define GRAPHIC_CLS_H
#include <iostream>
#include <windows.h>
#include <SDL.h>
#include "field_cls.hpp"

class graphic_cls {
public:
    static const int height;
    static const int width;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event ev;

    void init(){
        SDL_Init(SDL_INIT_EVERYTHING);
        if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
            printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        }
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, height*10, width*10, 0 );
        renderer = SDL_CreateRenderer(window,-1, SDL_RENDERER_ACCELERATED);
    }

    void gen(field_cls & field){
        SDL_Rect rect;
        rect.w = 10;
        rect.h = 10;
        for(int c = 0; c < height; ++c) {
            for(int r = 0; r < width; ++r) {
                    rect.x = c*10;
                    rect.y = r*10;
                    char chk = field.get(c,r);
                    switch(chk){
                        case '~':{
                            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

                            SDL_RenderDrawRect(renderer, &rect);
                            SDL_RenderFillRect(renderer, &rect);
                            break;
                        }
                        case '@':{
                            SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

                            SDL_RenderDrawRect(renderer, &rect);
                            SDL_RenderFillRect(renderer, &rect);
                            break;
                        }
                        case '#':{
                            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

                            SDL_RenderDrawRect(renderer, &rect);
                            SDL_RenderFillRect(renderer, &rect);
                            break;
                        }
                        case 'X':{
                            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

                            SDL_RenderDrawRect(renderer, &rect);
                            SDL_RenderFillRect(renderer, &rect);
                            break;
                        }
                    }

            }

        }
    }
    void update(){
        SDL_RenderPresent( renderer );
    }
    void clear(){
        SDL_RenderClear( renderer );
    }
    void close(){
        SDL_DestroyRenderer( renderer );
        SDL_DestroyWindow( window );
        SDL_Quit();
    }
    bool eventHandling(){
         switch (ev.type) {
            case SDL_WINDOWEVENT:

            switch (ev.window.event) {

                case SDL_WINDOWEVENT_CLOSE:   // exit game
                return 1;
                break;

            default:
                break;
        }
        break;
        }
        return 0;
    }
} graphic;

#endif

//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <conio.h>      /* getch */ 

#elif __APPLE__
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#endif

#include "./Partida.h"
#include "./InfoJoc.h"


int main(int argc, const char* argv[])
{
    //Instruccions necesaries per poder incloure la llibreria i que trobi el main
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    //Mostrem la finestra grafica

    Partida game;
    int opcio;
    //game.inicialitza("C:/Users/santa/Downloads/wewooo/intro_llibreria_grafica_estudiants/1. Resources/data/Games/partida.txt");
    //game.mostraTauler();
    

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;
    bool run, show;
    do
    {
        show = false;
        bool menu;
        do
        {
            menu = true;
            opcio = game.menu();
            switch (opcio)
            {
            case 1:
                game.juga();
                run = true;
                break;
            case 2:
                game.test(); //VARIABLE BOOLEANA PER GENERAR MES FIGURES/llegir moviments
                run = true;
                break;
            case 3:
                game.mostraPuntuacions();
                run = false;
                show = true;
                break;
            case 4:
                run = false;
                break;

            default:
                cout << "Això no és una opció.\n";
                menu = false;

            }
        } while (!menu);
        if (run)
        {
            pantalla.show();
            do {
                LAST = NOW;
                NOW = SDL_GetPerformanceCounter();
                deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

                // Captura tots els events de ratolí i teclat de l'ultim cicle
                pantalla.processEvents();

                game.actualitza(deltaTime);

                // Actualitza la pantalla
                pantalla.update();
            } while (!game.isFinish());


            if (run && !game.isTest()) {
                cout << "GAME OVER\n";
                game.afegeixPuntuacio();
            }

            else if (game.isTest())
            {
                cout << "Test finalitzat: no queden moviments.\n";
            }
        }

    } while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE) && (run || show));
    // Sortim del bucle si pressionem ESC

    //Instruccio necesaria per alliberar els recursos de la llibreria 
    SDL_Quit();
    return 0;
}


#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <iostream>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"
#include <vector>
#include <queue>
#include <list>

using namespace std;


class Cua
{
public:
    void afegeix_m(const int& valor);
    int elemina_passa_seguent();
    void inicialitza_test();
    Figura seguentFigura();
    TipusFigura generaTipus();
    void ompleBossa();
    void generaFigura();


private:
    queue <Figura> m_cola_figuras;
    int* f_next;
    queue <int> m_cola_movimientos;
    int* m_next;
    vector <TipusFigura> m_bossaFig;

};



class Llista
{
public:

    void setPuntos(const int& puntos) { m_puntuacio = puntos; }
    void setNom(const string& nom) { m_nom = nom; }
    string getNom() const { return m_nom; }
    int getPunt() const { return m_puntuacio; }
    bool operator<(const Llista& llista) { return m_puntuacio < llista.m_puntuacio; }

private:

    int m_puntuacio;
    string m_nom;
};





class Partida
{
public:
    Partida();

    void actualitza(double deltaTime);

    void inicialitza(const string& nomFitxer);

    void test() { modeTest = true; cua.inicialitza_test(); }

    void mostraTauler();

    void juga();

    int menu();

    void mostraPuntuacions();

    void afegeixPuntuacio();

    bool isFinish() { return m_acabat; }

    bool isTest() { return modeTest; }
    

private:

    void actualitzaPuntuacio(const int& linies);

    void actualitzaFigura();

    double m_temps;

    

    vector <TipusFigura> figura;

    string nombre;

    Joc Tetris;
    Cua cua;
    bool modeTest;
    int m_puntuacio;
    int m_nivell;
    bool m_acabat;
};




#endif 

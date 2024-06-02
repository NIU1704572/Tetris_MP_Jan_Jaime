#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Joc
{
public:
	Joc() { m_figura = Figura(); m_tauler = Tauler(); m_puntuacio = 0; }
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(const int& dirX);
	int baixaFigura(bool& baixat);
	void escriuTauler(const string& nomFitxer);
	void dibuixa() { m_tauler.dibuixa(); m_figura.dibuixa(); }
	void mostraTauler();
	void setFigura(const Figura& fig) { m_figura = fig; }
	int plantaFigura();
	bool gameOver();
private:
	Figura m_figura;
	Tauler m_tauler;
	int m_puntuacio;
};


#endif
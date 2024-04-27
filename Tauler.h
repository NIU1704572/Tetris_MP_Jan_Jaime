#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
	Tauler();
public:
	bool baixaFigura();
	bool mouFigura(const int& x);
	bool giraFigura(DireccioGir direccio);
private:
	void eliminaFila(const int& index);
	bool solapa(const Figura& f);
	int ComprovaFiles();


	TipusFigura m_tauler[MAX_FILA][MAX_COL];
	Figura m_figura;
};
#endif
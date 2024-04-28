#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
	
public:
	Tauler();
	bool baixaFigura();
	bool mouFigura(const int& x);
	bool giraFigura(DireccioGir direccio);

	int ComprovaFiles();

	void insertaFigura();

private:
	void eliminaFila(const int& index);
	bool solapa(const Figura& f);
	


	ColorFigura m_tauler[MAX_FILA][MAX_COL];
	Figura m_figura;
};
#endif
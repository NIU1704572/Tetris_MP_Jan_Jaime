#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"

const int MAX_FILA = 21;
const int MAX_COL = 11;

class Tauler
{
	
public:
	Tauler();


	int ComprovaFiles();

	void insertaFigura(const Figura& f);

	bool solapa(const Figura& f) const;

	ColorFigura getTauler(const int& y, const int& x) { return m_tauler[y][x]; }

	void setTauler(const int& y, const int& x, const int& color) { m_tauler[y][x] = (ColorFigura)color; }

	void dibuixa();

	bool gameOver();

private:

	void eliminaFila(const int& index);


	ColorFigura m_tauler[MAX_FILA][MAX_COL];
};
#endif
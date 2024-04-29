#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
using namespace std;

class Joc
{
public:
	Joc() {}
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(const int& dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);

private:
	Figura m_figura;
	Tauler m_tauler;

	int m_puntuacio;
};


#endif
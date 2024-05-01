#include "Joc.h"





int Joc::baixaFigura()
{
	int nCol = 0;
	bool valid = false;
	Figura comprovacio = m_figura;

	comprovacio.baixaFigura();

	valid = (!m_tauler.solapa(comprovacio));
	if (valid)
	{
		m_figura = comprovacio;
	}
	
	
	else {
		m_tauler.insertaFigura(m_figura);
		nCol = m_tauler.ComprovaFiles();
	}

	return nCol;
}

bool Joc::mouFigura(const int& x)
{

	bool valid = false;
	Figura comprovacio = m_figura;

	if (m_figura.getY() > 0 && (x == 1 || x == -1))
	{
		comprovacio.mouFigura(x);
		valid = (!m_tauler.solapa(comprovacio));
		if (valid)
		{
			m_figura = comprovacio;
		}
	}
	return valid;
}


bool Joc::giraFigura(DireccioGir direccio)
{
	bool valid = false;
	Figura comprovacio = m_figura;

	if (m_figura.getY() > 0 && (direccio == 1 || direccio == 0))
	{
		comprovacio.giraFigura(direccio);
		valid = (!m_tauler.solapa(comprovacio));
		if (valid)
		{
			m_figura = comprovacio;
		}
	}
	return valid;
}


void Joc::inicialitza(const string& nomFitxer)
{
	
	ifstream Fitxer;
	int in;
	Fitxer.open(nomFitxer);

	if (!Fitxer.eof()) 
	{
		int orientacio, col, fila, tipus;

		Fitxer >> tipus >> fila >> col >> orientacio;

		m_figura.setTipus((TipusFigura)tipus);
		m_figura.setX(col);
		m_figura.setY(fila);
		m_figura.setOrientacio(orientacio);

		m_figura.fesForma();

		int i = 0, j = 0;
		while (!Fitxer.eof() && j < MAX_FILA)
		{

			Fitxer >> in;
			m_tauler.setTauler(j, i, in);

			
			if (i >= MAX_COL)
			{
				j++;
				i = 0;
			}
			else {
				i++;
			}
				
		}
	}
	Fitxer.close();
}


void Joc::escriuTauler(const string& nomFitxer)
{
	int out;
	ofstream fitxer;
	fitxer.open(nomFitxer);
	int y;
	int x;

	switch (m_figura.getTipus())
	{

	case FIGURA_O:
		x = m_figura.getX();
		y = m_figura.getY();
		break;

	case FIGURA_I:
		x = m_figura.getX() - 2;
		y = m_figura.getY() - 1;
		break;

	default:
		x = m_figura.getX() - 1;
		y = m_figura.getY() - 1;
		break;
	}


	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			if ((i >= y && j >= x) && !(j>x+3 || i>x+3) && m_figura.getColor(i, j) != NO_COLOR)
			{
				out = m_figura.getColor(i, j);
			}
			else
			{
				out = m_tauler.getTauler(i, j);
				
			}
			fitxer << out;
		}
	}
	fitxer.close();
}
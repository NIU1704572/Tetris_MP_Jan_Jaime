#include "Joc.h"




int Joc::baixaFigura(bool& baixat)
{
	int nCol = 0;
	bool valid = false;
	Figura comprovacio = m_figura;

	comprovacio.baixaFigura();

	valid = (!m_tauler.solapa(comprovacio));
	if (valid)
	{
		m_figura.baixaFigura();
	}

	else {
		m_tauler.insertaFigura(m_figura);
		m_figura.netejaForma();
		nCol = m_tauler.ComprovaFiles();
	}

	baixat = valid;

	return nCol;
}

bool Joc::mouFigura(const int& x)
{

	bool valid = false;
	Figura comprovacio = m_figura;


	comprovacio.mouFigura(x);
	valid = (!m_tauler.solapa(comprovacio));
	if (valid)
	{
		m_figura.mouFigura(x);
	}

	return valid;
}


bool Joc::giraFigura(DireccioGir direccio)
{
	bool valid = false;
	Figura comprovacio = m_figura;

	if (direccio == 1 || direccio == 0)
	{
		comprovacio.giraFigura(direccio);
		valid = (!m_tauler.solapa(comprovacio));
		if (valid)
		{
			m_figura.giraFigura(direccio);
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

		for (int i = 0; i < orientacio % 4; i++)
		{
			m_figura.iniGir(GIR_HORARI);
		}

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

			i++;

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
		y = m_figura.getY() - 1;
		break;

	case FIGURA_I:
		x = m_figura.getX() - 1;
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
			bool u = (i >= y && j >= x);
			bool dos = (j < x + MAX_AMPLADA && i < y + MAX_ALCADA);
			bool tres = (m_figura.getColor(i - y, j) != NO_COLOR);

			if ((i >= y && j >= x) && (j < x + MAX_AMPLADA && i < y + MAX_ALCADA) && (m_figura.getColor(i - y, j - x) != NO_COLOR))
			{


				out = m_figura.getColor(i - y, j - x);
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



void Joc::mostraTauler()
{
	int y;
	int x;

	switch (m_figura.getTipus())
	{

	case FIGURA_O:
		x = m_figura.getX();
		y = m_figura.getY() - 1;
		break;

	case FIGURA_I:
		x = m_figura.getX() - 1;
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
			bool u = (i >= y && j >= x);
			bool dos = (j < x + MAX_AMPLADA && i < y + MAX_ALCADA);
			bool tres = (m_figura.getColor(i - y, j) != NO_COLOR);

			if ((i >= y && j >= x) && (j < x + MAX_AMPLADA && i < y + MAX_ALCADA) && (m_figura.getColor(i - y, j - x) != NO_COLOR))
			{


				cout << m_figura.getColor(i - y, j - x) << " ";
			}

			else
			{
				cout << m_tauler.getTauler(i, j) << " ";

			}
		}
		cout << endl;
	}
	
}


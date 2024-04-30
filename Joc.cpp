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
		for (int i = 0; i < 4; i++)
		{
			Fitxer >> in;
			switch (i)
			{
			case 0: 
				m_figura.setTipus(in);
				break;
			case 1:
				m_figura.setX(in);
				break;
			case 2:
				m_figura.setY(in);
				break;
			case 3:
				m_figura.setOrientacio(in);
				break;
			}
		}

		m_figura.fesForma();

		int i = 0, j = 0;
		while (!Fitxer.eof() || j < MAX_FILA)
		{

			Fitxer >> in;
			m_tauler.setTauler(j, i, in);

			i++;
			if (i <= MAX_COL)
				j++;
		}
	}
	Fitxer.close();
}


void Joc::escriuTauler(const string& nomFitxer)
{
	int out;
	ofstream fitxer;
	fitxer.open(nomFitxer);

	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			out = m_tauler.getTauler(i, j);
			fitxer << out << " ";
		}
		fitxer << endl;
	}
	fitxer.close();
}
#include "Tauler.h"

Tauler::Tauler() 
{
	m_figura = Figura(MAX_COL, MAX_FILA);
	for (int i = 0; i < MAX_FILA; i++) 
	{
		for (int j = 0; j < MAX_COL; j++) 
		{
			m_tauler[i][j] = NO_COLOR;
		}
	}
}


bool Tauler::solapa(const Figura& f) 
{
	bool solapa = false;

	int x = m_figura.getX();
	int y = m_figura.getY();
	int i = 0;
	int j;

	solapa = (f.getX() < 0 || f.getX()  >= MAX_COL);

	while (!solapa && i < 4)
	{
		j = 0;
		while (!solapa && j < 4)
		{
			solapa = ((m_figura.getColor(i, j) != NO_COLOR) && ((x + j >= MAX_COL || x + j < 0) || (m_tauler[i + y][j + x] != NO_COLOR)));
		}
	}

	return solapa;
}



bool Tauler::baixaFigura() 
{	
	bool valid = false;
	Figura comprovacio = m_figura;

	if (m_figura.getY() > 0) 
	{
		comprovacio.baixaFigura();
		valid = (!solapa(comprovacio));
		if (valid)
		{
			m_figura = comprovacio;
		}
	}
	return valid;
}

bool Tauler::mouFigura(const int& x)
{

	bool valid = false;
	Figura comprovacio = m_figura;

	if (m_figura.getY() > 0 && (x == 1 || x == -1)) 
	{
		comprovacio.mouFigura(x);
		valid = (!solapa(comprovacio));
		if (valid)
		{
			m_figura = comprovacio;
		}
	}
	return valid;
}


bool Tauler::giraFigura(DireccioGir direccio)
{
	bool valid = false;
	Figura comprovacio = m_figura;

	if (m_figura.getY() > 0 && (direccio == 1 || direccio == 0)) 
	{
		comprovacio.giraFigura(direccio);
		valid = (!solapa(comprovacio));
		if (valid)
		{
			m_figura = comprovacio;
		}
	}
	return valid;
}


void Tauler::eliminaFila(const int& index)
{
	for (int i = index; i + 1 < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			m_tauler[i][j] = m_tauler[i + 1][j];
		}
	}
}


int Tauler::ComprovaFiles() 
{

	int nCompletes = 0;
	int j;
	bool fCompleta = true;
	for (int i = 0; i < MAX_FILA; i++)
	{
		j = 0;
		while (fCompleta && j < MAX_COL)
		{
			fCompleta = (m_tauler[i][j] != NO_COLOR);
			if (j == MAX_COL - 1 && fCompleta)
			{
				nCompletes++;
				this->eliminaFila(i);
			}
		}
	}
	return nCompletes;
}


void Tauler::insertaFigura()
{
	ColorFigura fColor;
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			fColor = m_figura.getColor(i, j);

			if (fColor != NO_COLOR)
				m_tauler[i + m_figura.getY()][j + m_figura.getX()] = fColor;
		}
	}
}

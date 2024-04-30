#include "Tauler.h"

Tauler::Tauler() 
{
	for (int i = 0; i < MAX_FILA; i++) 
	{
		for (int j = 0; j < MAX_COL; j++) 
		{
			m_tauler[i][j] = NO_COLOR;
		}
	}
}


bool Tauler::solapa(const Figura& f) const
{
	bool solapa = false;

	int x = f.getX();
	int y = f.getY();
	int i = 0;
	int j;

	solapa = (f.getX() < 0 || f.getX()  >= MAX_COL);

	while (!solapa && i < 4)
	{
		j = 0;
		while (!solapa && j < 4)
		{
			solapa = ((f.getColor(i, j) != NO_COLOR) && ((x + j >= MAX_COL || x + j < 0) || (m_tauler[i + y][j + x] != NO_COLOR)) || f.getY() >= MAX_FILA || f.getY() < 0);
		}
	}

	return solapa;
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
	for (int i = 0; i < MAX_COL; i++)
	{
		m_tauler[0][i] = NO_COLOR;
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


void Tauler::insertaFigura(const Figura& f)
{
	ColorFigura fColor;
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			fColor = f.getColor(i, j);

			if (fColor != NO_COLOR)
				m_tauler[i + f.getY()][j + f.getX()] = fColor;
		}
	}
}

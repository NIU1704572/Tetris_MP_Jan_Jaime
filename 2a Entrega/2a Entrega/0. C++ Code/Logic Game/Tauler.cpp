#include "Tauler.h"
#include "InfoJoc.h"

Tauler::Tauler() 
{
	for (int i = 0; i < MAX_FILA; i++) 
	{
		for (int j = 0; j < MAX_COL; j++) 
		{
			m_tauler[i][j] = COLOR_NEGRE;
		}
	}
}


bool Tauler::solapa(const Figura& f) const
{

	bool solapa = false;

	int x;
	int y;
	int i = 0;
	int j;



	switch (f.getTipus())
	{

	case FIGURA_O:
		x = f.getX() - 1;
		y = f.getY();
		break;

	default:
		x = f.getX() - 1;
		y = f.getY() - 1;
		break;
	}


	solapa = false;

	while (!solapa && i < 4)
	{
		j = 0;
		while (!solapa && j < 4)
		{
			solapa = ((f.getColor(i, j) != NO_COLOR) && ((x + j >= MAX_COL) || (x + j < 0) || (m_tauler[i + y][j + x] != COLOR_NEGRE) || (y + i + 1 > MAX_FILA)));
			j++;
		}
		i++;
	}

	return solapa;
}






void Tauler::eliminaFila(const int& index)
{
	for (int i = index; i >= 0; i--)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			m_tauler[i][j] = m_tauler[i - 1][j];
		}
	}
	for (int i = 0; i < MAX_COL; i++)
	{
		m_tauler[0][i] = COLOR_NEGRE;
	}
}


int Tauler::ComprovaFiles() 
{

	int nCompletes = 0;
	int j;
	bool fCompleta;
	for (int i = 0; i < MAX_FILA; i++)
	{
		j = 0;
		fCompleta = true;

		while (fCompleta && j < MAX_COL)
		{
			fCompleta = (m_tauler[i][j] != COLOR_NEGRE);
			if (j == MAX_COL - 1 && fCompleta)
			{
				nCompletes++;
				this->eliminaFila(i);
			}
			j++;
		}
	}
	return nCompletes;
}


void Tauler::insertaFigura(const Figura& f)
{
	int x, y;
	switch (f.getTipus())
	{

	case FIGURA_O:
		x = f.getX() - 1;
		y = f.getY();
		break;

	case FIGURA_I:
		x = f.getX() - 1;
		y = f.getY() - 1;
		break;

	default:
		x = f.getX() - 1;
		y = f.getY() - 1;
		break;
	}
	ColorFigura fColor;
	for (int i = 0; i < MAX_ALCADA; i++)
	{
		for (int j = 0; j < MAX_AMPLADA; j++)
		{
			fColor = f.getColor(i, j);

			if (fColor != NO_COLOR)
				m_tauler[i + y][j + x] = fColor;
		}
	}
}

void Tauler::dibuixa()
{
	ColorFigura casella;

	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, 120, 100, false);
	for (int i = 0; i < MAX_FILA; i++)
	{
		for (int j = 0; j < MAX_COL; j++)
		{
			casella = m_tauler[i][j];
			if (casella != COLOR_NEGRE)
				GraphicManager::getInstance()->drawSprite((IMAGE_NAME)((int)m_tauler[i][j] + 1),
				POS_X_TAULER + ((1 + j) * MIDA_QUADRAT), POS_Y_TAULER + ( i * MIDA_QUADRAT), false);
		}
	}
}

bool Tauler::gameOver()
{
	bool over = false;
	int i = 0, j = 0;

	
	while (!over && j < MAX_COL)
	{
		over = (m_tauler[i][j] != COLOR_NEGRE);
		j++;
	}


	return over;
}
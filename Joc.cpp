#include "Joc.h"





int Joc::baixaFigura()
{
	bool valid = false;
	Figura comprovacio = m_figura;

	if (m_figura.getY() > 0)
	{
		comprovacio.baixaFigura();
		valid = (!m_tauler.solapa(comprovacio));
		if (valid)
		{
			m_figura = comprovacio;
		}
	}
	return valid;
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
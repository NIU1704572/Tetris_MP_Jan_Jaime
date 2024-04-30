#include "Figura.h"




Figura::Figura() {
    m_y = 0;
    m_x = 0;
    m_orientacio = 0;
    m_tipus = NO_FIGURA;
    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        for (int j = 0; j < MAX_ALCADA; j++)
        {
            m_forma[i][j] = NO_COLOR;
        }
    }
}


Figura::Figura(const int& nColum, const int& nFil) 
{
    m_y = 0;
    m_x = nFil / 2 -2;
    m_orientacio = 0;
    m_tipus = NO_FIGURA;
    for (int i = 0; i < MAX_AMPLADA; i++)
    {
        for (int j = 0; j < MAX_ALCADA; j++)
        {
            m_forma[i][j] = NO_COLOR;
        }
    }
}



void transposaFigura(ColorFigura figura[MAX_ALCADA][MAX_AMPLADA], const TipusFigura& m_tipus) 
{
    ColorFigura transposada[MAX_ALCADA][MAX_AMPLADA];
    if (m_tipus == FIGURA_I) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                transposada[j][i] = figura[i][j];
            }
        }
    }

    else {
        if (m_tipus == FIGURA_I) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (j != 0 && i != 0)
                        transposada[j][i] = figura[i][j];
                    else
                        transposada[j][i] = NO_COLOR;
                }
            }
        }
    }

    figura = transposada;

}

bool inverteixColumnes(ColorFigura figura[MAX_ALCADA][MAX_AMPLADA], const TipusFigura& m_tipus) 
{

    ColorFigura invertida[MAX_ALCADA][MAX_AMPLADA];

    if (m_tipus == FIGURA_I) {
        for (int i = 0; i < MAX_AMPLADA; i++)
        {
            for (int j = 0; j < MAX_ALCADA; j++)
            {

                invertida[i][j] = figura[i][3 - j];

            }
        }
    }

    else {
        for (int i = 0; i < MAX_AMPLADA; i++)
        {
            for (int j = 0; j < MAX_ALCADA; j++)
            {
                if (j != 0 && i != 0)
                    invertida[j][i] = figura[i][3-j];
                else
                    invertida[j][i] = NO_COLOR;

            }
        }
    
    }

    figura = invertida;
}

bool inverteixFiles(ColorFigura figura[MAX_ALCADA][MAX_AMPLADA], const TipusFigura& m_tipus)
{
    ColorFigura invertida[MAX_ALCADA][MAX_AMPLADA];

    if (m_tipus == FIGURA_I) {
        for (int i = 0; i < MAX_AMPLADA; i++)
        {
            for (int j = 0; j < MAX_ALCADA; j++)
            {

                invertida[i][j] = figura[i][3 - j];

            }
        }
    }

    else {
        for (int i = 0; i < MAX_AMPLADA; i++)
        {
            for (int j = 0; j < MAX_ALCADA; j++)
            {
                if (j != 0 && i != 0)
                    invertida[j][i] = figura[3-i][3];
                else
                    invertida[j][i] = NO_COLOR;

            }
        }

    }
    figura = invertida;
}


void inverteixFigura(ColorFigura figura[MAX_ALCADA][MAX_AMPLADA], DireccioGir direccio, TipusFigura m_tipus)
{
    if (direccio == 0)
        inverteixFiles(figura, m_tipus);
    else
        inverteixColumnes;
}



void Figura::giraFigura(DireccioGir direccio)
{
    if (m_tipus == FIGURA_O) 
        return;
    
    


    transposaFigura(m_forma, m_tipus);
    inverteixFigura(m_forma, direccio, m_tipus);
      
    m_orientacio -= 2 * direccio;
    m_orientacio++;

    if (m_orientacio > 3)
        m_orientacio = 0;

    else if (m_orientacio < 0)
        m_orientacio = 3;
}


void Figura::fesForma()
{
    ColorFigura color = (ColorFigura)(int)m_tipus;
    switch (m_tipus)
    {
    case FIGURA_O:

        m_forma[0][0] = color;
        m_forma[1][0] = color;
        m_forma[0][1] = color;
        m_forma[1][1] = color;
        break;

    case FIGURA_I:

        m_forma[1][0] = color;
        m_forma[1][1] = color;
        m_forma[1][2] = color;
        m_forma[1][3] = color;
        break;

    case FIGURA_T:

        m_forma[0][1] = color;
        m_forma[1][1] = color;
        m_forma[2][1] = color;
        m_forma[3][1] = color;
        break;

    case FIGURA_L:

        m_forma[1][0] = color;
        m_forma[1][1] = color;
        m_forma[1][2] = color;
        m_forma[2][2] = color;
        break;


    case FIGURA_J:

        m_forma[2][0] = color;
        m_forma[2][1] = color;
        m_forma[2][2] = color;
        m_forma[1][2] = color;
        break;

    case FIGURA_Z:

        m_forma[0][0] = color;
        m_forma[0][1] = color;
        m_forma[1][1] = color;
        m_forma[1][2] = color;
        break;

    case FIGURA_S:

        m_forma[0][1] = color;
        m_forma[0][2] = color;
        m_forma[1][0] = color;
        m_forma[1][1] = color;
        break;
    }
}

/* NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,*/
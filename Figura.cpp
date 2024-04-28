#include "Figura.h"




Figura::Figura() {
    m_y = 0;
    m_x = 0;
    m_orientacio = 0;
    m_tipus = NO_FIGURA;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m_forma[i][j] = NO_COLOR;
        }
    }
}


Figura::Figura(const int& nColum, const int& nFil) 
{
    m_y = nColum-1;
    m_x = nFil / 2;
    m_orientacio = 0;
    m_tipus = NO_FIGURA;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m_forma[i][j] = NO_COLOR;
        }
    }
}



void transposaFigura(ColorFigura figura[4][4], const TipusFigura& m_tipus) 
{
    ColorFigura transposada[4][4];
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

bool inverteixColumnes(ColorFigura figura[4][4], const TipusFigura& m_tipus) 
{

    ColorFigura invertida[4][4];

    if (m_tipus == FIGURA_I) {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {

                invertida[i][j] = figura[i][3 - j];

            }
        }
    }

    else {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
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

bool inverteixFiles(ColorFigura figura[4][4], const TipusFigura& m_tipus)
{
    ColorFigura invertida[4][4];

    if (m_tipus == FIGURA_I) {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {

                invertida[i][j] = figura[i][3 - j];

            }
        }
    }

    else {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
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


void inverteixFigura(ColorFigura figura[4][4], DireccioGir direccio, TipusFigura m_tipus)
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

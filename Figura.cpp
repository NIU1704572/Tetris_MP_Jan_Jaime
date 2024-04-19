#include "Figura.h"
#define FILAS 100;
#define COLUMNAS 100;

int tauler[FILAS][COLUMNAS];

void transposaFigura(ColorFigura figura[4][4], const TipusFigura& tipus) 
{
    ColorFigura transposada[4][4];
    if (tipus == FIGURA_I) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                transposada[j][i] = figura[i][j];
            }
        }
    }

    else {
        if (tipus == FIGURA_I) {
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

bool inverteixColumnes(ColorFigura figura[4][4], const TipusFigura& tipus) 
{
    
    /*
    int i = 0;
    int j=0;
    bool valid = false;
    while(i < 4 && !valid) 
    {
        while(j < 4 && !valid) 
        {
            if(invertida[i][j] == 0)
                valid = true;  

            else
            j++;
        }
        i++;
    }
    */
    
    ColorFigura invertida[4][4];

    if (tipus == FIGURA_I) {
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

bool inverteixFiles(ColorFigura figura[4][4], const TipusFigura& tipus)
{
    ColorFigura invertida[4][4];

    if (tipus == FIGURA_I) {
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


void inverteixFigura(ColorFigura figura[4][4], DireccioGir direccio, TipusFigura tipus)
{
    if (direccio == 0)
        inverteixFiles(figura, tipus);
    else
        inverteixColumnes;
}



void Figura::giraFigura(DireccioGir direccio)
{
    if (tipus == FIGURA_O) 
        return;
    
    


    transposaFigura(forma, tipus);
    inverteixFigura(forma, direccio, tipus);
      
    orientacio -= 2 * direccio;
    orientacio++;

    if (orientacio > 3)
        orientacio = 0;

    else if (orientacio < 0)
        orientacio = 3;
}

#include "Joc.h"


bool Joc::giraFigura(DireccioGir direccio)
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
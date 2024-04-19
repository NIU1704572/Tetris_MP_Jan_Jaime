#ifndef FIGURA_H
#define FIGURA_H

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC,
    COLOR_BLAUCEL,
    COLOR_MAGENTA,
    COLOR_TARONJA,
    COLOR_BLAUFOSC,
    COLOR_VERMELL,
    COLOR_VERD,
    NO_COLOR
} ColorFigura;


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O,
    FIGURA_I,
    FIGURA_T,
    FIGURA_L,
    FIGURA_J,
    FIGURA_Z,
    FIGURA_S,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;


class Figura
{
    Figura();
public:
    void giraFigura(DireccioGir direccio);

    TipusFigura getTipus() const { return tipus; };
    ColorFigura getColor() const { return forma[2][3]; };
    int getOrientacio() const { return orientacio; };
    int getY() const { return pos_y; };
    int getX() const { return pos_x; };


private:
    TipusFigura tipus;
    ColorFigura forma[4][4];
    int orientacio;
    int pos_x, pos_y;
};


#endif

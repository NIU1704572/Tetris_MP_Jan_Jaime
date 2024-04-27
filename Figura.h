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
    Figura(const int& nColum, const int& nFil);
public:
    void giraFigura(DireccioGir direccio);

    TipusFigura getTipus() const { return m_tipus; };
    ColorFigura getColor(const int& x, const int& y) const { return m_forma[x][y]; };
    int getOrientacio() const { return m_orientacio; };
    int getY() const { return m_y; };
    int getX() const { return m_x; };
    
    void mouFigura(const int& n) { m_x += n; }
    void baixaFigura() { m_y--; }


private:
    TipusFigura m_tipus;
    ColorFigura m_forma[4][4];
    int m_orientacio;
    int m_x, m_y;
};


#endif

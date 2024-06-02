#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"

Partida::Partida()
{
    m_puntuacio = 0;
    m_temps = 0;
    m_nivell = 0;
    modeTest = false;
    m_acabat = false;
}

void Partida::actualitza(double deltaTime)
{
    m_temps += deltaTime;
    if (!modeTest)
    {
        this->jocNormal();
    }

    else
    {
        this->jocTest();
    }
    Tetris.dibuixa();
    m_acabat = Tetris.gameOver();
    this->drawScore();
}


void Partida::jocNormal()
{
    bool baixat = false;

    if (Keyboard_GetKeyTrg(KEYBOARD_E))
        this->actualitzaPuntuacio(4);

    if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
        Tetris.mouFigura(-1);


    if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
        Tetris.mouFigura(+1);


    if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE))
        m_acabat = true;

    if (Keyboard_GetKeyTrg(KEYBOARD_Q))
        m_puntuacio += 1000;

    if (Keyboard_GetKeyTrg(KEYBOARD_UP))
        Tetris.giraFigura(GIR_HORARI);


    if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
        Tetris.giraFigura(GIR_ANTI_HORARI);

    if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
    {
        this->actualitzaPuntuacio(Tetris.plantaFigura());
        cua.generaFigura();
        this->actualitzaFigura();

    }

    if (m_temps > 0.6 - ((float)m_nivell) / 20.0)
    {
        this->actualitzaPuntuacio(Tetris.baixaFigura(baixat));
        if (!baixat)
        {
            cua.generaFigura();
            this->actualitzaFigura();
        }
        m_temps = 0;
    }
}

void Partida::jocTest()
{
    bool baixat = false;

    int mov = cua.elimina_passa_seguent();
    switch (mov)
    {
    case 0:
        Tetris.mouFigura(-1);
        break;

    case 1:
        Tetris.mouFigura(+1);
        break;

    case 2:
        Tetris.giraFigura(GIR_HORARI);
        break;

    case 3:
        Tetris.giraFigura(GIR_ANTI_HORARI);
        break;

    case 4:
        this->actualitzaPuntuacio(Tetris.baixaFigura(baixat));
        if (!baixat)
            this->actualitzaFigura();
        

    case 5:
        this->actualitzaPuntuacio(Tetris.plantaFigura());
        cua.generaFigura();
        this->actualitzaFigura();
    }

}


void Partida::inicialitza(const string& nomFitxer)
{
    Tetris.inicialitza(nomFitxer);
}

void Partida::mostraTauler()
{
    Tetris.mostraTauler();
}

void Cua::afegeix_m(const int& valor)
{
    m_cola_movimientos.push(valor);
}


int Cua::elimina_passa_seguent()
{
    int num = m_cola_movimientos.front();

    if (m_cola_movimientos.empty())
    {
        num = -1;
    }

    m_cola_movimientos.pop();

    return num;
}

Figura Cua::seguentFigura()
{
    Figura fig;
    
    if (!m_cola_figuras.empty())
    {
        fig = m_cola_figuras.front();
        
    }

    m_cola_figuras.pop();

    return fig;
}


void Cua::inicialitza_test()
{
    ifstream fitxer;

   

    int leido;

    

    fitxer.open("../2a Entrega/1. Resources/data/Games/moviments");

    while (!fitxer.eof())
    {
        fitxer >> leido;
        afegeix_m(leido);
    }

    fitxer.close();


    fitxer.open("../1. Resources/data/Games/figures");
    int i = 0;
    Figura fig;
    while (!fitxer.eof())
    {
        int orientacio, col, fila, tipus;

        fitxer >> tipus >> fila >> col >> orientacio;

        fig.setTipus((TipusFigura)tipus);
        fig.setX(col);
        fig.setY(fila);
        fig.setOrientacio(orientacio);

        fig.fesForma();

        for (int i = 0; i < orientacio % 4; i++)
        {
            fig.iniGir(GIR_HORARI);
        }

        m_cola_figuras.push(fig);
    }


    fitxer.close();

}


int Partida::menu()
{

    cout << "1. Joc en mode normal " << endl
        << "2. Joc en mode test " << endl
        << "3. Mostrar puntuacions" << endl
        << "4. Sortir" << endl << endl;

    int opcion;

    cin >> opcion;

    return opcion;

}

void Partida::test()
{
    Tetris.inicialitza("../1. Resources/data/Games/partida");
    this->Tetris.dibuixa();
    cua.inicialitza_test();
    modeTest = true;
 
}

void Cua::ompleBossa()
{
    m_bossaFig.push_back(FIGURA_L);
    m_bossaFig.push_back(FIGURA_O);
    m_bossaFig.push_back(FIGURA_I);
    m_bossaFig.push_back(FIGURA_S);
    m_bossaFig.push_back(FIGURA_Z);
    m_bossaFig.push_back(FIGURA_J);
    m_bossaFig.push_back(FIGURA_T);
}

TipusFigura Cua::generaTipus() 
{
    vector <TipusFigura>::iterator tipus;
    if (m_bossaFig.empty()) {
        this->ompleBossa();
    }

    int aux = rand() % m_bossaFig.size();

    tipus = m_bossaFig.begin();

    for (int i = 0; i < aux; i++)
    {
        tipus++;
    }
    TipusFigura teepus = *tipus;

    m_bossaFig.erase(tipus);

    return teepus;
}

void Cua::generaFigura()
{
 
    Figura fig;
    fig.setTipus(this->generaTipus());

    fig.setOrientacio(rand() % 4);
    fig.setX(5);
    fig.setY(0);
    fig.fesForma();
    m_cola_figuras.push(fig);
}


void Partida::actualitzaFigura()
{
    Tetris.setFigura(cua.seguentFigura());
}

void Partida::mostraPuntuacions()
{
    ifstream fitxer;

    cout << "LLISTAT DE PUNTUACIONS\n======================\n\n";

    fitxer.open("../1. Resources/data/Games/puntuacions.txt");
    if (fitxer.is_open())
    {
        int i = 1;
        int punt;
        string nom;
        while (!fitxer.eof())
        {
            fitxer >> nom >> punt;

            cout << i << ".\t" << nom << "\t" << punt << endl;
            i++;
        }
        fitxer.close();
    }

    else
        cout << "No s'ha pogut obrir el fitxer.";

}



void Partida::afegeixPuntuacio()
{
    string nom;
    cout << "Nom del jugador: " << endl;
    cin >> nom;

    Llista in;
    in.setNom(nom);
    in.setPuntos(m_puntuacio);

    list <Llista> llista;

    llista.push_back(in);


    int puntuacio;

    ifstream fitxer;
    fitxer.open("../1. Resources/data/Games/puntuacions.txt");

    while (!fitxer.eof())
    {
        fitxer >> nom >> puntuacio;
        in.setNom(nom);
        in.setPuntos(puntuacio);
        llista.push_back(in);

    }

    fitxer.close();

    llista.sort();
    llista.reverse();

    list<Llista>::iterator actual = llista.begin();
    ofstream out;
    out.open("../1. Resources/data/Games/puntuacions.txt");
    
    while (!llista.empty())
    {
        in = *actual;
        out << in.getNom() << " " << in.getPunt() << endl;
        actual = llista.erase(actual);
      

        
    }

}

void Partida::actualitzaPuntuacio(const int& linies)
{
    switch (linies)
    {
    case 0:
        break;
    case 1:
        m_puntuacio += 100;
        break;
    case 2:
        m_puntuacio += 250;
        break;
    case 3:
        m_puntuacio += 375;
        break;
    case 4:
        m_puntuacio += 500;

    default:
        cout << "Error de Puntuacio: Aquesta xifra no hauria de ser possible.\n";
         break;
    }

    m_nivell = m_puntuacio / 1000;
}


void Partida::juga()
{
    cua.generaFigura();
    cua.generaFigura();
    this->actualitzaFigura();
}


void Partida::drawScore()
{
    string msg = "Puntuacio: " + to_string(m_puntuacio) + ", Nivell: " + to_string(m_nivell);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg);
}
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
    bool baixat;
    if (!modeTest)
    {
        if (Keyboard_GetKeyTrg(KEYBOARD_E))
            this->actualitzaPuntuacio(4);

        if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
            Tetris.mouFigura(-1);


        if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
            Tetris.mouFigura(+1);


        if (m_temps > 0.5 - ((float)m_nivell) / 10)
        {
            this->actualitzaPuntuacio(Tetris.baixaFigura(baixat));
            if (!baixat)
            {
                cua.generaFigura();
                this->actualitzaFigura();
            }
            Tetris.mostraTauler();
            m_temps = 0;
        }
    }
    else
    {

    }
    Tetris.dibuixa();
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


int Cua::elemina_passa_seguent()
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

    fitxer.open("../../2a Entrega/1. Resources/data/Games/figures");

    int leido;
    int i = 0;
    Figura fig;
    while (!fitxer.eof())
    {
        fitxer >> leido;
        switch (i) {
        case 0:
            fig.setTipus((TipusFigura)leido);
            break;

        case 1:
            fig.setX(leido);
            break;

        case 2:
            fig.setY(leido);
            break;

        case 3:
            fig.setOrientacio(leido);
            fig.fesForma();
            m_cola_figuras.push(fig);
            break;

        }


        i++;

        if (i > 3)
            i = 0;
    }


    fitxer.close();

    fitxer.open("../../2a Entrega/1. Resources/data/Games/moviments");

    while (!fitxer.eof())
    {
        fitxer >> leido;
        afegeix_m(leido);
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
/*void Partida::test()
{
    cua.inicialitza_test();
    Tetris.inicialitza("../../1. Resources/data/Games/partida.txt");

    if (!Tetris.baixaFigura()) {
        Tetris.setFigura(cua.seguentFigura());
    }
}*/

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

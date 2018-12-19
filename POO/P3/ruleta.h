//Ruleta.h
//la clase ruleta representa ciertos atributos de un juego de apuestas con una ruleta.
#ifndef RULETA_H
#define RULETA_H
#include <stdlib>       //rand() y srand()
#include <time>
#include "crupier.h"
#include "jugador.h"

using std::list;
using std::string;

srand( time(NULL) );

class Ruleta{
  private:
    int banca_;                     //Dinero de la banca en €
    int bola_;
    list <Jugador> jugadores_;      //Lista de Jugador heredado
    Crupier crupier_;               //crupier heredado
    //Métodos para la bola
    string getColor_();
    string getParImpar_();
    string getAltoBajo_();

  public:
    Ruleta(int banca, int bola, Crupier c);
    inline int getBanca(){ return banca_; };
    inline int getBola(){ return bola_; };
    bool setBanca(int aux);
    bool setBola(int aux);
    inline Crupier getCrupier( return crupier_; );
    inline Crupier setCrupier(Crupier aux){ crupier_ = aux; };
    inline list <Jugador> getJugadores(){ return jugadores_; };
    bool addJugador(Jugador aux);
    int deleteJugador(Jugador aux);
    int deleteJugador(string dni);
    void escribeJugadores();
    void leeJugadores();
    inline void giraRuleta(){ setBola( rand()%37 ); };
    void getPremios();
};
#endif

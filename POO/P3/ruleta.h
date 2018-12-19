//Ruleta.h
//la clase ruleta representa ciertos atributos de un juego de apuestas con una ruleta.
#ifndef RULETA_H
#define RULETA_H
#include "crupier.h"
#include "jugador.h"

using std::list;
using std::string;

class Ruleta{
  private:
    int banca_;                     //Dinero de la banca en €
    int bola_;
    list <Jugador> jugadores_;      //Lista de Jugador heredado
    Crupier crupier_;               //crupier heredado

  public:
    Ruleta(int banca, int bola, Crupier c);
    inline int getBanca(){return banca_;};
    inline int getBola(){return bola_;};
    bool setBanca(int aux);
    bool setBola(int aux);
    inline Crupier getCrupier(return crupier_;);
    inline Crupier setCrupier(Crupier aux){crupier_ = aux;};
    inline list <Jugador> getJugadores(){return jugadores_};
    bool addJugador(Jugador aux);
    int deleteJugador(Jugador aux);
    int deleteJugador(string dni);
    void escribeJugadores();
    void leeJugadores();
};
#endif

//Ruleta.h
//la clase ruleta representa ciertos atributos de un juego de apuestas con una ruleta.
#ifndef RULETA_H
#define RULETA_H

using std::list;
using std::string;

class Ruleta{
  private:
    int banca_;                     //Dinero de la banca en €
    int bola_;
    list<string> jugadores_;
    Crupier c_; //crupier heredado no se como va

  public:
    Ruleta(int banca, int bola, Crupier c);
    inline int getBanca(){return banca_;};
    inline int getBola(){return bola_;};
    bool setBanca(int aux);
    bool setBola(int aux);
    inline Crupier getCrupier(return c_;);
    Crupier setCrupier(Crupier aux);

    bool addJugador(Jugador aux);
    inline int deleteJugador(string dni){jugadores_;};
};
#endif

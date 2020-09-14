//dados.h
//La clase dados representa la tirada de 2 dados

class Dados{
  private:
    int d1_;
    int d2_;
    int cont1_;
    int cont2_;
  public:
    Dados();                       //Constructor, es tipo void
    void lanzamiento();            //Obtiene un valor aleatorio para ambos dados
    int getDado1();                //el método devuelve un entero
    int getDado2();                //''   ''    ''      ''  ''
    bool setDado1(int value);      //Asigna un valor introducido por teclado al dado 1 y devuelve true si esta entre1 y 6
    bool setDado2(int value);      //Lo mismo que la anterior, pero para el dado 2
    int getSuma();                 //Suma los resultados de ambos dados
    int getDiferencia();           //Resta los resultados de los dados
    int getLanzamientos1();        //Devuelve las veces que se ha lanzad el dado 1
    int getLanzamientos2();        //Devuelve las veces que se ha lanzad el dado 2

};

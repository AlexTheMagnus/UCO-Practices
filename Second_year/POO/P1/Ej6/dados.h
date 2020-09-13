//dados.h
//La clase dados representa la tirada de 2 dados

class Dados{
  private:
    int d1_;
    int d2_;
    int cont1_;
    int cont2_;
    int total1_;                   //Es la suma de todos los valores del dado 1
    int total2_;                   //Es la suma de todos los valores del dado 2
    int v1_[5];                    //Es un vecto para almacenar los 5 ultimos resultados del dado 1
    int v2_[5];                    //Es un vecto para almacenar los 5 ultimos resultados del dado 2
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
    float getMedia1();             //Devuelve la media de todos los valores que han salido en el dado 1
    float getMedia2();             //Devuelve la media de todos los valores que han salido en el dado 1
    void getUltimos1();            //Almacena el nuevo valor en el vector de los ultimos valores del dado 1
    void getUltimos2();            //Almacena el nuevo valor en el vector de los ultimos valores del dado 2
    void showUltimos1();           //Muestar el vector del dado 1
    void showUltimos2();           //Muestar el vector del dado 2
};

#include <iostream>
using namespace std;

int main(){
	float nval_ini, nval, valor_acu, aux, media;
	cout<<"Introduzca de cuantos valores quiere hacer la media:"<<endl;
	cin>>nval_ini;
	nval=nval_ini;
	valor_acu=0;

do{
		nval=nval-1;
		cout<<"Introduzca un numero:"<<endl;
		cin>>aux;
		valor_acu=valor_acu+aux;
	}while(nval!=0);

	media=valor_acu/nval_ini;
cout<<"La media es "<<media<<endl;

cin.ignore();
cin.get();
}
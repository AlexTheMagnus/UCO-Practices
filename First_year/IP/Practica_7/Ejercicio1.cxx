#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int espacios(string cad){
	int cont=0;	
	string espacio=" ";
	for(int i=0; i<cad.size(); i++){
		if(espacio[0]==cad[i]){
			cont++;
		}
	}

	return cont;
}

int main(){
	string cad;
	cout<<"Introduzca el texto del que quiera contar los espacios"<<endl;
	getline(cin,cad);
	cout<<"Hay "<<espacios(cad)<<" espacios en la cadena"<<endl;

cin.ignore();
cin.get();
system("pause");
}
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int digitos(string cad){
	int cont=0;	
	for(int i=0; i<cad.size(); i++){
		if(isdigit(cad[i])==1){
			cont++;
		}
	}
	return cont;
}

int main(){
	string cad;
	cout<<"Introduzca el texto del que quiera contar los digitos:"<<endl;
	getline(cin,cad);
	
	
	cout<<"Hay "<<digitos(cad)<<" digitos en la cadena"<<endl;

cin.ignore();
cin.get();
system("pause");
}
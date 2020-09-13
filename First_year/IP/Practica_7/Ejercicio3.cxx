#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

void convierte_a_mayusculas(string& cad){
	for(int i=0; i<cad.size(); i++){
		putchar (toupper(cad[i]));
	}
}

int main(){
	string cad;
	cout<<"Introduzca el texto que desea pasar a mayuscula:"<<endl;
	getline(cin,cad);
	convierte_a_mayusculas(cad);

cin.ignore();
cin.get();
system("pause");
}
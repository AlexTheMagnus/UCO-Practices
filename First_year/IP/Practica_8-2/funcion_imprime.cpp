#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;


//al principio

void imprime(int i){
	cout<<"	Dni:"<<alumnos[i].dni<<endl;
	cout<<"	Edad:"<<alumnos[i].edad<<endl;
	cout<<"	Nota:"<<alumnos[i].nota<<endl;
}

//f2
int main(){
	int i;
	cout<<"Introduzca el numero del alumno:"<<endl;
	cin>>i;
	if(i>9){
		cout<<"Error, no hay ningun alumno asignado a ese numero"<<endl;
	}
	else{imprime(i);}
}



//f3

for(int j=0; j<10; j++){
	imprime(i);
}
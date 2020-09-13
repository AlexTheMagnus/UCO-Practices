#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

void lee(float v[], int n){
	int i=0;
	while(i<n){
		cout<<"Introduzca el valor del elemento numero "<<i+1<<"  del vector:"<<endl;
		cin>>v[i];
		i++;
	}
}


void imprime(float v[], int n){
	int i=0;
	while(i<n){
		cout<<"El  elemento numero "<<i+1<<" del vector vale "<<v[i]<<endl;
		i++;
	}
}



int main(){
	int n;
	float v [n];
	cout<<"Escoja el numero de elementos del vector:"<<endl;
	cin>>n;
	if(n<1){cout<<"Error, use un numero positivo"<<endl;};
	lee(v,n);
	imprime(v,n);

    system("pause");
}


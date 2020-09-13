#include <iostream>
using namespace std;

int main(){
	int n, suma=0;
	cout<<"¿Numero hasta el que desea sumar los impares?"<<endl;
	cin>>n;

	while(n!=0){
		if(n%2!=0){
		suma=suma+n;
		}
		n=n-1;
	};

	cout<<"El resultado es "<<suma<<endl;

cin.ignore();
cin.get();
}
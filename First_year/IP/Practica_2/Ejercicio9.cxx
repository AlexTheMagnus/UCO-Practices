#include <iostream>
using namespace std;

int main(){
	int suma=0, n;
	cout<<"Introduzca el número hasta el cual sumar:"<<endl;
	cin>>n;

	while(n>0){
		if((n%2==0)  || (n%3==0)){
			suma=suma+n;
		}
		n=n-1;
	}

	cout<<"La suma es: "<<suma<<endl;	

cin.ignore();
cin.get();
}
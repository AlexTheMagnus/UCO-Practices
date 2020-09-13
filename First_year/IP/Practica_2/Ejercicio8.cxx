#include <iostream>
using namespace std;

int main(){
	int n, a, b;
	cout<<"¿Cuántos términos de la sucesión de Fibonacci quiere conocer?"<<endl;
	cin>>n;				//Variable contador
	cout<<"Los términos de la sucesión son:"<<endl;

	a=0,			//Números iniciales de la sucesión
	b=1;
	cout<<a<<endl;		
	cout<<b<<endl;
	n=n-2;
		
	while(n>0){
	if(n>0){
		a=a+b;
		cout<<a<<endl;

		n=n-1;
	}

	if(n>0){
		b=a+b;
		cout<<b<<endl;

		n=n-1;
	}
}

cin.ignore();
cin.get();
}
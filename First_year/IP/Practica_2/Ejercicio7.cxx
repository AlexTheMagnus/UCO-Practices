#include <iostream>
using namespace std;

int main(){
	int N, a, b, c=0;
	cout<<"Indique el número el cual desea comprobar si es primo:"<<endl;
	cin>>N;
	a=N;

	while(a!=0){
	b=N%a;
		if(b==0){		//Para que c cuente el número de divisores de N
			c=c+1;		
		}
		a=a-1;
	};

	if(c>2){
		cout<<"No es un número primo"<<endl;
	}
	else{
		cout<<"Es un número primo"<<endl;
	}

cin.ignore();
cin.get();
}
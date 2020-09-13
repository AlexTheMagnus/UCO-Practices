#include <iostream>
using namespace std;

int main(){
	int n, a, b;
	cout<<"¿Numero del que desea saber los divisores?"<<endl;
	cin>>n;
	a=n;

	while(a!=0){
	b=n%a;
		if(b==0){
			cout<<a<<endl;
		}
		a=a-1;
	};

cin.ignore();
cin.get();
}
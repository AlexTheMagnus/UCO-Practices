#include <iostream>
using namespace std;

int main(){
	int n, a, b;
	cout<<"¿Numero del que desea saber los divisores?"<<endl;
	cin>>n;
	a=1;

	while(a<=n){
	b=n%a;
		if(b==0){
			cout<<a<<endl;
		}
		a=a+1;
	};

cin.ignore();
cin.get();
}
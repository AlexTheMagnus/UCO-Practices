#include <iostream>
using namespace std;

void divisores(int v){
	int i=1;
	while(i<=v){
		if(v%i==0){
			cout<<i<<endl;
		}
		i++;
	}
}

int main(){
int a;
cout<<"Introduzca el numero del que desea saber los divisores:"<<endl;
cin>>a;

cout<<"Los divisores son:"<<endl;
divisores(a);

cin.ignore();
cin.get();
}


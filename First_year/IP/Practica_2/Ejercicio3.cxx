#include <iostream>
using namespace std;

int main(){
	int i, fact=1;
	cout<<"¿De que numero desea hallar el factorial?"<<endl;
	cin>>i;

	while(i!=0){
		fact=fact*i;
		i=i-1;
		};

	cout<<"El resultado es "<<fact<<endl;

cin.ignore();
cin.get();
}
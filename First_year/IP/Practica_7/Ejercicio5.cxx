#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

void replace(string &cad, char a, char b){

	for(int i=0; i<cad.size(); i++){
		if(cad[i]==a){
			cad[i]=b;
		}
	}
	cout<<cad<<endl;
}

int main(){
	string cad;
	cout<<"Introduzca el texto que desea modificar:"<<endl;
	getline(cin,cad);
	char a;
	cout<<"Introduzca el carater a modificar:"<<endl;
	cin>>a;
	char b;
	cout<<"Introduzca el carater a ser modificado:"<<endl;
	cin>>b;
	replace(cad, a, b);
	
cin.ignore();
cin.get();
system("pause");
}
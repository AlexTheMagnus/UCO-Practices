#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int vocales(string cad){
	int nvol=0;
	char vocales[5]={'a', 'e', 'i','o', 'u'};

for(int k=0; k<cad.size(); k++){
		cad[k]=tolower(cad[k]);
	}

	for(int i=0; i<cad.size(); i++){
		for(int j=0; j<5; j++){
			if(cad[i]==vocales[j]){
				nvol++;
			}
		}
	}
	return nvol;
}

int main(){
	string cad;
	cout<<"Introduzca el texto del cual desea contar las vocales:"<<endl;
	getline(cin,cad);
	
	cout<<"Hay "<<vocales(cad)<<" vocales en el texto."<<endl;
cin.ignore();
cin.get();
system("pause");
}
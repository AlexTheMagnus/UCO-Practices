#include <iostream>
using namespace std;

bool esprimo(int v){
	bool res;
	int  b, c=0;
	int a =v;
	
	
	while(a != 0){
		b=v%a;
		if(b==0){
			c++;
		}
		a--;
	};
	if(c>2){res=false;}
	else{res=true;}
	return res;
}



void primo(int n){
	int i=1, aux=1;
	while(aux <=n){
		if(esprimo(i)){
			cout<<	i<<endl;
			aux++;
		}
	i++;
	}
}

int main(){
int z;
cout<<"Introduzca cuántos primos desea conocer:"<<endl;
cin>>z;
primo(z);

cin.ignore();
cin.get();
}


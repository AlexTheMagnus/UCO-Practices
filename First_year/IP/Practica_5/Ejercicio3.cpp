#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void fijaValorAleatorio(int v[],int n,int max ){
	srand(time(0));
	for(int i=0; i<n; i++){
		 n=rand()%max;
		v[i]=n;
		i++;}
}

int main(){
	int n, v[n], max;
	cout<<"Introduzca el numero de elementos del vector:"<<endl;
	cin>>n;
	cout<<"Introduzca  el numero maximo que puede aparecer:"<<endl;
	cin>>max;
	fijaValorAleatorio(v, n, max+1 );
	for(int i=0;i<n;i++){
		cout<<v[i]<<endl;			
		}
    system("pause");
}


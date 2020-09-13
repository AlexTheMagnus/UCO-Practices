#include <iostream>
using namespace std;

int main(){
	float n, suma, total;
	cout<<"n=";
	cin>>n;
	suma=1;
	total=0;

	do{
		n=n-1;
		total=total+suma;
		suma=suma+1;
		}while(n!=0);

	cout<<"El total es "<<total<<endl;

cin.ignore();
cin.get();
}
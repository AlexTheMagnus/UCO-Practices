#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
int n, i=1, fact=1;
cin<<n;
while(i<=n){
	fact=i*i;
	i++;
}
cout<<fact<<endl;
    system("pause");
}


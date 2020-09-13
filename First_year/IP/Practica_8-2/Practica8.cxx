#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
//Crea la estructura alumno
struct Alumno{
		string dni;
		int edad;
		float nota;
	};

//f1
void addalumno(Alumno alumnos[], int nmatriculados){
	cout<<"Introduzca el dni del alumno:"<<endl;
	cin>>alumnos[nmatriculados].dni;
	cout<<"Introduzca la edad del alumno:"<<endl;
	cin>>alumnos[nmatriculados].edad;	
	cout<<"Introduzca la nota del alumno:"<<endl;
	cin>>alumnos[nmatriculados].nota;	
}

//f2 y f3
void imprime(Alumno alumnos[], int i){
	cout<<"	Dni:"<<alumnos[i].dni<<endl;
	cout<<"	Edad:"<<alumnos[i].edad<<endl;
	cout<<"	Nota:"<<alumnos[i].nota<<endl;
}

//f4
void editalumno(Alumno alumnos[], int nalumno){
	int opcion_menu2;
	do{
		cout<<"¿Que desea modificar del alumno nº"<<nalumno<<"?"<<endl;
		cout<<"	1. Dni"<<endl;
		cout<<"	2. Edad"<<endl;
		cout<<"	3. Nota"<<endl;
		cout<<"	4. Volver al menu principal"<<endl;
		cin>>opcion_menu2;
		
		switch(opcion_menu2){
			case 1:{
				cout<<"Introduzca el dni del alumno:"<<endl;
				cin>>alumnos[nalumno].dni;
			}break;
			case 2:{
				cout<<"Introduzca la edad del alumno:"<<endl;
				cin>>alumnos[nalumno].edad;	
			}break;
			case 3:{
				cout<<"Introduzca la nota del alumno:"<<endl;
				cin>>alumnos[nalumno].nota;	
			}break;
		}
	}while(opcion_menu2!=4);
}

//f5
void deletealumno(Alumno alumnos[], int ndelete){
	for( ; ndelete<9; ndelete++){
		alumnos[ndelete].dni=alumnos[ndelete+1].dni;
		alumnos[ndelete].edad=alumnos[ndelete+1].edad;	
		alumnos[ndelete].nota=alumnos[ndelete+1].nota;	
	}	

}

int main(){
	Alumno alumnos[10];
	int nmatriculados=0;
	int opcion_menu=0;
	do{
		cout<<"Seleccione una opcion:"<<endl;
		cout<<"	1. Añadir alumno"<<endl;
		cout<<"	2. Imprimir datos alumno"<<endl;
		cout<<"	3. Imprimir datos de todos los alumnos"<<endl;
		cout<<"	4. Modificar alumno"<<endl;
		cout<<"	5. Eliminar a un alumno"<<endl;
		cout<<"	6. Salir"<<endl;

		cin>>opcion_menu;
		switch(opcion_menu){
			case 1:{
				addalumno(alumnos, nmatriculados);
				cout<<"Alumno con nº de matricula: "<<nmatriculados<<endl;
				nmatriculados++;
			}break;

			case 2:{
				int i;
				cout<<"Introduzca el numero del alumno:"<<endl;
				cin>>i;
				if(i>9){
					cout<<"Error, no hay ningun alumno asignado a ese numero"<<endl;
				}
				else{imprime(alumnos, i);}
			}break;

			case 3:{
				for(int j=0; j<10; j++){
					cout<<"Alumno nº: "<<j<<endl;
					imprime(alumnos, j);
				}
			}break;

			case 4:{
				int nalumno;
				cout<<"¿Que alumno desea modificar?"<<endl;
				cin>>nalumno;
				editalumno(alumnos, nalumno);
			}break;

			case 5:{
				int ndelete;
				cout<<"¿Que alumno desea eliminar?"<<endl;
				cin>>ndelete;
				deletealumno(alumnos, ndelete);
				nmatriculados--;
			}break;
		}
	}while(opcion_menu!=6);
	cin.ignore();
	cin.get();
	system("pause");
}
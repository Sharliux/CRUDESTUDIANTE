#include <iostream>
#include <stdio.h>  
#include <string.h> 
using namespace std;
const char *nombe_archivo = "archivo.dat";
int opcion=0;
	int cod;
    struct Estudiante{
	int codigo;
	char nombre[50];
	char apellido[50];
	int telefono;

};
 void menu_estudiante();
 void ingresar_estudiante();
 void abrir_estudiante();
 void modificar_estudiante();
 void buscar_codigo();
 void eliminar_estudiante();


main(){

menu_estudiante();	
}

void menu_estudiante(){
	system("cls");
cout<<"\t____________MENU DE OPCIONES____________"<<endl;
cout<<"\t\t1. Crear estudiante"<<endl;
cout<<"\t\t2. ver estudiantes"<<endl;
cout<<"\t\t3. Actualizar estudiante"<<endl;
cout<<"\t\t4. Buscar estudiante"<<endl;
cout<<"\t\t5. eliminar estudiante"<<endl;
cout<<"\t\t6. Salir"<<endl<<endl;
cout<<"\t\t\tDigite su opcion: ";
cin>>opcion; 
			
	system("cls");
	
	switch(opcion)
	{
		case 1: ingresar_estudiante();		 	;break;
 		case 2: abrir_estudiante();				;break;
 		case 3: modificar_estudiante();	 		;break;
 		case 4: buscar_codigo();				;break;
 		case 5: eliminar_estudiante();	 		;break;
 		case 6: exit(-1);				;break;  
		default:cout<<"Opcion no valida";  
	}
}
void abrir_estudiante(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Estudiante estudiante;
	int registro=0;
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
	cout<<"____________________________________________________________________"<<endl;
	cout << "id" <<"|"<< "CODIGO" <<"|"<<"      NOMBRE      "<<" "<<"      APELLIDO      "<<" "<<"      TELEFONO      "<<" "<<endl;	
		do{
		cout<<"____________________________________________________________________"<<endl;
		cout << registro <<" |  "<< estudiante.codigo <<"  |  "<< estudiante.nombre<<"    "<<estudiante.apellido<< "      "<<estudiante.telefono<<endl;
        
        
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
		system("pause");
		
		menu_estudiante();
	}
	void modificar_estudiante(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido;	
    	Estudiante estudiante;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Estudiante), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
	fclose(archivo);
	
		system("pause");
		
	menu_estudiante();
}
void ingresar_estudiante(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); 
	
	
		Estudiante estudiante;
		 string nombre,apellido;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>estudiante.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombre:";
		getline(cin,nombre);
    	strcpy(estudiante.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellido:";
		getline(cin,apellido);
		strcpy(estudiante.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el Telefono:";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite( &estudiante, sizeof(Estudiante), 1, archivo );
		
		cout<<"Desea Agregar otro Nombre s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_estudiante();
	//buscar_indice();	
	buscar_codigo();
	system("pause");
		
		menu_estudiante();
	
}
void buscar_codigo(){
		FILE* archivo = fopen(nombe_archivo,"rb");	
	int pos=0,indice=0,cod=0;
	cout<<"Que codigo desea ver: ";
	cin>>cod;
	
	Estudiante estudiante;
	fread(&estudiante,sizeof(Estudiante),1,archivo);	
	do{
	   if(estudiante.codigo == cod)	{
	   	cout<<"Codigo: "<<estudiante.codigo<<endl;
	   	cout<<"Nombres: "<<estudiante.nombre<<endl;
	   	cout<<"Apellidos: "<<estudiante.apellido<<endl;
	   	cout<<"Telefono: "<<estudiante.telefono<<endl;
	   }
	   fread(&estudiante,sizeof(Estudiante),1,archivo);	
	} while(feof(archivo)==0);
	
	
	fclose(archivo);
	system("pause");
		
		menu_estudiante();
}
void eliminar_estudiante(){
			system("cls");	
	FILE* archivo = fopen(nombe_archivo,"r+b");
	FILE* archiv = fopen(nombe_archivo,"r+b");
	int id1;
	int id2;
	Estudiante estudiante;
	string nombre,apellido;
	cout<<"Ingres el ID que desa Eliminar:";
	cin>>id1;
	fseek(archivo,id1 * sizeof(Estudiante),SEEK_SET);
	if (id1==id2){
		cout<<"**eliminado**";
	}else{
		cout<<"Error";
}
	fwrite(&estudiante,sizeof(Estudiante),1,archivo);

	remove("archivo");
	rename("archivo2.dat","archivo.dat");
	fclose(archivo);
	abrir_estudiante();
	
	
		system("pause");
		
	menu_estudiante();
}

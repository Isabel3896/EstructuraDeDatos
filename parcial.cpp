#include <iostream>
#include <malloc.h>
#include <cstring>

using namespace std;

int cont= 1000; /* declaramos el contador para el id */
int conM = 0;
int conF = 0;

struct cliente {
    int id;
    char nombre[30]; 
    int edad;
    char genero;
    char motivo[50];
    cliente *sig;
};

cliente *cab, *auxC, *aux2C,*aux; /*declaración de apuntadores */
struct clienteAtendido {
    int idA;
    char nombreA[30]; 
    int edadA;
    char generoA;
    char motivoA[50];
    clienteAtendido *sig;

};

clienteAtendido *cabA, *auxA; 

void registrar(){
   
    auxC= (struct cliente* ) malloc (sizeof(cliente)); /*pedimos tamaño para la estructura */
    cout<<"Por favor, diganos su edad: " <<endl;
    cin>>auxC->edad;
    if (auxC->edad<18){
        cout<<"Lo siento, no tienes la edad suficiente para requerir el servicio: " <<endl;
        return;
    }
    cin.ignore();
    cout<<"Por favor, diganos su nombre completo: " <<endl;
    cin.getline(auxC->nombre, 30);
    cout<<"Por favor, diganos su genero (M/F): " <<endl;
    cin >> auxC->genero;
    while (auxC->genero != 'M' && auxC->genero != 'F') {
        cout << "Entrada no válida. Por favor, ingrese solo 'M' o 'F': " << endl;
        cin >> auxC->genero;
    }
    if (auxC->genero == 'M') {
    conM++;
        } 
        else if (auxC->genero  == 'F') {
     conF++;
             }
     
       if (conM - conF > 4 || conF - conM > 4) {
    cout << "Lo siento, pero ya no podemos añadir más personas a la fila." << endl;
    return;
     }
    cin.ignore();
    cout<<"Por favor, diganos el motivo por el cual realiza la llamada: " <<endl;
    cin.getline(auxC->motivo, 50);
    cont++;
    auxC->id=cont;
    auxC->sig = NULL;

    if (cab == NULL) {
        cab = auxC;
    }
      else {
        aux2C = cab;
        while (aux2C->sig != NULL) {
            aux2C = aux2C->sig;
        }
        if (aux2C != NULL) {
            aux2C->sig = auxC;
        }

     }  
        
}

void despachar(){
    if(cab){
        auxA= (struct clienteAtendido* ) malloc (sizeof(clienteAtendido)); /*pedimos tamaño para la estructura */
        strcpy(auxA->nombreA,cab->nombre);
        strcpy(auxA->motivoA,cab->motivo);
        auxA->generoA=cab->genero;
        auxA->edadA=cab->edad;
        auxA->idA=cab->id;

        if(cabA==NULL){
         cabA = auxA;
         cabA->sig=NULL;
        } else{
        auxA->sig = cabA; 
        cabA=auxA;
        }
        aux = cab;
        cab = cab->sig; 
        free(aux); 
            cout<<"El cliente ha sido atentido." <<endl;

    }else{
        cout<<"No hay clientes por atender." <<endl;
        return;
    }
}

void retroceso(){
    if(cabA){
        auxC= (struct cliente* ) malloc (sizeof(cliente)); /*pedimos tamaño para la estructura */
        strcpy(auxC->nombre,cabA->nombreA);
        strcpy(auxC->motivo,cabA->motivoA);
        auxC->genero=cabA->generoA;
        auxC->edad=cabA->edadA;
        auxC->id=cabA->idA;
        auxC->sig = NULL;

        if (cab == NULL) {
            cab = auxC;
        } else {
            aux2C = cab;
            while (aux2C->sig != NULL) {
                aux2C = aux2C->sig;
            }
            aux2C->sig = auxC;
        }
        
        // Eliminar de la lista de atendidos
        auxA = cabA;
        cabA = cabA->sig;
        free(auxA);
        
            cout<<"El cliente ha sido devuelto a la cola de espera." <<endl;
            return;

    }else{
        cout<<"No hay clientes por devolver." <<endl;
        return;
    }
}
    



void historial(){
    auxA=cabA;
    while(auxA!=NULL) {
        cout<<"El cliente es: " <<auxA->nombreA<<", es: " <<auxA->generoA<<endl<<" y su edad es: " <<auxA->edadA<<endl<<"su identificador es: " <<auxA->idA<<endl<<"el motivo es: " <<auxA->motivoA<<endl;
        auxA = auxA->sig;
    }
  }

  void mostrar(){
    auxC=cab;
    while(auxC!=NULL) {
        cout<<"El cliente es: " <<auxC->nombre<<", es: " <<auxC->genero<<endl<<" y su edad es: " <<auxC->edad <<endl<<"su identificador es: " <<auxC->id<<endl<<"el motivo es: " <<auxC->motivo<<endl;
        auxC = auxC->sig;
    }
}





void contador (){
    if (cab == NULL) {
cout << "No hay clientes registrados."<<endl;
return;
}

int c=0;
    auxC=cab;
    while(auxC!=NULL){
    c++;
    auxC=auxC->sig;
    }
    cout<<"La cantidad de clientes en espera es: "<< c <<endl;     
/*Con un  while iterar sobre la  la estructura de nodos y usamos un contador que aumente 1 por cada cliente */
}

void liberarMemoria() {
    // Liberar clientes en espera
    while (cab != NULL) {
        auxC = cab;
        cab = cab->sig;
        free(auxC);
    }
    
    // Liberar clientes atendidos
    while (cabA != NULL) {
        auxA = cabA;
        cabA = cabA->sig;
        free(auxA);
    }
}



int main(){
        int opcion=0;
    do {
      cout<<"Menu"<<endl<<"1. Ingresar cliente"<<endl<<"2. Mostrar clientes"<<endl<<"3. Atender Cliente"<<endl<<"4. Historial de atención"<<endl<<"5. Cantidad de clientes en espera"<<endl<<"6. Deshacer última atención "<<endl; 
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            registrar();
        break;
        case 2:
            mostrar();
        break;
        
        case 3:
            despachar ();
        break;
        
        case 4:
        historial ();
        break;
        
        case 5:
        contador (); 
        break;

        case 6:
        retroceso ();
        break;
        case 7:
        liberarMemoria();
        

        }
    }while(opcion!=7);

    

    return 0; 
}
/* Renteria Renteria Isabela*/
/* Rodallega Cuellar Allison Ayana*/

#include <iostream>
#include <malloc.h>
using namespace std;

int cont=10230; /* declaramos el contador para el id */

struct producto {
    int id;
    char Nombre[30]; /*se intentó usar string...no pudimos*/
    producto *sig;
};

producto cabPro, *auxPro, *aux2Pro, *auxAn,*aux; /*declaración de apuntadores */

void registrar(){
    auxPro = (struct producto ) malloc (sizeof(producto)); /*pedimos tamaño para la estructura */
    cout<<"Ingrese el nombre del producto: " <<endl;
    cin>>auxPro->Nombre;
    cont++;
    auxPro->id=cont;
/* Una vez agregamos un nuevo producto este apunta a siguiente que es nada */
    auxPro->sig = NULL;
   /*Se ve si hay más, si no se ubica el recién ingresado como nuevo y si hay más se busca el último y se conecta al ultimo*/
 if(!cabPro){
        cabPro = auxPro;
    } else {
        aux2Pro=cabPro;
        while(aux2Pro->sig!=NULL){
            aux2Pro = aux2Pro->sig;
        }
        aux2Pro->sig = auxPro;
    }
}

void mostrar(){
    auxPro=cabPro;
    while(auxPro!=NULL){
        cout<<"El producto es: " <<auxPro->Nombre<<endl<<"y su id es: " <<auxPro->id <<endl;
        auxPro = auxPro->sig;
    }
/* En esta se usa un ciclo while para iterar sobre la estructura y se van representando cada uno de los nodos*/
}

void buscar() {
    int semilla;
    cout << "Ingrese el ID del producto que quiere buscar:" << endl;
    cin >> semilla;
    auxPro = cabPro;

    while (auxPro != NULL && auxPro->id != semilla) {
        auxPro = auxPro->sig;
    }

    if (auxPro != NULL) {
        cout << "Producto encontrado y su nombre es: " << auxPro->Nombre << endl;
    } else {
        cout << "Producto no encontrado." << endl;
    }
/* Funciona casi igual como la función de buscar pero con una semilla como condición, además de un if */
}

void modificar(){
int idb;
    cout<<"Ingresé el ID del producto que quiere modificar" <<endl;
    cin >>idb;
    auxPro=cabPro;
    while(auxPro!= NULL && auxPro->id !=idb){
        auxPro= auxPro ->sig;

    }
       if (idb==auxPro->id){
            cout<<"El nombre del producto es: "<<auxPro->Nombre <<endl;
            cout<<"Ingrese el nombre nuevo: " <<endl;
            cin>>auxPro->Nombre;
        }else {
            cout<<"Producto no  encontrado. " <<endl;
        } 
        /*Está implementa la función para buscar con una semilla para así saber que se quiere modificar al final se guarda el nuevo del nodo*/
}


void eliminar (){
int seed;
    cout<<"Ingresé el ID del producto que quiere eliminar:" <<endl;
    cin >>seed;
    aux=cabPro;
    while(aux!= NULL && aux->id !=seed){
        auxAn = aux;
        aux= aux ->sig;
    }
    if (aux==cabPro){
        cabPro=aux->sig;
    }else {
    auxAn->sig= aux->sig;
    }
         free(aux);
         aux=NULL;
        cout<<"Se elimino correctamente." <<endl;
}


void contador (){
    if (cabPro == NULL) {
cout << "No hay productos registrados.";
return;
}

int c=0;
    auxPro=cabPro;
    while(auxPro!=NULL){
    c++;
    auxPro=auxPro->sig;
    }
    cout<<"La cantidad de productos registrados es: "<<c <q<endl;     
/*Con un  while iterar sobre la  la estructura de nodos y usamos un contador que aumente 1 por cada producto */
}

void liberarMemoria() {
    auxPro = cabPro;
    while (auxPro != NULL) {
        aux2Pro = auxPro->sig; 
        free(auxPro);       
        auxPro = aux2Pro;     
    }
    cabPro = NULL; 
    cout << "Memoria liberada correctamente." << endl;
}


int main(){
    int opcion;
    do {
      cout<<"Menu"<<endl<<"1. Insertar Datos"<<endl<<"2. Mostrar Datos"<<endl<<"3. Buscar"<<endl<<"4. Contar"<<endl<<"5. Eliminar"<<endl<<"6. Modificar"<<endl;
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
            buscar ();
        break;
        
        case 4:
        contador();
        break;
        
        case 5:
        eliminar();
        
        break;
        
        case 6:
        modificar();
        
        break;
        
        }
    }while(opcion!=7);

    liberarMemoria (); 

    return 0; 
}
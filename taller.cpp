#include <iostream>
#include <cstring>
using namespace std;

struct pelicula {
    char nombre[50];
    char genero[30];
    float dinero;
    int fecha;
    struct pelicula *izq;
    struct pelicula *der;
};

pelicula* f1 = NULL;
pelicula* f2 = NULL;
pelicula* f3 = NULL;

char pelib[50];
char gen[30];

struct pelicula *raiz=NULL, *aux,*aux2 ;

void posicionarpelicula(){
    if(aux->fecha <= aux2->fecha){
        if(aux2->izq != NULL) {
            aux2 = aux2->izq;
            posicionarpelicula();
        } else {
            aux2->izq = aux;
        }
    }else {
        if(aux2->der != NULL) {
            aux2 = aux2->der;
            posicionarpelicula();
        } else {
            aux2->der = aux;
        }


    }
}

void adicionarpelicula(){
    aux = (struct pelicula *) malloc(sizeof(struct pelicula));
    aux->izq = aux->der = NULL;
    cout<<"Ingrese el nombre de la pelicula:";
    cin.getline(aux->nombre, 50);
    cout<<"Ingrese el genero de la pelicula:";
    cin.getline(aux->genero, 30);
    cout<<"Ingrese el año en el que salio la pelicula:";
    cin>>aux->fecha;
    cout<<"Ingrese el valor de recaudo de la pelicula en millones de dolares:";
    cin>>aux->dinero;
    if(raiz==NULL){
        raiz = aux;
        aux = NULL;
        free(aux);
    }
    else {
        aux2 =raiz;
        posicionarpelicula();
    }
}
int buscar(struct pelicula *nuevaR){

    if(nuevaR->izq!=NULL){
        buscar(nuevaR->izq);
    }
    
     if(nuevaR->der!=NULL){
        buscar(nuevaR->der);  
    }
    return 0;
}
int preorden(struct pelicula *nuevaRaiz){

    
    cout<<"nombre de la pelicula: "<<nuevaRaiz->nombre<<endl;
    cout<<"genero de la pelicula: "<<nuevaRaiz->genero<<endl;
    cout<<"año de publicacion de la pelicula: "<<nuevaRaiz->fecha<<endl;
    cout<<" recaudo de la pelicula en millones: "<<nuevaRaiz->dinero<<endl;
    
    if(nuevaRaiz->izq!=NULL){
        preorden(nuevaRaiz->izq);
    }
    
     if(nuevaRaiz->der!=NULL){
        preorden(nuevaRaiz->der);  
    }
    return 0;
}
int inorden(struct pelicula *nuevaRaiz){

    if(nuevaRaiz->izq!=NULL){
        inorden(nuevaRaiz->izq);
    }
    cout<<"nombre de la pelicula: "<<nuevaRaiz->nombre<<endl;
    cout<<"genero de la pelicula: "<<nuevaRaiz->genero<<endl;
    cout<<"año de publicacion de la pelicula: "<<nuevaRaiz->fecha<<endl;
    cout<<" recaudo de la pelicula en millones: "<<nuevaRaiz->dinero<<endl;
    
    
    if(nuevaRaiz->der!=NULL){
        inorden(nuevaRaiz->der);  
    }
    return 0;
}
int postorden(struct pelicula *nuevaRaiz){

    if(nuevaRaiz->izq!=NULL){
        postorden(nuevaRaiz->izq);
    }
    
    if(nuevaRaiz->der!=NULL){
        postorden(nuevaRaiz->der);  
    }
    cout<<"nombre de la pelicula: "<<nuevaRaiz->nombre<<endl;
    cout<<"genero de la pelicula: "<<nuevaRaiz->genero<<endl;
    cout<<"año de publicacion de la pelicula: "<<nuevaRaiz->fecha<<endl;
    cout<<" recaudo de la pelicula en millones: "<<nuevaRaiz->dinero<<endl;
    return 0;
}
void buscarpornombre(pelicula* ayd) {
    if (ayd != NULL){
    if (strcmp(pelib, ayd->nombre) == 0) {
        cout << "Nombre de la película: " << ayd->nombre << endl;
        cout << "Género de la película: " << ayd->genero << endl;
        cout << "Año de publicación de la película: " << ayd->fecha << endl;
        cout << "Recaudación de la película: " << ayd->dinero << endl;
    }
    buscarpornombre(ayd->izq);
    buscarpornombre(ayd->der);


    }
 
}


void procesogenero(pelicula* ayd ){
    if (ayd == NULL) return;


    if (strcmp(gen, ayd->genero) == 0) {
        cout << "Nombre de la película: " << ayd->nombre << endl;
        cout << "Año de publicación de la película: " << ayd->fecha << endl;
        cout << "recaudacion de la película: " << ayd->dinero << endl;

    }


procesogenero(ayd->izq);
procesogenero(ayd->der);
}
void buscarporgenero(pelicula* raiz) {

    cout << "Ingrese el genero de película que desea buscar: ";
    cin.getline(gen, 50);
    procesogenero(raiz);

    
}



void encontrarTresfracs(pelicula* raiz) {
    if (raiz == NULL)
        return;

    if (f1 == NULL || raiz->dinero < f1->dinero) {
        f3 = f2;
        f2 = f1;
        f1 = raiz;
    } else if (f2 == NULL || raiz->dinero < f2->dinero) {
        f3 = f2;
        f2 = raiz;
    } else if (f3 == NULL || raiz->dinero < f3->dinero) {
        f3 = raiz;
    }

    encontrarTresfracs(raiz->izq);
    encontrarTresfracs(raiz->der);
}


int main(){
    int opcion=0;
    do {
        cout<<"1. Registrar"<<endl;
        cout<<"2. preorden"<<endl;
        cout<<"3. inorden"<<endl;
        cout<<"4. postsorden"<<endl;
        cout<<"5. busqueda por nombre"<<endl;
        cout<<"6. busqueda por genero"<<endl;
        cout<<"7. presentar las peliculas con menos recauidacion"<<endl;
        cout<<"8. salir"<<endl;
        cout<<"Digite la opción: ";
        cin>>opcion;
        cin.ignore();
        
     switch(opcion){
            case 1: adicionarpelicula(); break;
            case 2: preorden(raiz); break;
            case 3: inorden(raiz); break;
            case 4: postorden(raiz); break;
            case 5 :
            cout << "Ingrese el nombre de la película que desea buscar: ";
            cin.getline(pelib, 50);
            buscarpornombre(raiz);
             break;
            case 6 : buscarporgenero(raiz); break;
            case 7: 
            encontrarTresfracs(raiz);
            
        cout  << "1. Nombre de la película: " << f1->nombre << endl;
        cout << "recaudacion: " << f1->dinero << endl;
        cout  << "2. Nombre de la película: " << f2->nombre << endl;
        cout << "recaudacion: " << f2->dinero << endl;
        cout  << "3. Nombre de la película: " << f3->nombre << endl;
        cout << "recaudacion: " << f3->dinero << endl;
        break;
        case 8: 
        cout<<"programa cerrado con exito"<<endl; break;

        }
    }while(opcion!=8);
}
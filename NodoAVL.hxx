#include "NodoAVL.h"

template< class T >
NodoAVL<T>::NodoAVL(T &val){
    this->dato = val;
    this->hijoIzq = NULL;
    this->hijoDer = NULL;  
}

template< class T >
T& NodoAVL<T>::obtenerDato(){
    return this->dato;
}

template< class T >
void NodoAVL<T>::fijarDato(T &val){
    this->dato = val;
}

template< class T >
NodoAVL<T>* NodoAVL<T>::obtenerHijoIzq(){
    return this->hijoIzq;
}

template< class T >
NodoAVL<T>* NodoAVL<T>::obtenerHijoDer(){
    return this->hijoDer;
}

template< class T >
void NodoAVL<T>::fijarHijoIzq(NodoAVL<T> *izq){
    this->hijoIzq = izq;
}

template< class T >
void NodoAVL<T>::fijarHijoDer(NodoAVL<T> *der){
    this->hijoDer = der;
}

template< class T >
bool NodoAVL<T>::esHoja(){
    return (this->hijoIzq == NULL && this->hijoDer == NULL);
}

template< class T >
int NodoAVL<T>::altura(){

    int valAlt;
    if (this->esHoja()){
        valAlt = 0;
    } else {
        int valAlt_izq = -1;
        int valAlt_der = -1;
        if (this->hijoIzq != NULL){
            valAlt_izq = (this->hijoIzq)->altura();
        }
        if (this->hijoDer != NULL){
            valAlt_der = (this->hijoDer)->altura();
        }
        
        if (valAlt_izq > valAlt_der){
            valAlt = valAlt_izq + 1;
        } else {
            valAlt = valAlt_der + 1;
        }
    }

    return valAlt;
}

template < class T >
unsigned int NodoAVL<T>::tamano(){
    //Nodo actual
    int contador = 1;
    if (this->hijoIzq != NULL)
        contador += (this->hijoIzq)->tamano();
    if (this->hijoDer != NULL)
        contador += (this->hijoDer)->tamano();
    return contador;
}

template < class T >
void NodoAVL<T>::preOrden(){
    std::cout<<this->dato<<" ";

    if (this->hijoIzq != NULL)
        (this->hijoIzq)->preOrden();
    if (this->hijoDer != NULL)
        (this->hijoDer)->preOrden();
}

template < class T >
void NodoAVL<T>::posOrden(){
    if (this->hijoIzq != NULL)
        (this->hijoIzq)->posOrden();
    if (this->hijoDer != NULL)
        (this->hijoDer)->posOrden();

    std::cout<<this->dato<<" ";
}

template < class T >
void NodoAVL<T>::inOrden(){
    if (this->hijoIzq != NULL)
        (this->hijoIzq)->inOrden();
    std::cout<<this->dato<<" ";
    if (this->hijoDer != NULL)
        (this->hijoDer)->inOrden();
}

template < class T >
void NodoAVL<T>::inordenEnLista(std::list<T> TList){
    if (this->hijoIzq != NULL)
        (this->hijoIzq)->inordenEnLista(TList);
    TList.push_back(this->dato);
    if (this->hijoDer != NULL)
        (this->hijoDer)->inordenEnLista(TList);    
}

template < class T >
NodoAVL<T>* NodoAVL<T>::obtenerMaximo(){
    NodoAVL<T>* nodoActual = this;
    
    // Recorrer hacia la derecha hasta encontrar el nodo más grande
    while (nodoActual->hijoDer != NULL) {
        nodoActual = nodoActual->hijoDer;
    }
    
    return nodoActual;
}

template < class T >
NodoAVL<T>* NodoAVL<T>::rotacionIzq(){
    NodoAVL<T>* padre = this->hijoDer;
    this->hijoDer = padre->hijoIzq;
    padre->fijarHijoIzq(this);
    return padre;
}

template < class T >
NodoAVL<T>* NodoAVL<T>::rotacionDer(){
    NodoAVL<T>* padre = this->hijoIzq;
    this->hijoIzq = padre->hijoDer;
    padre->fijarHijoDer(this);
    return padre;
}

template < class T >
NodoAVL<T>* NodoAVL<T>::rotacionIzqDer(){
    NodoAVL<T>* aux = (this->hijoIzq)->rotacionIzq();
    this->hijoIzq = aux;
    return this->rotacionDer();
}

template < class T >
NodoAVL<T>* NodoAVL<T>::rotacionDerIzq(){
    NodoAVL<T>* aux = (this->hijoDer)->rotacionDer();
    this->hijoDer = aux;
    return this->rotacionIzq();
}

template < class T >
int NodoAVL<T>::difAlturas(){
    int alturaDer = -1, alturaIzq = -1;

    if (this->hijoIzq != NULL) {
        alturaIzq = (this->hijoIzq)->altura();
    }

    if (this->hijoDer != NULL) {
        alturaDer = (this->hijoDer)->altura();
    }

    return alturaIzq - alturaDer;
}
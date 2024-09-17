#include "ArbolAVL.h"
#include <queue>


template < class T >
ArbolAVL<T>::ArbolAVL(){
    this->raiz = NULL;
}

template < class T >
ArbolAVL<T>::~ArbolAVL(){
    if (this->raiz != NULL) {
        delete this->raiz;
        this->raiz = NULL;
    }
}

template < class T >
bool ArbolAVL<T>::esVacio(){
    return this->raiz == NULL;
}
template < class T >
T& ArbolAVL<T>::datoRaiz(){
    return (this->raiz)->obtenerDato();
}

//Recursiva
template < class T >
int ArbolAVL<T>::altura(){
    if(this->esVacio()){
        return -1;
    }
    else{
        return (this->raiz)->altura();
    }
}

//Recursiva
template < class T >
unsigned int ArbolAVL<T>::tamano(){
  // si esta vacio, retornar 0
    if (this->esVacio())
        return 0;
    
    int tam = 0;

    tam += (this->raiz)->tamano();

    return tam;
}


template < class T >
bool ArbolAVL<T>::insert(T &val){
    bool insertado = false;
    this->raiz = insert(this->raiz, val, insertado);
    return insertado;
}

//Recurrente
template < class T >
NodoAVL<T>* ArbolAVL<T>::insert(NodoAVL<T>* nodo,T& val, bool& insertado){
    //Caso base
    if (nodo == NULL) {
        insertado = true;
        NodoAVL<T>* nodoIns = new NodoAVL<T>(val);
        return nodoIns;
    }

    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(insert(nodo->obtenerHijoIzq(), val, insertado));
    } else if (val > nodo->obtenerDato()) {
        nodo->fijarHijoDer(insert(nodo->obtenerHijoDer(), val, insertado));
    } else {
        insertado = false;
        return nodo;
    }
    return balancear(nodo);   
}

//Recurrente
template < class T >
bool ArbolAVL<T>::remove(T &val){
  bool eliminado = false;
  this->raiz = remove(this->raiz, val, eliminado);
  return eliminado;
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::remove(NodoAVL<T>* nodo, T& val, bool& eliminado) {
    //Caso base
    if (nodo == NULL) {
        eliminado = false;
        return nodo;
    }

    //Ir por el lado Izquierdo
    if (val < nodo->obtenerDato()) {
        nodo->fijarHijoIzq(remove(nodo->obtenerHijoIzq(), val, eliminado));
    } else if (val > nodo->obtenerDato()) { //Ir por el lado derecho
        nodo->fijarHijoDer(remove(nodo->obtenerHijoDer(), val, eliminado));
    } else {
        //Encontro al nodo
        eliminado = true;
        NodoAVL<T>* aux;
        //Caso I: Nodo Hoja
        if(nodo->esHoja()){
        delete nodo;
        return NULL;
        } //Caso II: Nodo con un hijo
        else if (nodo->obtenerHijoDer() == NULL) {
            aux = nodo->obtenerHijoIzq();
            delete nodo;
            return aux;    
        } else if (nodo->obtenerHijoIzq() == NULL){
            aux = nodo->obtenerHijoDer();
            delete nodo;
            return aux;
        } //Caso III: Nodo con dos hijos
        else {
            aux = (nodo->obtenerHijoIzq())->obtenerMaximo();
            nodo->fijarDato(aux->obtenerDato());
            nodo->fijarHijoIzq(remove(nodo->obtenerHijoIzq(), aux->obtenerDato(), eliminado));
        }
    }
    //Balancear a medida que avanza
    return balancear(nodo);
}

//Iterativa
template < class T >
bool ArbolAVL<T>::search(T &val){
    NodoAVL<T>* nodo = this->raiz;
    bool encontrado = false;

    while (nodo != NULL && !encontrado){
        if (val < nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoIzq();
        } else if (val > nodo->obtenerDato()) {
            nodo = nodo->obtenerHijoDer();
        } else {
            encontrado = true;
        }
    }

    return encontrado;
}

//Recurrente
template < class T >
void ArbolAVL<T>::preOrden(){
    if (!this->esVacio()) {
        (this->raiz)->preOrden();
    }
}

//Recurrente
template < class T >
void ArbolAVL<T>::posOrden(){
    if (!this->esVacio()) {
        (this->raiz)->posOrden();
    }
}

//Recurrente
template < class T >
void ArbolAVL<T>::inOrden(){
    if (!this->esVacio()) {
        (this->raiz)->inOrden();
    }
}

template < class T>
void ArbolAVL<T>::inordenEnLista(std::list<T> TList){
    if (!this->esVacio()) {
        (this->raiz)->inordenEnLista(TList);
    }
}

//Iterativa
template < class T >
void ArbolAVL<T>::nivelOrden(){
    if (!this->esVacio()) {
        std::queue<NodoAVL<T>*> cola;
        cola.push(this->raiz);
        NodoAVL<T>* nodo;
        // hacer un ciclo mientar haya algo en la cola
        while (!cola.empty()) {
            nodo = cola.front();
            cola.pop();
            std::cout<<nodo->obtenerDato()<<" ";
            if (nodo->obtenerHijoIzq() != NULL) {
                cola.push(nodo->obtenerHijoIzq());
            }
            if (nodo->obtenerHijoDer() != NULL) {
                cola.push(nodo->obtenerHijoDer());
            }
        }
    }
}

template <class T>
NodoAVL<T>* ArbolAVL<T>::balancear(NodoAVL<T> *nodo) {
    int dif = nodo->difAlturas();
    // Si el subárbol está desbalanceado (|dif| > 1)
    if (dif == 2) {
        NodoAVL<T>* n1 = nodo->obtenerHijoIzq();
        // Subárbol izquierdo más alto (rotaciones hacia la derecha)
        if (n1->difAlturas() < 0) {
            // Caso de rotación Izquierda-Derecha
            return nodo->rotacionIzqDer();
        } else if (n1->difAlturas() > 0) {
            // Caso de rotación Derecha
            return nodo->rotacionDer();
        }

    } else if (dif == -2) {
        NodoAVL<T>* n2 = nodo->obtenerHijoDer();
        // Subárbol derecho más alto (rotaciones hacia la izquierda)
        if (n2->difAlturas() > 0) {
            // Caso de rotación Derecha-Izquierda
            return nodo->rotacionDerIzq();
        } else if (n2->difAlturas() < 0) {
            // Caso de rotación Izquierda
            return nodo->rotacionIzq();
        }
    }
    return nodo;
}

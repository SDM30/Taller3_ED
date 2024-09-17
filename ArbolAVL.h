#ifndef __ARBOLAVL__H__
#define __ARBOLAVL__H__

#include "NodoAVL.h"
#include <stack>
#include <list>

template <class T> 
class ArbolAVL {
  protected:
    NodoAVL<T> *raiz;
  public:
    ArbolAVL();
    ~ArbolAVL();
    bool esVacio();
    T &datoRaiz();
    int altura();
    unsigned int tamano();
    bool insert(T &val);
    NodoAVL<T>* insert(NodoAVL<T>* nodo,T& val, bool& insertado);
    bool remove(T &val);
    NodoAVL<T>* remove(NodoAVL<T>* nodo, T& val, bool& eliminado);
    bool search(T &val);
    void preOrden();
    void posOrden();
    void inOrden();
    void inordenEnLista(std::list<T> TList);
    void nivelOrden();
    NodoAVL<T>* balancear(NodoAVL<T> *nodo);
};

#include "ArbolAVL.hxx"

#endif
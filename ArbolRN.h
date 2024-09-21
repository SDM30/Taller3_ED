#ifndef __ARBOLRN__H__
#define __ARBOLRN__H__

#include <set>
#include <list>

template <typename T>
class ArbolRN {
private:
    std::set<T> set;  // El set esta encapsulado
public:
    // Buscar un valor en el set
    T search(const T& val);  // Devuelve el valor en lugar del iterador

    bool remove(const T& val);

    // Obtener los elementos del set en orden inorden usando una lista
    std::list<T> inordenEnLista() const;
}

#include "ArbolRN.hxx"

#endif

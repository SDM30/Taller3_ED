#ifndef __ARBOLRN__H__
#define __ARBOLRN__H__

#include <set>
#include <list>

template <typename T>
class ArbolRN {
protected:
    std::set<T> set;  // El set esta encapsulado
public:
    bool insert(const T& val);

    bool search(const T& val);

    bool remove(const T& val);

    void inordenEnLista(std::list<T>& resultado) const;
};

#include "ArbolRN.hxx"

#endif

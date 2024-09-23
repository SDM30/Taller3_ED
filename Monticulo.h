#ifndef __MONTICULO__H__
#define __MONTICULO__H__
#include <algorithm>
#include <vector>
#include <list>

template<class T>
class Monticulo {
    protected:
      std::vector<T> vec;
    public:
        Monticulo();
        bool insert(const T& val);
        bool remove(const T & val);
        bool search(const T& val) const;
        int tamano() const;
        void inordenEnLista(std::list<T>& resultado) const;

};

#include "Monticulo.hxx"

#endif

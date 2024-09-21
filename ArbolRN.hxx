#include "ArbolRN.h"

// Buscar un valor en el set
template <typename T>
T ArbolRN<T>::search(const T& val) {
    auto it = set.find(val);
    if (it != set.end()) {
        return *it;  // Devolver el valor al que apunta el iterador
    } else { //En caso de que el valor no este en el arbol.
        throw std::runtime_error("Valor no encontrado en el ArbolRN.");
    }
}

// Eliminar un valor del set
template <typename T>
bool ArbolRN<T>::remove(const T& val) {
    //Si devuelve 1 fue eliminado de lo contrario no fue eliminado
    return set.erase(val) > 0;
}

template <typename T>
std::list<T> ArbolRN<T>::inordenEnLista() const {
    std::list<T> resultado;
    for (const T& elem : set) {
        resultado.push_back(elem);  // Los elementos ya están en orden inorden
    }
    return result;
}

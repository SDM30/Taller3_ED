#include "ArbolRN.h"

template <typename T>
bool ArbolRN<T>::insert(const T& val) {
    auto result = set.insert(val);  // Intenta insertar el valor
    return result.second;  // Retorna true si fue insertado, false si ya existia
}

// Buscar un valor en el set
template <typename T>
bool ArbolRN<T>::search(const T& val) {
    auto it = set.find(val);
    return it != set.end();  // Retorna true si encuentra el valor, false si no
}

// Eliminar un valor del set
template <typename T>
bool ArbolRN<T>::remove(const T& val) {
    //Si devuelve 1 fue eliminado de lo contrario no fue eliminado
    return set.erase(val) > 0;
}

template <typename T>
void ArbolRN<T>::inordenEnLista(std::list<T>& resultado) const {
    for (const T& elem : set) {
        resultado.push_back(elem);  // Los elementos ya estan en orden inorden
    }
}

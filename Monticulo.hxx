#include "Monticulo.h"

template<class T>
Monticulo<T>::Monticulo(){

}

template<class T>
bool Monticulo<T>::insert(const T& val){
    vec.push_back(val);
    std::push_heap(vec.begin(), vec.end());
    return true;
}

template<class T>
bool Monticulo<T>::remove(const T& val) {
    auto it = std::find(vec.begin(), vec.end(), val);
    if (it != vec.end()) {
        std::swap(*it, vec.back());
        vec.pop_back();
        if (!vec.empty()) {
            std::make_heap(vec.begin(), vec.end()); // Solo rehacer el heap si no está vacío
        }
        return true;
    }
    return false;
}

template<class T>
bool Monticulo<T>::search(const T& val) const {
   return std::find(vec.begin(), vec.end(), val) != vec.end();
}

template<class T>
int Monticulo<T>::tamano() const {
    return vec.size();
}

template<class T>
void Monticulo<T>::inordenEnLista(std::list<T>& resultado) const {
    // Crear una copia del montículo
    std::vector<T> copia = vec;
    
    // Ordenar la copia para obtener los elementos en orden
    std::sort(copia.begin(), copia.end());
    
    // Insertar los elementos en la lista
    for (const T& elem : copia) {
        resultado.push_back(elem);
    }
}

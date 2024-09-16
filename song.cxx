#include "song.h"

// Constructor
// Constructor
Song::Song(std::string id, std::string name, std::string genre,
           std::string artists, std::string album,
           int popularity, int durationMs, bool explicitContent)
    : id(id), nombre(name), genero(genre), artistas(artists),
      album(album), popularidad(popularity),
      duracion_ms(durationMs), expl(explicitContent) {}

Song::Song()
    : id(""), nombre(""), genero(""), artistas(""),
      album(""), popularidad(0),
      duracion_ms(0), expl(false) {}

// Getters
// TODO #4: Implementar las funciones getters de cada uno de los campos que definen una cancion. (Total de getters: 8)
std::string Song::obtenerId() { 
return id; 
}
std::string Song::obtenerNombre() { 
return nombre; 
}
std::string Song::obtenerGenero() { 
    return genero; 
}
std::string Song::obtenerArtistas() { 
    return artistas; 
}
std::string Song::obtenerAlbum() { 
    return album; 
}
unsigned int Song::obtenerPopularidad() { 
    return popularidad; 
}
unsigned int Song::obtenerDuracion() { 
    return duracion_ms; 
}
bool Song::obtenerExpl() { 
    return expl; 
}
// Setters
// TODO #5: Implementar las funciones setters de cada uno de los campos que definen una cancion. (Total de setters: 8)
void Song::fijarId(std::string nuevoId) { 
    this->id = nuevoId; 
}

void Song::fijarNombre(std::string nuevoNombre) { 
    nombre = nuevoNombre; 
}

void Song::fijarGenero(std::string nuevoGenero) { 
    genero = nuevoGenero; 
}

void Song::fijarArtistas(std::string nuevosArtistas) { 
    artistas = nuevosArtistas; 
}

void Song::fijarAlbum(std::string nuevoAlbum) { 
    album = nuevoAlbum; 
}

void Song::fijarPopularidad(unsigned int nuevaPopularidad) { 
    popularidad = nuevaPopularidad; 
}

void Song::fijarDuracion(unsigned int nuevaDuracion) { 
    duracion_ms = nuevaDuracion; 
}

void Song::fijarExpl(bool nuevaExp) { 
    expl = nuevaExp; 
}
// Overloaded operators
// TODO #6: Implementar las funciones de sobrecarga de operadores >, < e ==.
bool Song::operator>(const Song& other) const {
    return this->id > other.id;
}
bool Song::operator<(const Song& other) const {
    return this->id < other.id;
}
bool Song::operator==(const Song& other) const {
    return this->id == other.id;
}

std::ostream &operator<<( std::ostream& cout, Song& song) {

    cout << "ID: " << song.obtenerId() << std::endl;
    return cout;
}
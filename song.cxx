#include "song.h"

// Constructor
// Constructor
Song::Song(int id, std::string name, std::string genre,
           std::string artists, std::string album,
           int popularity, int durationMs, bool explicitContent)
    : id(id), nombre(name), genero(genre), artistas(artists),
      album(album), popularidad(popularity),
      duracion_ms(durationMs), expl(explicitContent) {}

// Getters
// TODO #4: Implementar las funciones getters de cada uno de los campos que definen una cancion. (Total de getters: 8)

// Setters
// TODO #5: Implementar las funciones setters de cada uno de los campos que definen una cancion. (Total de setters: 8)

// Overloaded operators
// TODO #6: Implementar las funciones de sobrecarga de operadores >, < e ==.
bool Song::operator>(const Song& other) const {
    return true;
}

bool Song::operator<(const Song& other) const {
    return true;
}

bool Song::operator==(const Song& other) const {
    return true;
}
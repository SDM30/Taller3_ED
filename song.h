#ifndef SONG_H
#define SONG_H

#include <string>
#include <vector>

class Song {
    public:
    // Constructor
    Song(int id, std::string name, std::string genre,
         std::string artists, std::string album,
         int popularity, int durationMs, bool explicitContent);

    // Getters
    // TODO #2: Definir las funciones getters de cada uno de los campos que definen una cancion. (Total de getters: 8)
        int obtenerId();
        std::string obtenerNombre();
        std::string obtenerGenero();
        std::string obtenerArtistas();
        std::string obtenerAlbum();
        unsigned int obtenerPopularidad();
        unsigned int obtenerDuracion();
    // Setters
    // TODO #3: Definir las funciones setters de cada uno de los campos que definen una cancion. (Total de setters: 8)
        void fijarId(int nuevoId);
        void fijarNombre(std::string nuevoNombre);
        void fijarGenero(std::string nuevoGenero);
        void fijarArtistas(std::string nuevosArtistas);
        void fijarAlbum(std::string nuevoAlbum);
        void fijarPopularidad(unsigned int nuevaPopularidad);
        void fijarDuracion(unsigned int nuevaDuracion);
        void fijarExpl(bool nuevaExp);

    // Overloaded operators
    bool operator>(const Song& other) const;
    bool operator<(const Song& other) const;
    bool operator==(const Song& other) const;

    private:
    // TODO #1: Definir cada uno de los campos de la cancion. (Total de campos: 8)
        int id;
        std::string nombre;
        std::string genero;
        std::string artistas;
        std::string album;
        unsigned int popularidad;
        unsigned int duracion_ms;
        bool expl;
};

#endif // SONG_H
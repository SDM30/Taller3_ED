#ifndef __SONG__H__
#define __SONG__H__
#include <string>

class song {
    protected:
        std::string id;
        std::string nombre;
        std::string genero;
        std::string artista;
        std::string album;
        unsigned int popularidad;
        unsigned int duracion_ms;
        bool expl;
    public:
        song(std::string id, std::string nombre, std::string genero, std::string artista, 
             std::string album, unsigned int popularidad, unsigned int duracion_ms,bool expl);
        //Getters
        std::string obtenerId();
        std::string obtenerNombre();
        std::string obtenerGenero();
        std::string obtenerArtista();
        std::string obtenerAlbum();
        unsigned int obtenerPopularidad();
        unsigned int obtenerDuracion();
        bool obtenerExpl();
        //Setters
        void fijarId(std::string nuevoId);
        void fijarNombre(std::string nuevoNombre);
        void fijarGenero(std::string nuevoGenero);
        void fijarArtista(std::string nuevoArtista);
        void fijarAlbum(std::string nuevoAlbum);
        void fijarPopularidad(unsigned int nuevaPopularidad);
        void fijarDuracion(unsigned int nuevaDuracion);
        void fijarExpl(bool nuevaExp);
};

#endif
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <list>

#include "song.h"

// TODO #7: incluir cabecera arbol AVL
#include "ArbolAVL.h"
// TODO #8: incluir cabecera arbol RN a utilizar
// #include <set>
// #include <map>
// TODO #9: incluir cabecera monticulo
// #include "monticulo.h"

// -------------------------------------------------------------------------
typedef std::list< Song > TList;

// TODO #10: definir nombre alternativo para arbol AVL de tipo Song
typedef ArbolAVL< Song > TAVL;
// TODO #11: definir nombre alternativo para arbol RN de tipo Song
// typedef std::set< Song >  TSet;
// typedef std::map< std::string, Song >  TMap;
// TODO #12: definir nombre alternativo para monticulo de tipo Song
// typedef monticulo< Song > THeap;

// -------------------------------------------------------------------------
template< class TArbol >
bool addData( TArbol& arbol, const std::string& nomArch );

template< class TArbol >
bool searchData( TArbol& arbol, const std::string& nomArch );

template< class TArbol >
bool deleteData( TArbol& arbol, const std::string& nomArch );

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  if( argc < 4 )
  {
    std::cerr << "Uso: " << argv[ 0 ] << " archivo_adicionar archivo_eliminar archivo_buscar" << std::endl;
    return( -1 );

  } // fi

  // Declarar arboles a usar
  // TODO #13: Declarar arbol AVL a utilizar
  TAVL miArbolAVL;
  // TODO #14: Declarar arbol RN a utilizar
  // TSet miArbolRN;
  // TMap miArbolRN;
  // TODO #15: Declarar monticulo a utilizar
  // THeap miMonticulo;

/**** QUITAR CUANDO ESTE ROJO Y NEGRO
  // Llenar arbol rojinegro y calcular el tiempo empleado
  std::clock_t inicioLecturaRN = std::clock( );
  bool lecturaRN = addData( miArbolRN, argv[ 1 ] );
  std::clock_t finLecturaRN = std::clock( );
  double tiempoLecturaRN = ( finLecturaRN - inicioLecturaRN ) / double( CLOCKS_PER_SEC );
  if( lecturaRN )
    std::cout
      << "Tiempo de llenado arbol RN = "
      << tiempoLecturaRN << "segs."
      << std::endl;
  else
    std::cout
      << "Error al leer \"" << argv[ 1 ]
      << "\" para llenar el arbol RN."
      << std::endl;
  
****/
  // Llenar arbol AVL y calcular el tiempo empleado
  std::clock_t inicioLecturaAVL = std::clock( );
  bool lecturaAVL = addData( miArbolAVL, argv[ 1 ] );
  std::clock_t finLecturaAVL = std::clock( );
  double tiempoLecturaAVL = ( finLecturaAVL - inicioLecturaAVL ) / double( CLOCKS_PER_SEC );
  if( lecturaAVL )
    std::cout
    << "Tiempo de llenado arbol AVL = "
    << tiempoLecturaAVL << "segs."
    << std::endl;
  else
    std::cout
    << "Error al leer \"" << argv[ 1 ]
    << "\" para llenar el arbol AVL."
    << std::endl;
/**** QUITAR CUANDO ESTE MONTICULO
  // Llenar monticulo y calcular el tiempo empleado
  std::clock_t inicioLecturaHeap = std::clock( );
  bool lecturaHeap = addData( miMonticulo, argv[ 1 ] );
  std::clock_t finLecturaHeap = std::clock( );
  double tiempoLecturaHeap = ( finLecturaHeap - inicioLecturaHeap ) / double( CLOCKS_PER_SEC );
  if( lecturaHeap )
    std::cout
      << "Tiempo de llenado monticulo = "
      << tiempoLecturaHeap << "segs."
      << std::endl;
  else
    std::cout
      << "Error al leer \"" << argv[ 1 ]
      << "\" para llenar el monticulo."
      << std::endl;
****/
  // Obtener el recorrido en inorden de los arboles
  TList inordenAVL;
  TList inordenRN;
  TList inordenHeap;
  // TODO #18: Generar el recorrido en inorden de los arboles a través de una funcion de cada arbol
  miArbolAVL.inordenEnLista( inordenAVL );
  miArbolAVL.inOrden();
  // miArbolRN.inordenEnLista( inordenRN );
  // miMonticulo.inordenEnLista( inordenHeap );
  //Hacer al final
  if( inordenAVL.size( ) != inordenRN.size( ) && inordenAVL.size( ) != inordenHeap.size( ) )
  {
    std::cout << "Cantidad de elementos en los arboles no coinciden." << std::endl;
    return( -1 );

  } // fi

  // Comparar los arboles
  // TODO #19: Comparar que los tres recorridos inorden tengan los mismos datos en las mismas posiciones (O(N))
  // RECOMENDACION: HACER DE ULTIMO
  /* BUSQUEDA DE DATOS */

/**** QUITAR CUANDO ESTE ROJO Y NEGRO
  // busqueda en arbol rojinegro y calcular el tiempo empleado
  std::clock_t inicioBusquedaRN = std::clock( );
  bool BusquedaRN = searchData( miArbolRN, argv[ 2 ] );
  std::clock_t finBusquedaRN = std::clock( );
  double tiempoBusquedaRN = ( finBusquedaRN - inicioBusquedaRN ) / double( CLOCKS_PER_SEC );
  if( BusquedaRN )
    std::cout
      << "Tiempo de busqueda arbol RN = "
      << tiempoBusquedaRN << "segs."
      << std::endl;
  else
    std::cout
      << "Error al leer \"" << argv[ 2 ]
      << "\" para busqueda el arbol RN."
      << std::endl;
****/

  // busqueda en arbol AVL y calcular el tiempo empleado
  std::clock_t inicioBusquedaAVL = std::clock( );
  bool BusquedaAVL = searchData( miArbolAVL, argv[ 3 ] );
  std::clock_t finBusquedaAVL = std::clock( );
  double tiempoBusquedaAVL = ( finBusquedaAVL - inicioBusquedaAVL ) / double( CLOCKS_PER_SEC );
  if( BusquedaAVL )
    std::cout
    << "Tiempo de busqueda arbol AVL = "
    << tiempoBusquedaAVL << "segs."
    << std::endl;
  else
    std::cout
    << "Error al leer \"" << argv[ 2 ]
    << "\" para busqueda el arbol AVL."
    << std::endl;

/**** QUITAR CUANDO ESTE MONTICULO
  // busqueda en monticulo y calcular el tiempo empleado
  std::clock_t inicioBusquedaHeap = std::clock( );
  bool BusquedaHeap = searchData( miMonticulo, argv[ 2 ] );
  std::clock_t finBusquedaHeap = std::clock( );
  double tiempoBusquedaHeap = ( finBusquedaHeap - inicioBusquedaHeap ) / double( CLOCKS_PER_SEC );
  if( BusquedaHeap )
    std::cout
      << "Tiempo de busqueda monticulo = "
      << tiempoBusquedaHeap << "segs."
      << std::endl;
  else
    std::cout
      << "Error al leer \"" << argv[ 2 ]
      << "\" para busqueda el monticulo."
      << std::endl;
****/

  /* ELIMINACION DE DATOS */

/**** QUITAR CUANDO ESTE ROJO Y NEGRO
  // eliminacion en arbol rojinegro y calcular el tiempo empleado
  std::clock_t inicioeliminacionRN = std::clock( );
  bool eliminacionRN = deleteData( miArbolRN, argv[ 2 ] );
  std::clock_t fineliminacionRN = std::clock( );
  double tiempoeliminacionRN = ( fineliminacionRN - inicioeliminacionRN ) / double( CLOCKS_PER_SEC );
  if( eliminacionRN )
    std::cout
      << "Tiempo de eliminacion arbol RN = "
      << tiempoeliminacionRN << "segs."
      << std::endl;
  else
    std::cout
      << "Error al leer \"" << argv[ 2 ]
      << "\" para eliminacion el arbol RN."
      << std::endl;
****/


  // eliminacion en arbol AVL y calcular el tiempo empleado
  std::clock_t inicioeliminacionAVL = std::clock( );
  bool eliminacionAVL = deleteData( miArbolAVL, argv[ 2 ] );
  std::clock_t fineliminacionAVL = std::clock( );
  double tiempoeliminacionAVL = ( fineliminacionAVL - inicioeliminacionAVL ) / double( CLOCKS_PER_SEC );
  if( eliminacionAVL )
    std::cout
    << "Tiempo de eliminacion arbol AVL = "
    << tiempoeliminacionAVL << "segs."
    << std::endl;
  else
    std::cout
    << "Error al leer \"" << argv[ 2 ]
    << "\" para eliminacion el arbol AVL."
    << std::endl;

/**** QUITAR CUANDO ESTE MONTICULO
  // eliminacion en monticulo y calcular el tiempo empleado
  std::clock_t inicioeliminacionHeap = std::clock( );
  bool eliminacionHeap = deleteData( miMonticulo, argv[ 2 ] );
  std::clock_t fineliminacionHeap = std::clock( );
  double tiempoeliminacionHeap = ( fineliminacionHeap - inicioeliminacionHeap ) / double( CLOCKS_PER_SEC );
  if( eliminacionHeap )
    std::cout
      << "Tiempo de eliminacion monticulo = "
      << tiempoeliminacionHeap << "segs."
      << std::endl;
  else
    std::cout
      << "Error al leer \"" << argv[ 2 ]
      << "\" para eliminacion el monticulo."
      << std::endl;
****/

  return( 0 );
}

// -------------------------------------------------------------------------
template< class TArbol >
bool addData( TArbol& arbol, const std::string& nomArch )
{
  std::ifstream entrada( nomArch.c_str( ) );
  std::string linea;
  if( !entrada )
    return( false );

  //ignorar primera linea de add.txt
  std::getline(entrada,linea);

  while( std::getline(entrada,linea) )
  {
    // TODO #16: Leer la linea del archivo y tokenizar para crear un objeto tipo song
    std::stringstream flujoLinea(linea);
    std::string id, nombre, genero, artistas, album, 
                str_popularidad, str_duracion_ms, str_explicito;
    unsigned int popularidad, duracion_ms;
    bool expl;

    std::getline(flujoLinea, id, ';');
    std::getline(flujoLinea, nombre, ';');
    std::getline(flujoLinea, genero, ';');
    std::getline(flujoLinea, artistas, ';');
    std::getline(flujoLinea, album, ';');

    std::getline(flujoLinea, str_popularidad, ';');
    popularidad = stoi(str_popularidad);

    std::getline(flujoLinea, str_duracion_ms, ';');
    duracion_ms = stoi(str_duracion_ms);


    std::getline(flujoLinea, str_explicito, ';');
    expl = (str_explicito == "VERDADERO") ? true : false;

    Song valor(id, nombre, genero, artistas, album, popularidad, duracion_ms, expl);

    // std::cout << "ID: " << valor.obtenerId() << std::endl;
    //           << "Nombre: " << valor.obtenerNombre() << ", "
    //           << "Género: " << valor.obtenerGenero() << ", "
    //           << "Artistas: " << valor.obtenerArtistas() << ", "
    //           << "Álbum: " << valor.obtenerAlbum() << ", "
    //           << "Popularidad: " << valor.obtenerPopularidad() << ", "
    //           << "Duración (ms): " << valor.obtenerDuracion() << ", "
    //           << "Explícito: " << valor.obtenerExpl() << std::endl;

    // TODO #17: Implementar la función insert en cada uno de los arboles
    arbol.insert( valor );  // El arbol debe proveer el metodo "insert"

  } // elihw
  entrada.close( );
  return( true );
}
// -------------------------------------------------------------------------


// -------------------------------------------------------------------------

template< class TArbol >
bool searchData( TArbol& arbol, const std::string& nomArch )
{
  std::ifstream entrada( nomArch.c_str( ) );
  std::string linea;

  if( !entrada )
    return( false );

  while( std::getline(entrada,linea) )
  {
    // TODO #20: Leer la linea del archivo y extraer el identificador a buscar
    std::string id;

    std::stringstream flujoLinea(linea);
    std::getline(flujoLinea, id);
  
    Song valor;
    valor.fijarId(id);
    // TODO #21: Implementar la función search en cada uno de los arboles
    //arbol.search( valor );  // El arbol debe proveer el metodo "search"

  } // elihw
  entrada.close( );
  return( true );
}

// -------------------------------------------------------------------------

// -------------------------------------------------------------------------

template< class TArbol >
bool deleteData( TArbol& arbol, const std::string& nomArch )
{
  std::ifstream entrada( nomArch.c_str( ) );
  std::string linea;

  if( !entrada )
    return( false );
  while( std::getline(entrada,linea) )
  {
    // TODO #22: Leer la linea del archivo y extraer el identificador a eliminar
    std::string id;

    std::stringstream flujoLinea(linea);
    std::getline(flujoLinea, id);
  
    Song valor;
    valor.fijarId(id);

    // TODO #23: Implementar la función delete en cada uno de los arboles
    arbol.remove( valor );  // El arbol debe proveer el metodo "delete"

  } // elihw
  entrada.close( );
  return( true );
}

// -------------------------------------------------------------------------

// eof - taller_3_ordenamiento_busqueda.cxx

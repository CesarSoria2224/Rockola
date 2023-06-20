#include <vector>
#include "Cancion.h"
#include <list>
//#include "CancionManejadorDatos.cpp"

class CancionManejadorDatosEstaticos {
private:
    std::list<cancion> canciones;

public:
    CancionManejadorDatosEstaticos() {
        // Inicializar los datos estáticos de canciones
        cancion c7("fiesta pagana", 6, 30, Artista("mago de oz", "espania", Genero::Rock), 2);
        cancion c8("que", 5, 40, Artista("jessi", "mexico", Genero::Baladas), 1);
        cancion c9("mira", 3, 40, Artista("marco", "mexico", Genero::Romantica), 4);
        cancion c10("bobo", 4, 52, Artista("cristian", "mexico", Genero::Romantica), 5);
        cancion c11("anda", 2, 30, Artista("pulga", "argentina", Genero::Cumbia), 6);
        cancion c12("pasha", 3, 40, Artista("pulga", "argentina", Genero::Cumbia), 8);
        cancion c29("se", 3, 5, Artista("frontera", "mexico", Genero::Romantica), 3);
        cancion c30("termino", 3, 50, Artista("cesar", "bolivia", Genero::Romantica), 5);

        // Agregar las canciones al vector de canciones estáticas
        canciones = { c7, c8, c9, c10, c11, c12, c29, c30 };
    }

    std::list<cancion> obtenerCanciones() {
        return canciones;
    }
};

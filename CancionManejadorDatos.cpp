#ifndef CANCIONMANEJADORDATOS_H
#define CANCIONMANEJADORDATOS_H

#include <list>
#include "Cancion.h"

class CancionManejadorDatos {
public:
    virtual std::list<cancion> cargar() = 0;
    virtual void guardar(cancion canci) = 0;
};

#endif // CANCIONMANEJADORDATOS_H

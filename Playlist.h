#pragma once
#include "cancion.h"
#include <vector>
#include <list>



class playlist
{
private:
	list<cancion> lista;
	string nombre;
	string descripcion;
public:
	void agregarCancion(cancion c);
	void eliminarCancion(int nroCancion);
	void verLista();
	cancion buscarCancion(string titulo);
	int getNumCanciones();
	void verlistaResumen();
	void verlistaCompleta();
	bool existeNroCancion(int pos);
	void clonarLista(playlist &lista);
	void importarLista(playlist& list);
	void limpiarLista();
	list<cancion> getCanciones() const;
	cancion getCancioCorta();
	cancion getCancioLarga();
	list<cancion> getTopCanciones(int nro);
	list<cancion> getTop10Canciones();
};

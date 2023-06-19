#include "Playlist.h"
#include "Cancion.h"
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct compararCancion {
	bool operator () (cancion& c1, cancion& c2)
	{
		return c1.ObtenertiempoSegundo() < c2.ObtenertiempoSegundo();
	}
};
struct compararDECancion {
	bool operator () (cancion& c1, cancion& c2)
	{
		return c1.getpunto() < c2.getpunto();
	}
};

void playlist::agregarCancion(cancion c)
{
	bool existe = false;
	for (auto i : lista)
	{
		if (i.getTitulo() == c.getTitulo())
		{
			existe = true;
			break;
		}
	}
	if (!existe)
	{
		lista.push_back(c);
	}
}

void playlist::eliminarCancion(int nroCancion)
{
	if (nroCancion >= 0 && nroCancion < lista.size())
	{
		auto it = lista.begin();
		advance(it, nroCancion);
		lista.erase(it);
		cout << "Cancion eliminada correctamente." << endl;
	}
	else
	{
		cout << "no existe numero de cancion" << endl;
	}
}

void playlist::verLista()
{
	int i = 1;
	for (auto cancion : lista)
	{
		cout << i++ << ".- ";
		cancion.verInfo();
	}
}

cancion playlist::buscarCancion(string titulo)
{
	for ( auto cancion : lista)
	{
		if (cancion.getTitulo() == titulo)
		{
			return cancion;
		}
	}
	// Si no se encuentra la canción, se retorna una canción vacía
	return cancion();
}
void playlist::limpiarLista()
{
	lista.clear();
}

list<cancion> playlist::getCanciones() const
{
	return list<cancion>();
}

void playlist::importarLista(playlist& lista)
{
	
	for (auto cancion : lista.lista)
	{
		agregarCancion(cancion);
	}
	lista.lista.clear();
}

void playlist::clonarLista(playlist& lista)
{
	limpiarLista();
	importarLista(lista);
}

bool playlist::existeNroCancion(int pos)
{
	bool existe = false;
	if (pos >= 0 && pos < lista.size())
	{
		existe = true;
		return existe;
	}
}

cancion playlist::getCancioCorta()
{
	if (lista.empty())
	{
		return cancion();
	}

	lista.sort(compararCancion());
	auto it = lista.begin();
	return *it;
}
cancion playlist::getCancioLarga()
{
	if (lista.empty())
	{
		return cancion();
	}
	lista.sort(compararCancion());
	auto it = lista.end();
	--it; //retrocede el iterador al ultimo elemento
	return *it;
}

list<cancion> playlist::getTop10Canciones()
{
	
	lista.sort(compararDECancion());
	lista.reverse();

	list<cancion> Pauxi;
	auto it = lista.begin();
	int count = 0;
	while (it != lista.end() && count < 10) {
		Pauxi.push_back(*it);
		++it;
		++count;
	}

	return Pauxi;
	
}


list<cancion> playlist::getTopCanciones(int nro)
{
	lista.sort(compararDECancion());
	list <cancion> topCanciones;
	auto it = lista.begin();
	int i = 0;
	while (it != lista.end() && i < nro)
	{
		topCanciones.push_back(*it);
		++it;
		++i;
	}
	return topCanciones;
}

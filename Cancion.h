#pragma once
#include <string>
#include "Artista.h"
using namespace std;
struct Tiempo
{
	int minuto;
	int segundo;
};
class cancion
{
private:
	string titulo;
	Tiempo duracion;
	Artista compositor;
	int punto;
	int posicion;
	string e;

public:
	cancion();
	cancion(string _nombre, int m, int s,Artista comp);
	cancion(string _nombre, int m, int s,Artista comp, int _punto);
	cancion(string _titulo, Tiempo t, Artista comp);
	cancion(string _titulo, int m, int s, string e,int posicion, int _punto);
	cancion(string _titulo, int m, int s, string _e, int _punto);
	float ObtenertiempoSegundo();
	void formatearDuracion();
	void verInfo();
	bool esNulo();


	int getsegundo()
	{
		return duracion.segundo;
	}
	int getMinuto()
	{
		return duracion.minuto;
	};
	string getTitulo()
	{
		return titulo;
	};
	int getpunto()
	{
		return punto;
	}
	int getposicion()
	{
		return posicion;
	}
};

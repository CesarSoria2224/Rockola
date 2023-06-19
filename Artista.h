#pragma once
#include <string>
using namespace std;
enum Genero 
{ Rock, Baladas, Cumbia, Romantica};

class Artista
{
private:
	string nombre;
	string procedencia;
	Genero genero;
public:
	Artista(string nom, string proc, Genero gen);
	Artista(string nom, string proc);
	Artista(string nom, string pro, string gen);
	Artista();
	void verInfo();
	string getNombre();
	string getProcedencia();
	Genero getGenero();
	void setNombre(string n);
	void setProcedencia(string p);
	string vergenero();
};



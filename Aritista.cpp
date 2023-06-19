#include "Artista.h"
#include "Cancion.h"
#include <iostream>
using namespace std;
Artista::Artista(string nom, string proc, Genero gen)
{
    nombre = nom;
    procedencia = proc;
    genero = gen;
}
Artista::Artista(string nom, string proc)
{
    nombre = nom;
    procedencia = proc;
}
Artista::Artista(string nom, string pro, string gen)
{
    nombre = nom;
    procedencia = pro;
    if(gen == "Rock")
        genero = Rock;
    if(gen == "Baladas")
        genero = Baladas;
    if(gen == "Cumbia")
        genero = Cumbia;
    if(gen == "Romatica")
        genero = Genero::Romantica;
}
Artista::Artista()
{
    /*nombre = "alex campos";
    procedencia = "sucre";
    genero = Romatica;*/
}

string  Artista::getNombre()
{
    return nombre;
}

string Artista::getProcedencia() {
    return procedencia;
}

Genero Artista::getGenero()
{
    return genero;
}

void Artista::verInfo()
{
    cout << nombre << "  " << procedencia << genero<<  endl;
};


void Artista::setNombre(string n) {
    nombre = n;
}

void Artista::setProcedencia(string p) {
    procedencia = p;
}
string Artista::vergenero()
{
    switch (genero)
    {
    case Rock:
        return "Rock";
        break;
    case Baladas:
        return "Baladas";
        break;
    case Cumbia:
        return "Cumbia";
        break;
    case Romantica:
        return "Romantica";
        break;
    default:
        break;
    }
}
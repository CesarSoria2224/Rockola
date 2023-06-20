#include <iostream>
#include <list>
#include <fstream>
#include "ArtistaManejadorDatos.cpp"
#include <sstream>
#include <string>
using namespace std;
class ArtistaManejadorDatosArchivo :public ArtistaManejadorDatos
{


public:
    ArtistaManejadorDatosArchivo()
    {
        cout<<"Creating subclass type"<<endl;
    }

    list<Artista> cargar()
    {
        //lista donde se almacenaran los artistas leidos
        list<Artista> listaArtistas;
        //ubicacion de nuestro arcivo
        ifstream cin2("artistas.txt");

        string nombre, procedencia, genero;
        //Genero genero;
        int nro = 1;
        //la funcion peek() verifica que no estemos al final del archivo 
        while (cin2.peek() != EOF) // corroboramos que no hayamos llegado al final
        {
            //leemos todo lo que podamos donde se encuentra el cursor, (en la primera iteracion al principio) hasta donde encontremos una primera coma
            getline(cin2, nombre, ',');
            // continuacion leemos hasta encontrar otra coma, que seria el dato asociado a la procednecia
            getline(cin2, procedencia, ',');
            // finalmente leemos desde donde este el cursor, toda la linea, que seria el resto de la informacion asociada al genero
            getline(cin2, genero);

            nro++;
            Artista art(nombre, procedencia,   genero);
            listaArtistas.push_back(art);

        }

        //cin2.close();
        return listaArtistas;
    }
    void guardar(Artista artist)
    {
        //declaramos una variable que permita cargar en memoria un archivo para poder guardar en el mismo
        ofstream cout2;
        cout2.open("artistas.txt", std::ios_base::app);
        stringstream ss;
        ss << artist.getNombre() << ", " << artist.getProcedencia() << ", " << artist.getGenero() << endl;
        string s = ss.str();
        cout2 << s;
    }
};

#include <iostream>
#include <List>
#include <fstream>
#include "CancionManejadorDatos.cpp"
#include "ArtistaManejadorDatos.cpp"
#include "Artista.h"
#include <sstream>
#include <string>
using namespace std;
class CancionManejadorDatosArchivo: public CancionManejadorDatos 
{
private:
    ArtistaManejadorDatos* artistaManager;

public:
    CancionManejadorDatosArchivo(ArtistaManejadorDatos &manejador)
    {
        this->artistaManager = &manejador;
    }
   
    list<cancion> cargar()
    {
        //lista donde se almacenaran los artistas leidos
        list<Artista> listaArtista = artistaManager->cargar();
        cout << "NRO DE ARTISTAS " << listaArtista.size() << endl;
        list<cancion> listacanciones;

        ifstream cin2("canciones.txt");
        
  
        string titulo, minuto, segundos,auxi, posicion, puntos;

        //cin>>a;
        int nro =1;
        //la funcion peek() verifica que no estemos al final del archivo
        while(cin2.peek() != EOF)// corroboramos que no hayamos llegado a la ultima linea, es decir al final del archivo
        {  
            getline(cin2,titulo,',');
            getline(cin2,minuto,':');
            getline(cin2,segundos ,' ');
            getline(cin2, auxi, ',');
            getline(cin2,posicion,',');
            getline(cin2,puntos);

            cout << nro << " NOMBRE " << titulo << " --  " << minuto << ":" <<segundos  <<"  " << posicion<< "  " << puntos << endl;
            nro++;

            //ENLAZAR AL ARTISTA LAS CANCIONES
            list<Artista>::iterator it = listaArtista.begin();
            
            advance(it, stoi(posicion) - 1);
            
            Artista aux = *it;
           
            cancion c(titulo, stoi(minuto), stoi(segundos), auxi, stoi(puntos));
            
            listacanciones.push_back(c);
        }
     
       // listacanciones.begin()->verInfo();

        return listacanciones;
    }
    void guardar(cancion canci)
    {

    }
};


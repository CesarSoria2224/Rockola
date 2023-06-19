#include <iostream>
#include <list>
#include <string>
#include "Cancion.h" 
#include "Playlist.h"
#include <algorithm>
#include "DataManager.cpp"
#include "ArtistaManejadorDatosArchivo.cpp"  
#include "CancionManejadorDatosArchivo.cpp"
//#include "RockolaManager.cpp"

using namespace std;
void Menuplaylist();
void MenuPricipal();
void opcionAImportar(playlist& favoritos, playlist& latinos, playlist& lista1);
void elegirPlaylist(playlist& favoritos, playlist& latinos, playlist& lista1);
void agregarAPlaylist(playlist& Playlist, list<cancion>& canciones);

void eliminarDPlaylist(playlist& lista, int numCancion);
void InformacionPlaylist(playlist& lista);
void CancionesTOP(playlist& lista);





void agregarAPlaylisttxt(playlist& playlist, list<cancion>& canciones)
{
    int opcion;
    cout << "Seleccione el n�mero de la canci�n que desea agregar: ";
    cin >> opcion;

    if (opcion >= 1 && opcion <= canciones.size())
    {
        auto it = canciones.begin();
        advance(it, opcion - 1);

        playlist.agregarCancion(*it);
        cout << "La canci�n fue agregada a la playlist." << endl;
    }
    else {
        cout << "El n�mero de canci�n es incorrecto." << endl;
    }
}



int main()
{

    /* RockolaManager rockola;
    rockola.loadData();
    rockola.start();*/

    // Rocola::loadData();
    // Rocola::start();

    /*
    Seleccion el tipo de fuente datos
    1) Estico
    2) Archivo
    3) FuenteX

    DataManager *dm;
    CancionManejadorDatos *a;
    ArtistaManejadorDatos *b;
    si opcion=1
    a = new CancionManejadorDatosEstaticos();
    b = new ArtistaManejadorDatosEStaticos();
    si opcion= 2
    a = new CancionManejadorDatosArchivo();
    b = new ArtistaManejadorDatosArchivo();
    si opcion = 3
    a = new CancionManejadorDatosFuenteX();
    b = new ArtistaManejadorDatosFuenteX();
    dm = DataManager::getInstance(a,b)
    */

    ArtistaManejadorDatosArchivo artistaManager;
    CancionManejadorDatosArchivo cancionManager(artistaManager);

    list<cancion> listadecanciones = cancionManager.cargar();


    ArtistaManejadorDatos *a = new ArtistaManejadorDatosArchivo();
    CancionManejadorDatos *b = new CancionManejadorDatosArchivo(*a);

    DataManager *dm1,*dm2;
    dm1 = DataManager::getInstance(*a,*b);
    dm2 = DataManager::getInstance(*a,*b);

    cout<<"Direccion de dm1 "<<dm1<<endl;
    cout<<"Direccion de dm2 "<<dm2<<endl;


    // ArtistaManejadorDatos* a = new ArtistaManejadorDatosArchivo();
    //a->cargar();
    //Artista artistica;

    playlist lista1;
    playlist favoritos;
    playlist latinos;
    // agregarAPlaylisttxt(favoritos, canciones);


    cancion c7("fiesta pagana", 6, 30, Artista("mago de oz", "espania", Genero::Rock), 2);
    cancion c8("que", 5, 40, Artista("jessi", "mexico", Genero::Baladas), 1);
    cancion c9("mira", 3, 40, Artista("marco ", "mexico", Genero::Romantica), 4);
    cancion c10("bobo", 4, 52, Artista("cristian ", "mexico", Genero::Romantica), 5);
    cancion c11("anda", 2, 30, Artista("pulga", "argentina", Genero::Cumbia), 6);
    cancion c12("pasha", 3, 40, Artista("pulga", "argentina", Genero::Cumbia), 8);
    cancion c29("se", 3, 5, Artista("frontera", "mexico", Genero::Romantica),3);
    cancion c30("termino", 3, 50, Artista("cesar", "bolivia", Genero::Romantica),5);
    list<cancion> canciones = 
    { c7, c8, c9, c10,
        c11, c12,c29,c30 };

    cout << "Canciones disponibles: " << endl;
    int i = 1;
    for ( auto& cancion:canciones) {
        cout << i++ << ". "<<cancion.getTitulo()<<endl;
        //cancion.verInfo();
    }

    int opcion;

    do {
        MenuPricipal();
        cin >> opcion;
        switch (opcion) {
        case 1:
            agregarAPlaylist(favoritos, canciones);

            break;
        case 2:
            agregarAPlaylist(latinos, canciones);
            break;
        case 3:
            agregarAPlaylist(lista1, canciones);
            break;
        case 4:

            cout << "Lista de canciones de favoritos:" << endl;
            InformacionPlaylist(favoritos);
            cout << "Lista de canciones de latinos:" << endl;
            InformacionPlaylist(latinos);
            cout << "Lista de canciones de lista1:" << endl;
            InformacionPlaylist(lista1);
            break;
        case 5:
            int numero;
            cout << "Seleccione el numero de la cancion que desea eliminar: ";
            cin >> numero;
            eliminarDPlaylist(favoritos,numero);
            break;

        case 6:
            int numer;
            cout << "Seleccione el numero de la cancion que desea eliminar: ";
            cin >> numer;
            eliminarDPlaylist(latinos,numer);
            break;
        case 7:
            int nume;
            cout << "Seleccione el numero de la cancion que desea eliminar: ";
            cin >> nume;
            eliminarDPlaylist(lista1,nume);
            break;
        case 8:
            elegirPlaylist(favoritos, latinos, lista1);
            break;
        case 9:
            opcionAImportar(favoritos, latinos, lista1);
            cout << "se importo correctamente" << endl;
            cout << endl;
            break;
        case 10:
            opcionAImportar(favoritos, latinos, lista1);
            cout << "se clono correctamente" << endl;
            cout << endl;
            break;
        case 11:
            return 0;
            break;
        } 
    }while (opcion != 11);
}











void Menuplaylist()
{
    cout << "1. Favoritos" << endl;
    cout << "2. Latinos" << endl;
    cout << "3. Lista1" << endl;
}

void MenuPricipal()
{
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Agregar una cancion a la playlist favoritos" << endl;
    cout << "2. Agregar una cancion a la playlist latinos" << endl;
    cout << "3. Agregar una cancion a la playlist lista1" << endl;
    cout << "4. Ver lista de canciones" << endl;
    cout << "5. Eliminar una cancion de la playlist favoritos" << endl;
    cout << "6. Eliminar una cancion de la playlist latinos" << endl;
    cout << "7. Eliminar una cancion de la playlist lista1" << endl;
    cout << "8. Para ver el top de las canciones segun la puntuacion" << endl;
    cout << "9. para importar playlist" << endl;
    cout << "10. para clonar playlist" << endl;
    cout << "11. Salir del menu" << endl;
}
void opcionAImportar(playlist& favoritos, playlist& latinos, playlist& lista1)
{
    int origen, destino;
    cout << "origen" << endl;
    Menuplaylist();
    cin >> origen;
    cout << "destino" << endl;
    Menuplaylist();
    cin >> destino;

    if (origen == destino) {
        cout << "No se puede importar la playlist a si misma." << endl;
        return;
    }

    // Realizar la importaci�n seg�n las opciones seleccionadas
    switch (origen)
    {
    case 1: // Importar de Favoritos
        switch (destino)
        {
        case 2: // Importar a Latinos
            latinos.importarLista(favoritos);
            // latinos.clonarLista(favoritos);
            break;

        case 3: // Importar a Lista1
            lista1.importarLista(favoritos);
            // lista1.clonarLista(favoritos);
            break;
        default:
            cout << "Destino invalido." << endl;
            return;
        }
        break;
    case 2: // Importar de Latinos
        switch (destino)
        {
        case 1: // Importar a Favoritos
            favoritos.importarLista(latinos);
            //  favoritos.clonarLista(latinos);
            break;

        case 3: // Importar a Lista1
            lista1.importarLista(latinos);
            // lista1.clonarLista(latinos);
            break;
        default:
            cout << "Destino invalido." << endl;
            return;
        }
        break;
    case 3: // Importar de Lista1
        switch (destino)
        {
        case 1: // Importar a Favoritos
            favoritos.importarLista(lista1);
            // favoritos.clonarLista(lista1);
            break;
        case 2: // Importar a Latinos
            latinos.importarLista(lista1);
            //  latinos.clonarLista(lista1);
            break;
        default:
            cout << "Destino invalido." << endl;
            return;
        }
        break;
    default:
        cout << "Origen invalido." << endl;
        return;
    }

}
void elegirPlaylist(playlist& favoritos,playlist& latinos, playlist& lista1 )
{
    int opcion;
    Menuplaylist();
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        CancionesTOP(favoritos);
        break;
    case 2:
        CancionesTOP(latinos);
        break;
    case 3:
        CancionesTOP(lista1);
        break;
    default:
        cout << "Opci�n inv�lida." << endl;
        break;
    }
}
void InformacionPlaylist(playlist& lista)
{
    //playlist auxi = lista;
    lista.verLista(); cout << endl;
    cancion Corta = lista.getCancioCorta();
    cancion Larga = lista.getCancioLarga();
    if (Corta.esNulo() && Larga.esNulo())
    {
        cout << "playlist vacia" << endl;
    }
    else
    {
        cout << "la cancion mas corta" << endl;
        Corta.verInfo();
        cout << endl;
        cout << "la cancion mas larga" << endl;
        Larga.verInfo();

    }
    cout << endl;
}


void agregarAPlaylist(playlist& Playlist, list<cancion>& canciones)
{
    int opcion;
    cout << "Seleccione el numero de la cancion que desea agregar: ";
    cin >> opcion;

    auto it = canciones.begin();
    advance(it, opcion - 1);

    if (opcion >= 1 && opcion <= canciones.size())
    {
        Playlist.agregarCancion(*it);
        cout << "La cancion fue agregada a la playlist." << endl;
    }
    else {
        cout << "El numero de cancion es incorrecto." << endl;
    }
}
void CancionesTOP(playlist& lista)
{
    cout << "top mejores canciones por mejor puntuacion" << endl; cout << endl;
    list<cancion> topcanciones = lista.getTop10Canciones();
    int it = 1;
    cout << "nro:    titulo:" << "   puntuacion:"<<endl;
    for (auto& cancion : topcanciones)
    {
        // cout << "nro:    titulo:" << "   puntuacion:"<<endl;
        cout << it++ << ".      " << cancion.getTitulo() <<"       "<< cancion.getpunto()<<endl;
    }
}
void eliminarDPlaylist(playlist& lista, int numCancion)
{

    if (lista.existeNroCancion(numCancion))
    {
        lista.eliminarCancion(numCancion - 1);
    }
    else
    {
        cout << "el numero es incorrecto" << endl;
    }
}
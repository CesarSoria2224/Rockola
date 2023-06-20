#include <iostream>
#include <list>
#include <string>
#include "Cancion.h"
#include "Playlist.h"
#include <algorithm>
#include "DataManager.cpp"
#include "ArtistaManejadorDatosArchivo.cpp"  
#include "CancionManejadorDatosArchivo.cpp"
#include "CancionManejadorDatosEstaticos.cpp"
using namespace std;
class RockolaManager {
private:
    playlist lista1;
    playlist favoritos;
    playlist latinos;
    list<cancion> canciones;
private:
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

        // Realizar la importación según las opciones seleccionadas
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
    void elegirPlaylist(playlist& favoritos, playlist& latinos, playlist& lista1)
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
            cout << "Opción inválida." << endl;
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
        cout << "nro:    titulo:" << "   puntuacion:" << endl;
        for (auto& cancion : topcanciones)
        {
            // cout << "nro:    titulo:" << "   puntuacion:"<<endl;
            cout << it++ << ".      " << cancion.getTitulo() << "       " << cancion.getpunto() << endl;
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


public:

    RockolaManager() {
      
    }

    void loadData() {
        // Cargar datos adicionales si es necesario
    }
    void IniciarDatoEstatico()
    {
        CancionManejadorDatosEstaticos ca;
        std::list<cancion> cancionesVector = ca.obtenerCanciones();
       
        int i = 1;
        for ( auto& cancion:cancionesVector) {
           cout << i++ << ". "<<cancion.getTitulo()<<endl;
           //cancion.verInfo();
        }
        int opcion;


        do {
            MenuPricipal();
            cin >> opcion;
            switch (opcion) {
            case 1:
                agregarAPlaylist(favoritos, cancionesVector);

                break;
            case 2:
                agregarAPlaylist(latinos, cancionesVector);
                break;
            case 3:
                agregarAPlaylist(lista1, cancionesVector);
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
                eliminarDPlaylist(favoritos, numero);
                break;

            case 6:
                int numer;
                cout << "Seleccione el numero de la cancion que desea eliminar: ";
                cin >> numer;
                eliminarDPlaylist(latinos, numer);
                break;
            case 7:
                int nume;
                cout << "Seleccione el numero de la cancion que desea eliminar: ";
                cin >> nume;
                eliminarDPlaylist(lista1, nume);
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
                //return 0;
                break;
            }
        } while (opcion != 11);
    }
    void IniciarDatoArchivo() {
        ArtistaManejadorDatosArchivo artistaManager;
        CancionManejadorDatosArchivo cancionManager(artistaManager);

        list<cancion> listadecanciones = cancionManager.cargar();
        int opcion;
        

        do {
            MenuPricipal();
            cin >> opcion;
            switch (opcion) {
            case 1:
                agregarAPlaylist(favoritos, listadecanciones);

                break;
            case 2:
                agregarAPlaylist(latinos, listadecanciones);
                break;
            case 3:
                agregarAPlaylist(lista1, listadecanciones);
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
                eliminarDPlaylist(favoritos, numero);
                break;

            case 6:
                int numer;
                cout << "Seleccione el numero de la cancion que desea eliminar: ";
                cin >> numer;
                eliminarDPlaylist(latinos, numer);
                break;
            case 7:
                int nume;
                cout << "Seleccione el numero de la cancion que desea eliminar: ";
                cin >> nume;
                eliminarDPlaylist(lista1, nume);
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
                //return 0;
                break;
            }
        } while (opcion != 11);
    }


};

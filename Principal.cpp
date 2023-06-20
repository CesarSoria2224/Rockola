#include "RockolaManager.cpp"
#include <iostream>
using namespace std;


int main() {
    RockolaManager rockola;
    //rockola.loadData();
   /* DataManager* dm;
    CancionManejadorDatos* a;
    ArtistaManejadorDatos* b;*/

    int opcion;
     do{
    cout << "Seleccione el tipo de dato a trabajar:" << endl;
    cout << "1. Datos estaticos" << endl;
    cout << "2. Datos desde archivo de texto" << endl;
    cout << "Ingrese su opcion: ";
    cin >> opcion;

    if (opcion == 1) {
        // Trabajar con datos estáticos
        rockola.IniciarDatoEstatico();
    } else if (opcion == 2) {
        // Trabajar con datos desde archivo de texto
        rockola.IniciarDatoArchivo();
    } else {
        cout << "Opcion invalida. Saliendo del programa." << endl;
    } 
    }while (opcion != 3);

     //int opcion;

     //do {
     //    cout << "Selecciona el tipo de fuente de datos:" << endl;
     //    cout << "1) Estático" << endl;
     //    cout << "2) Archivo TXT" << endl;
     //    cout << "0) Salir" << endl;
     //    cout << "Opción: ";
     //    cin >> opcion;

     //    switch (opcion) {
     //    case 1:
     //        a = new CancionManejadorDatosEstaticos();
     //        b = new ArtistaManejadorDatosEstaticos();
     //        // Realiza las operaciones con los datos estáticos
     //        // ...
     //        break;
     //    case 2:
     //        a = new CancionManejadorDatosArchivo();
     //        b = new ArtistaManejadorDatosArchivo();
     //        // Realiza las operaciones con los datos del archivo TXT
     //        // ...
     //        break;
     //    case 0:
     //        cout << "Saliendo del programa..." << endl;
     //        break;
     //    default:
     //        cout << "Opción inválida. Inténtalo de nuevo." << endl;
     //        break;
     //    }

     //    // Liberar la memoria asignada a los objetos a y b
     //    delete a;
     //    delete b;

     //} while (opcion != 0);
     /*
     Seleccion el tipo de fuente datos
     1) Estico
     2) Archivo TXT
   

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



    return 0;
}

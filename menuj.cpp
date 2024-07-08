#include <iostream>
#include <fstream>

using namespace std;

void juego1();
void juego2();
void juego3();

void mostrarMenu();

int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                juego1();
                break;
            case 2:
                juego2();
                break;
            case 3:
                juego3();
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}

void mostrarMenu() {
    cout << "======== MENU PRINCIPAL ========" << endl;
    cout << "1. Juego 1" << endl;
    cout << "2. Juego 2" << endl;
    cout << "3. Juego 3" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

// Funciones para cada juego
void juego1() {
    cout << "Iniciando Juego 1..." << endl;
    // Lógica del Juego 1
}

void juego2() {
    cout << "Iniciando Juego 2..." << endl;
    // Lógica del Juego 2
}

void juego3() {
    cout << "Iniciando Juego 3..." << endl;
    // Lógica del Juego 3
}

#include <iostream>
#include <fstream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()

using namespace std;

void guardarPuntaje(int intentos) {
    ofstream archivo("puntajes.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Intentos usados: " << intentos << endl;
        archivo.close();
        cout << "Puntaje guardado correctamente!" << endl;
    } else {
        cout << "No se pudo abrir el archivo para guardar el puntaje." << endl;
    }
}

void mostrarPuntajes() {
    ifstream archivo("puntajes.txt");
    string linea;

    if (archivo.is_open()) {
        cout << "Puntajes guardados:" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo de puntajes." << endl;
    }
}

void adivinaElNumero() {
    int numeroSecreto, intento, intentos = 0;
    const int MAX_INTENTOS = 5;
    char jugarDeNuevo;

    // Inicializa el generador de números aleatorios
    srand(time(0));
    numeroSecreto = rand() % 100 + 1;  // Genera un número aleatorio entre 1 y 100

    cout << "Bienvenido al juego 'Adivina el Número'!" << endl;
    cout << "Estoy pensando en un número entre 1 y 100." << endl;
    cout << "Tienes " << MAX_INTENTOS << " intentos para adivinarlo." << endl;

    do {
        cout << "Intento #" << (intentos + 1) << ": Ingresa tu intento: ";
        cin >> intento;

        if (intento > numeroSecreto) {
            cout << "Muy alto! Intenta de nuevo." << endl;
        } else if (intento < numeroSecreto) {
            cout << "Muy bajo! Intenta de nuevo." << endl;
        } else {
            cout << "Felicidades! Adivinaste el número secreto!" << endl;
            guardarPuntaje(intentos + 1);
            break;
        }

        intentos++;
    } while (intentos < MAX_INTENTOS);

    if (intento != numeroSecreto) {
        cout << "Lo siento, se te acabaron los intentos. El número secreto era: " << numeroSecreto << endl;
    }

    cout << "¿Quieres jugar de nuevo? (s/n): ";
    cin >> jugarDeNuevo;

    if (jugarDeNuevo == 's' || jugarDeNuevo == 'S') {
        adivinaElNumero();
    } else {
        cout << "Gracias por jugar!" << endl;
        mostrarPuntajes();
    }
}

int main() {
    adivinaElNumero();
    return 0;
}

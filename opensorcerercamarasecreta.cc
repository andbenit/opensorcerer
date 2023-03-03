//Incluir librerías
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
Using namespace std;

// Definir constantes
Const int LONGITUD = 7; // Longitud de la clave
Const int MAXIMO = 9; // Máximo valor posible para cada cifra
Const int MINIMO = 0; // Mínimo valor posible para cada cifra

// Definir funciones
Vector<int> generar_clave(); // Genera una clave aleatoria sin repetir cifras
Void mostrar_clave(vector<int> clave); // Muestra una clave por pantalla
Void lanzar_conjuro(vector<int> clave); // Lanza el conjuro para introducir la clave en latín
String leer_pista(); // Lee la pista devuelta por la puerta mágica
Void actualizar_cifras(vector<bool> &cifras_validas, vector<bool> &posiciones_validas,Vector<int> clave_actual,String pista); // Actualiza los vectores booleanos según la pista

// Programa principal
Int main() {
    // Inicializar variables
    Vector<bool> cifras_validas(MAXIMO – MINIMO + 1,true); // Indica si cada cifra es válida o no (inicialmente todas lo son)
    Vector<bool> posiciones_validas(LONGITUD,true); // Indica si cada posición es válida o no (inicialmente todas lo son)
    Vector<int> clave; // Almacena la clave actual
    String pista; // Almacena la pista devuelta por la puerta

// Crear un generador de números aleatorios
Random_device rd;
Mt19937 gen(rd());

// Bucle principal
While (true) {
    // Generar una clave aleatoria sin repetir cifras y que cumpla con las restricciones
    Do {
        Clave = generar_clave();
    } while (¡all_of(clave.begin(), clave.end(), [&](int x) { return cifras_validas[x – MINIMO]; }) ||
             ¡all_of(posiciones_validas.begin(), posiciones_validas.end(), [](bool x) { return x; }));

    // Mostrar la clave por pantalla
    Mostrar_clave(clave);

    // Lanzar el conjuro para introducir la clave en latín
    Lanzar_conjuro(clave);

    // Leer la pista devuelta por la puerta mágica
    Pista = leer_pista();

    // Si la pista es “Correcta”, significa que se ha abierto la Cámara Secreta y se termina el programa
    If (pista == “Correcta”) {
        Cout << “¡Enhorabuena! Has abierto la Cámara Secreta.\n”;
        Break;
    }

    // Si no, se actualizan los vectores booleanos según la pista
    Else {
        Actualizar_cifras(cifras_validas, posiciones_validas, clave, pista);
    }
}

Return 0;
}

// Función que genera una clave aleatoria sin repetir cifras vector<int> generar_clave() { vector<int> clave(LONGITUD); // Vector que almacena la clave vector<int> candidatos(MAXIMO – MINIMO + 1); // Vector que almacena los candidatos a formar parte de la clave

// Rellenar el vector de candidatos con los valores entre MINIMO y MAXIMO
Iota(candidatos.begin(), candidatos.end(), MINIMO);

// Barajar el vector de candidatos
Shuffle(candidatos.begin(), candidatos.end(), gen);

// Copiar los primeros LONGITUD elementos del vector de candidatos al vector de clave
Copy_n(candidatos.begin(), LONGITUD, clave.begin());

Return clave;
}

// Función que muestra una clave por pantalla void mostrar_clave(vector<int> clave) {

// Recorrer el vector de clave y mostrar cada cifra separada por un espacio
For (int x : clave) {
    Cout << x << “ “;
}
Cout << “\n”;
}

// Función que lanza el conjuro para introducir la clave en latín void lanzar_conjuro(vector<int> clave) { // Crear un vector que almacene los nombres de los números en latín vector<string> numeros = {“nulla”, “una”, “duo”, “tres”, “quattuor”, “quinque”, “sex”, “septem”, “octo”, “novem”};

// Mostrar el conjuro por pantalla con el formato: Clavis est: [clave en latín]. Aperi!
Cout << “Clavis est: “;
For (int x : clave) {
    Cout << numeros[x] << “ “;
}
Cout << “. Aperi!\n”;
}

// Función que lee la pista devuelta por la puerta mágica string leer_pista() { string pista; // Variable que almacena la pista

// Leer la pista desde la entrada estándar
Getline(cin, pista);

Return pista;
}

// Función que actualiza los vectores booleanos según la pista void actualizar_cifras(vector<bool> &cifras_validas, vector<bool> &posiciones_validas, vector<int> clave_actual, string pista) { // Recorrer cada cifra de la clave actual y compararla con la pista for (int i = 0; i < LONGITUD; i++) { int x = clave_actual[i]; // Cifra actual char c = pista[i]; // Carácter correspondiente en la pista

    // Si el carácter es ‘N’, significa que la cifra no está en la clave y se marca como inválida
    If (c == ‘N’) {
        Cifras_validas[x – MINIMO] = false;
    }

    // Si el carácter es ‘P’, significa que la cifra está en la clave pero no en su posición y se marca como inválida para esa posición
    Else if (c == ‘P’) {
        Posiciones_validas[i] = false;
    }

    // Si el carácter es ‘C’, significa que la cifra está en la clave y en su posición y se marca como válida solo para esa posición
    Else if (c == ‘C’) {
        For (int j = 0; j < LONGITUD; j++) {
            If (j ¡= i) {
                Posiciones_validas[j] = false;
            }
        }
    }
}
}

// Fin de la historia

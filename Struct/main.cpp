#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "menu.h"
#include "userinput.h"
using namespace std;

struct Lvl {
    string word;
    string advice;
    void print();
};

queue<Lvl> loadLevels();

string getinput() {
    string input;
    cin >> input;
    
    for (auto& letra : input) 
        letra = tolower(letra);
    
    return input;
}

vector<char> getLetrasDePalabra(string palabra)
{
    vector<char> Letrasdelapalabra;
    for (auto letra : palabra) {
        if (find(Letrasdelapalabra.begin(), Letrasdelapalabra.end(), letra) == Letrasdelapalabra.end()) { /*Si no existe, se añade*/
            Letrasdelapalabra.push_back(letra);
        }
    }
    return Letrasdelapalabra;
}

void printCoincidencia(string palabra, vector<char> Letrasconocidas)
{
    cout << "Estas son las coincidencias con tu palabra: " << endl;

    for (auto letra : palabra)
    {
        if (find(Letrasconocidas.begin(), Letrasconocidas.end(), letra) != Letrasconocidas.end())
            cout << letra;
        else
            cout << '_';
    }

    cout << "\n\n";
}

void printIntentosRestantes(int intentosTotales, int attemps)
{
    cout << "Intentos restantes: ";

    for (int i = 0; i < (intentosTotales - attemps); i++)
        cout << 'X';

    cout << "\n\n";
}

void playlevel(Lvl lvlactual, bool& win) {
    const int intentosTotales = 5;
    auto Letrasdelapalabra = getLetrasDePalabra(lvlactual.word);
    vector<char> Letrasconocidas;

    cout << "Nuevo nivel! A continuacion su consejo:\n";
    cout << lvlactual.advice << "\n\n";

    for (int attemps = 0; attemps < intentosTotales; attemps++) {

        printCoincidencia(lvlactual.word, Letrasconocidas);
        printIntentosRestantes(intentosTotales, attemps);

        cout << "Ingrese una letra o palabra" << endl;
        auto input = getinput();
    
        cout << "\n\n";
        
        if (input == lvlactual.word) {
            win = true;
            break;
        }
        if (input.size() == 1) {
            if (find(Letrasconocidas.begin(), Letrasconocidas.end(), input[0]) != Letrasconocidas.end()) { /*Si existe*/
                attemps--;
            } else {
                if (find(Letrasdelapalabra.begin(), Letrasdelapalabra.end(), input[0]) != Letrasdelapalabra.end()) {
                    Letrasconocidas.push_back(input[0]);
                    attemps--;
                }
            }
        }
    }
}

void play() {
    auto niveles = loadLevels();
    while (!niveles.empty()) {
        bool win = false;
        clearConsole();
        playlevel(niveles.front(), win);
        if (win) {
            cout << "Has completado el nivel" << endl;   
        }
        else {
            cout << "Has perdido el juego. Mala suerte!" << endl;
            return;
        }
        niveles.pop();
    }

    clearConsole();
    cout << "Enhorabuena, has superado cada nivel!\n";
    cout << "Muchas gracias por jugar <3\n";
}


void printCreditos() {
    cout << "Este juego fue desarrollado por:" << endl;
    cout << "Guillermo Silva" << endl;
    cout << "Martin Velasquez" << endl;
    cout << "Reyna Figuera" << endl;
    cout << "Agradecimiento especial a Daniel Ramirez, todo esto es posible gracias a el." << endl;
}

int main() {

    vector<MenuFunction> funcionesDelMenu
    {
        {"Jugar", &play},
        {"Creditos", &printCreditos},
    };
    
    MainMenu menu{ "Bienvenido a Guess the Word", funcionesDelMenu };

    menu.run();
    return 0;
}



void printLose() {
    cout << "Has perdido.\n ¿Desea volver a jugar?" << endl;
}

void printWin() {
    cout << "¡Ganaste, felicidades!" << endl;
}

void Lvl::print() {
    cout << word << ":" << endl;
    cout << advice << endl;
}

queue<Lvl> loadLevels() {
    srand(time(0));
    vector<Lvl> list;
    queue<Lvl> levelQueue;

    Lvl w1 = { "entero" , "Es la representacion de un numero sin decimal"};
    Lvl w2 = { "vector" , "Funciona como arreglo dinamico. Es una de las multiples estructuras llamadas contenedores"};
    Lvl w3 = { "cola" , "Caracterizada por ser una secuencia de elementos. Primer elemento en entrar sera tambien el primero en salir."};
    Lvl w4 = { "pila" , "Permite almacenar y recuperar datos, siendo el modo de acceso a sus elementos de tipo, ultimo en entrar, primero en salir."};
    Lvl w5 = { "arreglo" , "Son estructuras de datos que permiten almacenar un conjunto de elementos relacionados bajo un solo nombre."};

    
    list.push_back(w1);
    list.push_back(w2);
    list.push_back(w3);
    list.push_back(w4);
    list.push_back(w5);
    
    while(!list.empty()) {
        int index = rand() % list.size();
        levelQueue.push(list[index]);
        list.erase(next(list.begin(),index));
    }

    return levelQueue;
}
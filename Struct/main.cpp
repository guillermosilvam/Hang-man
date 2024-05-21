#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
#include "menu.h"
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

void playlevel(Lvl lvlactual, bool& win) {
    vector<char> Letrasdelapalabra;
    for (auto letra : lvlactual.word) {
        if (find(Letrasdelapalabra.begin(), Letrasdelapalabra.end(), letra ) == Letrasdelapalabra.end()) { /*Si no existe, se añade*/
            Letrasdelapalabra.push_back(letra);
        }    
    }
    vector<char> Letrasconocidas;
    for (int attemps = 0; attemps < 5; attemps++) {
        cout << "Estas son las letras que conoces: " << endl;
        for (auto letra : Letrasconocidas) {
            cout << letra << " ";
        }
        cout << endl;
        cout << "Ingrese una letra o palabra" << endl;
        auto input = getinput();
        
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
        playlevel(niveles.front(), win);
        if (win) {
            cout << "Has completado el nivel" << endl;   
        }
        else {
            cout << "Perdiste" << endl;
            break;
        }
        niveles.pop();
    }

}

void printBienvenida() {
    cout << "Hang-a-Dev es el clasico juego del ahorcado, sin embargo, con tematica basada programacion. ¡Diviertete!";
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
    
    MainMenu menu{ "Bienvenido a Hang-a-Dev", funcionesDelMenu };

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

    Lvl w1 = { "entero" , "..." };
    Lvl w2 = { "vector" , "..."};
    Lvl w3 = { "cola" , "..."};
    Lvl w4 = { "pila" , "..."};
    Lvl w5 = { "arreglo" , "..."};

    
    list.push_back(w1);
    /*list.push_back(w2);
    list.push_back(w3);
    list.push_back(w4);
    list.push_back(w5);
    */
    
    while(!list.empty()) {
        int index = rand() % list.size();
        levelQueue.push(list[index]);
        list.erase(next(list.begin(),index));
    }

    return levelQueue;
}
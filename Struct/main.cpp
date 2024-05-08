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
        {"Jugar", &printBienvenida},
        {"Creditos", &printCreditos},
        
    };
    
    MainMenu menu{ "Bienvenido a Hang-a-Dev", funcionesDelMenu };

    menu.run();

    /*

    queue<Lvl> colaxd = loadLevels();

    while (!colaxd.empty()) {
        colaxd.front().print();
        colaxd.pop();
    }

    */

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

    Lvl w1 = { "Entero" , "..." };
    Lvl w2 = { "Vector" , "..."};
    Lvl w3 = { "Cola" , "..."};
    Lvl w4 = { "Pila" , "..."};
    Lvl w5 = { "Arreglo" , "..."};

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
#include <iostream>
#include <string>

using namespace std;

struct Lvl {
    string palabra;
    string consejo;
    void print();
};

int main() {
    Lvl w1;
    w1.palabra = "Entero";
    w1.consejo = "Sirven para xd";
        
    w1.print();
    
    return 0;
}


void Lvl::print() {
    cout << palabra << ":" << endl;
    cout << consejo << endl;

}

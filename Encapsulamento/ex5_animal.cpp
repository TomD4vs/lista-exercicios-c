#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    string especie;
    string som;

    void emitir_som() {
        cout << "O " << especie << " faz: " << som << endl;
    }
};

int main() {
    Animal a;
    a.especie = "gato";
    a.som = "Miau";

    a.emitir_som();

    return 0;
}

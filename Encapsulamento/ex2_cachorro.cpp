#include <iostream>
#include <string>
using namespace std;

class Cachorro {
public:
    string nome;
    string raca;

    void latir() {
        cout << "Au Au! O cachorro " << nome << " esta latindo." << endl;
    }
};

int main() {
    Cachorro c;
    c.nome = "Rex";
    c.raca = "Labrador";

    c.latir();

    return 0;
}

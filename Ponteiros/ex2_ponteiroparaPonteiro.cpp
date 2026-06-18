#include <iostream>
using namespace std;

void criarNovoInteiro(int** ptr, int valor) {
    *ptr = new int;   
    **ptr = valor;    
}

int main() {
    int* p = nullptr;

    cout << "Antes: p = " << p << endl;

    criarNovoInteiro(&p, 42);

    cout << "Depois: p aponta para " << p << endl;
    cout << "Valor: *p = " << *p << endl;

    delete p;
    return 0;
}

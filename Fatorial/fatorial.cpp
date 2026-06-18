#include <iostream>

using namespace std;

long long calcularFatorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * calcularFatorial(n - 1); 
}

int main() {
    int numero;
    
    cout << "Digite um numero inteiro positivo: ";
    cin >> numero;

    if (numero < 0) {
        cout << "O fatorial nao existe para numeros negativos." << endl;
    } else {
        cout << "O fatorial de " << numero << " e: " << calcularFatorial(numero) << endl;
    }

    return 0;
}

#include <iostream>

using namespace std;


int calcularFibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return calcularFibonacci(n - 1) + calcularFibonacci(n - 2); 
    }
}

int main() {
    int termos;

    cout << "Digite a quantidade de termos de Fibonacci que deseja exibir: ";
    cin >> termos;

    cout << "Serie de Fibonacci: ";
    for (int i = 0; i < termos; i++) {
        cout << calcularFibonacci(i) << " ";
    }
    cout << endl;

    return 0;
}

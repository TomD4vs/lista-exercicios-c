#include <iostream>
using namespace std;

bool calcular(int a, int b, char operador, int* resultado) {
    int valor;

    switch (operador) {
        case '+': valor = a + b; break;
        case '-': valor = a - b; break;
        case '*': valor = a * b; break;
        case '/':
            if (b == 0) return false;
            valor = a / b;
            break;
        default:
            return false;
    }

    if (resultado != nullptr)
        *resultado = valor;

    return true;
}

int main() {
    int res;

    
    if (calcular(10, 2, '/', &res))
        cout << "10 / 2 = " << res << endl;

   
    if (calcular(10, 2, '+', nullptr))
        cout << "10 + 2 e valido (resultado ignorado)" << endl;

  
    if (!calcular(5, 0, '/', &res))
        cout << "Erro: divisao por zero" << endl;

   
    if (!calcular(5, 3, '%', &res))
        cout << "Erro: operador desconhecido" << endl;

    return 0;
}

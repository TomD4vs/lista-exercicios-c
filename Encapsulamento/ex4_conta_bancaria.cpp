#include <iostream>
#include <string>
using namespace std;

class ContaBancaria {
public:
    string titular;
    float saldo;

    void depositar(float valor) {
        saldo += valor;
        cout << "Deposito de R$" << valor << " realizado." << endl;
    }

    void sacar(float valor) {
        if (valor > saldo)
            cout << "Saldo insuficiente." << endl;
        else {
            saldo -= valor;
            cout << "Saque de R$" << valor << " realizado." << endl;
        }
    }
};

int main() {
    ContaBancaria conta;
    conta.titular = "Elyton";
    conta.saldo = 0;

    conta.depositar(500);
    conta.sacar(200);

    cout << "Saldo final de " << conta.titular << ": R$" << conta.saldo << endl;

    return 0;
}

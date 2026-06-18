#include <iostream>
#include <string>

using namespace std;

class Funcionario {
protected:
    string nome;
    double salario;

public:
    Funcionario(string n, double s)
        : nome(n), salario(s) {}

    virtual ~Funcionario() {}

    virtual void mostrarSalario() {
        cout << "Funcionario: " << nome << endl;
        cout << "Salario: R$ " << salario << endl;
    }
};

class Gerente : public Funcionario {
public:
    Gerente(string n, double s)
        : Funcionario(n, s) {}

    void mostrarSalario() override {
        double bonus = salario * 0.20;

        cout << "Gerente: " << nome << endl;
        cout << "Salario: R$ " << salario << endl;
        cout << "Bonus (20%): R$ " << bonus << endl;
        cout << "Total: R$ " << salario + bonus << endl;
    }
};

void fazerMostrar(Funcionario* f) {
    f->mostrarSalario();
    cout << endl;
}

int main() {
    Funcionario* f1 = new Funcionario("Joao", 2000);
    Funcionario* g1 = new Gerente("Maria", 5000);

    fazerMostrar(f1);
    fazerMostrar(g1);

    delete f1;
    delete g1;

    return 0;
}
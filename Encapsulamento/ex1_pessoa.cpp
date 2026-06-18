#include <iostream>
#include <string>
using namespace std;

class Pessoa {
public:
    string nome;
    int idade;
};

int main() {
    Pessoa p1;
    p1.nome = "Elyton";
    p1.idade = 25;

    Pessoa p2;
    p2.nome = "Antonio";
    p2.idade = 30;

    cout << "Nome: " << p1.nome << ", Idade: " << p1.idade << endl;
    cout << "Nome: " << p2.nome << ", Idade: " << p2.idade << endl;

    return 0;
}

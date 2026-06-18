#include <iostream>
#include <string>
using namespace std;

class Aluno {
public:
    string nome;
    float nota1;
    float nota2;

    float calcularMedia() {
        return (nota1 + nota2) / 2;
    }

    void mostrarResultado() {
        float media = calcularMedia();
        cout << "Aluno: " << nome << " | Media: " << media;
        if (media >= 7)
            cout << " | Aprovado" << endl;
        else
            cout << " | Reprovado" << endl;
    }
};

int main() {
    Aluno a1;
    a1.nome = "Elyton";
    a1.nota1 = 8.0;
    a1.nota2 = 9.0;

    Aluno a2;
    a2.nome = "Antonio";
    a2.nota1 = 5.0;
    a2.nota2 = 6.0;

    a1.mostrarResultado();
    a2.mostrarResultado();

    return 0;
}

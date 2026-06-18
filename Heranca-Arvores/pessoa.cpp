#include <iostream>
#include <string> 
using namespace std;

class Pessoa{
protected:
    string nome;

public:
    Pessoa(string n) : nome(n) {}
};

class Aluno : public Pessoa {
private:
    int matricula;

public: 
    Aluno(string n, int m) : Pessoa(n), matricula(m){}
    
    void exibir(){
        cout << "Nome: " << nome << ", Matricula: " << matricula << endl;
    }
};

int main (){
    Aluno tom("Tom", 123);
    tom.exibir();
    return 0;
}
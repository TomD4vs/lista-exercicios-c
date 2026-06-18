#include <iostream>
#include <string>
using namespace std;

class Produto {
protected:
    string nome;
    double preco;

public:
    Produto(string nome, double preco) : nome(nome), preco(preco) {}

    virtual void exibir() const {
        cout << "Produto: " << nome << " | Preco: R$ " << preco;
    }

    virtual ~Produto() = default;
};

class Livro : public Produto {
    string autor;

public:
    Livro(string nome, double preco, string autor)
        : Produto(nome, preco), autor(autor) {}

    void exibir() const override {
        Produto::exibir();
        cout << " | Autor: " << autor;
    }
};

class Eletronico : public Produto {
    string marca;

public:
    Eletronico(string nome, double preco, string marca)
        : Produto(nome, preco), marca(marca) {}

    void exibir() const override {
        Produto::exibir();
        cout << " | Marca: " << marca;
    }
};

int main() {
    Livro livro1("Dom Casmurro", 39.90, "Machado de Assis");
    Livro livro2("O Cortico", 29.90, "Alceo Alencar");

    Eletronico elet1("Smartphone", 1999.00, "Samsung");
    Eletronico elet2("Notebook", 3499.00, "Dell");

    cout << "=== Livros ===" << endl;
    livro1.exibir(); cout << endl;
    livro2.exibir(); cout << endl;

    cout << "\n=== Eletronicos ===" << endl;
    elet1.exibir(); cout << endl;
    elet2.exibir(); cout << endl;

    return 0;
}

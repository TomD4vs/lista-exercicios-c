#include <iostream>
#include <string>
using namespace std;

class Personagem {
protected:
    string nome;
    int    poder;
    string tipo;

public:
    Personagem(string nome, int poder, string tipo)
        : nome(nome), poder(poder), tipo(tipo) {}

    virtual ~Personagem() {}

    int getPoder() const { return poder; }

    virtual void exibir() const {
        cout << "[" << tipo << "] " << nome << " | Poder: " << poder << "\n";
    }
};

class Chefe : public Personagem {
    string reino;

public:
    Chefe(string nome, int poder, string tipo, string reino)
        : Personagem(nome, poder, tipo), reino(reino) {}

    void exibir() const override {
        cout << "[" << tipo << " - CHEFE] " << nome
             << " | Poder: " << poder
             << " | Reino: " << reino << "\n";
    }
};

struct No {
    Personagem* personagem;
    No*         esquerda;
    No*         direita;

    No(Personagem* p) : personagem(p), esquerda(nullptr), direita(nullptr) {}
};

class ArvoreBinaria {
    No* raiz;

    No* inserir(No* no, Personagem* p) {
        if (no == nullptr)
            return new No(p);

        if (p->getPoder() < no->personagem->getPoder())
            no->esquerda = inserir(no->esquerda, p);
        else
            no->direita = inserir(no->direita, p);

        return no;
    }

    void emOrdem(No* no) const {
        if (no == nullptr) return;

        emOrdem(no->esquerda);
        no->personagem->exibir();
        emOrdem(no->direita);
    }

    void destruir(No* no) {
        if (no == nullptr) return;
        destruir(no->esquerda);
        destruir(no->direita);
        delete no->personagem;
        delete no;
    }

public:
    ArvoreBinaria() : raiz(nullptr) {}
    ~ArvoreBinaria() { destruir(raiz); }

    void inserir(Personagem* p) {
        raiz = inserir(raiz, p);
    }

    void percorrerEmOrdem() const {
        cout << "\n=== Floresta Encantada (do menos ao mais poderoso) ===\n\n";
        emOrdem(raiz);
        cout << "\n======================================================\n";
    }
};

int main() {
    ArvoreBinaria floresta;

    floresta.inserir(new Personagem("Lupi",        30, "Animal"));
    floresta.inserir(new Personagem("Mago Merlin", 75, "Mago"));
    floresta.inserir(new Personagem("Fennec",      15, "Animal"));
    floresta.inserir(new Personagem("Bruxa Helga", 50, "Mago"));

    floresta.inserir(new Chefe("Chefe Dragao",      90, "Animal", "Montanhas do Norte"));
    floresta.inserir(new Chefe("Arquimago Solaris", 60, "Mago",   "Torre da Luz"));

    floresta.percorrerEmOrdem();

    return 0;
}

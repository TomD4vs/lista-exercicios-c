#include <iostream>
#include <string>

using namespace std;

class Veiculo{
protected:
    string marca;

public:
    Veiculo(string m) : marca(m) {}

    virtual ~Veiculo() {}

    virtual void falar()
    {
        cout << "Marca do veiculo: " << marca << endl;
    }
};

class Carro : public Veiculo
{
private:
    string modelo;

public:
    Carro(string m, string mod)
        : Veiculo(m), modelo(mod) {}

    void falar() override
    {
        cout << "Veiculo: Carro" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << endl;
    }
};

void fazerFalar(Veiculo *v)
{
    v->falar();
    cout << endl;
}

int main()
{
    Veiculo *v1 = new Carro("Ford", "Mustang");
    Veiculo *v2 = new Carro("Lamborghini", "Huracan");

    fazerFalar(v1);
    fazerFalar(v2);

    delete v1;
    delete v2;

    return 0;
}
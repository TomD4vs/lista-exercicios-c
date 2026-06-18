#include <iostream>
#include <string>

using namespace std;

int main()
{
    string loginCorreto = "Elyton";
    string loginDigitado;

    int senhaCorreta = 1234;
    int senhaDigitada;

    int tentativas = 0;
    int limiteTentativas = 3;

    while (tentativas < limiteTentativas)
    {
        cout << "Digite seu login: ";
        cin >> loginDigitado;

        cout << "Digite a senha (Tentativa "
             << tentativas + 1 << " de "
             << limiteTentativas << "): ";
        cin >> senhaDigitada;

        if (loginDigitado == loginCorreto &&
            senhaDigitada == senhaCorreta)
        {
            cout << "Ola, bem vindo "
                 << loginDigitado
                 << "! Acesso Liberado!\n";
            break;
        }
        else
        {
            tentativas++;
            cout << "\nLogin ou senha incorretos!\n";
        }
    }

    if (tentativas == limiteTentativas)
    {
        cout << "Limite de tentativas excedido. Acesso Bloqueado!\n";
    }

    return 0;
}
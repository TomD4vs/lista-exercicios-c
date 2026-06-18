#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int NUM_JOGOS      = 4;
const int NUM_APOSTADORES = 3;

// ========== CLASSE JOGO ==========
class Jogo {
private:
    string timeA;
    string timeB;
    int golsA;
    int golsB;
    bool registrado;

public:
    Jogo() : timeA(""), timeB(""), golsA(0), golsB(0), registrado(false) {}

    Jogo(const string& tA, const string& tB)
        : timeA(tA), timeB(tB), golsA(0), golsB(0), registrado(false) {}

    void setResultado(int ga, int gb) {
        golsA = ga;
        golsB = gb;
        registrado = true;
    }

    int    getGolsA()     const { return golsA; }
    int    getGolsB()     const { return golsB; }
    string getTimeA()     const { return timeA; }
    string getTimeB()     const { return timeB; }
    bool   isRegistrado() const { return registrado; }

    void exibir(int num) const {
        cout << "  Jogo " << num << ": " << timeA << " x " << timeB;
        if (registrado)
            cout << "  ->  " << golsA << " x " << golsB;
        else
            cout << "  ->  (sem resultado)";
        cout << "\n";
    }
};

// ========== CLASSE APOSTADOR ==========
class Apostador {
private:
    string nome;
    Jogo*  palpites;     
    int    numPalpites;
    int    pontuacao;
    bool   apostou;

    // calcula pontos para um jogo: 10 / 5 / 2 / 0
    int pontosJogo(int ga, int gb, int pa, int pb) const {
        if (pa == ga && pb == gb) return 10;

        int resReal    = (ga > gb) ? 1 : (ga < gb) ? -1 : 0;
        int resPalpite = (pa > pb) ? 1 : (pa < pb) ? -1 : 0;

        if (resReal == resPalpite)       return 5;   // vencedor correto (ou empate)
        if (abs(ga - gb) == abs(pa - pb)) return 2;   // diferenca de gols correta
        return 0;
    }

public:
    Apostador() : nome(""), palpites(nullptr), numPalpites(0), pontuacao(0), apostou(false) {}

    ~Apostador() {
        delete[] palpites;
    }

    void registrarAposta(const Jogo* jogos, int numJogos) {
        delete[] palpites;

        cout << "  Nome: ";
        cin >> nome;

        numPalpites = numJogos;
        palpites    = new Jogo[numPalpites];  

        cout << "  Palpites:\n";
        for (int i = 0; i < numPalpites; i++) {
            cout << "    Jogo " << (i + 1)
                 << " (" << jogos[i].getTimeA() << " x " << jogos[i].getTimeB() << "):\n";
            int ga, gb;
            cout << "      Gols " << jogos[i].getTimeA() << ": ";  cin >> ga;
            cout << "      Gols " << jogos[i].getTimeB() << ": ";  cin >> gb;
            palpites[i].setResultado(ga, gb);
        }
        pontuacao = 0;
        apostou   = true;
        cout << "  Aposta de " << nome << " registrada!\n";
    }

    void calcularPontuacao(const Jogo* jogos, int numJogos) {
        pontuacao = 0;
        for (int i = 0; i < numJogos; i++) {
            pontuacao += pontosJogo(
                jogos[i].getGolsA(), jogos[i].getGolsB(),
                palpites[i].getGolsA(), palpites[i].getGolsB()
            );
        }
    }

    void exibirDetalhes(const Jogo* jogos) const {
        cout << "Apostador: " << left << setw(15) << nome
             << " | Total: " << pontuacao << " pts\n";
        for (int i = 0; i < numPalpites; i++) {
            int pa  = palpites[i].getGolsA();
            int pb  = palpites[i].getGolsB();
            int pts = pontosJogo(jogos[i].getGolsA(), jogos[i].getGolsB(), pa, pb);

            string resultado;
            if      (pts == 10) resultado = "[+10 PLACAR EXATO]";
            else if (pts ==  5) resultado = "[+ 5 VENCEDOR/EMPATE]";
            else if (pts ==  2) resultado = "[+ 2 DIFERENCA DE GOLS]";
            else                resultado = "[+ 0 ERROU]";

            cout << "  Jogo " << (i + 1)
                 << " (" << jogos[i].getTimeA() << " x " << jogos[i].getTimeB() << "): "
                 << pa << " x " << pb << "  " << resultado << "\n";
        }
    }

    string getNome()      const { return nome; }
    int    getPontuacao() const { return pontuacao; }
    bool   isApostou()    const { return apostou; }
};

// ========== UTILITARIOS ==========
void limparTela() { system("cls"); }

void pausar() {
    cout << "\nPressione ENTER para continuar...";
    cin.ignore(1000, '\n');
    cin.get();
}

void exibirMenu() {
    cout << "\n==========================================\n";
    cout << "         BOLAO DA COPA DO MUNDO 2026\n";
    cout << "==========================================\n";
    cout << "(1) Registrar resultados oficiais dos jogos\n";
    cout << "(2) Registrar apostas dos jogadores\n";
    cout << "(3) Calcular pontuacao e exibir ranking\n";
    cout << "(4) Sair do programa\n";
    cout << "------------------------------------------\n";
    cout << "Opcao: ";
}

// ========== MAIN ==========
int main() {
    // Vetor ESTATICO de objetos Jogo (pre-definido com os times da rodada)
    Jogo jogos[NUM_JOGOS] = {
        Jogo("BRA", "EGT"),
        Jogo("RSA", "MAR"),
        Jogo("FRA", "ARG"),
        Jogo("GER", "COS")
    };

    Apostador apostadores[NUM_APOSTADORES];

    bool jogosOk   = false;
    bool apostasOk = false;

    int opcao;
    do {
        limparTela();
        exibirMenu();
        cin >> opcao;
        cin.ignore(1000, '\n');
        limparTela();

        switch (opcao) {

        // --- OPCAO 1: resultados oficiais ---
        case 1: {
            cout << "=== REGISTRAR RESULTADOS OFICIAIS ===\n\n";
            for (int i = 0; i < NUM_JOGOS; i++) {
                int ga, gb;
                cout << "Jogo " << (i + 1) << " - "
                     << jogos[i].getTimeA() << " x " << jogos[i].getTimeB() << ":\n";
                cout << "  Gols " << jogos[i].getTimeA() << ": ";  cin >> ga;
                cout << "  Gols " << jogos[i].getTimeB() << ": ";  cin >> gb;
                jogos[i].setResultado(ga, gb);
            }
            jogosOk   = true;
            apostasOk = false; 
            cout << "\nResultados registrados!\n";
            for (int i = 0; i < NUM_JOGOS; i++) jogos[i].exibir(i + 1);
            pausar();
            break;
        }

        // --- OPCAO 2: apostas dos jogadores ---
        case 2: {
            cout << "=== REGISTRAR APOSTAS DOS JOGADORES ===\n\n";
            cout << "Jogos desta rodada:\n";
            for (int i = 0; i < NUM_JOGOS; i++) {
                cout << "  Jogo " << (i + 1) << ": "
                     << jogos[i].getTimeA() << " x " << jogos[i].getTimeB() << "\n";
            }
            cout << "\n";

            for (int i = 0; i < NUM_APOSTADORES; i++) {
                cout << "\n--- Apostador " << (i + 1) << " de " << NUM_APOSTADORES << " ---\n";
                apostadores[i].registrarAposta(jogos, NUM_JOGOS);
            }
            apostasOk = true;
            cout << "\nTodas as apostas foram registradas!\n";
            pausar();
            break;
        }

        // --- OPCAO 3: calcular pontuacao + ranking ---
        case 3: {
            if (!jogosOk) {
                cout << "ATENCAO: registre os resultados oficiais primeiro (opcao 1).\n";
                pausar();
                break;
            }
            if (!apostasOk) {
                cout << "ATENCAO: registre as apostas dos jogadores primeiro (opcao 2).\n";
                pausar();
                break;
            }

            // Calcula pontuacoes
            for (int i = 0; i < NUM_APOSTADORES; i++)
                apostadores[i].calcularPontuacao(jogos, NUM_JOGOS);

            // Ordena por pontuacao (bubble sort descendente via array de indices)
            int idx[NUM_APOSTADORES];
            for (int i = 0; i < NUM_APOSTADORES; i++) idx[i] = i;
            for (int i = 0; i < NUM_APOSTADORES - 1; i++)
                for (int j = 0; j < NUM_APOSTADORES - 1 - i; j++)
                    if (apostadores[idx[j]].getPontuacao() < apostadores[idx[j + 1]].getPontuacao())
                        swap(idx[j], idx[j + 1]);

            // Exibe resultados oficiais
            cout << "=== RESULTADOS OFICIAIS ===\n";
            for (int i = 0; i < NUM_JOGOS; i++) jogos[i].exibir(i + 1);

            // Exibe palpites detalhados
            cout << "\n=== PALPITES E PONTUACOES ===\n\n";
            for (int i = 0; i < NUM_APOSTADORES; i++) {
                apostadores[idx[i]].exibirDetalhes(jogos);
                cout << "\n";
            }

            // Exibe ranking final
            cout << "==========================================\n";
            cout << "              RANKING FINAL\n";
            cout << "==========================================\n";
            cout << left << setw(8) << "Coloc." << setw(20) << "Nome" << "Pontuacao\n";
            cout << "------------------------------------------\n";
            for (int i = 0; i < NUM_APOSTADORES; i++) {
                cout << left
                     << setw(8) << (to_string(i + 1) + "o.")
                     << setw(20) << apostadores[idx[i]].getNome()
                     << apostadores[idx[i]].getPontuacao() << " pts\n";
            }
            cout << "==========================================\n";
            cout << "Regras: placar exato = 10 | vencedor/empate = 5 | diferenca = 2\n";
            pausar();
            break;
        }

        // --- OPCAO 4: sair ---
        case 4:
            cout << "Obrigado por participar do Bolao da Copa 2026!\n";
            cout << "Ate a proxima rodada!\n";
            break;

        default:
            cout << "Opcao invalida! Digite 1, 2, 3 ou 4.\n";
            pausar();
        }

    } while (opcao != 4);

    return 0;
}

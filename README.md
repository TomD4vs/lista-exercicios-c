# Lista Completa de Exercícios — C++

Coleção de exercícios e projetos práticos de C++, organizados por tema, cobrindo desde os fundamentos da linguagem até orientação a objetos e ponteiros.

---

## Estrutura do Projeto

```
Lista Completa Exercicio C++/
├── HelloWord/
├── Fatorial/
├── Fibonacci/
├── Tabuada/
├── Login/
├── Encapsulamento/
├── Herança e Arvores/
├── Ponteiros/
├── bolao-cpp-worldcup26/
└── bolao-cpp-worldcup26_V2/
```

---

## Módulos

### Hello World
**Pasta:** `HelloWord/`

Programa introdutório de saída no console. Ponto de partida para familiarização com o ambiente de compilação.

---

### Fatorial
**Pasta:** `Fatorial/`

Cálculo de fatorial usando **recursão**. Introduz o conceito de função que chama a si mesma com caso base.

---

### Fibonacci
**Pasta:** `Fibonacci/`

Geração da sequência de Fibonacci via **recursão**. Reforça a construção de funções recursivas com dois casos base.

---

### Tabuada
**Pasta:** `Tabuada/`

Geração da tabuada usando laços. Exercício de repetição com `for` e formatação de saída.

---

### Login
**Pasta:** `Login/`

Sistema de autenticação com validação de usuário e senha, controle de **limite de tentativas** e bloqueio de acesso. Exercita condicionais, laços e lógica de controle de fluxo.

---

### Encapsulamento
**Pasta:** `Encapsulamento/`

Série de exercícios sobre **classes e encapsulamento** em C++:

| Arquivo | Descrição |
|---|---|
| `ex1_pessoa.cpp` | Classe `Pessoa` com nome e idade |
| `ex2_cachorro.cpp` | Classe `Cachorro` com raça e método latir |
| `ex3_aluno.cpp` | Classe `Aluno` com notas e cálculo de média |
| `ex4_conta_bancaria.cpp` | Classe `ContaBancaria` com depósito e saque |
| `ex5_animal.cpp` | Classe `Animal` com espécie e emissão de som |

Conceitos: `class`, atributos privados, métodos públicos, construtores.

---

### Herança e Árvores
**Pasta:** `Herança e Arvores/`

Exercícios de **herança e polimorfismo**:

| Arquivo | Descrição |
|---|---|
| `pessoa.cpp` | Classe base `Pessoa` com derivada `Aluno` |
| `marcaVeiculo.cpp` | Hierarquia de veículos com métodos virtuais |
| `funcionario.cpp` | Classe `Funcionario` com salário e destrutor virtual |
| `produtos.cpp` | Classe base `Produto` com derivadas (`Livro`, etc.) |

Conceitos: herança (`:`), `virtual`, polimorfismo, destrutor virtual.

---

### Ponteiros
**Pasta:** `Ponteiros/` 

Exercícios práticos sobre ponteiros:

| Arquivo | Descrição |
|---|---|
| `ex1_trocaValores.cpp` | Troca de valores sem variável auxiliar (XOR com ponteiros) |
| `ex2_ponteiroparaPonteiro.cpp` | Ponteiro para ponteiro com alocação dinâmica (`new`/`delete`) |
| `ex3_calculadoraSegura.cpp` | Calculadora com ponteiro nullable como parâmetro opcional |

Conceitos: desreferenciamento, `int**`, `new`/`delete`, `nullptr`.

---

### Bolão Copa do Mundo 2026
**Pasta:** `bolao-cpp-worldcup26/`

Aplicação de apostas para a Copa do Mundo 2026. O usuário aposta nos resultados das partidas e o sistema compara com os resultados pré-definidos, calculando a pontuação final.

---

### Bolão Copa do Mundo 2026 — V2 (POO)
**Pasta:** `bolao-cpp-worldcup26_V2/`

Reescrita do bolão usando **Programação Orientada a Objetos**. Introduz a classe `Jogo` para encapsular dados e lógica de cada partida, tornando o código mais modular e extensível.

---

## Como compilar

### VS Code
Abra o arquivo `.cpp` desejado e pressione `Ctrl+Shift+B`.

### Terminal
```bash
g++ nome_do_arquivo.cpp -o saida.exe
.\saida.exe
```

> Compilador usado: **g++** via MSYS2/MinGW-w64 (`C:\msys64\ucrt64\bin\g++.exe`)

---

## Progressão de aprendizado

```
Hello World → Fatorial / Fibonacci → Tabuada → Login
     ↓
Encapsulamento → Herança e Polimorfismo → Ponteiros
     ↓
Bolão (procedural) → Bolão V2 (POO)
```

# 🏆 Bolão da Copa 2026

Sistema desenvolvido em **C++** para simular um bolão de futebol da Copa do Mundo. O programa permite que três participantes realizem seus palpites para partidas previamente definidas e calcula automaticamente a pontuação de cada jogador com base nos resultados oficiais.

Ao final da execução, é exibido um ranking dos participantes e os resultados oficiais das partidas.

---

## 📖 Sobre o Projeto

Este projeto foi desenvolvido como atividade prática de programação em C++, com foco na utilização de:

- Variáveis
- Estruturas condicionais (`if` / `else`)
- Estruturas de repetição (`for`)
- Entrada e saída de dados
- Manipulação de strings
- Algoritmos de classificação (ranking)

O sistema simula um bolão esportivo simples, utilizando regras de pontuação semelhantes às encontradas em bolões reais.

---

## ⚽ Jogos do Bolão

Os resultados oficiais já estão definidos diretamente no código.

| Jogo | Confronto | Resultado Oficial |
|------|-----------|------------------|
| 1 | 🇧🇷 BRA x EGT 🇪🇬 | 3 x 0 |
| 2 | 🇿🇦 RSA x MAR 🇲🇦 | 1 x 1 |
| 3 | 🇫🇷 FRA x ARG 🇦🇷 | 1 x 2 |
| 4 | 🇩🇪 GER x COS 🇨🇷 | 4 x 2 |

---

## 🎯 Regras de Pontuação

### ✅ Acertou o placar exato

Exemplo:

Resultado oficial:

```text
BRA 3 x 0 EGT
```

Palpite:

```text
BRA 3 x 0 EGT
```

Pontuação:

```text
+10 pontos
```

---

### ✅ Acertou apenas o vencedor ou empate

Resultado oficial:

```text
BRA 3 x 0 EGT
```

Palpite:

```text
BRA 2 x 1 EGT
```

Pontuação:

```text
+5 pontos
```

O placar está incorreto, porém o participante acertou quem venceu a partida.

---

### ❌ Errou o resultado

Resultado oficial:

```text
BRA 3 x 0 EGT
```

Palpite:

```text
BRA 1 x 2 EGT
```

Pontuação:

```text
0 pontos
```

---

## 🚀 Funcionalidades

- Cadastro de 3 participantes.
- Registro dos palpites para 4 partidas.
- Cálculo automático da pontuação.
- Comparação entre palpites e resultados oficiais.
- Geração automática de ranking.
- Exibição da classificação final.
- Exibição dos resultados oficiais ao término da execução.

---

## 🛠 Tecnologias Utilizadas

- C++
- Biblioteca `<iostream>`
- Biblioteca `<string>`

---

## 📂 Estrutura do Projeto

```text
Bolao-Copa-2026/
│
├── aposta.cpp
├── README.md
│
└── Executável gerado após compilação
```

---

## 🔍 Lógica do Programa

### 1. Definição dos Resultados Oficiais

Os resultados dos jogos são armazenados em variáveis:

```cpp
int realA1 = 3, realB1 = 0;
int realA2 = 1, realB2 = 1;
int realA3 = 1, realB3 = 2;
int realA4 = 4, realB4 = 2;
```

---

### 2. Cadastro dos Participantes

O programa solicita o nome dos três integrantes do bolão:

```cpp
Digite o nome do integrante 1:
Digite o nome do integrante 2:
Digite o nome do integrante 3:
```

---

### 3. Registro dos Palpites

Cada participante informa o número de gols para os quatro jogos.

Exemplo:

```text
[BRA x EGT]

Gols BRA: 3
Gols EGT: 0
```

---

### 4. Cálculo dos Pontos

O sistema compara cada palpite com o resultado oficial.

Regras:

- Placar exato → 10 pontos
- Mesmo vencedor/empate → 5 pontos
- Resultado incorreto → 0 pontos

---

### 5. Geração do Ranking

Após calcular as pontuações, o programa compara os participantes e define:

```text
1º Lugar
2º Lugar
3º Lugar
```

---

## 💻 Como Compilar

### Linux

```bash
g++ aposta.cpp -o aposta
```

Executar:

```bash
./aposta
```

---

### Windows (MinGW)

Compilar:

```bash
g++ aposta.cpp -o aposta.exe
```

Executar:

```bash
aposta.exe
```

---

## 📷 Exemplo de Execução

```text
========================================
           BOLAO DA COPA 2026
========================================

Digite o nome do integrante 1: Maria

Apostas de Maria:

[BRA x EGT]
Gols BRA: 3
Gols EGT: 0

-> Acertou em cheio! (+10 pontos)

[BRA x EGT]
...
```

Saída final:

```text
========================================
             RANKING FINAL
========================================

1o Lugar: Maria com 35 pontos.
2o Lugar: João com 20 pontos.
3o Lugar: Pedro com 15 pontos.
```

---

## 📊 Fluxograma Simplificado

```text
Início
  │
  ▼
Cadastrar Participantes
  │
  ▼
Receber Palpites
  │
  ▼
Comparar com Resultados Oficiais
  │
  ▼
Calcular Pontuação
  │
  ▼
Gerar Ranking
  │
  ▼
Exibir Resultados Oficiais
  │
  ▼
Fim
```

---

## 🎓 Conceitos Aplicados

Durante o desenvolvimento deste projeto foram utilizados os seguintes conceitos da linguagem C++:

- Variáveis primitivas
- Operadores relacionais
- Operadores lógicos
- Estruturas condicionais
- Estruturas de repetição
- Manipulação de strings
- Entrada e saída padrão
- Organização lógica de algoritmos

---

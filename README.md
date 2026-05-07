# 🧬 Jogo da Vida de Conway — Autômato Celular

Trabalho Prático 1 da disciplina **Estruturas de Dados 1** 

---

## 📋 Descrição

Implementação do [Jogo da Vida de Conway](https://pt.wikipedia.org/wiki/Jogo_da_vida) em linguagem C. O programa simula um autômato celular em uma grade bidimensional n×n, onde cada célula pode estar **viva** (`1`) ou **morta** (`0`), evoluindo ao longo de gerações conforme as regras clássicas do jogo.

### Regras do Jogo da Vida

- Uma célula **viva** com 2 ou 3 vizinhos vivos **sobrevive**
- Uma célula **viva** com menos de 2 ou mais de 3 vizinhos vivos **morre**
- Uma célula **morta** com exatamente 3 vizinhos vivos **nasce**

---

## 📁 Estrutura do Projeto

```
.
├── automato.h          # Declarações da estrutura Tabuleiro e funções
├── automato.c          # Implementação das funções do autômato
├── tp.c                # Arquivo principal (main)
├── Makefile            # Script de compilação
├── corretor.py         # Script de correção automática por casos de teste
├── docs/
│   ├── main.tex        # Relatório em LaTeX
│   └── setup.tex       # Configurações do LaTeX
└── tests/              # Casos de teste (.in / .out)
```

---

## ⚙️ Compilação e Execução

### Usando o Makefile (recomendado)

```bash
make        # Compila e gera o executável ./exe
make run    # Executa o programa
```

### Manualmente

```bash
gcc -g -o exe tp.c automato.c -Wall
```

### Executando com entrada manual

```bash
./exe
```

O programa lê da **entrada padrão** no seguinte formato:

```
<n> <geracoes>
<estado inicial do tabuleiro n×n com 0s e 1s>
```

**Exemplo:**

```
3 2
0 1 0
0 0 1
1 1 1
```

### Verificação de vazamento de memória (Valgrind)

```bash
valgrind --leak-check=full -s ./exe
```

---

## 🧪 Testes Automáticos

O script `corretor.py` roda todos os casos de teste da pasta `tests/` e calcula a nota automaticamente. Cada caso de teste é composto por um arquivo `.in` (entrada) e um `.out` (saída esperada).

```bash
python3 corretor.py
```

> ⚠️ É necessário ter uma pasta `tests/` com ao menos um par de arquivos `.in` / `.out`.

---

## 🗂️ Funções Implementadas

| Função | Descrição |
|---|---|
| `alocarReticulado(n)` | Aloca memória para um tabuleiro n×n |
| `desalocarReticulado(&tab)` | Libera toda a memória do tabuleiro |
| `LeituraReticulado(tab)` | Lê o estado inicial via entrada padrão |
| `evoluirReticulado(tab, n, geracoes)` | Evolui o tabuleiro recursivamente por N gerações |
| `imprimeReticulado(tab)` | Imprime o estado atual do tabuleiro |

---

## 📊 Análise de Desempenho

Testado com Valgrind no caso de teste `20.in`:

- ✅ **Sem vazamentos de memória** — `All heap blocks were freed -- no leaks are possible`
- ✅ **Sem erros** — `ERROR SUMMARY: 0 errors from 0 contexts`

---

## 👥 Autores

- Fábio Tavares Pinto  
- Hugo Augusto Silva de Faria

**Professor:** Pedro Henrique Lopes Silva

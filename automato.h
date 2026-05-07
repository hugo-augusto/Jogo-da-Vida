#pragma once  // Garante que este arquivo de cabeçalho será incluído apenas uma vez no processo de compilação

typedef struct {
    int n;            // A dimensão do tabuleiro (n x n)
    int **matriz;     // Ponteiro para uma matriz de inteiros que representa o tabuleiro
} Tabuleiro;

// Função para alocar memória para o tabuleiro e a matriz
Tabuleiro* alocarReticulado(int n);

// Função para desalocar a memória do tabuleiro
void desalocarReticulado(Tabuleiro **tab);

// Função para ler o tabuleiro
void LeituraReticulado(Tabuleiro *tab);

// Função para evoluir o estado do tabuleiro para a geracao N de acordo com as regras do jogo da vida
Tabuleiro* evoluirReticulado(Tabuleiro *tab, int n,int geracoes);

// Função para imprimir o estado do tabuleiro na tela
void imprimeReticulado(Tabuleiro *tab);
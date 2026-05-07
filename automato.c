#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

Tabuleiro *alocarReticulado(int n)
{
    // Aloca memória para o struct Tabuleiro.
    Tabuleiro *tab = (Tabuleiro *)malloc(sizeof(Tabuleiro));
    if (tab == NULL)
    {
        printf("Erro de memória\n");
        return NULL;
    }

    // Inicializa a dimensão do tabuleiro.
    tab->n = n;

    // Aloca memória para a matriz do tabuleiro.
    tab->matriz = (int **)malloc(n * sizeof(int *));
    if (tab->matriz == NULL)
    {
        printf("Erro de memória\n");
        return NULL;
    }

    // Aloca memória para cada linha da matriz.
    for (int i = 0; i < n; i++)
    {
        tab->matriz[i] = (int *)malloc(n * sizeof(int));
        if (tab->matriz[i] == NULL)
        {
            printf("Erro de memória\n");
            return NULL;
        }
    }

    return tab;
}

void desalocarReticulado(Tabuleiro **tab)
{
    if (tab == NULL || *tab == NULL || (*tab)->matriz == NULL)
    {
        return;
    }

    // Libera a memória de cada linha da matriz.
    for (int i = 0; i < (*tab)->n; i++)
    {
        free((*tab)->matriz[i]);
    }

    // Libera a memória da matriz e do struct Tabuleiro.
    free((*tab)->matriz);
    free(*tab);
}

void LeituraReticulado(Tabuleiro *tab)
{
    // Lê o estado inicial do tabuleiro.
    for (int i = 0; i < tab->n; i++)
    {
        for (int j = 0; j < tab->n; j++)
        {
            scanf("%d", &tab->matriz[i][j]);
        }
    }
}

Tabuleiro *evoluirReticulado(Tabuleiro *tab, int n, int geracoes)
{
    // Caso base: se não há mais gerações para evoluir, retorne o tabuleiro atual.
    if (geracoes == 0)
    {
        return tab; // Se o número de gerações restantes é 0, retornamos o tabuleiro atual, que representa o estado após todas as gerações solicitadas.
    }

    // Evolui o tabuleiro para a próxima geração.
    // Cria um novo tabuleiro para armazenar o estado da próxima geração.
    Tabuleiro *novoTabuleiro = alocarReticulado(n);

    // Verifica se a alocação foi bem-sucedida.
    if (novoTabuleiro == NULL)
    {
        return NULL; // Se a alocação falhar, retorna NULL. Isso indica um erro na alocação de memória.
    }

    // Aplica as regras do Jogo da Vida para definir o próximo estado da célula (i, j).
    // Percorre cada célula no tabuleiro atual.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int vizinhosVivos = 0; // Conta o número de vizinhos vivos da célula (i, j).

            // Verifica todas as células ao redor da célula atual (i, j), incluindo diagonais.
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    // Ignora a própria célula (i, j).
                    if (di == 0 && dj == 0)
                        continue;

                    int ni = i + di; // Calcula a linha do vizinho.
                    int nj = j + dj; // Calcula a coluna do vizinho.

                    // Verifica se o vizinho está dentro dos limites do tabuleiro.
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n)
                    {
                        // Adiciona o valor da célula vizinha ao contador de vizinhos vivos.
                        vizinhosVivos += tab->matriz[ni][nj];
                    }
                }
            }

            // Aplica as regras do Jogo da Vida para atualizar o estado da célula (i, j).
            if (tab->matriz[i][j] == 1) // Se a célula está viva.
            {
                // A célula continua viva se tiver 2 ou 3 vizinhos vivos; caso contrário, morre.
                if (vizinhosVivos == 2 || vizinhosVivos == 3)
                    novoTabuleiro->matriz[i][j] = 1; // Continua viva.
                else
                    novoTabuleiro->matriz[i][j] = 0; // Morre.
            }
            else // Se a célula está morta.
            {
                // A célula se torna viva se tiver exatamente 3 vizinhos vivos; caso contrário, permanece morta.
                if (vizinhosVivos == 3)
                    novoTabuleiro->matriz[i][j] = 1; // Torna-se viva.
                else
                    novoTabuleiro->matriz[i][j] = 0; // Permanece morta.
            }
        }
    }

    // Desaloca o tabuleiro antigo para liberar memória.
    desalocarReticulado(&tab);

    // Chama a função recursivamente para o próximo número de gerações.
    // Atualiza o tabuleiro para a nova geração e decrementa o número de gerações restantes.
    return evoluirReticulado(novoTabuleiro, n, geracoes - 1);
}

void imprimeReticulado(Tabuleiro *tab)
{
    printf("\n");

    for (int i = 0; i < tab->n; i++)
    {
        for (int j = 0; j < tab->n; j++)
        {
            // Imprime o valor de cada célula do tabuleiro seguido de um espaço.
            printf("%d ", tab->matriz[i][j]);
        }
        // Imprime uma nova linha após cada linha do tabuleiro.
        printf("\n");
    }
}
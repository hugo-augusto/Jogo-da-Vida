#include <stdio.h>
#include <stdlib.h>
#include "automato.h"

int main()
{
    int n, geracoes;

    // Lê a dimensão do tabuleiro e o número de gerações.
    scanf("%d %d", &n, &geracoes);

    // Aloca memória para o Tabuleiro com a dimensão lida.
    Tabuleiro *tab = alocarReticulado(n);

    // Le o estado inicial do tabuleiro.
    LeituraReticulado(tab);

    // Evolui o tabuleiro após n geracoes.
    tab = evoluirReticulado(tab, n, geracoes);

    // Imprime o estado do novo tabuleiro.
    imprimeReticulado(tab);

    // Desaloca a memória do tabuleiro final.
    desalocarReticulado(&tab);

    return 0;
}

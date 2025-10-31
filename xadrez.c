#include <stdio.h>

/* ============================================================
   PROGRAMA: Simulação de Movimentos de Peças de Xadrez (Nível Avançado)
   PEÇAS: Torre, Bispo, Rainha e Cavalo
   OBJETIVO: Aplicar recursividade, loops aninhados e controle de fluxo.
   ============================================================ */

/* ------------------------------------------------------------
   FUNÇÃO RECURSIVA - TORRE
   Move-se em linha reta (5 casas para a direita).
   ------------------------------------------------------------ */
void moverTorre(int atual, int limite) {
    if (atual > limite) return; // Caso base da recursão

    printf("Direita (%d)\n", atual);
    moverTorre(atual + 1, limite); // chamada recursiva
}

/* ------------------------------------------------------------
   FUNÇÃO RECURSIVA + LOOPS ANINHADOS - BISPO
   Move-se na diagonal (5 casas para cima e à direita).
   Loop externo: movimento vertical (recursivo)
   Loop interno: movimento horizontal (for)
   ------------------------------------------------------------ */
void moverBispo(int vertical, int limite) {
    if (vertical > limite) return; // Caso base

    // Loop interno para o movimento horizontal
    for (int horizontal = 1; horizontal <= limite; horizontal++) {
        printf("Cima, Direita (%d,%d)\n", vertical, horizontal);
    }

    // Chamada recursiva para o próximo movimento vertical
    moverBispo(vertical + 1, limite);
}

/* ------------------------------------------------------------
   FUNÇÃO RECURSIVA - RAINHA
   Move-se em todas as direções.
   Neste exemplo: 8 casas para a esquerda.
   ------------------------------------------------------------ */
void moverRainha(int atual, int limite) {
    if (atual > limite) return; // Caso base

    printf("Esquerda (%d)\n", atual);
    moverRainha(atual + 1, limite);
}

/* ------------------------------------------------------------
   LOOPS COMPLEXOS - CAVALO
   Move-se em "L": duas casas para cima e uma para a direita.
   Usa loops aninhados com múltiplas condições, e controle
   de fluxo (continue e break).
   ------------------------------------------------------------ */
void moverCavalo() {
    int casasCima = 2;
    int casasDireita = 1;
    int contadorMovimentos = 0;

    printf("===== Movimento do CAVALO =====\n");

    // Loop externo: movimento vertical (para cima)
    for (int i = 1; i <= casasCima; i++) {

        // Loop interno: movimento horizontal (para a direita)
        int j = 1;
        while (j <= casasDireita) {
            // Condição para simular o movimento em "L"
            if (i < casasCima) {
                printf("Cima (%d)\n", i);
            } else if (i == casasCima && j == casasDireita) {
                printf("Direita (%d)\n", j);
            } else {
                // Controle de fluxo (ignora condições inválidas)
                j++;
                continue;
            }

            contadorMovimentos++;

            // Interrompe caso já tenha feito os 3 passos
            if (contadorMovimentos >= 3)
                break;

            j++;
        }

        // Sai completamente se já tiver feito o movimento completo
        if (contadorMovimentos >= 3)
            break;
    }
}

/* ------------------------------------------------------------
   FUNÇÃO PRINCIPAL
   ------------------------------------------------------------ */
int main() {
    int casasTorre = 5;
    int casasBispo = 5;
    int casasRainha = 8;

    printf("===== Movimento da TORRE =====\n");
    moverTorre(1, casasTorre);

    printf("\n===== Movimento do BISPO =====\n");
    moverBispo(1, casasBispo);

    printf("\n===== Movimento da RAINHA =====\n");
    moverRainha(1, casasRainha);

    printf("\n");
    moverCavalo(); // chamada da função do cavalo

    printf("\n===== FIM DA SIMULAÇÃO =====\n");

    return 0;
}

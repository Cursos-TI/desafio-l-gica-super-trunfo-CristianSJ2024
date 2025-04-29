#include <stdio.h>
#include <string.h>

// Definição da estrutura de carta
typedef struct {
    char nome[50];
    int populacao;
    int area;
    int densidade;
    int pib;
} Carta;

// Função para exibir os atributos disponíveis
void exibirAtributosDisponiveis(int selecionado) {
    printf("\nEscolha um atributo:\n");
    if (selecionado != 1) printf("1. População\n");
    if (selecionado != 2) printf("2. Área\n");
    if (selecionado != 3) printf("3. Densidade Demográfica (Menor vence)\n");
    if (selecionado != 4) printf("4. PIB\n");
}

// Função para obter o valor do atributo da carta
int obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.densidade;
        case 4: return carta.pib;
        default: return -1;
    }
}

// Função para exibir o nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "Densidade Demográfica";
        case 4: return "PIB";
        default: return "Desconhecido";
    }
}

// Função principal
int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 211000000, 8515767, 25, 22000};
    Carta carta2 = {"Canadá", 38000000, 9984670, 4, 17000};

    int atributo1 = 0, atributo2 = 0;

    // Menu para escolher o primeiro atributo
    while (atributo1 < 1 || atributo1 > 4) {
        exibirAtributosDisponiveis(0);
        printf("Digite o número do primeiro atributo: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 4) {
            printf("Opção inválida. Tente novamente.\n");
        }
    }

    // Menu dinâmico para o segundo atributo
    while (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1) {
        exibirAtributosDisponiveis(atributo1);
        printf("Digite o número do segundo atributo: ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 4 || atributo2 == atributo1) {
            printf("Opção inválida ou atributo repetido. Tente novamente.\n");
        }
    }

    // Comparação de atributos
    int valor1_c1 = obterValorAtributo(carta1, atributo1);
    int valor2_c1 = obterValorAtributo(carta1, atributo2);
    int valor1_c2 = obterValorAtributo(carta2, atributo1);
    int valor2_c2 = obterValorAtributo(carta2, atributo2);

    // Avaliação individual dos atributos
    int ponto_c1 = 0, ponto_c2 = 0;

    // Atributo 1
    if (atributo1 == 3) { // Densidade Demográfica: menor vence
        (valor1_c1 < valor1_c2) ? ponto_c1++ : (valor1_c1 > valor1_c2) ? ponto_c2++ : 0;
    } else {
        (valor1_c1 > valor1_c2) ? ponto_c1++ : (valor1_c1 < valor1_c2) ? ponto_c2++ : 0;
    }

    // Atributo 2
    if (atributo2 == 3) { // Densidade Demográfica: menor vence
        (valor2_c1 < valor2_c2) ? ponto_c1++ : (valor2_c1 > valor2_c2) ? ponto_c2++ : 0;
    } else {
        (valor2_c1 > valor2_c2) ? ponto_c1++ : (valor2_c1 < valor2_c2) ? ponto_c2++ : 0;
    }

    int soma1 = valor1_c1 + valor2_c1;
    int soma2 = valor1_c2 + valor2_c2;

    // Exibição dos resultados
    printf("\n===== Resultado da Rodada =====\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("  %s: %d\n", nomeAtributo(atributo1), valor1_c1);
    printf("  %s: %d\n", nomeAtributo(atributo2), valor2_c1);
    printf("  Soma: %d\n", soma1);

    printf("\nCarta 2: %s\n", carta2.nome);
    printf("  %s: %d\n", nomeAtributo(atributo1), valor1_c2);
    printf("  %s: %d\n", nomeAtributo(atributo2), valor2_c2);
    printf("  Soma: %d\n", soma2);

    // Resultado final
    if (soma1 > soma2) {
        printf("\n>>> Vencedor: %s <<<\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("\n>>> Vencedor: %s <<<\n", carta2.nome);
    } else {
        printf("\n>>> Empate! <<<\n");
    }

    return 0;
}

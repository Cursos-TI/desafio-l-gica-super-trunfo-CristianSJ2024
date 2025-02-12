#include <stdio.h>

int main() {
    int codigo;
    char nome[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    
    printf("Digite o código da cidade: \n");
    scanf("%d", &codigo);
    printf("Digite o nome da cidade: \n");
    scanf("%s", &nome);
    printf("Digite a população da cidade: \n");
    scanf("%d", &populacao);
    printf("Digite o PIB da cidade: \n");
    scanf("%f", &pib);
    printf("Digite a quantidade de pontos turísticos da cidade: \n");
    scanf("%d", &pontosTuristicos);

    printf("Digite o código da cidade 2: \n");
    scanf("%d", &codigo);
    printf("Digite o nome da cidade 2: \n");
    scanf("%s", &nome);
    printf("Digite a população da cidade 2: \n");
    scanf("%d", &populacao);
    printf("Digite o PIB da cidade 2: \n");
    scanf("%f", &pib);
    printf("Digite a quantidade de pontos turísticos da cidade 2: \n");
    scanf("%d", &pontosTuristicos);
    
    if (populacao > 12.000000) {
        printf("A cidade 1 tem maior população. \n");
    } else {
        printf("Cidade 2 tem maior população. \n");
    }

    if (area > 1.523) {
        printf("A cidade 1 tem maior áera. \n");
    } else {
        printf("A cidade 2 tem maior área. \n");
    }
    
    if (pib > 1.600000000000) {
        printf("A cidade 1 tem maior PIB, \n");
    } else {
        printf("A cidade 2 tem maior PIB. \n");
    }

    if (pontosTuristicos > 36) {
        printf("A cidade 1 tem mais pontos turísticos. \n");
    } else {
        printf("A cidade 2 tem mais pontos tirísticos. \n");
    }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}

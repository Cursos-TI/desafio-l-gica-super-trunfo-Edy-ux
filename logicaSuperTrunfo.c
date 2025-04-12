#include <stdio.h>
#include <locale.h>

/*Jogo de cartas Super Trunfo
O jogo consiste em duas cartas, cada uma representando uma cidade do Brasil.
O jogador escolhe um atributo (população, área, PIB ou pontos turísticos) e compara os valores das cartas.
*/

//  Estrutuca de uma carta
struct Carta
{
    char estado[50];
    char codigo[20];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};
// Função para cadastrar os dados de uma carta
void cadastrarCarta(struct Carta *carta)
{
    printf("Estado: ");
    scanf("%s", &carta->estado);

    printf("Código da carta: ");
    scanf("%s", &carta->codigo);

    printf("Nome da cidade: ");
    scanf("%s", &carta->nomeCidade);

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    printf("=============================\n");

    // Limpar o buffer do teclado
    getchar();
}

// Função para comparar duas cartas e determinar o vencedor
void compararCartas(struct Carta carta1, struct Carta carta2, int atributo)
{

    // Comparar os atributos das cartas com base no atributo escolhido
    // 1 - População
    // 2 - Área
    // 3 - PIB
    // 4 - Pontos turísticos
    printf("Comparação de cartas (Atributo: %s)\n", atributo == 1 ? "População" : atributo == 2 ? "Área"
                                                                              : atributo == 3   ? "PIB"
                                                                                                : "Pontos turísticos");
    switch (atributo)
    {
    case 1:
        printf("Carta 1: %s: %d \n", carta1.nomeCidade, carta1.populacao);
        printf("Carta 2: %s: %d \n", carta2.nomeCidade, carta2.populacao);
        if ((int)(carta1.populacao > carta2.populacao))
            printf("carta1 venceu  \n"); // carta1 vence
        else if (carta1.populacao < carta2.populacao)
            printf("carta1 venceu \n"); // carta2 vence
        else
            printf("Empate");
        break;
    case 2:
        printf("Carta 1: %s: %f \n", carta1.nomeCidade, carta1.area);
        printf("Carta 2: %s: %f \n", carta2.nomeCidade, carta2.area);
        if ((int)(carta1.area > carta2.area))
            printf("carta1 venceu"); // carta1 vence
        else if (carta1.area < carta2.area)
            printf("carta1 venceu"); // carta2 vence
        else
            printf("Empate");
        break;
    case 3:
        printf("Carta 1: %s: %f \n", carta1.nomeCidade, carta1.pib);
        printf("Carta 2: %s: %f \n", carta2.nomeCidade, carta2.pib);
        if ((int)(carta1.pib > carta2.pib))
            printf("carta1 venceu"); // carta1 vence
        else if (carta1.pib < carta2.pib)
            printf("carta1 venceu"); // carta2 vence
        else
            printf("Empate");
        break;
    case 4:
        printf("Carta 1: %s: %d \n", carta1.nomeCidade, carta1.pontosTuristicos);
        printf("Carta 2: %s: %d \n", carta2.nomeCidade, carta2.pontosTuristicos);
        if ((int)(carta1.pontosTuristicos > carta2.pontosTuristicos))
            printf("carta1 venceu"); // carta1 vence
        else if (carta1.pontosTuristicos < carta2.pontosTuristicos)
            printf("carta1 venceu \n"); // carta2 vence
        else
            printf("Empate");
        break;

    default:
        printf("Atributo inválido");
        break;
    }
}

int main()
{
    int atributo;
    struct Carta carta1, carta2;

    cadastrarCarta(&carta1);
    cadastrarCarta(&carta2);

    printf("Escolha o atributo para comparar as cartas: \n\n");
    printf("> População escolha 1 \n");
    printf("> Área escolha 2\n");
    printf("> PIB escolha 3\n");
    printf("> Pontos turísticos escolha 4\n");
    printf("=============================\n");

    scanf("%d", &atributo);
    // Mostrar vencedor
    compararCartas(carta1, carta2, atributo);

    return 0;
}
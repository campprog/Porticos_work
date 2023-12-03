#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void clearConsole()
{
    printf("\033[2J\033[H");
}
struct Portico
{
    int id;
    float motorcyclePrice;
    float lightVehiclePrice;
    float heavyVehiclePrice;
};

typedef struct Portico portico;

void addPortico(portico p[], int *nrOfporticos)
{
    clearConsole();
    portico newPortico;

    printf("insira o numero do portico: ");
    scanf("%d", &newPortico.id);

    for (int i = 0; i < *nrOfporticos; i++)
    {
        if (newPortico.id == p[i].id)
        {
            printf("ja existe esse numero");
            return;
        }
    }
    printf("insira o preço da passagem do motociclo: ");
    scanf("%f", &newPortico.motorcyclePrice);
    printf("insira o preço da passagem do veiculo ligeiro: ");
    scanf("%f", &newPortico.lightVehiclePrice);
    printf("insira o preço da passagem do veiculo pesado: ");
    scanf("%f", &newPortico.heavyVehiclePrice);

    p[*nrOfporticos] = newPortico;
    (*nrOfporticos)++;
};

void listPorticos(portico p[], int nrOfporticos)
{
    clearConsole();
    printf("%d", nrOfporticos);
    for (int i = 0; i < nrOfporticos; i++)
    {
        printf("\n---------------------------------------------------------------------\n");
        printf("id: %d \n", p[i].id);
        printf("Motociclos: %f \n", p[i].motorcyclePrice);
        printf("Veiculos ligeiros: %f \n", p[i].lightVehiclePrice);
        printf("Veiculos pesados %f \n", p[i].heavyVehiclePrice);
        printf("---------------------------------------------------------------------\n");
    }
}
void editPrices(portico p[], int nrOfporticos)
{

    clearConsole();
    int EditPortico;
    printf("Insira o número do portico que deseja editar: ");
    scanf("%d", &EditPortico);

    for (int i = 0; i < nrOfporticos; i++)
    {
        if (EditPortico == p[i].id)
        {
            printf("Insira o novo preço do motociclo: ");
            scanf("%f", &p[i].motorcyclePrice);
            printf("Insira o novo preço do veiculo ligeiro: ");
            scanf("%f", &p[i].lightVehiclePrice);
            printf("Insira o novo preço do veiculo pesado: ");
            scanf("%f", &p[i].heavyVehiclePrice);
            printf("Preços do Portico Atualizado!");
            return;
        }
    }
}
int main(int argc, char const *argv[])
{
    int nrOfporticos = 4;
    int option;

    portico p[500] = {
        {1, 3, 2, 1},
        {2, 2, 1, 3},
        {3, 1, 1, 1},
        {4, 3, 2, 1}

    };

    do
    {
        printf("\n 1 - Inserir pórticos com tabela de preços");
        printf("\n 2 - Listar Pórticos ");
        printf("\n 3 - Alterar Preços do Pórtico");
        printf("\n 4 -  Inserir passagem num Pórtico ");
        printf("\n 5 - Rendimento Diário por Pórtico ");
        printf("\n 6 - Tráfego diário por classe de Veículo");
        printf("\n 7 - Rendimento diário por classe de Veículo");
        printf("\n 8 - Preço Pórtico por classe");
        printf("\n 9 - Média Tráfego por Pórtico");
        printf("\n 10 - Tráfego Total por Pórticos");
        printf("\n 11 - Total passagens em todos os Pórticos");
        printf("\n 12 - Listar a passagem em um Pórtico");
        printf("\n 13 - Passagem totais de um Veiculo por Pórtico");
        printf("\n 14 - Rendimento total");
        printf("\n 15 - Total de gastos por Veículo");
        printf("\n 16 - Pórtico com maior tráfego");
        printf("\n\n Escolha uma opcao: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {

            addPortico(p, &nrOfporticos);
            break;
        }
        case 2:
        {
            printf("\n\n Opcao escolhida: 2 ");
            listPorticos(p, nrOfporticos);
            break;
        }

        case 3:
        {

            printf("\n\n Opcao escolhida: 3 ");
            editPrices(p, nrOfporticos);
            break;
        }

        case 4:
        {

            printf("\n\n Opcao escolhida: 4 ");
            break;
        }
        case 5:
        {

            printf("\n\n Opcao escolhida: 5 ");
            break;
        }
        case 6:
        {

            printf("\n\n Opcao escolhida: 6 ");
            break;
        }
        case 7:
        {

            printf("\n\n Opcao escolhida: 7 ");
            break;
        }
        case 8:
        {

            printf("\n\n Opcao escolhida: 8 ");
            break;
        }
        case 9:
        {

            printf("\n\n Opcao escolhida: 9 ");
            break;
        }
        case 10:
        {

            printf("\n\n Opcao escolhida: 10 ");
            break;
        }
        case 11:
        {

            printf("\n\n Opcao escolhida: 11 ");
            break;
        }
        case 12:
        {

            printf("\n\n Opcao escolhida: 12 ");
            break;
        }
        case 13:
        {

            printf("\n\n Opcao escolhida: 13 ");
            break;
        }
        case 14:
        {

            printf("\n\n Opcao escolhida: 14 ");
            break;
        }
        case 15:
        {

            printf("\n\n Opcao escolhida: 15 ");
            break;
        }
        case 16:
        {

            printf("\n\n Opcao escolhida: 16 ");
            break;
        }
        default:
        {

            printf("\n\n Opcao invalida ");
            break;
        }
        case 17:
        {

            printf("\n\n Sair do programa");
            break;
        }
        }

    } while (option != 17);

    return 0;
}

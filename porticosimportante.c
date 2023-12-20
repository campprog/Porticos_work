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
    int totalPassages;
    // int nrMotorcyclepasses;
    // int nrLightVehiclepasses;
    // int nrHeavyVehicle;
};
/*struct Veiculo
{
    int id;
    int class;
    char licensePlate[8];

};*/
struct Passage
{
    int licensePlate;
    int vehicleClass;
    int porticoId;
    int day;
    int hour;
};
// podemos meter int id em vez de ter que usar o formato de matricula- Usar o formato da matricula com o Char hhh
// Como se mete as horas, apenas necessario meter a hora ou tambem os minutos e as datas como se metem tambem?
typedef struct Portico portico;
typedef struct Passage passage;

void addPortico(portico p[], int *nrOfporticos)
{
    clearConsole();
    portico newPortico;

    printf("Insira o número do pórtico: ");
    scanf("%d", &newPortico.id);

    for (int i = 0; i < *nrOfporticos; i++)
    {
        if (newPortico.id == p[i].id)
        {
            printf("Já existe um pórtico com esse número!");
            return;
        }
    }
    printf(" Insira o preço da passagem do motociclo: ");
    scanf("%f", &newPortico.motorcyclePrice);
    printf(" Insira o preço da passagem do veículo ligeiro: ");
    scanf("%f", &newPortico.lightVehiclePrice);
    printf(" Insira o preço da passagem do veículo pesado: ");
    scanf("%f", &newPortico.heavyVehiclePrice);

    newPortico.totalPassages = 0;

    p[*nrOfporticos] = newPortico;
    (*nrOfporticos)++;
}

void listPorticos(portico p[], int nrOfporticos)
{
    clearConsole();
    printf("%d", nrOfporticos);
    for (int i = 0; i < nrOfporticos; i++)
    {
        printf("\n---------------------------------------------------------------------\n");
        printf(" ID: %d \n", p[i].id);
        printf(" Motociclos: %f \n", p[i].motorcyclePrice);
        printf(" Veículos ligeiros: %f \n", p[i].lightVehiclePrice);
        printf(" Veículos pesados %f \n", p[i].heavyVehiclePrice);
        printf("---------------------------------------------------------------------\n");
    }
}
void editPrices(portico p[], int nrOfporticos)
{
    clearConsole();
    int EditPortico;
    printf("Insira o número do pórtico no qual deseja editar: ");
    scanf("%d", &EditPortico);

    for (int i = 0; i < nrOfporticos; i++)
    {
        if (EditPortico == p[i].id)
        {
            printf("Insira o novo preço do motociclo: ");
            scanf("%f", &p[i].motorcyclePrice);
            printf("Insira o novo preço do veículo ligeiro: ");
            scanf("%f", &p[i].lightVehiclePrice);
            printf("Insira o novo preço do veículo pesado: ");
            scanf("%f", &p[i].heavyVehiclePrice);
            printf("Preços do Pórtico Atualizado!");
            return;
        }
    }
}

void priceCheckForEachClass(portico porticos[], int nrOfporticos)
{
    int porticoid;
    int porticoClass;
    int porticoPosition;
    printf("\nEscolha o Pórtico: ");
    scanf("%d", &porticoid);

    for (int i = 0; i < nrOfporticos; i++)
    {
        if (porticoid == porticos[i].id)
        {
            printf(" Escolha a classe: \n");
            printf(" Motociclo: 1\n");
            printf(" Veículos Ligeiros: 2\n");
            printf(" Veículos Pesados: 3\n");
            scanf("%d", &porticoClass);

            if (porticoClass == 1)
            {
                printf(" Preço do Motociclo: %f", porticos[i].motorcyclePrice);
            }
            else if (porticoClass == 2)
            {
                printf(" Preço do Veículo Ligeiro: %f", porticos[i].lightVehiclePrice);
            }
            else if (porticoClass == 3)
            {
                printf(" Preço do Veículo Pesado: %f", porticos[i].heavyVehiclePrice);
            }
            else
            {
                printf(" Opção Inválida!");
            }
            return;
        }
    }
    printf(" Lamento, mas esse Pórtico não existe.");
}

void insertPassage(passage passages[], int *nrOfPassages, int nrOfporticos, portico porticos[])
{
    clearConsole();
    passage newPassage;
    printf("\n Insira o pórtico de passagem:\n");
    scanf("%d", &newPassage.porticoId);
    clearConsole();
    for (int i = 0; i < nrOfporticos; i++)
    {
        if (newPassage.porticoId == porticos[i].id)
        {
            printf(" Insira a matricula:\n ");
            scanf("%d", &newPassage.licensePlate);
            clearConsole();
            printf(" Insira a classe do veículo:\n");
            printf(" Motociclo: 1\n");
            printf(" Veículos Ligeiros: 2\n");
            printf(" Veículos Pesados: 3\n");
            scanf("%d", &newPassage.vehicleClass);
            clearConsole();
            printf(" Insira a data:\n ");
            scanf("%d", &newPassage.day);
            clearConsole();
            printf(" Insira a hora:\n ");
            scanf("%d", &newPassage.hour);

            porticos[i].totalPassages++;

            passages[*nrOfPassages] = newPassage;
            (*nrOfPassages)++;

            printf("Aceite, passagem adicionada!\n\n");

            return;
        }
    }

    printf(" Lamento, mas esse Pórtico não existe.");
}
void listpassage(passage passages[], int nrOfPassages)
{

    clearConsole();
    printf("%d", nrOfPassages);
    for (int i = 0; i < nrOfPassages; i++)
    {
        printf("\n---------------------------------------------------------------------\n");
        printf(" Matrícula: %d \n", passages[i].licensePlate);
        printf(" Dia: %d \n", passages[i].day);
        printf(" Hora %d\n", passages[i].hour);

        if (passages[i].vehicleClass == 1)
        {
            printf(" Motociclo \n");
        }
        else if (passages[i].vehicleClass == 2)
        {
            printf(" Veículo Ligeiro \n");
        }
        else if (passages[i].vehicleClass == 3)
        {
            printf(" Veículo Pesado \n");
        }
    }
}
/*void listPassageNumPortico(passage passages[], int nrOfPassages, portico porticos[], int nrOfporticos)
{

    clearConsole();
    int passageid;
    int porticoid;
    int passageClass;
    int passagePosition;

    printf("\nEscolha o Portico: ");
    scanf("%d", &porticoid);

    for (int i = 0; i < nrOfporticos; i++)
    {
        if (porticoid == porticos[i].id)
        {
            printf("Escolha o Pórtico: \n");
        }

    }
}*/
// anulei o de cima e criei o nº11 - Total passagens em todos os Pórticos , isto face a vossa ideia original
// como funciona: o utilizador terá que adicionar no número 5 o portico que passou || cons: limitado devido a só conseguir colocar 1 portico

void listTotalPassages(portico porticos[], int nrOfPorticos)
{
    for (int i = 0; i < nrOfPorticos; i++)
    {
        printf("\n------------------------------------\n");
        printf("ID do Pórtico: %d\n", porticos[i].id);
        printf("Total de Passagens: %d\n", porticos[i].totalPassages);
        printf("------------------------------------\n");
    }
}

int main(int argc, char const *argv[])
{
    int nrOfPorticos = 4;
    int option;
    int nrOfPassages = 0;
    passage passages[500];

    portico porticos[500] = {
        {1, 3, 2, 1},
        {2, 2, 1, 3},
        {3, 1, 1, 1},
        {4, 3, 2, 1}

    };

    do
    {
        printf("\n 1 - Inserir pórticos com tabela de preços");
        printf("\n 2 - Listar Pórticos ");
        printf("\n 3 - Preço Pórtico por classe");
        printf("\n 4 - Alterar Preços do Pórtico");
        printf("\n 5 - Inserir passagem num Pórtico");
        printf("\n 6 - Rendimento Diário por Pórtico");
        printf("\n 7 - Tráfego diário por classe de Veículo");
        printf("\n 8 - Rendimento diário por classe de Veículo");
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

            addPortico(porticos, &nrOfPorticos);
            break;
        }
        case 2:
        {
            printf("\n\n Opcao escolhida: 2 ");
            listPorticos(porticos, nrOfPorticos);
            break;
        }

        case 3:
        {
            printf("\n\n Opcao escolhida: 3 ");
            priceCheckForEachClass(porticos, nrOfPorticos);
            break;
        }

        case 4:
        {

            printf("\n\n Opcao escolhida: 4 ");
            editPrices(porticos, nrOfPorticos);
            break;
        }
        case 5:
        {

            printf("\n\n Opcao escolhida: 5 ");
            insertPassage(passages, &nrOfPassages, nrOfPorticos, porticos);
            break;
        }
        case 6:
        {

            printf("\n\n Opcao escolhida: 6 ");
            listpassage(passages, nrOfPassages);
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
            listTotalPassages(porticos, nrOfPorticos);
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
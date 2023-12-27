#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
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
    char licensePlate[10];
    int vehicleClass;
    int porticoId;
    int day;
    int hour;
};

struct licencePlate
{
    char letters[3];
    int numbers;
};
// podemos meter int id em vez de ter que usar o formato de matricula- Usar o formato da matricula com Char.- Usar o formato da matricula com o Char hhh
// Como se mete as horas, apenas necessario meter a hora ou tambem os minutos e as datas como se metem tambem?
typedef struct Portico portico;
typedef struct Passage passage;
typedef struct licencePlate plate;
void menu();
int nrOfPorticos = 4;
int option;
int nrOfPassages = 0;

portico porticos[500] = {
    {1, 3, 2, 1},
    {2, 2, 1, 3},
    {3, 1, 4, 1},
    {4, 3, 2, 1}

};
// porque tenho que meter valor 500 dentro do [], se nao meter entra em loop infinito
passage passages[500];
plate plates[500];
void addPortico(portico p[], int *nrOfporticos)
{
    clearConsole();
    portico newPortico;
    printf("\033[1;37m");
    printf("\n|------------------------------------------------------|");
    printf("\n|Insira o numero do portico:");
    printf("\033[0m");
    scanf("%d", &newPortico.id);

    for (int i = 0; i < *nrOfporticos; i++)
    {
        if (newPortico.id == p[i].id)
        {
            printf("ja existe esse Pórtico");
            return;
        }
    }
    printf("\033[1;37m");
    printf("\n|------------------------------------------------------|");
    printf("\n| Insira o preço da passagem do Motociclo:");
    scanf("%f", &newPortico.motorcyclePrice);
    printf("\n|------------------------------------------------------|");
    printf("\n|Insira o preço da passagem do Veiculo Ligeiro:"); 
    scanf("%f", &newPortico.lightVehiclePrice);
    printf("\n|------------------------------------------------------|");
    printf("\n|Insira o preço da passagem do Veiculo Pesado:");
    printf("\033[0m");
    scanf("%f", &newPortico.heavyVehiclePrice);

    p[*nrOfporticos] = newPortico;
    (*nrOfporticos)++;
    // void menu;
    menu();
}
void listPorticos(portico p[], int nrOfporticos)
{
    clearConsole();
    printf("%d", nrOfporticos);
    for (int i = 0; i < nrOfporticos; i++)
    {
        printf("\033[1;37m");
        printf("\n|---------------------------------------------------------------------|");
        printf("\n|Pórtico: %d                                                           |", p[i].id);
        printf("\n|---------------------------------------------------------------------|");
        printf("\n|Motociclos: %f                                                 |", p[i].motorcyclePrice);
        printf("\n|Veiculos Ligeiros: %f                                          |", p[i].lightVehiclePrice);
        printf("\n|Veiculos Pesados %f                                            |", p[i].heavyVehiclePrice);
        printf("\n|---------------------------------------------------------------------|");
        printf("\033[0m");
    }
    menu();
}
void editPrices(portico p[], int nrOfporticos)
{
    clearConsole();
    int EditPortico;
    int porticoEncontrado = 0;
    printf("\033[1;37m"); 
    printf("\n|------------------------------------------------------------|");
    printf("\n|Insira o número do portico que deseja editar:               |\n");
    scanf("%d", &EditPortico);

    for (int i = 0; i < nrOfporticos; i++)
    {
        if (EditPortico == p[i].id)
        {
            porticoEncontrado = 1;
            printf("\033[1;37m"); 
            printf("\n|------------------------------------------------------------|");
            printf("\n|Insira o novo preço do motociclo:                           |\n");
            scanf("%f", &p[i].motorcyclePrice);
            printf("\n|------------------------------------------------------------|");
            printf("\n|Insira o novo preço do veiculo ligeiro:                     |\n");
            scanf("%f", &p[i].lightVehiclePrice);
            printf("\n|------------------------------------------------------------|");
            printf("\n|Insira o novo preço do veiculo pesado:                      |\n ");
            scanf("%f", &p[i].heavyVehiclePrice);
            printf("Preços do Portico Atualizado!");
            printf("\033[0m"); 
        } 
    }
     if (!porticoEncontrado)
            {
                printf("Este portico nao existe");
                printf("\033[0m"); 
            }
    menu();   
}
void priceCheckForEachClass(portico porticos[], int nrOfporticos)
{
    int porticoid;
    int porticoClass;
    int porticoPosition;
    int porticoEncontrado = 0;
    printf("\033[1;37m"); 
    printf("\n|------------------------------------|");
    printf("\n|Escolha o Portico:                  |\n");
    scanf("%d", &porticoid);

    for (int i = 0; i < nrOfporticos; i++)
    {
        if (porticoid == porticos[i].id)
        {
            porticoEncontrado = 1;
            printf("\n|----------------------------------------------------|");
            printf("\n|Escolha a classe:                                   |");
            printf("\n|----------------------------------------------------|");
            printf("\n|motociclo: 1                                        |");
            printf("\n|veiculos ligeiros: 2                                |");
            printf("\n|veiculos Pesados: 3                                 |");
            printf("\n|----------------------------------------------------|\n");
            scanf("%d", &porticoClass);

            if (porticoClass == 1)
            {
                printf("Preco do Motociclo: %f", porticos[i].motorcyclePrice);
            }
            else if (porticoClass == 2)
            {
                printf("Preco do veiculo ligeiro: %f", porticos[i].lightVehiclePrice);
            }
            else if (porticoClass == 3)
            {
                printf("Preco do veiculo Pesado: %f", porticos[i].heavyVehiclePrice);
            }
            else
            {
                printf("Opcao Invalida");
            }
        }
    }
            if (!porticoEncontrado)
            {
                printf("Este portico nao existe");
            }
    
    printf("\033[0m"); 
    menu();
}
void insertPassage(passage passages[], int *nrOfPassages, int nrOfporticos, portico porticos[])
{
    clearConsole();
    int porticoEncontrado = 0;
    passage newPassage;
    printf("\033[1;37m"); 
    printf("\n|---------------------------------------------------|");
    printf("\n|Insira o portico de passagem:                      |\n");
    scanf("%d", &newPassage.porticoId);
    clearConsole();
    for (int i = 0; i < nrOfporticos; i++)
    {
        if (newPassage.porticoId == porticos[i].id)
        {
            porticoEncontrado = 1;
            printf("\n|-------------------------------------------------|");
            printf("\n|Insira a matricula (no formato 99-XX-99): ");
            scanf("%s", &newPassage.licensePlate);

            clearConsole();
            printf("\n|-------------------------------------------------|");
            printf("\n|Insira a classe do veiculo:                      |");
            printf("\n|-------------------------------------------------|");
            printf("\n|Motociclo: 1                                     |");
            printf("\n|Veiculos ligeiros: 2                             |");
            printf("\n|Veiculos Pesados: 3                              |");
            printf("\n|-------------------------------------------------|\n");
            scanf("%d", &newPassage.vehicleClass);
            clearConsole();
            printf("\n|-------------------------------------------------|");
            printf("\n|Insira a data:\n ");
            scanf("%d", &newPassage.day);
            clearConsole();
            printf("\n|-------------------------------------------------|");
            printf("\n|Insira a hora:\n ");
            scanf("%d", &newPassage.hour);
            clearConsole();
            printf("Passagem adicionada\n\n");
            passages[*nrOfPassages] = newPassage;
            (*nrOfPassages)++;
             menu();
            return;
        }
    }
     if (!porticoEncontrado)
            {
                printf("Este portico nao existe");
            }
    printf("\033[0m"); 
     menu();
}
void listpassage(passage passages[], int nrOfPassages)
{

    clearConsole();
    printf("%d", nrOfPassages);
    for (int i = 0; i < nrOfPassages; i++)
    {
        printf("\033[1;37m"); 
        printf("\n|------------------------------------------------------------|");
        printf("\n|Matricula: %s                                                |", passages[i].licensePlate);
        printf("\n|------------------------------------------------------------|");
        printf("\n|Dia: %d                                                      |", passages[i].day);
        printf("\n|------------------------------------------------------------|");
        printf("\n|Hora %d                                                      |", passages[i].hour);
        printf("\n|------------------------------------------------------------|");
        if (passages[i].vehicleClass == 1)
        {
            printf("\n|------------------------------------------------------------|");
            printf("\n|Motociclo                                                   |");
            printf("\n|------------------------------------------------------------|");
        }
        if (passages[i].vehicleClass == 2)
        {
            printf("\n|------------------------------------------------------------|");
            printf("\n|Veiculo Ligeiro                                             |");
            printf("\n|------------------------------------------------------------|");
        }
        if (passages[i].vehicleClass == 3)
        {
            printf("\n|------------------------------------------------------------|");
            printf("\n|Veiculo Pesado                                              |");
            printf("\n|------------------------------------------------------------|");
            printf("\033[0m"); 
        }
    }
     menu();
}
void listPassageNumPortico(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{

    clearConsole();
    int porticoid;
 
    printf("\nEscolha o Portico: ");
    scanf("%d", &porticoid);

    for (int i = 0; i < nrOfPassages; i++)
    {
        
        if (porticoid == passages[i].porticoId)
        {
            printf(" Passou o veiculo com a matricula %d\n",passages[i].licensePlate);
        }
        else
        {
            printf("Não Existe passagem neste Pórtico");
        }
    }
    
    menu();
}
void RendimentoPorClasse(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
      clearConsole();
    int vehicleClass;
    int totalRendimento = 0;
    printf("\033[1;37m"); 
    printf("\n|------------------------------------------------------------|");
    printf("\n|Escolha a classe que  deseja ver o rendimento:              |");
    printf("\n|------------------------------------------------------------|");
    printf("\n|1 - Motociclo                                               |");
    printf("\n|2 - Veículo ligeiro                                         |");
    printf("\n|3 - Veículo pesado                                          |");
    printf("\n|------------------------------------------------------------|");
    printf("\n|Escolha:");
    scanf("%d", &vehicleClass);

    int dayToCheck;
    printf("\n|------------------------------------------------------------|");
    printf("\n|Insira o dia desejado:");
    scanf("%d", &dayToCheck);

        for(int i = 0; i < nrOfPassages; i++)
        {

            if (passages[i].day == dayToCheck && passages[i].vehicleClass)
            {
               for(int j = 0; j < nrOfPorticos; j++)
               {
                if(porticos[j].id == passages[i].porticoId)
                {
                    switch (vehicleClass)
                    {
                    case 1:
                        totalRendimento += porticos[j].motorcyclePrice;
                        break;
                    case 2:
                        totalRendimento += porticos[j].motorcyclePrice;
                        break;
                    case 3:
                        totalRendimento += porticos[j].motorcyclePrice;
                        break;
                    default:
                        printf("Classe de veículo inválida\n");
                        break;
                    }
                }
               }
            }
            if (totalRendimento > 0 )
            {
                 printf("\n Rendimento diário total para a classe escolhida é de  %d Euros\n", totalRendimento);
            }
            else
            {
                 printf("Para a classe escolhida no dia selecionado não existe qualquer rendimento");
            }    
        }
    printf("\033[0m"); 

    menu();
}
void averagePassagesPerPortico(passage passages[],int nrOfPorticos){
    int media = 0;
    int PassagensTotais = 0;


     for (int i = 0; i < nrOfPassages; i++) {
        if (passages[i].porticoId > 0) {
            PassagensTotais++;
        }
    }
    if (PassagensTotais > 0) {
        media = PassagensTotais / nrOfPorticos;
        printf("\033[1;37m");
        printf("A média de passagens em todos os pórticos é de %d passagens por pórtico.\n", media);
    } else {
        printf("Não existe qualquer passagem nos pórticos.\n");
        printf("\033[0m");
    }
}
void totalTraficoPorPortico(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    clearConsole();
    int porticoId;
    int totalTrafico = 0;
    printf("\033[1;37m"); 
    printf("\nEscolha o Portico: ");
    scanf("%d", &porticoId);

    for (int i = 0; i < nrOfPassages; i++)
    {
        if (porticoId == passages[i].porticoId)
        {
            totalTrafico++;
        }
    }

    if (totalTrafico > 0)
    {
        printf("O tráfego total no Pórtico %d é de: %d passagens\n", porticoId, totalTrafico);
    }
    else
    {
        printf("Não há passagens registadas neste Pórtico %d\n", porticoId);
        printf("\033[0m"); 
    }
    menu();
}
void totalPassagePorticos(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    clearConsole();
    int totalPassagePorticos = 0;
    for (int i = 0; i < nrOfPassages; i++)
    {
    if( passages[i].porticoId > 0)
    {
         totalPassagePorticos++;
    }
    }
    if(totalPassagePorticos > 0)
    {
        printf("\033[1;37m"); 
        printf("O total de Passagens em Todos os Porticos é de %d passagens", totalPassagePorticos);
    }
    else
    {
        printf("Não existe qualquer passagem nos Pórticos");
        printf("\033[0m"); 
    }
    menu();
}
void trafegoDiarioPorClasse(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    {
    clearConsole();
    int vehicleClass;
    printf("\033[1;37m"); 
    printf("\n|------------------------------------------------------|");
    printf("\n|Escolha a classe de veículo:                          |");
    printf("\n|------------------------------------------------------|");
    printf("\n|1 - Motociclo                                         |");
    printf("\n|2 - Veículo Ligeiro                                   |");
    printf("\n|3 - Veículo Pesado                                    |");
    printf("\n|------------------------------------------------------|\n");
    scanf("%d", &vehicleClass);

    int totalTrafegoDiario = 0;

    for (int i = 0; i < nrOfPassages; i++)
    {
        if (passages[i].vehicleClass == vehicleClass)
        {
            totalTrafegoDiario++;
        }
    }

    switch (vehicleClass)
    {
    case 1:
        printf("O tráfego de Motociclos é de: %d passagens\n",  totalTrafegoDiario);
        break;
    case 2:
        printf("O tráfego de Veículos Ligeiros é de: %d passagens\n",  totalTrafegoDiario);
        break;
    case 3:
        printf("O tráfego de Veículos Pesados é de: %d passagens\n",  totalTrafegoDiario);
        break;
    default:
        printf("Classe de veículo inválida\n");
        printf("\033[0m"); 
        break;
    }
    menu();
}
}
void PassagensVeiculoPorPortico(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos) {
    int totalPassagensVeiculo = 0;
    int porticoId;
    int licensePlate;
    printf("\033[1;37m"); 
    printf("\n|--------------------------------------------------|");
    printf("\n|Insira o Pórtico:\n");
    scanf("%d", &porticoId);
    printf("\n|--------------------------------------------------|");
    printf("\n|Insira a matricula do veiculo:\n");
    scanf("%d", &licensePlate);

    for (int i = 0; i < nrOfPassages; i++) {
        if (passages[i].porticoId == porticoId && passages[i].licensePlate == licensePlate) {
            totalPassagensVeiculo++;
        }
    }
    if (totalPassagensVeiculo > 0 )
    {
        printf("Total de passagens do veículo %d no portico %d: %d\n", licensePlate, porticoId, totalPassagensVeiculo);
    }
    else
    {
        printf("Este veiculo de matricula %d não efetuou nenhuma passagem", licensePlate);
    }
    printf("\033[0m"); 
    menu();
}
void RendimentoTotal(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    float valorRendimentoTotal;
    for (int i = 0; i < nrOfPassages; i++)
    {
        for (int j = 0; j < nrOfPorticos; j++)
        {
            if (passages[i].porticoId == porticos[j].id)
            {
                switch (passages[i].vehicleClass)
                {
                case 1:
                    valorRendimentoTotal += porticos[j].motorcyclePrice;
                    break;
                case 2:
                    valorRendimentoTotal += porticos[j].lightVehiclePrice;
                    break;
                case 3:
                    valorRendimentoTotal += porticos[j].heavyVehiclePrice;
                    break;
                default:
                    printf("Classe de veículo inválida\n");
                }
                break;
            }
        }
    }
    printf("O valor do Rendimento total é de %0.1f Euros\n", valorRendimentoTotal);
    menu();
}
void gastoVeiculoAPorticos(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    int licensePlate;
    int gastosVeiculo;
    printf("\033[1;37m"); 
    printf("\n|--------------------------------------------------|");
    printf("\n|Insira a matricula do veiculo:\n");
    scanf("%d", &licensePlate);
    for (int i = 0; i < nrOfPassages; i++) {
        for(int j = 0; j < nrOfPorticos; j++){
        if (passages[i].porticoId == porticos[j].id && passages[i].licensePlate == licensePlate)
        {
             switch (passages[i].vehicleClass)
                {
                case 1:
                    gastosVeiculo += porticos[j].motorcyclePrice;
                    break;
                case 2:
                    gastosVeiculo += porticos[j].lightVehiclePrice;
                    break;
                case 3:
                    gastosVeiculo += porticos[j].heavyVehiclePrice;
                    break;
                default:
                    printf("Classe de veículo inválida\n");
                }
                break;
            }
        }
    }
    if (gastosVeiculo > 0)
    {
        printf("O veiculo com matricula %d teve um gasto total de %d Euros", licensePlate, gastosVeiculo);
    }
    else
    {
        printf("Este veiculo não teve qualquer gasto nos Porticos");
    }
    printf("\033[0m"); 
    menu();
}
void rendimentoDiarioPorPortico(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    int dayToCheck;
    float rendimentoTotalPortico;
    int porticoId;
    printf("\033[1;37m"); 
    printf("\n|------------------------------------------|");
    printf("\n|Insira o Dia \n");
    scanf("%d", &dayToCheck);
    printf("\n|------------------------------------------|");
    printf("\n|Insira o Portico \n");
    scanf("%d", &porticoId);

    for(int i = 0; i < nrOfPassages; i++)
    {
            if (passages[i].day == dayToCheck)
            {
               for(int j = 0; j < nrOfPorticos; j++)
               {
                if(porticos[j].id == passages[i].porticoId)
                {
                    switch (passages[i].vehicleClass)
                    {
                    case 1:
                        rendimentoTotalPortico += porticos[j].motorcyclePrice;
                        break;
                    case 2:
                        rendimentoTotalPortico += porticos[j].lightVehiclePrice;
                        break;
                    case 3:
                        rendimentoTotalPortico += porticos[j].heavyVehiclePrice;
                        break;
                    default:
                        printf("Classe de veículo inválida\n");
                        break;
                    }
                }
            }
       }
    }
    if (rendimentoTotalPortico > 0)
    {
       printf("o rendimento Diário do Portico %d no dia %d é de %0.1f", porticoId, dayToCheck, rendimentoTotalPortico);
    }
    else
    {
        printf("Não existe qualquer rendimento neste Portico");
        printf("\033[0m"); 
    }
    menu();
}
void porticoMaiorTrafego(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    int porticoAtual = 0;
    int maior ;
    for (int i = 0; i < nrOfPorticos; i++)
    {
        for (int j = 0; j < nrOfPassages; j++)
        {
           if (porticos[i].id == passages[j].porticoId )
           {
             porticoAtual++;

           }
        }
    if (porticoAtual > maior)
             {
               printf("Portico com maior trafego: ",porticos[i].id);
             }
             
           
           
        }
        
}
    


void menu()
{
    printf("\033[1;37m"); 
    printf("\n|===============================MENU==============================|");
    printf("\n| 1 - Inserir pórticos com tabela de preços                     --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 2 - Listar Pórticos                                           --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 3 - Preço Pórtico por classe                                  --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 4 - Alterar Preços do Pórtico                                 --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 5 - Inserir passagem num Pórtico                              --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 6 - Listar as passagens de todos os Pórticos                  --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 7 - Listar a passagem em um Pórtico                           --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 8 - Rendimento diário por classe de Veículo                   --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 9 - Média Tráfego por Pórtico                                 --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 10 -Tráfego Total por Pórticos                                --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 11 -Total passagens em todos os Pórticos                      --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 12 -Tráfego classe de Veículo em todos os Pórticos            --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 13 -Passagem totais de um  Veiculo em um Pórtico              --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 14 -Rendimento total das passagens                            --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 15 -Total de gastos por Veículo em todos os Pórticos          --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 16 -Pórtico com maior tráfego                                 --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 17 -Rendimento diário por Pórtico                             --|");
    printf("\n|=================================================================|");
    printf("\n|Escolha uma opcao:");
    printf("\033[0m");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
    {
        printf("\033[1;37m"); 
        printf("\n\n Opcao escolhida: 2 ");
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
        listPassageNumPortico(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 8:
    {

        printf("\n\n Opcao escolhida: 8 ");
        RendimentoPorClasse(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 9:
    {
        averagePassagesPerPortico(passages, nrOfPorticos);
        printf("\n\n Opcao escolhida: 9 ");
        break;
    }
    case 10:
    {
        totalTraficoPorPortico(passages,nrOfPassages, porticos, nrOfPorticos);
        printf("\n\n Opcao escolhida: 10 ");
        break;
    }
    case 11:
    {
         totalPassagePorticos( passages, nrOfPassages,  porticos,  nrOfPorticos);
        printf("\n\n Opcao escolhida: 11 ");
        break;
    }
    case 12:
    {
        trafegoDiarioPorClasse( passages, nrOfPassages, porticos, nrOfPorticos);
        printf("\n\n Opcao escolhida: 12 ");
        break;
    }
    case 13:
    {
        PassagensVeiculoPorPortico( passages,  nrOfPassages, porticos, nrOfPorticos);
        printf("\n\n Opcao escolhida: 13 ");
        break;
    }
    case 14:
    {
        RendimentoTotal( passages,  nrOfPassages,  porticos,  nrOfPorticos);
        printf("\n\n Opcao escolhida: 14 ");
        break;
    }
    case 15:
    {
        gastoVeiculoAPorticos(passages,  nrOfPassages,porticos, nrOfPorticos);
        printf("\n\n Opcao escolhida: 15 ");
        break;
    }
    case 16:
    {

        printf("\n\n Opcao escolhida: 16 ");
        porticoMaiorTrafego(passages, nrOfPassages,porticos, nrOfPorticos);
        break;
    }
    case 17:
    {
        rendimentoDiarioPorPortico(passages, nrOfPassages,  porticos, nrOfPorticos);
        printf("\n\n Opcao escolhida: 16 ");
        break;
    }
    default:
    {
        printf("\n\n Sair do programa");
        printf("\033[0m"); 
        break;
    }
    }
}

int main(int argc, char const *argv[])
{
    menu();
    
}

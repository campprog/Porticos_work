#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
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
struct Date
{
    int day;
    int month;
    int year;
};
struct Time
{
    int hour;
    int minutes;
};
struct Passage
{
    char licensePlate[10];
    int vehicleClass;
    int porticoId;
    struct Date date;
    struct Time time;
};

typedef struct Portico portico;
typedef struct Passage passage;
typedef struct Time time;
typedef struct Date Date;
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

passage passages[500];
// ERROS
// Na 6 quando se escolhe um portico que nao existe ele printa a dizer que nao existe no meio do menu, no final do printf ("11 -Tráfego Total por Pórticos ")

void addPortico(portico p[], int *nrOfporticos)
{
    clearConsole();
    portico newPortico;
    printf("\033[1;37m");
    printf("\n|------------------------------------------------------|");
    printf("\n|Insira o numero do portico:");
        while (1) {
        if (scanf("%d", &newPortico.id) == 1) {
            // A entrada é um número, sair do loop
            break;
        } else {
            // Limpar o buffer de entrada (stdin)
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n'); // Limpar o buffer de entrada
            // Pode ser útil adicionar um prompt para o usuário tentar novamente
            printf("Insira o portico de passagem novamente: ");
        }
    }
    for (int i = 0; i < *nrOfporticos; i++)
    {
        if (newPortico.id == p[i].id)
        {

            printf("ja existe esse Pórtico");
            return menu();
        }
    }
    printf("\n|------------------------------------------------------|");
    printf("\n| Insira o preço da passagem do Motociclo:");
     while (1) {
        if (scanf("%f", &newPortico.motorcyclePrice) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
    printf("\n|------------------------------------------------------|");
    printf("\n|Insira o preço da passagem do Veiculo Ligeiro:");
     while (1) {
        if (scanf("%f", &newPortico.lightVehiclePrice) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
    printf("\n|------------------------------------------------------|");
    printf("\n|Insira o preço da passagem do Veiculo Pesado:");
    printf("\033[0m");
 while (1) {
        if (scanf("%f", &newPortico.heavyVehiclePrice) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
    p[*nrOfporticos] = newPortico;
    (*nrOfporticos)++;
    // void menu;
    return menu();
}
void removePortico(portico p[], int *nrOfporticos)
{
    clearConsole();
    int RemovePortico;
    int porticoEncontrado = 0;
    printf("\033[1;37m");
    printf("\n|------------------------------------------------------------|");
    printf("\n|Insira o número do portico que deseja remover:              |\n");
  while (1) {
        if (scanf("%d", &RemovePortico) == 1) {
            // A entrada é um número, sair do loop
            break;
        } else {
            // Limpar o buffer de entrada (stdin)
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n'); // Limpar o buffer de entrada
            // Pode ser útil adicionar um prompt para o usuário tentar novamente
            printf("Insira o portico de passagem novamente: ");
        }
    }
    for (int i = 0; i < *nrOfporticos; i++)
    {
        if (RemovePortico == p[i].id)
        {
            porticoEncontrado = 1;

            // Move os porticos seguintes para uma posição anterior no array
            for (int j = i; j < *nrOfporticos - 1; j++)
            {
                p[j] = p[j + 1];
            }

            (*nrOfporticos)--;
            printf("Pórtico removido com sucesso!");
            printf("\033[0m");
        }
    }

    if (!porticoEncontrado)
    {
        printf("Este pórtico não existe");
        printf("\033[0m");
    }

    return menu();
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
    return menu();
}
void editPrices(portico p[], int nrOfporticos)
{
    clearConsole();
    int EditPortico;
    int porticoEncontrado = 0;
    printf("\033[1;37m");
    printf("\n|------------------------------------------------------------|");
    printf("\n|Insira o número do portico que deseja editar:               |\n");
 while (1) {
        if (scanf("%d", &EditPortico) == 1) {
            break;
        } else {
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n'); 
            printf("Insira o portico de passagem novamente: ");
        }
    }
    for (int i = 0; i < nrOfporticos; i++)
    {
        if (EditPortico == p[i].id)
        {
            porticoEncontrado = 1;
            printf("\033[1;37m");
            printf("\n|------------------------------------------------------------|");
            printf("\n|Insira o novo preço do motociclo:                           |\n");
            while (1) {
        if (scanf("%f", &p[i].motorcyclePrice) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
            printf("\n|------------------------------------------------------------|");
            printf("\n|Insira o novo preço do veiculo ligeiro:                     |\n");
             while (1) {
        if (scanf("%f", &p[i].lightVehiclePrice) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
            printf("\n|------------------------------------------------------------|");
            printf("\n|Insira o novo preço do veiculo pesado:                      |\n ");
            while (1) {
        if (scanf("%f", &p[i].heavyVehiclePrice) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
            printf("Preços do Portico Atualizado!");
            printf("\033[0m");
        }
    }
    if (!porticoEncontrado)
    {
        printf("Este portico nao existe");
        printf("\033[0m");
    }
    return menu();
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
     while (1) {
        if (scanf("%d", &porticoid) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
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
             while (1) {
        if (scanf("%d", &porticoClass) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
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
    return menu();
}
void insertPassage(passage passages[], int *nrOfPassages, int nrOfporticos, portico porticos[])
{
    clearConsole();
    int porticoEncontrado = 0;
    passage newPassage;
    int verificarClass = 0;
    int escolha;
    int escolha2;
    int escolha3;
    printf("\033[1;37m");
    printf("\n|---------------------------------------------------|");
    printf("\n|Insira o portico de passagem:                      |\n");
    while (1) {
        if (scanf("%d", &newPassage.porticoId) == 1) {
            // A entrada é um número, sair do loop
            break;
        } else {
            // Limpar o buffer de entrada (stdin)
            printf("Entrada inválida. Insira um número.\n");

            while (getchar() != '\n'); // Limpar o buffer de entrada

            // Pode ser útil adicionar um prompt para o usuário tentar novamente
            printf("Insira o portico de passagem novamente: ");
        }
    }
    clearConsole();
    for (int i = 0; i < nrOfporticos; i++)
    {
        if (newPassage.porticoId == porticos[i].id)
        {
            porticoEncontrado = 1;
            printf("\n|-------------------------------------------------|");
            printf("\n|Insira a matricula (no formato 99-XX-99): ");
             scanf("%s", &newPassage.licensePlate);
            while (strlen(newPassage.licensePlate) != 8 ||
                   !isdigit(newPassage.licensePlate[0]) ||
                   !isdigit(newPassage.licensePlate[1]) ||
                   !(isalpha(newPassage.licensePlate[3]) && isupper(newPassage.licensePlate[3])) ||
                   !(isalpha(newPassage.licensePlate[4]) && isupper(newPassage.licensePlate[4])) ||
                   !isdigit(newPassage.licensePlate[6]) ||
                   !isdigit(newPassage.licensePlate[7]) ||
                   newPassage.licensePlate[2] != '-' ||
                   newPassage.licensePlate[5] != '-')
            {
                printf("Formato de matrícula inválido\n");
                printf("Deseja voltar voltar ao menu ou voltar a meter a matricula de novo?\n");
                printf("1- Meter matricula\n");
                printf("2- Voltar ao menu\n");
                 while (1) {
        if (scanf("%d", &escolha) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
        }
    }
                switch (escolha)
                {
                case 1:
                    printf("Insira a matricula de novo\n");
                    scanf("%s", &newPassage.licensePlate);
                    break;
                case 2:
                    return menu();
                    break;
                default:
                printf("Escolha umas das duas opções");
                break;
                }
               
            }
            clearConsole();
            printf("\n|-------------------------------------------------|");
            printf("\n|Insira a classe do veiculo:                      |");
            printf("\n|-------------------------------------------------|");
            printf("\n|Motociclo: 1                                     |");
            printf("\n|Veiculos ligeiros: 2                             |");
            printf("\n|Veiculos Pesados: 3                              |");
            printf("\n|-------------------------------------------------|\n");
             while (1) {
        if (scanf("%d", &newPassage.vehicleClass) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
            if (newPassage.vehicleClass < 1 || newPassage.vehicleClass > 3)
            {
                printf("Opção invalida");
                return menu();
            }

            for (int j = 0; j < *nrOfPassages; j++)
            {
                if (strcmp(passages[j].licensePlate, newPassage.licensePlate) == 0 &&
                    passages[j].vehicleClass != newPassage.vehicleClass)
                {
                    printf("Esta matricula já está associada a outro veiculo\n");
                    return menu();
                }
            }
            int maxDays = 31;
            int maxMonths = 12;
            clearConsole();
            printf("\n|-------------------------------------------------|");
            printf("\n|Insira a data (no formato 99/9/9999): ");
            scanf("%d/%d/%d", &newPassage.date.day, &newPassage.date.month, &newPassage.date.year);
            while (newPassage.date.day < 1 || newPassage.date.day > maxDays ||
                   newPassage.date.month < 1 || newPassage.date.month > maxMonths ||
                   newPassage.date.year < 1900 || newPassage.date.year > 2100)
            {
                printf("Formato de data inválido\n");
                printf("Deseja voltar ao menu ou voltar a inserir a data de novo?\n");
                printf("1- Inserir data\n");
                printf("2- Voltar ao menu\n");
                  while (1) {
        if (scanf("%d", &escolha2) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
        }
    }
                switch (escolha2)
                {
                case 1:
                    printf("Insira a data de novo no formato 99/9/9999\n");
                    scanf("%d/%d/%d", &newPassage.date.day, &newPassage.date.month, &newPassage.date.year);
                    break;
                case 2:
                    return menu();
                    break;
                }
            }
            clearConsole();
            printf("\n|-------------------------------------------------|");
            printf("\n|Insira a hora (no formato 99:99):\n ");
            scanf("%d:%d", &newPassage.time.hour, &newPassage.time.minutes);
            while (newPassage.time.hour < 1 || newPassage.time.hour > 23 ||
                   newPassage.time.minutes < 1 || newPassage.time.minutes > 59)
            {
                printf("Formato de hora inválido\n");
                printf("Deseja voltar ao menu ou voltar a inserir a hora de novo?\n");
                printf("1- Inserir hora\n");
                printf("2- Voltar ao menu\n");
                  while (1) {
        if (scanf("%d", &escolha3) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
        }
    }
                switch (escolha3)
                {
                case 1:
                    printf("Insira a hora de novo no formato 99:99\n");
                    scanf("%d:%d", &newPassage.time.hour, &newPassage.time.minutes);
                    break;
                case 2:
                    return menu();
                    break;
                }
            }

            clearConsole();
            printf("Passagem adicionada\n\n");
            passages[*nrOfPassages] = newPassage;
            (*nrOfPassages)++;
            return menu();
        }
    }
    if (!porticoEncontrado)
    {
        printf("Este portico nao existe");
    }
    printf("\033[0m");
    return menu();
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
        printf("\n|Dia: %d/%d/%d                                                 |", passages[i].date.day, passages[i].date.month, passages[i].date.year);
        printf("\n|------------------------------------------------------------|");
        printf("\n|Hora: %d:%d                                                     |", passages[i].time.hour, passages[i].time.minutes);
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
    return menu();
}
void listPassageNumPortico(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{

    clearConsole();
    int porticoid;
    printf("\033[1;37m");
    printf("\nEscolha o Portico: ");
      while (1) {
        if (scanf("%d", &porticoid) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }

    for (int i = 0; i < nrOfPassages; i++)
    {

        if (porticoid == passages[i].porticoId)
        {
            printf(" Passou o veiculo com a matricula %s\n", passages[i].licensePlate);
        }
        else
        {
            printf("Não Existe passagem neste Pórtico");
            printf("\033[0m");
        }
    }

    return menu();
}
void RendimentoPorClasse(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    clearConsole();
    int vehicleClass;
    int totalRendimento = 0;
    int escolha;
    passage newPassage;
    
    printf("\033[1;37m");
    printf("\n|------------------------------------------------------------|");
    printf("\n|Escolha a classe que deseja ver o rendimento:               |");
    printf("\n|------------------------------------------------------------|");
    printf("\n|1 - Motociclo                                               |");
    printf("\n|2 - Veículo ligeiro                                         |");
    printf("\n|3 - Veículo pesado                                          |");
    printf("\n|------------------------------------------------------------|");
    printf("\n|Escolha:");
      while (1) {
        if (scanf("%d",  &vehicleClass) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira a classe novamente: ");
        }
    }
    if (vehicleClass < 1 || vehicleClass > 3)
    {
        printf("Opção inválida\n");
        return menu();
    }
    struct Date dateToCheck;
    int maxDays = 31;
    int maxMonths = 12;
    
    printf("\n|------------------------------------------------------------|");
    printf("\n|Insira a data (no formato 99/9/9999): ");
    scanf("%d/%d/%d", &dateToCheck.day, &dateToCheck.month, &dateToCheck.year);
    while (dateToCheck.day < 1 || dateToCheck.day > maxDays ||
           dateToCheck.month < 1 || dateToCheck.month > maxMonths ||
           dateToCheck.year < 1900 || dateToCheck.year > 2100)
    {
        printf("Formato de data inválido\n");
        printf("Deseja voltar ao menu ou voltar a inserir a data de novo?\n");
        printf("1- Inserir data\n");
        printf("2- Voltar ao menu\n");
         while (1) {
        if (scanf("%d",  &escolha) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
        }
    }   
        switch (escolha)
        {
            case 1:
                printf("Insira a data de novo no formato 99/9/9999\n");
                scanf("%d/%d/%d", &dateToCheck.day, &dateToCheck.month, &dateToCheck.year);
                break;
            case 2:
                return menu();
                break;
        }
    }
    
    if (nrOfPassages > 0)
    {
        for (int i = 0; i < nrOfPassages; i++)
        {
            // Verifique se a data é igual
            if (passages[i].date.day == dateToCheck.day &&
                passages[i].date.month == dateToCheck.month &&
                passages[i].date.year == dateToCheck.year &&
                passages[i].vehicleClass == vehicleClass)
            {
                for (int j = 0; j < nrOfPorticos; j++)
                {
                    if (porticos[j].id == passages[i].porticoId)
                    {
                        switch (vehicleClass)
                        {
                            case 1:
                                totalRendimento += porticos[j].motorcyclePrice;
                                break;
                            case 2:
                                totalRendimento += porticos[j].lightVehiclePrice;
                                break;
                            case 3:
                                totalRendimento += porticos[j].heavyVehiclePrice;
                                break;
                            default:
                                printf("Classe de veículo inválida\n");
                                break;
                        }
                    }
                }
            }
        }
        
        if (totalRendimento > 0)
        {
            printf("\n Rendimento diário total para a classe escolhida é de %d Euros\n", totalRendimento);
        }
        else
        {
            printf("Para a classe escolhida no dia selecionado não existe qualquer rendimento\n");
        }
        
        printf("\033[0m");
        return menu();
    }
    else
    {
        printf("Para a classe escolhida no dia selecionado não existe qualquer rendimento\n");
        printf("\033[0m");
        return menu();
    }
}
void averagePassagesPerPortico(passage passages[], int nrOfPorticos)
{
    float media = 0;

    float PassagensTotais = 0;

    for (int i = 0; i < nrOfPassages; i++)
    {
        if (passages[i].porticoId > 0)
        {
            PassagensTotais++;
        }
    }
    if (PassagensTotais > 0)
    {
        media = PassagensTotais / nrOfPorticos;
        printf("\033[1;37m");
        printf("A média de passagens em todos os pórticos é de %f passagens por pórtico.\n", media);
    }
    else
    {
        printf("Não existe qualquer passagem nos pórticos.\n");
        printf("\033[0m");
    }
    return menu();
}
void totalTraficoPorPortico(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    clearConsole();
    int porticoId;
    int totalTrafico = 0;
    printf("\033[1;37m");
    printf("\nEscolha o Portico: ");
    while (1) {
        if (scanf("%d", &porticoId) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
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
    return menu();
}
void totalPassagePorticos(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    clearConsole();
    int totalPassagePorticos = 0;
    for (int i = 0; i < nrOfPassages; i++)
    {
        if (passages[i].porticoId > 0)
        {
            totalPassagePorticos++;
        }
    }
    if (totalPassagePorticos > 0)
    {
        printf("\033[1;37m");
        printf("O total de Passagens em Todos os Porticos é de %d passagens", totalPassagePorticos);
    }
    else
    {
        printf("Não existe qualquer passagem nos Pórticos");
        printf("\033[0m");
    }
    return menu();
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
        while (1) {
        if (scanf("%d", &vehicleClass) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
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
            printf("O tráfego de Motociclos é de: %d passagens\n", totalTrafegoDiario);
            break;
        case 2:
            printf("O tráfego de Veículos Ligeiros é de: %d passagens\n", totalTrafegoDiario);
            break;
        case 3:
            printf("O tráfego de Veículos Pesados é de: %d passagens\n", totalTrafegoDiario);
            break;
        default:
            printf("Classe de veículo inválida\n");
            printf("\033[0m");
            break;
        }
        return menu();
    }
}
void PassagensVeiculoPorPortico(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    int totalPassagensVeiculo = 0;
    int porticoId;
     passage newPassage;
    char licensePlate[20]; // Assumindo que a matrícula do veículo pode ter até 19 caracteres
    int verificarPortico = 0;
    int escolha;

    printf("\033[1;37m");
    printf("\n|--------------------------------------------------|");
    printf("\n|Insira o Pórtico:\n");
     while (1) {
        if (scanf("%d", &porticoId) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
    for (int j = 0; j < nrOfPorticos; j++)
    {
        if (porticos[j].id == porticoId)
        {
            verificarPortico = 1;
            break;
        }
    }
    if (!verificarPortico)
    {
        printf("Portico nao existe\n");
        return menu(); // Se a função menu() não retorna nada, ajuste conforme necessário
        return;
    }
   printf("\n|Insira a matricula (no formato 99-XX-99): ");
            scanf("%s", &newPassage.licensePlate);
            while (strlen(newPassage.licensePlate) != 8 ||
                   !isdigit(newPassage.licensePlate[0]) ||
                   !isdigit(newPassage.licensePlate[1]) ||
                   !(isalpha(newPassage.licensePlate[3]) && isupper(newPassage.licensePlate[3])) ||
                   !(isalpha(newPassage.licensePlate[4]) && isupper(newPassage.licensePlate[4])) ||
                   !isdigit(newPassage.licensePlate[6]) ||
                   !isdigit(newPassage.licensePlate[7]) ||
                   newPassage.licensePlate[2] != '-' ||
                   newPassage.licensePlate[5] != '-')
            {
                printf("Formato de matrícula inválido\n");
                printf("Deseja voltar voltar ao menu ou voltar a meter a matricula de novo?\n");
                printf("1- Meter matricula\n");
                printf("2- Voltar ao menu\n");
                scanf("%d", &escolha);
                 while (1) {
        if (scanf("%d", &escolha) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
                switch (escolha)
                {
                case 1:
                    printf("Insira a matricula de novo\n");
                    scanf("%s", &newPassage.licensePlate);
                    break;
                case 2:
                    return menu();
                    break;
                }
            }
    for (int i = 0; i < nrOfPassages; i++)
{
    if (passages[i].porticoId == porticoId && strcmp(passages[i].licensePlate, newPassage.licensePlate) == 0)
    {
        totalPassagensVeiculo++;
    }
}
    if (totalPassagensVeiculo > 0)
{
    printf("Total de passagens do veículo %s no portico %d: %d\n", newPassage.licensePlate, porticoId, totalPassagensVeiculo);
    return menu();
}
else
{
    printf("Este veiculo de matricula %s não efetuou nenhuma passagem\n", newPassage.licensePlate);
    return menu();
}
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
                    printf("\033[1;37m");
                    printf("Classe de veículo inválida\n");
                }
                break;
            }
        }
    }
    printf("O valor do Rendimento total é de %0.1f Euros\n", valorRendimentoTotal);
    printf("\033[0m");
    return menu();
}
void gastoVeiculoAPorticos(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    char licensePlate[10];
    int gastosVeiculo = 0;
    int escolha;
    passage newPassage;
    printf("\033[1;37m");
    printf("\n|--------------------------------------------------|");
    printf("\n|Insira a matricula do veiculo:\n");
    printf("\n|-------------------------------------------------|");
            printf("\n|Insira a matricula (no formato 99-XX-99): ");
            scanf("%s", &newPassage.licensePlate);
            while (strlen(newPassage.licensePlate) != 8 ||
                   !isdigit(newPassage.licensePlate[0]) ||
                   !isdigit(newPassage.licensePlate[1]) ||
                   !(isalpha(newPassage.licensePlate[3]) && isupper(newPassage.licensePlate[3])) ||
                   !(isalpha(newPassage.licensePlate[4]) && isupper(newPassage.licensePlate[4])) ||
                   !isdigit(newPassage.licensePlate[6]) ||
                   !isdigit(newPassage.licensePlate[7]) ||
                   newPassage.licensePlate[2] != '-' ||
                   newPassage.licensePlate[5] != '-')
            {
                printf("Formato de matrícula inválido\n");
                printf("Deseja voltar voltar ao menu ou voltar a meter a matricula de novo?\n");
                printf("1- Meter matricula\n");
                printf("2- Voltar ao menu\n");
                 while (1) {
        if (scanf("%d", &escolha) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
                switch (escolha)
                {
                case 1:
                    printf("Insira a matricula de novo\n");
                    scanf("%s", &newPassage.licensePlate);
                    break;
                case 2:
                    return menu();
                    break;
                }
            }
    for (int i = 0; i < nrOfPassages; i++)
    {
        for (int j = 0; j < nrOfPorticos; j++)
        {
            if (strcmp(passages[i].licensePlate, licensePlate) == 0)
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
        printf("O veiculo com matricula %s teve um gasto total de %d Euros", licensePlate, gastosVeiculo);
    }
    else
    {
        printf("Este veiculo não teve qualquer gasto nos Porticos");
    }
    printf("\033[0m");
    return menu();
}
void rendimentoDiarioPorPortico(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    int porticoEncontrado = 0;
    float rendimentoTotalPortico;
    int porticoId;
    bool porticoExiste = false;
    struct Date dateToCheck;
     passage newPassage;
    int escolha;
     int maxDays = 31;
    int maxMonths = 12;
    printf("\033[1;37m");
    printf("\n|------------------------------------------|");
    printf("\n|Insira o Portico \n");
     while (1) {
        if (scanf("%d", &porticoId) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
    for (int j = 0; j < nrOfPorticos; j++)
    {
        if (porticoId == porticos[j].id)
        {
            porticoExiste = true;
        }
        if (!porticoExiste)
        {
            return menu();
        }
    }

    printf("\n|------------------------------------------|");
   printf("\n|Insira a data (no formato 99/9/9999): ");
            scanf("%d/%d/%d", &newPassage.date.day, &newPassage.date.month, &newPassage.date.year);
            while (newPassage.date.day < 1 || newPassage.date.day > maxDays ||
                   newPassage.date.month < 1 || newPassage.date.month > maxMonths ||
                   newPassage.date.year < 1900 || newPassage.date.year > 2100)
            {
                printf("Formato de data inválido\n");
                printf("Deseja voltar ao menu ou voltar a inserir a data de novo?\n");
                printf("1- Inserir data\n");
                printf("2- Voltar ao menu\n");
                scanf("%d", &escolha);
                 while (1) {
        if (scanf("%d", &escolha) == 1) {   
            break;
        } else {  
            printf("Entrada inválida. Insira um número.\n");
            while (getchar() != '\n');  
            printf("Insira o portico de passagem novamente: ");
        }
    }
                switch (escolha)
                {
                case 1:
                    printf("Insira a data de novo no formato 99/9/9999\n");
                    scanf("%d/%d/%d", &newPassage.date.day, &newPassage.date.month, &newPassage.date.year);
                    break;
                case 2:
                    return menu();
                    break;
                }
            }
    for (int i = 0; i < nrOfPassages; i++)
    {
        // Verifique se a data é igual
        if (passages[i].date.day == dateToCheck.day &&
            passages[i].date.month == dateToCheck.month &&
            passages[i].date.year == dateToCheck.year)
        {
            for (int j = 0; j < nrOfPorticos; j++)
            {
                if (porticos[j].id == passages[i].porticoId)
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
        printf("O rendimento Diário do Portico %d no dia %d/%d/%d é de %0.1f\n", porticoId, dateToCheck.day, dateToCheck.month, dateToCheck.year, rendimentoTotalPortico);
    }
    else
    {
        printf("Não existe qualquer rendimento neste Portico");
        printf("\033[0m");
    }
    return menu();
}
void porticoMaiorTrafego(passage passages[], int nrOfPassages, portico porticos[], int nrOfPorticos)
{
    int porticoAtual;
    int maior = 0;
    int indexMaiorPortico = -1;
    for (int i = 0; i < nrOfPorticos; i++)
    {
        for (int j = 0; j < nrOfPassages; j++)
        {
            if (porticos[i].id == passages[j].porticoId)
            {
                porticoAtual++;
            }
        }
        if (porticoAtual > maior)
        {
            maior = porticoAtual;
            indexMaiorPortico = i;
        }
    }
    if (indexMaiorPortico != -1)
    {
        printf("\033[1;37m");
        printf("Portico com maior trafego: %d\n", porticos[indexMaiorPortico].id);
        printf("\033[0m");
    }
    else
    {
        printf("\n Nao existe passagens");
        printf("\033[0m");
    }
    return menu();
}
void sair()
{
    return;
}
void menu()
{
    printf("\033[1;37m");
    printf("\n|===============================MENU==============================|");
    printf("\n| 1 - Inserir pórticos com tabela de preços                     --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 2 - Remover Pórtico                                           --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 3 - Listar Pórticos                                           --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 4 - Preço Pórtico por classe                                  --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 5 - Alterar Preços do Pórtico                                 --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 6 - Inserir passagem num Pórtico                              --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 7 - Listar as passagens de todos os Pórticos                  --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 8 - Listar a passagem em um Pórtico                           --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 9 - Rendimento diário por classe de Veículo                   --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 10 - Média Tráfego por Pórtico                                --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 11 -Tráfego Total por Pórticos                                --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 12 -Total passagens em todos os Pórticos                      --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 13 -Tráfego classe de Veículo em todos os Pórticos            --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 14 -Passagem totais de um  Veiculo em um Pórtico              --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 15 -Rendimento total das passagens                            --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 16 -Total de gastos por Veículo em todos os Pórticos          --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 17 -Pórtico com maior tráfego                                 --|");
    printf("\n|-----------------------------------------------------------------|");
    printf("\n| 18 -Rendimento diário por Pórtico                             --|");
    printf("\n|=================================================================|");
    printf("\n| 19 -Sair                                                      --|");
    printf("\n|=================================================================|");
    printf("\n|Escolha uma opcao:");
    printf("\033[0m");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
    {
        printf("\033[1;37m");
        printf("\n\n Opcao escolhida: 1 ");
        addPortico(porticos, &nrOfPorticos);
        break;
    }
    case 2:
    {
        printf("opção escolhida: 2 ");
        removePortico(porticos, &nrOfPorticos);
        break;
    }
    case 3:
    {
        printf("\n\n Opcao escolhida: 3 ");
        listPorticos(porticos, nrOfPorticos);
        break;
    }

    case 4:
    {
        printf("\n\n Opcao escolhida: 4 ");
        priceCheckForEachClass(porticos, nrOfPorticos);
        break;
    }

    case 5:
    {

        printf("\n\n Opcao escolhida: 5 ");
        editPrices(porticos, nrOfPorticos);
        break;
    }
    case 6:
    {

        printf("\n\n Opcao escolhida: 6 ");
        insertPassage(passages, &nrOfPassages, nrOfPorticos, porticos);
        break;
    }
    case 7:
    {

        printf("\n\n Opcao escolhida: 7 ");
        listpassage(passages, nrOfPassages);
        break;
    }
    case 8:
    {

        printf("\n\n Opcao escolhida: 8 ");
        listPassageNumPortico(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 9:
    {

        printf("\n\n Opcao escolhida: 9 ");
        RendimentoPorClasse(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 10:
    {
        printf("\n\n Opcao escolhida: 10 ");
        averagePassagesPerPortico(passages, nrOfPorticos);
        break;
    }
    case 11:
    {
        printf("\n\n Opcao escolhida: 11 ");
        totalTraficoPorPortico(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 12:
    {
        printf("\n\n Opcao escolhida: 12 ");
        totalPassagePorticos(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 13:
    {
        printf("\n\n Opcao escolhida: 13 ");
        trafegoDiarioPorClasse(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 14:
    {
        printf("\n\n Opcao escolhida: 14 ");
        PassagensVeiculoPorPortico(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 15:
    {
        printf("\n\n Opcao escolhida: 15 ");
        RendimentoTotal(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 16:
    {
        printf("\n\n Opcao escolhida: 16 ");
        gastoVeiculoAPorticos(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 17:
    {

        printf("\n\n Opcao escolhida: 17 ");
        porticoMaiorTrafego(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 18:
    {
        printf("\n\n Opcao escolhida: 18 ");
        rendimentoDiarioPorPortico(passages, nrOfPassages, porticos, nrOfPorticos);
        break;
    }
    case 19:
    {
        printf("\n\n Opcao escolhida: 18 ");
        sair();
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

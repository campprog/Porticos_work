#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num;
struct Portico
{
    int price;
    int vehicleType;
};
typedef struct Portico portico;

int main(int argc, char const *argv[])
{
portico p;
p.price= 3;


    struct Portico Porticos[3] = {
        
    };

    printf("\n 1 - Pórticos ");
    printf("\n 2 - Listar Pórticos ");
    printf("\n 3 - Média Tráfego por Pórtico");
    printf("\n 4 - Tráfego Total por Pórticos");
    printf("\n 5 - Rendimento Diário por Pórtico ");
    printf("\n 6 - Tráfego diário por classe de Veículo");
    printf("\n 7 - Rendimento diário por classe de Veículo");
    printf("\n 8 - Preço Pórtico por classe");
    printf("\n 9 - Alterar Preços do Pórtico");
    printf("\n 10 - Inserir passagem num Pórtico");
    printf("\n 11 - Total passagens em todos os Pórticos");
    printf("\n 12 - Listar a passagem em um Pórtico");
    printf("\n 13 - Passagem totais de um Veiculo por Pórtico");
    printf("\n 14 - Rendimento total");
    printf("\n 15 - Total de gastos por Veículo");
    printf("\n 16 - Pórtico com maior tráfego");
    printf("\n\n Escolha uma opcao: ");
    scanf("%d", &num);

    // estrutura switch
    switch (num)
    {
    case 1:
    {
        struct Registro novoRegistro;
        printf("Digite o número do pórtico: ");
        scanf("%d", &novoRegistro.novoPortico);
        printf("Digite o valor para a classe Motociclos: ");
        scanf("%d", &novoRegistro.ValorVeiculoMotociclo);
        printf("Digite o valor para a classe Ligeira: ");
        scanf("%d", &novoRegistro.ValorVeiculoLigeiro);
        printf("Digite o valor para a classe Pesada: ");
        scanf("%d", &novoRegistro.ValorVeiculoPesado);
        adicionarRegistro(arquivo, novoRegistro);
        printf("Pórtico Adicionado\n");
        break;
    }
    case 2:
    {
        printf("\n\n Opcao escolhida: 2 ");
        break;
    }

    case 3:
    {

        printf("\n\n Opcao escolhida: 3 ");
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
    }
    return 0;
}
#include "assets.h"

int display()
{
    int input, temp, status;

    do
    {
        system("cls");
        printf("1 - Guitarras\n2 - Clientes\n3 - Alugueres\n4 - Sair\n");
        status = scanf("%d", &input);
    } while ((temp = _getch()) != EOF && temp != '\n' && input < 1 || input > 4);

    return input;
}

int displayGuitarras()
{
    int input, temp, status;

    do
    {
        system("cls");
        printf("1 - Adicionar guitarra\n2 - Historico guitarra\n3 - Listar stock\n4 - Listar aluguer\n5 - Voltar\n");
        status = scanf("%d", &input);
    } while ((temp = _getch()) != EOF && temp != '\n' && input < 1 || input > 5);

    return input;
}

int displayClientes()
{
    int input, temp, status;

    do
    {
        system("cls");
        printf("1 - Adicionar cliente\n2 - Remover cliente\n3 - Estado cliente\n4 - Clientes ativos\n5 - Clientes banidos\n6 - Voltar\n");
        status = scanf("%d", &input);
    } while ((temp = _getch()) != EOF && temp != '\n' && input < 1 || input > 6);

    return input;
}

int displayAlugueres()
{
    int input, temp, status;

    do
    {
        system("cls");
        printf("1 - Criar aluguer\n2 - Concluir aluguer\n3 - Listar alugueres\n4 - Voltar\n");
        status = scanf("%d", &input);
    } while ((temp = _getch()) != EOF && temp != '\n' && input < 1 || input > 4);

    return input;
}

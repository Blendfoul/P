#include "assets.h"

pCli NovoCliente(pCli pointer)
{
    pCli new = NULL, aux = NULL, atual = pointer;

    new = (pCli)malloc(sizeof(client));

    if (!new)
    {
        return pointer;
    }

    ClienteInfo(new);

    if (verificaNIF(pointer, new) == 1)
    {
        printf("NIF: %d ja existente!\n", new->nif);
        _getch();
        free(new);
        return pointer;
    }

    if (atual == NULL) //Insere no fim da lista
        atual = new;
    else
    {
        aux = atual;
        while (aux->prox != NULL)
            aux = (pCli)aux->prox;
        (pCli) aux->prox = new;
    }

    return atual;
}

void ClienteInfo(pCli new)
{
    printf("Nome do cliente: ");
    scanf_s("\n%[^\n]s", new->nome, 50);
    printf("NIF do cliente: ");
    scanf("%9d", &new->nif);
    new->banido = false;
    new->nGuitar = 0;
    new->al = NULL;
    new->prox = NULL;
}

pCli RemoverCliente(pCli pointer, int *NIF)
{
    pCli actual, previous = NULL;

    actual = pointer;

    while (actual != NULL && actual->nif == *NIF)
    {
        previous = actual;
        actual = (pCli)actual->prox;
    }

    if (actual == NULL || actual->banido == true)
    {
        printf("\nCliente Banido ou Inexistente!\n");
        return pointer;
    }
    if (previous == NULL)
        pointer = (pCli)actual->prox;
    else
        previous->prox = actual->prox;

    free(actual);
    return pointer;
}

pCli LeClientesBanidos(pCli pointer)
{
    FILE *bInfo;
    pCli new = NULL, aux = NULL, atual = pointer;
    int size, total;

    bInfo = fopen("Banidos.dat", "rb");

    if (!bInfo)
        return pointer;

    fseek(bInfo, 0, SEEK_END);
    size = ftell(bInfo);

    if (size)
    {

        fseek(bInfo, -sizeof(int), SEEK_END);
        fread(&total, sizeof(int), 1, bInfo);
    
        for (int i = total - 1; i >= 0; i--)
        {
            fseek(bInfo, sizeof(client) * i, SEEK_SET);

            new = (pCli)malloc(sizeof(client));

            if (!new)
            {
                fclose(bInfo);
                return pointer;
            }

            fread(new, sizeof(client), 1, bInfo);
            new->prox = NULL;

            if (pointer == NULL)
                pointer = new;
            else
            {
                aux = pointer;
                while (aux->prox != NULL)
                    aux = (pCli)aux->prox;
                (pCli) aux->prox = new;
            }
        }
    }

    fclose(bInfo);

    return pointer;
}

pCli LeClientesAtivos(guitar *point, int *TAM)
{
    FILE *cInfo;
    pCli new = NULL, pointer = NULL, aux = NULL;
    pAlu novo = NULL;
    int returnedValue, a1, a2;

    cInfo = fopen("clientes.txt", "r");

    if (!cInfo)
    {
        return NULL;
    }

    fseek(cInfo, 0, SEEK_END);
    
    if (ftell(cInfo) != 0)
    {
        rewind(cInfo);

        while (true)
        {
            new = malloc(sizeof(client));

            if (!new)
                return NULL;

            returnedValue = fscanf(cInfo, "%d %d %[a-z A-Z ^\n]s", &new->nif, &new->nGuitar, new->nome);

            if (returnedValue == 3)
            {
                new->banido = false;
                new->prox = NULL; 
                new->al = NULL;


                if (new->nGuitar > 0)
                {
                    while (true)
                    {
                        novo = (pAlu)malloc(sizeof(aluguer));

                        if (!novo)
                            return pointer;

                        returnedValue = fscanf(cInfo, "%d %d %d %d %d %d %d %d %d %d %d", &a1, &a2,
                                               &novo->inicio.dia, &novo->inicio.mes, &novo->inicio.ano,
                                               &novo->fim_m.dia, &novo->fim_m.mes, &novo->fim_m.ano,
                                               &novo->fim.dia, &novo->fim.mes, &novo->fim.ano);

                        if (returnedValue == 11)
                        {
                            for (int i = 0; i < *TAM; i++)
                                if (a1 == point[i].id)
                                {
                                    novo->guitar = &point[i];
                                }

                            novo->prox = new->al;
                            new->al = novo;
                        }
                        else
                        {
                            free(novo);
                            break;
                        }
                    }
                }

                if (pointer == NULL)
                    pointer = new;
                else
                {
                    aux = pointer;
                    while (aux->prox != NULL)
                        aux = (pCli)aux->prox;
                    (pCli) aux->prox = new;
                }
            }

            else if (returnedValue == EOF)
            {
                free(new);
                break;
            }

            else
            {
                printf("Não encontrado!\n");
            }
        }
    }

    fclose(cInfo);
    return pointer;
}

void GravaClientesAtivos(pCli pointer)
{
    FILE *cInfo;
    pAlu ite = NULL;

    cInfo = fopen("clientes.txt", "wt");
    if (!cInfo)
        return;

    while (pointer != NULL)
    {
        if (!pointer->banido)
        {
            fprintf(cInfo, "%d %d %s", (int)pointer->nif, (int)pointer->nGuitar, pointer->nome);

            ite = pointer->al;

            while (ite != NULL)
            {
                fprintf(cInfo, "\n%d %d %d %d %d %d %d %d %d %d %d", (int)(ite)->guitar->id, (int)(ite)->guitar->state, (int)(ite)->inicio.dia, (int)(ite)->inicio.mes, (int)(ite)->inicio.ano, (int)(ite)->fim_m.dia, (int)(ite)->fim_m.mes, (int)(ite)->fim_m.ano, (int)(ite)->fim.dia, (int)(ite)->fim.mes, (int)(ite)->fim.ano);
                ite = (ite)->prox;
            }
        }
        pointer = (pCli)pointer->prox;
    }
    fclose(cInfo);
}

void GravaClientesBanidos(pCli pointer)
{
    FILE *bInfo;
    int total = 0;

    bInfo = fopen("banidos.dat", "wb");

    if (!bInfo)
        return;

    while (pointer != NULL)
    {
        if (pointer->banido)
        {
            fwrite(pointer, sizeof(client), 1, bInfo);
            total++;
        }
        pointer = (pCli)pointer->prox;
    }

    fwrite(&total, sizeof(int), 1, bInfo);

    fclose(bInfo);
}

void freeClientes(pCli pointer)
{
    pCli temp = NULL;
    puts("\n");
    while (pointer != NULL)
    {
        temp = (pCli)pointer->prox;
        printf("%p  ", pointer);
        free(pointer);
        pointer = temp;
        printf("Cliente libertado! \n");
    };
}
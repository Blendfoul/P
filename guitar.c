#include "assets.h"

guitar *Nova_guitarra(int *TAM, guitar *arr, int flag)
{
    guitar *new = arr;

    new = (guitar *)realloc(new, sizeof(guitar) * ((*TAM) + 1));

    if (!new)
    {
        free(new);
        return arr;
    }
    else if (flag)
    {
        (*TAM)++;
        preencheInfo(new, TAM);
    }
    else
    {
        (*TAM)++;
        return new;
    }

    return new;
}

void preencheInfo(guitar *new, int *TAM)
{
    if (*TAM > 1)
        new[(*TAM) - 1].id = new[(*TAM) - 2].id + 1;
    else
        new[(*TAM) - 1].id = 0;
    fflush(stdout);
    getchar();
    printf("Nome do Instrumento: ");
    gets(new[(*TAM) - 1].nome);
    printf("Valor do Instrumento: ");
    scanf("%d", &new[(*TAM) - 1].valor);
    printf("Preco por dia: ");
    scanf("%d", &new[(*TAM) - 1].pdia);
    new[(*TAM) - 1].state = 0;
}

guitar *Apaga_Guitarra(guitar *member, int *TAM, int *id)
{
    guitar *aux = member;
    int pos;
    if (aux == NULL)
        return member;

    for (pos = 0; pos < *TAM; pos++)
        if (*id == member[pos].id)
            break;

    if (!aux)
        return member;

    for (int i = pos; i < *TAM; i++)
    {
        if (i + 1 != *TAM)
        {
            aux[i].id = aux[i + 1].id;
            strcpy(aux[i].nome, aux[i + 1].nome);
            aux[i].valor = aux[i + 1].valor;
            aux[i].state = aux[i + 1].state;
        }
    }

    aux = (guitar *)realloc(aux, sizeof(guitar) * ((*TAM) - 1));
    (*TAM)--;

    return aux;
}

guitar *LeGuitarras(int *TAM)
{
    FILE *gInfo;
    guitar *pointer = NULL;
    int a1, a2, a3, a4, i;
    char b1[50];

    gInfo = fopen("Guitarras.txt", "rt");

    if (!gInfo)
    {
        printf("Erro ao aceder ao ficheiro\n");
        exit(-1);
    }

    while (true)
    {
        int ret = fscanf(gInfo, "%d %d %d %d %[a-z A-Z]s", &a1, &a2, &a3, &a4, b1);

        if (ret == 5)
        {

            pointer = Nova_guitarra(TAM, pointer, false);

            if (!pointer)
                return NULL;

            i = (*TAM) - 1;

            pointer[i].id = a1;
            pointer[i].pdia = a2;
            pointer[i].valor = a3;
            pointer[i].state = a4;
            strcpy(pointer[i].nome, b1);
        }

        else if (ret == EOF)
        {
            break;
        }

        else
        {
            printf("Não encontrado!\n");
        }
    }

    fclose(gInfo);

    return pointer;
}

void GravaGuitarras(guitar *pointer, int *TAM)
{
    FILE *gInfo;

    gInfo = fopen("Guitarras.txt", "wt");

    if (!gInfo)
    {
        printf("Erro ao aceder ao ficheiro\n");
        return;
    }

    for (int i = 0; i < *TAM; ++i)
    {
        fprintf(gInfo, "%d %d %d %d %s\n", pointer[i].id, pointer[i].pdia, pointer[i].valor, pointer[i].state, pointer[i].nome);
    }

    fclose(gInfo);
}

void freeGuitar(guitar *arr)
{
    free(arr);
}

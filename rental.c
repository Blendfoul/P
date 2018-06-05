#include "assets.h"

void NovoAluguer(pCli pointer, guitar *point, int *TAM, int *NIF)
{
    pAlu atual = NULL, new = NULL, aux = NULL;
    while (pointer != NULL && *NIF != pointer->nif)
        pointer = (pCli)pointer->prox;

    if (pointer)
    {

        atual = (pAlu)pointer->al;

        new = (pAlu)malloc(sizeof(aluguer));

        if (!new)
            return;


        AluguerInfo(new, point, TAM);

        new->prox = pointer->al; /*insere no inicio*/
        pointer->al = new;
        pointer->nGuitar++;
    }
    else{
        printf("Cliente nao encontrado!\n");
        _getch();
    }
}


void AluguerInfo(pAlu new, guitar *point, int *TAM)
{
    int pos;
    int id_guitar;
    bool flag = false;

    do
    {
        for (pos = 0; pos < *TAM; pos++)
            if (point[pos].state == 0)
                MostraGuitarra(&point[pos]);

        printf("\n\nID da guitarra escolhida: ");
        scanf("%d", &id_guitar);

        for (pos = 0; pos < *TAM; pos++)
            if (id_guitar == point[pos].id)
            {
                new->guitar = &point[pos];
                flag = true;
            }

        if (!flag)
            printf("Guitarra nao encontrada!\n");

    } while (!flag);

    printf("Data de Inicio[DD/MM/AAAA]: ");
    scanf("%d/%d/%d", &new->inicio.dia, &new->inicio.mes, &new->inicio.ano);

    printf("Data de Fim Prevista[DD/MM/AAAA]: ");
    scanf("%d/%d/%d", &new->fim_m.dia, &new->fim_m.mes, &new->fim_m.ano);

    int custo = diferenca(&new->inicio, &new->fim_m) * new->guitar->pdia;
    printf("\nCusto previsto: %d euros.\n", custo);

    new->fim.dia = new->fim.mes = new->fim.ano = 0;
    new->guitar->state = 1;
    new->prox = NULL;
    _getch();
}

void ConcluirAlguer(pCli pointer, int *NIF)
{
    pAlu iter = NULL;
    int delay;
    char damage;

    while (pointer != NULL)
    {
        if (pointer->nif == *NIF)
            break;
        else
            pointer = pointer->prox;
    }

    iter = pointer->al;

    if (iter == NULL)
    {
        printf("Este cliente nao tem alugueres ativos!");
        _getch();
        return;
    }
    else
    {
        printf("Data de Fim [DD/MM/AAAA]: ");
        scanf("%d/%d/%d", &iter->fim.dia, &iter->fim.mes, &iter->fim.ano);

        delay = diferenca(&iter->fim_m, &iter->fim);

        if (delay > 0)
        {
            printf("Atraso: %d", delay);
            iter->guitar->state = 0;
            pointer->banido = true;
            pointer->rban = 1;
            return;
        }

        printf("Guitarra danificada[S/N]: ");
        scanf("%c", &damage);

        if (damage == 'S' || damage == 's')
        {
            iter->guitar->state = 2;
            pointer->banido = true;
            pointer->rban = 2;
        }
        else
        {
            iter->guitar->state = 0;
            pointer->banido = false;
        }
    }
}
#ifndef CLI_H
#define CLI_H

#include "guitar.h"

typedef struct Aluguer aluguer, *pAlu;
typedef struct Client client, *pCli;
typedef struct Date DATE;

struct Date{
    int dia, mes, ano;
};

struct Client{
    char nome[50];
    int nif;
    bool banido;
    int rban;
    int nGuitar;
    pAlu al;
    pCli prox;
};

struct Aluguer{
    guitar *guitar;
    DATE inicio;
    DATE fim;
    DATE fim_m;
    pAlu prox;
};

#endif
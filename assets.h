#ifndef ASS_H
#define ASS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "guitar.h"
#include "client.h"

int display();
int displayGuitarras();
int displayClientes();
int displayAlugueres();
int getNIF();

guitar * Nova_guitarra(int *TAM, guitar *arr, bool flag);
guitar * Apaga_Guitarra(guitar *member, int *TAM, int *id);
guitar * LeGuitarras(int *TAM);
void freeGuitar(guitar *arr);
void preencheInfo(guitar *new, int *TAM);
void HistoricoGuitarra(pCli pointer);
void MostraInfo(guitar *member, int *TAM, int flag);
void GravaGuitarras(guitar *pointer, int *TAM);
void MostraGuitarra(guitar *member);

pCli NovoCliente(pCli pointer);
pCli RemoverCliente(pCli pointer, int *NIF);
void ClienteInfo(pCli new);
void InfoCliente(pCli pointer);
void InfoClienteSolo(pCli pointer, int *NIF);
void GravaClientes(pCli pointer);
void freeClientes(pCli pointer);
pCli LeClientes(guitar* pointer, int *TAM);
int verificaNIF(pCli pointer, pCli new);

void NovoAluguer(pCli pointer, guitar *point, int *TAM, int *NIF);
void AluguerInfo(pAlu new, guitar *point, int *TAM);
void GuitarraAluguer(guitar *member);
void ConcluirAlguer(pCli pointer, int *NIF);
void ListaAluguer(pCli pointer);


int diferenca(DATE *date, DATE *date1);
int countLeapYears(DATE *d);

void MostraData(pAlu pointer);

#endif

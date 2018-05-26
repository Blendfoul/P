#ifndef GUI_H
#define GUI_H

typedef struct Guitarra guitar, *pGui;

struct Guitarra{
    int id;
    char nome[50];
    int valor;
    int pdia;
    int state;
};

#endif
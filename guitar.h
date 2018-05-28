#ifndef GUI_H
#define GUI_H

typedef struct Guitarra guitar;

struct Guitarra{
    int id;
    char nome[50];
    int valor;
    int pdia;
    int state;
};

#endif
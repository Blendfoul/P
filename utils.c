#include "assets.h"

int getNIF(){
    int NIF;
    printf("NIF do cliente: ");
    scanf("%9d", &NIF);
    return NIF;
}

int verificaNIF(pCli pointer, pCli new){
    pCli aux = pointer;

    while(aux != NULL){
        if(new->nif == aux->nif)
            return 1;
        aux = (pCli) aux->prox;
    }
    
    return 0;
}

int AnoBisexto(int ano){
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 ==0)
        return 1;
    return 0;
}

int DiasNoMes(int mes, int ano) {
        int bisexto = AnoBisexto(ano);
        /*               J   F   M   A   M   J   J   A   S   O   N   D */
        int dias[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                           {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
        
        if (mes < 0 || mes > 11 || ano < 1753)
                return -1;

        return dias[bisexto][mes];
}

int diferenca(DATE *date, DATE *date1){
    int ano, mes;
    int totalDias = 0;

    for (ano = date->ano; ano >= date1->ano; ano--) {
        if (ano == date->ano) {
            for (mes = date->mes; mes >= 1 ; mes--) {
                if (mes == date->mes)  
                    totalDias += date->dia;
                else               
                    totalDias += DiasNoMes(mes, ano);
            }
        } else if (ano == date1->ano) {
            for (mes = 12 ; mes >= date1->mes ; mes--) {
                if (mes == date1->mes)
                    totalDias += DiasNoMes(mes, ano) - date1->dia;
                else                
                    totalDias += DiasNoMes(mes, ano);
                
            }
        } else {
            for (mes = 12 ; mes >= 1 ; mes--) {
                totalDias += DiasNoMes(mes, ano);
            }
        }

    }

    return totalDias;
}
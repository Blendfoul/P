#include "assets.h"

int getNIF()
{
    int NIF;
    printf("NIF do cliente: ");
    scanf("%9d", &NIF);
    return NIF;
}

int verificaNIF(pCli pointer, pCli new)
{
    pCli aux = pointer;

    while (aux != NULL)
    {
        if (new->nif == aux->nif)
            return 1;
        aux = (pCli)aux->prox;
    }

    return 0;
}

const int monthDays[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};
 
// This function counts number of leap years before the
// given date
int countLeapYears(DATE *d)
{
    int years = d->ano;
 
    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (d->mes <= 2)
        years--;
 
    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return years / 4 - years / 100 + years / 400;
}
 
// This function returns number of days between two given
// dates
int diferenca(DATE *dt1, DATE *dt2)
{
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1'
 
    // initialize count using years and day
    long int n1 = dt1->ano*365 + dt1->dia;
 
    // Add days for months in given date
    for (int i=0; i<dt1->mes - 1; i++)
        n1 += monthDays[i];
 
    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(dt1);
 
    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'
 
    long int n2 = dt2->ano*365 + dt2->dia;
    for (int i=0; i<dt2->mes - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(dt2);
 
    // return difference between two counts
    return (n2 - n1);
}
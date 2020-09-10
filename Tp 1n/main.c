#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operadores.h"

int main()
{
    int opcion;
    int a;
    int b;
    char seguir='y';
    int flagErrorA=1;
    int flagErrorB=1;

    menu();

    do
    {
        printf("Seleccione la opcion elegida: ");
        scanf("%d", &opcion);

        //system("cls");

        switch(opcion)
        {
        case 1:
            a=operandoA();
            flagErrorA=0;
            break;
        case 2:
            if(flagErrorA==0)
            {
                b=operandoB();
                flagErrorB=0;
            }
            else
            {
                printf("No se ingreso el valor de A. Ingrese A:\n");
            }
            break;
        case 3:
            if(flagErrorA==1 || flagErrorB==1)
            {
                printf("Se necesitan pasar ambos operadores para calcular\n");
            }
            else
            {
                calcular(a,b);
            }
            break;
        case 4:
            if(flagErrorA==1 || flagErrorB==1)
            {
                printf("Se necesita calcular para mostrar\n");
            }
            else
            {
                calculos(a,b);
            }
            break;
        case 5:
            seguir='n';
            break;
        default:
            printf("La opcion ingresada no es valida\n");
            fflush(stdin);
        }
    }
    while(seguir=='y');

    return 0;
}












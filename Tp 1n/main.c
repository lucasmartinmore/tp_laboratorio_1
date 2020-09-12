#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operadores.h"

int main()
{
    int opcion;
    int a;
    int b;
    char continuar='y';
    int operando_A=1;
    int operando_B=1;




    do
    {
        system("cls");
        menu(operando_A,operando_B,a,b);


        printf("Seleccione la opcion elegida: ");
        scanf("%d", &opcion);


        switch(opcion)
        {
        case 1:
            a=operandoA();
            operando_A=0;
            break;
        case 2:
            if(operando_A==0)
            {
                b=operandoB();
                operando_B=0;
            }
            else
            {
                printf("No se ingreso el valor de A. Ingrese A:\n");
            }
            system("pause");
            break;
        case 3:
            if(operando_A==1 || operando_B==1)
            {
                printf("Se necesitan pasar ambos operadores para calcular\n");
            }
            else
            {
                calcular(a,b);
            }
            system("pause");
            break;
        case 4:
            if(operando_A==1 || operando_B==1)
            {
                printf("Se necesita calcular para mostrar\n");
            }
            else
            {
                calculos(a,b);
            }
            system("pause");
            break;
        case 5:
            continuar='n';
            break;
        default:
            printf("La opcion ingresada no es valida\n");
            fflush(stdin);
            system("pause");
        }



    }
    while(continuar=='y');

    return 0;
}












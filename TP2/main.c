#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{

    char seguir='y';
    int contador=1;
    char continuar;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int opcionInformar;
    int idBaja;
    Employee* list;
    Employee arrayList[TAM];
    list = arrayList;
    initEmployees(list, TAM);

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            printf("****Alta empleados****\n\n");
            printf("Nombre: ");
            scanf("%s", name);

            printf("Apellido: ");
            scanf("%s", lastName);

            printf("Sueldo: ");
            scanf("%f", &salary);

            printf("Sector: ");
            scanf("%d", &sector);

            addEmployee(list, TAM, contador, name, lastName, salary, sector);
            contador++;
            break;
        case 2:
            system("cls");
            modifycaEmployee(list, TAM);
            break;
        case 3:
            system("cls");
            printf("Ingrese id de baja: ");
            scanf("%d", &idBaja);
            break;
        case 4:
            system("cls");
            printf("*****MENU INFORMAR*****\n\n1)Ascendente\n0)Descendente\n\nIngrese opcion: ");
            scanf("%d", &opcionInformar);
            while(opcionInformar<0 || opcionInformar>1)
            {
                printf("Opcion invalida.Reingrese opcion: ");
                scanf("%d", &opcionInformar);
            }
            sortEmployees(list, TAM, opcionInformar);
            printEmployees(list, TAM);
            totalSalary(list, TAM);
            break;
        case 5:
            seguir='n';
            break;
        default:
            printf("Esta no es una opcion valida\n");
            break;
        }
    }
    while(seguir=='y');

    return 0;
}

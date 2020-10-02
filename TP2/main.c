#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000
#define UP 1
#define DOWN 0
/*
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;
*/
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
    int flagInit= 0;
    Employee* list;
    Employee arrayList[TAM];
    list = arrayList;
    initEmployees(list, TAM);

    do
    {
        system("cls");

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
            flagInit=1;
            break;
        case 2:
            system("cls");
            if(flagInit==1)
            {

                modifycaEmployee(list, TAM);
            }
            else
            {
                printf("Ningun empleado cargado para modificar\n\n");
            }
            break;
        case 3:
            system("cls");
            if(flagInit==1)
            {
                if(removeEmployee(list, TAM)==0)
                {
                    printf("Baja exitosa\n");
                }
            }
            else
            {
                printf("Ningun empleado cargado para baja\n\n");
            }
            break;
        case 4:
            system("cls");
            if(flagInit==1)
            {
                printf("*****MENU INFORMAR*****\n\n0)Ascendente\n1)Descendente\n\nIngrese opcion: ");
                scanf("%d", &opcionInformar);
                if(opcionInformar==0)
                {
                    sortEmployees(list, TAM, UP);
                    printEmployees(list, TAM);
                }
                else if(opcionInformar==1)
                {
                    sortEmployees(list, TAM, DOWN);
                    printEmployees(list, TAM);
                }
                else
                {
                    printf("Opcion invalida\n\n");
                }
                Salary(list, TAM);
            }
            else
            {
                printf("Ningun empleado cargado para informar\n\n");
            }
            break;
        case 5:
            seguir='n';
            break;
        default:
            printf("Esta no es una opcion valida\n");
            break;
        }
        system("pause");

    }while(seguir=='y');

    return 0;
}

#include "ArrayEmployees.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

//FUNCION MENU
int menu()
{
    int opcion;
    printf("*****ABM PERSONAS*****\n\n");
    printf("1)Alta\n");
    printf("2)Modificar\n");
    printf("3)Baja\n");
    printf("4)Informar\n");
    printf("5)Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

//FUNCION INICIAL

int initEmployees(Employee* list, int len)
{
    if(len<0 || len >1000 || list == NULL)
    {
        return -1;
    }
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }
    return 0;
}

//FUNCION ALTA

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    if(len<0 || len >1000 || list == NULL)
    {
        return -1;
    }
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            list[i].id = id;
            strcpy(list[i].name, name);
            strcpy(list[i].lastName, lastName);
            list[i].salary = salary;
            list[i].sector = sector;
            list[i].isEmpty = 0;
            break;
        }
    }
    return 0;
}

//FUNCION LEER DATO

int printEmployees(Employee* list, int len)
{
    if(len<0 || len>1000 || list == NULL)
    {
        return -1;
    }
    printf("*****LISTADO DE EMPLEADOS*****\n\n");
    printf("ID     NAME     LASTNAME     SALARY     SECTOR\n");
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty != 1)
        {
            printf("%.4d   %s    %s        %8.2f     %.4d\n",
                   list[i].id,
                   list[i].name,
                   list[i].lastName,
                   list[i].salary,
                   list[i].sector);
        }
    }
    printf("\n\n");
    return 0;
}

//FUNCION BUSCAR PERSONA

int findEmployeeById(Employee* list, int len, int id)
{
    int indice=-1;
    for(int i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].isEmpty==0)
        {
            indice = i;
        }
    }
    return indice;
}

//FUNCION SACAR EMPLEADO

int removeEmployee(Employee* list, int len, int id)
{
    int indice;
    indice = findEmployeeById(list, len, id);

    if(indice == -1)
    {
        printf("Id invalido\n");
        return -1;
    }
    else
    {
        list[indice].isEmpty = 1;
    }
    return 0;
}

//FUNCION MODIFICAR DATOS

int modifycaEmployee(Employee* list, int len)
{
    int id;
    int indice=-1;
    int opcion;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    printEmployees(list, len);

    printf("Ingrese id a modificar: ");
    scanf("%d", &id);
    indice = findEmployeeById(list, len, id);

    if(indice == -1)
    {
        printf("Id invalido\n");
        return -1;
    }
    else
    {
        printf("*****MODIFICAR DATOS*****\n\n1)Nombre\n2)Apellido\n3)Salario\n4)Sector\n\n");
        printf("Ingrese opcion a modificar: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            fgets(name, 51, stdin);
            strcpy(list[indice].name, name);
            break;
        case 2:
            printf("Ingrese nuevo Apellido: ");
            fflush(stdin);
            fgets(lastName, 51, stdin);
            strcpy(list[indice].lastName, lastName);
            break;
        case 3:
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &salary);
            list[indice].salary = salary;
            break;
        case 4:
            printf("Ingrese nuevo sector: ");
            scanf("%d", &sector);
            list[indice].sector = sector;
            break;
        default:
            printf("No es una opcion valida\n");
            break;
        }
    }
    return 0;
}

int sortEmployees(Employee* list, int len, int order) //0 CRECIENTE 1 DECRECIENTE //
{
    Employee aux;
    if(list == NULL || len<0 || len>1000 || (order != 0 && order != 1))
    {
        return -1;
    }
    else
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j= i+1; j<len; j++)
            {
                if(list[i].isEmpty == 0 && list[j].isEmpty == 0) //ESTAN CARGADOS
                {
                    if(order==1) //CRECIENTE
                    {
                        if((strcmp(list[i].lastName, list[j].lastName) >0))
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                        if((strcmp(list[i].lastName, list[j].lastName) == 0) && list[i].sector > list[j].sector)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }
                    else // DECRECIENTE
                    {
                        if((strcmp(list[i].lastName, list[j].lastName)<0))
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j]= aux;
                        }
                        else if((strcmp(list[i].lastName, list[j].lastName) == 0) && list[i].sector < list[j].sector)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                    }

                }

            }
        }
    }
    return 0;
}

//FUNCION CALCULAR SALARIO TOTAL

int totalSalary(Employee* list, int len) //preguntar salario promedio y mostrar todo
{
    if(list == NULL || len<0 || len>1000)
    {
        return -1;
    }
    float acumulador=0;
    int contador=0;
    int contadorSalaryProm=0;
    float promedio;
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            acumulador += list[i].salary;
            contador++;
        }
    }
    if(contador == 0)
    {
        promedio = 0;
    }
    else
    {
        promedio = acumulador / contador;
    }
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            if(list[i].salary > promedio)
            {
               contadorSalaryProm++;
            }
        }
    }
    printf("El promedio de sueldo es: %.2f\n", promedio);
    printf("La cantidad de empleados que superan el sueldo promedio es: %d\n", contadorSalaryProm);
    return 0;
}


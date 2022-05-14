/*
 * ArrayPassenger.c
 *
 *  Created on: 14 may. 2022
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#define ACTIVO 1
#define COMPLETO 2
#define DEMORADO 3

int menu()
{
    system("cls");
    int opcion;
    printf("     ***** ABM PASAJEROS *****\n\n");
    printf("1)Alta\n");
    printf("2)Modificar\n");
    printf("3)Baja\n");
    printf("4)Informar\n");
    printf("5)Carga forzada\n");
    printf("6)Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int tipoDePasajero()
{
    system("cls");
    int opcion;
    printf("     ***** TIPO DE PASAJERO *****\n\n");
    printf("1)Premium\n");
    printf("2)Economica\n");
    printf("3)Turista\n");
    printf("4)Ejecutiva\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>4)
    {
        printf("Opcion invalida. Ingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int estadoDeVuelo()
{
    system("cls");
    int opcion;
    printf("     ***** ESTADO DE VUELO *****\n\n");
    printf("1)Activo\n");
    printf("2)Demorado\n");
    printf("3)Completo\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>3)
    {
        printf("Opcion invalida. Ingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int initPassengers(ePasajero* list, int len)
{
    if(len<0 || len >2000 || list == NULL)
    {
        return -1;
    }
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }
    return 0;
}

int addPassengers(ePasajero* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[])
{
    if(len<0 || len >2000 || list == NULL)
    {
        return -1;
    }
    else
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==1)
            {
                list[i].id = id;
                strcpy(list[i].name, name);
                strcpy(list[i].lastName, lastName);
                list[i].price = price;
                list[i].statusFly = ACTIVO;
                list[i].typePassenger = typePassenger;
                strcpy(list[i].flyCode, flyCode);
                list[i].isEmpty = 0;
                printf("\nPasajero cargado exitosamente!\n\n");
                break;
            }
        }
    }
    return 0;
}

int findPassengerById(ePasajero* list, int len, int id)
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

int removePassenger(ePasajero* list, int len, int id)
{
    int indice;
    indice = findPassengerById(list,len,id);

    if(indice == -1)
    {
        printf("Id invalido\n");
        return -1;
    }
    else
    {
        list[indice].isEmpty = 1;
        list[indice].statusFly = COMPLETO;
        printf("\nPasajero eliminado exitosamente!\n");
    }
    return 0;
}

int sortPassenger(ePasajero* list, int len, int order) //0 CRECIENTE 1 DECRECIENTE //
{
    ePasajero aux;
    if(list == NULL || len<0 || len>2000 || (order != 0 && order != 1))
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
                        if((strcmp(list[i].lastName, list[j].lastName) == 0) && list[i].typePassenger > list[j].typePassenger)
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
                        else if((strcmp(list[i].lastName, list[j].lastName) == 0) && list[i].typePassenger < list[j].typePassenger)
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

int printPassenger(ePasajero pasajero)
{
    printf("ID       NAME        LASTNAME             PRICE     FLY CODE  TIPE PASS\n");

    if(pasajero.isEmpty == 0) //&& pasajero.statusFly!=0)
    {
        printf("%.4d    %-11s    %-11s      %-9.2f    %.10s     %.3d\n",
               pasajero.id,
               pasajero.name,
               pasajero.lastName,
               pasajero.price,
               pasajero.flyCode,
               pasajero.typePassenger);
        printf("------------------------------------------------------------------------\n");
        return 0;
    }
    else
    {
        return -1;
    }
}

int printPassengers(ePasajero* list, int len)
{
    if(len<0 || len>2000 || list == NULL)
    {
        return -1;
    }
    printf("                 *****LISTADO DE PASAJEROS*****\n");
    printf("------------------------------------------------------------------------\n");
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0) //&& list[i].statusFly!=0)
        {
            printPassenger(list[i]);
        }
        else
        {
            return -2;
        }
    }
    return 0;
    printf("\n\n");
}

int modifycaEmployee(ePasajero* list, int len)
{
    int id;
    int indice=-1;
    int opcion;
    int typePassenger;
    int estadoVuelo;

    printPassengers(list,len);

    printf("Ingrese id a modificar: ");
    scanf("%d", &id);
    indice = findPassengerById(list,len,id);

    if(indice == -1)
    {
        printf("\nId invalido\n");
        return -1;
    }
    else
    {
        printf("     ***** MODIFICAR DATOS *****\n\n1)Nombre\n2)Apellido\n3)Precio\n4)Tipo de pasajero\n5)Codigo de vuelo\n6)Estado de vuelo\n\n");
        printf("Ingrese opcion a modificar: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            scanf("%s", list[indice].name);
            printf("\nNombre modificado exitosamente!\n\n");
            break;
        case 2:
            printf("Ingrese nuevo Apellido: ");
            fflush(stdin);
            scanf("%s", list[indice].lastName);
            printf("\nApellido modificado exitosamente!\n\n");
            break;
        case 3:
            printf("Ingrese nuevo precio: ");
            scanf("%f", &list[indice].price);
            printf("\nPrecio modificado exitosamente!\n\n");
            break;
        case 4:
            typePassenger = tipoDePasajero();
            list[indice].typePassenger = typePassenger;
            printf("\nTipo de pasajero modificado exitosamente!\n\n");
            break;
        case 5:
            printf("Ingrese nuevo codigo de vuelo: ");
            fflush(stdin);
            scanf("%s", list[indice].flyCode);
            printf("\nCodigo de vuelo modificado exitosamente!\n\n");
            break;
        case 6:
            estadoVuelo = estadoDeVuelo();
            list[indice].statusFly = estadoVuelo;
            printf("\nEstado de vuelo modificado exitosamente!\n\n");
            break;
        default:
            printf("No es una opcion valida\n");
            break;
        }
    }
    return 0;
}

int menuInformar()
{
    system("cls");
    int opcion;
    printf("     ***** MENU INFORME *****\n\n");
    printf("1)Por apellido y tipo de pasajero\n");
    printf("2)Total y promedio de precios\n");
    printf("3)Codigo de vuelo y activos\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>3)
    {
        printf("Error. Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int submenuInformar()
{
    system("cls");
    int opcion;
    printf("     ***** ORDEN POR APELLIDO Y TIPO *****\n\n");
    printf("1)De forma Ascendente\n");
    printf("2)De forma Descendente\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>2)
    {
        printf("Error. Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int hardcodearPasajeros(ePasajero* vecPasajero, int tam, int cantidad, int id)
{
    int retorno=-1;
    if (vecPasajero != NULL && tam > 0 && cantidad <= tam)
    {
        ePasajero pasajeros[10] =
        {
            {0,"Juan","Perez",98500.50,"olv8754",1,1,0},
            {0,"Perla","Godoy",25875.55,"hgf5214",3,1,0},
            {0,"Federico","Sosa",37400.80,"plo9357",2,1,0},
            {0,"Jimena","Diaz",64750.20,"asd4141",2,1,0},
            {0,"Pablo","Gomez",27950.35,"erd5455",1,1,0},
            {0,"Florencia","Bel",39820.65,"pzk7575",3,1,0},
            {0,"Pedro","Fuz",49000,"trf5555",3,1,0},
            {0,"Tamara","Castro",74900,"bff9999",2,1,0},
            {0,"Leandro","Mendez",41500.79,"ptz6969",1,1,0},
            {0,"Zoe","Pluch", 85670.35,"dye1515",3,1,0}
        };
        for (int i = 0; i < cantidad; i++)
        {
            vecPasajero[i] = pasajeros[i];
            vecPasajero[i].id= id;
            id++;
            retorno=0;
        }
    }
    return retorno;
}

int promedioPasajes(ePasajero* pasajeros, int tam)
{
    int retorno=-1;
    float acumPrecioPasajes=0;
    int contPasajeros=0;
    float promedio=0;
    if(pasajeros!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty==0)
            {
                acumPrecioPasajes+=pasajeros[i].price;
                contPasajeros++;
            }
        }
        if(contPasajeros!=0)
        {
            promedio=(float)(acumPrecioPasajes/contPasajeros);
        }
        system("cls");
        printf("     ***** INFORME PASAJES *****\n\n");

        printf("Precio total de pasajes: $ %.2f\n\n", acumPrecioPasajes);
        printf("Precio promedio de pasajes: $ %.2f\n\n", promedio);
        retorno=0;
    }
    return retorno;
}

int pasajerosPrecioPromedio(ePasajero* pasajeros, int tam)
{
    int retorno=-1;
    float acumPrecioPasajes=0;
    int contPasajeros=0;
    float promedio=0;
    if(pasajeros!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty==0)
            {
                acumPrecioPasajes+=pasajeros[i].price;
                contPasajeros++;
            }
        }
        if(contPasajeros!=0)
        {
            promedio=(float)(acumPrecioPasajes/contPasajeros);
        }
        printf("     ***** PASAJEROS CON PRECIO PROMEDIO *****\n");
        printf("------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if(pasajeros[i].isEmpty==0 && pasajeros[i].price>=promedio)
            {
                printPassenger(pasajeros[i]);
                retorno=0;
            }

        }
    }
    return retorno;
}



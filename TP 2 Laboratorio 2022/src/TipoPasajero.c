/*
 * TipoPasajero.c
 *
 *  Created on: 14 may. 2022
 *      Author: Lucas
 */
#include "TipoPasajero.h"
#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int mostrarPasajeroConTipo(ePasajero pasajero, eTipoDePasajero tipo)
{
    char tipoPasajero[20];
    switch(pasajero.typePassenger)
    {
    case 1:
        strcpy(tipoPasajero,"Premium");
        break;
    case 2:
        strcpy(tipoPasajero,"Economica");
        break;
    case 3:
        strcpy(tipoPasajero,"Turista");
        break;
    default:
        strcpy(tipoPasajero,"Ejecutiva");
        break;
    }
    printf("ID       NAME        LASTNAME             PRICE     FLY CODE    TIPE PASS\n");

    if(pasajero.isEmpty == 0)
    {
        for(int i=0; i<4; i++)
        {
            printf("%.4d    %-11s    %-11s      %-9.2f    %.10s     %-11s\n",
            pasajero.id,
            pasajero.name,
            pasajero.lastName,
            pasajero.price,
            pasajero.flyCode,
            tipoPasajero);
            printf("--------------------------------------------------------------------------\n");
            return 0;
        }
    }
    return -1;

}

int mostrarPasajerosConTipos(ePasajero* list, int lenP, eTipoDePasajero* tipo, int lenT)
{
    if(lenP<0 || lenP>2000 || list == NULL || tipo == NULL || lenT<0 || lenT>4)
    {
        return -1;
    }
    printf("                 *****LISTADO DE PASAJEROS*****\n");
    printf("--------------------------------------------------------------------------\n");
    for(int i=0; i<lenP; i++)
    {
        if(list[i].isEmpty == 0)
        {
            mostrarPasajeroConTipo(list[i],tipo[i]);
        }
        else
        {
            return -2;
        }
    }
    return 0;
    printf("\n\n");
}

int mostrarPasajeroActivo(ePasajero pasajero)
{
    char estadoVuelo[20];
    switch(pasajero.statusFly)
    {
    case 1:
        strcpy(estadoVuelo,"Activo");
        break;
    case 2:
        strcpy(estadoVuelo,"Completo");
        break;
    case 3:
        strcpy(estadoVuelo,"Demorado");
        break;
    }

    printf("NAME        LASTNAME       FLY CODE    STATUS FLY\n");

    if(pasajero.isEmpty == 0 && pasajero.statusFly!=0)
    {
        printf("%-11s    %-11s    %.10s    %-11s\n",
        pasajero.name,
        pasajero.lastName,
        pasajero.flyCode,
        estadoVuelo);
        printf("------------------------------------------------------------------------\n");
        return 0;
    }
    else
    {
        return -1;
    }
}

int pasajerosConVuelosActivos(ePasajero* pasajeros, int tam)
{
    int retorno=-1;
    if(pasajeros!=NULL && tam>0)
    {
        printf("     ***** PASAJEROS CON VUELO ACTIVOS *****\n");
        printf("------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(pasajeros[i].isEmpty==0 && pasajeros[i].statusFly==1)
            {
                mostrarPasajeroActivo(pasajeros[i]);
                retorno=0;
            }
        }
    }
    return retorno;
}





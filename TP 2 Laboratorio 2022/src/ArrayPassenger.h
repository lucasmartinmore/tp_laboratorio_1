/*
 * ArrayPassenger.h
 *
 *  Created on: 14 may. 2022
 *      Author: Lucas
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flyCode[10];
    int typePassenger;
    int statusFly;
    int isEmpty;
} ePasajero;

#endif /* ARRAYPASSENGER_H_ */

int menu();
int tipoDePasajero();
int estadoDeVuelo();
int initPassengers(ePasajero* list, int len);
int addPassengers(ePasajero* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[]);
int findPassengerById(ePasajero* list, int len, int id);
int removePassenger(ePasajero* list, int len, int id);
int sortPassenger(ePasajero* list, int len, int order);
int printPassenger(ePasajero pasajero);
int printPassengers(ePasajero* list, int len);
int modifycaEmployee(ePasajero* list, int len);
int menuInformar();
int submenuInformar();
int hardcodearPasajeros(ePasajero* vecPasajero, int tam, int cantidad, int id);
int promedioPasajes(ePasajero* pasajeros, int tam);
int pasajerosPrecioPromedio(ePasajero* pasajeros, int tam);

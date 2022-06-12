/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
#include "LinkedList.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[50];
	int estadoVuelo;
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precio,char* codigoDeVuelo,char* tipoPasajeroStr,char* estadoDeVuelo);

void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo);

int buscarIdNuevo(int* idLibre);
int actualizarId(int id);
int buscarPasajeroId(LinkedList* listadoPasajeros, int id);

int MenuPrincipal();
int menuModificar();

int altaPasajero(LinkedList* listadoPasajeros);
int bajaPasajero(LinkedList* listadoPasajeros);
int modificarPasajero(LinkedList* listadoPasajeros);

void cargarDescripcionTipoDePasajero(char* tipoDePasajero, int tipoEntero);
void cargarDescripcionEstadoPasajero(char* estadoDePasajero, int estadoEntero);

void imprimirPasajero(Passenger* pasajero);
int imprimirPasajeros(LinkedList* listadoPasajeros);


#endif /* PASSENGER_H_ */

/*
 * TipoPasajero.h
 *
 *  Created on: 14 may. 2022
 *      Author: Lucas
 */
#ifndef TIPOPASAJERO_H_
#define TIPOPASAJERO_H_
#include "ArrayPassenger.h"

typedef struct
{
    int idTipo;
    char descripcion[51];
} eTipoDePasajero;

#endif /* TIPOPASAJERO_H_ */
int mostrarPasajeroConTipo(ePasajero pasajero, eTipoDePasajero tipo);
int mostrarPasajerosConTipos(ePasajero* list, int lenP, eTipoDePasajero* tipo, int lenT);
int mostrarPasajeroActivo(ePasajero pasajero);
int pasajerosConVuelosActivos(ePasajero* pasajeros, int tam);

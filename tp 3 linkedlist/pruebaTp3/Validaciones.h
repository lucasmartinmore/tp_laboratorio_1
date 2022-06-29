/*
 * Validaciones.h
 *
 *  Created on: 23 jun. 2022
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

void validarCadena(char mensaje[], char mensajeDeError[], int tamanio, char variableCopiar[]);
int validarEntero(char mensaje[], char mensajeDeError[], int minimo, int maximo);
float validarFlotante(char mensaje[], char errorDeMensaje[], float minimo, float maximo);
char validarCaracter(char mensaje[], char errorDeMensaje[]);

#endif /* VALIDACIONES_H_ */

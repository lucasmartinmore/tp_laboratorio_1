/*
 * operadores.c
 *
 *  Created on: 7 sep. 2021
 *      Author: ACantarini
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operadores.h"

void menu(int primer, int segundo, int km, int importeAerolineas, int importeLatam)
{
	printf("*****MENU*****\n\n");
	if (primer == 1) {
		printf("1. Ingresar Kil�metros: ( km=x)\n");
	} else {
		printf("1. Ingresar Kil�metros: ( km=%d)\n", km);
	}
	if (segundo == 1) {
		printf("2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)\n- Precio vuelo Aerol�neas:\n- Precio vuelo Latam:\n");
	} else {
		printf("2. Ingresar Precio de Vuelos: (Aerol�neas=%d, Latam=%d)\n- Precio vuelo Aerol�neas:\n- Precio vuelo Latam:\n", importeAerolineas, importeLatam);
	}
	printf("3. Calcular todos los costos:\n");
	printf("a) Tarjeta de d�bito (descuento 10)\n");
	printf("b) Tarjeta de cr�dito (inter�s 25)\n");
	printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
	printf("d) Mostrar precio por km (precio unitario)\n");
	printf("e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)\n");
	printf("4. Informar resultados\n");
	printf("Latam:\n");
	printf("a: Precio con tarjeta de d�bito: r\n");
	printf("b: Precio con tarjeta de cr�dito: r\n");
	printf("c: Precio pagando con bitcoin : r\n");
	printf("d: Precio unitario: r\n");
	printf("Aerol�neas: \n");
	printf("a: Precio con tarjeta de d�bito: r\n");
	printf("b: Precio con tarjeta de cr�dito: r\n");
	printf("c: Precio pagando con bitcoin : r\n");
	printf("d: Precio unitario: r\n");
	printf("La diferencia de precio es: r\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n\n");
}

float operandos()
{
	float numero;
	printf("Ingrese el valor a guardar: ");
	scanf("%f", &numero);
	while(numero<1)
	{
		printf("Reingrese operando mayor a 1: ");
	    scanf("%f", &numero);
	}
	return numero;
}

float descuentoDebito(float precio)
{
	float descuento = precio*0.10;
	return descuento;
}

float interesCredito(float precio)
{
	float interes = (precio*0.25)+precio;
	return interes;
}

float conversorBitcoin(int precio)
{
	float conversor;
	conversor = (precio*1)/4606954.55;
	return conversor;
}

float precioUnitario(float km, float importeTotal)
{
	float precioUnitario;
	precioUnitario = importeTotal / km;
	return precioUnitario;
}

float diferenciaImporte(float importe1, float importe2)
{
	float diferencia;
	diferencia = (float)importe1 - importe2;
    return diferencia;
}

void informeFinal(float km, float importeAerolineas, float importeLatam, float descuentoA, float descuentoC,
float interesA, float interesC, float bitcoinA, float bitcoinC, float precioUnitarioA,
float precioUnitarioC, float diferenciaImporte)
{
	printf("La cantidad de KMS ingresados es: %.2f\n\n",km);
	printf("Precio Aerolineas: $%.2f\n",importeAerolineas);
	printf("a) Precio con tarjeta de d�bito: $%.2f\n",descuentoA);
	printf("b) Precio con tarjeta de cr�dito: $%.2f\n",interesA);
	printf("c) Precio pagando con Bitcoin: %.2f BTC\n",bitcoinA);
	printf("d) Precio unitario por KM: $%.2f\n\n",precioUnitarioA);
	printf("Precio Latam: $%.2f\n",importeLatam);
	printf("a) Precio con tarjeta de d�bito: $%.2f\n",descuentoC);
	printf("b) Precio con tarjeta de cr�dito: $%.2f\n",interesC);
	printf("c) Precio pagando con Bitcoin: %.2f BTC\n",bitcoinC);
	printf("d) Precio unitario por KM: $%.2f\n\n",precioUnitarioC);
	printf("La diferencia de precio es: $%.2f\n",diferenciaImporte);
}


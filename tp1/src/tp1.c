/*
 ============================================================================
 Name        : tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operadores.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	float km;
	float importeAerolineas;
	float importeLatam;
	char continuar = 'y';
	int operando_km = 1;
	int operando_preciosVuelos = 1;
	float descuentoAerolineas;
	float descuentoLatam;
	float interesAerolineas;
	float interesLatam;
	float bitcoinAerolineas;
	float bitcoinLatam;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferenciaEntreImporte;

	do {
		printf("\n\n");
		system("cls");
		menu(operando_km, operando_preciosVuelos, km, importeAerolineas, importeLatam);
		printf("Seleccione la opcion elegida: ");
		scanf("%d", &opcion);
		printf("\n\n");

		switch (opcion)
		{
		case 1:
			km = operandos();
			operando_km = 0;
			break;
		case 2:
			if (operando_km == 0)
			{
				importeAerolineas = operandos();
				importeLatam = operandos();
				operando_preciosVuelos = 0;
			}
			else
			{
				printf("No se ingreso el valor de x. Ingrese x:\n");
				system("pause");
			}
			break;
		case 3:
			if (operando_km == 1 || operando_preciosVuelos == 1)
			{
				printf("Se necesitan pasar los Kilometros y el precio de los vuelos para calcular\n");
			}
			else
			{
				descuentoAerolineas = descuentoDebito(importeAerolineas);
				descuentoLatam = descuentoDebito(importeLatam);
				interesAerolineas = interesCredito(importeAerolineas);
				interesLatam = interesCredito(importeLatam);
				bitcoinAerolineas = conversorBitcoin(importeAerolineas);
				bitcoinLatam = conversorBitcoin(importeLatam);
				precioUnitarioAerolineas = precioUnitario(km, importeAerolineas);
				precioUnitarioLatam = precioUnitario(km, importeLatam);
				diferenciaEntreImporte = diferenciaImporte(importeAerolineas, importeLatam);

				printf("Calculando los costos con diferentes metodos de pago entre LATAM y Aerolineas\n");
			}
			system("pause");
			break;
		case 4:
			if (operando_km == 1 || operando_preciosVuelos == 1)
			{
				printf("Se necesita calcular para mostrar\n");
			}
			else
			{
				informeFinal(km, importeAerolineas, importeLatam, descuentoAerolineas, descuentoLatam, interesAerolineas, interesLatam, bitcoinAerolineas, bitcoinLatam, precioUnitarioAerolineas, precioUnitarioLatam, diferenciaEntreImporte);
			}
			system("pause");
			break;
		case 5:
			informeFinal(7090, 1335000.66, 1350000.76, 120255.66, 120255.66, 150666.76, 150666.76, 33.66, 33.66, 10799.88, 10799.89, 30006.66);
			break;
		case 6:
			continuar = 'n';
			break;
		default:
			printf("La opcion ingresada no es valida\n");
			fflush(stdin);
			system("pause");
		}
	} while (continuar == 'y');

	return 0;
}

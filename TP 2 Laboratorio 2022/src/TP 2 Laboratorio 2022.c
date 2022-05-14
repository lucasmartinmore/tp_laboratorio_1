/*
 ============================================================================
 Name        : TP.c
 Author      : Lucas More
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "ArrayPassenger.h"
#include "TipoPasajero.h"
#define TAM_PASAJERO 2000
#define TAM_TIPO 4

int main(void) {
	setbuf(stdout, NULL);
	char seguir = 'y';
	int contador = 1;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int idBaja;
	int banderaInicial = 0;

	ePasajero listadoPasajeros[TAM_PASAJERO];
	ePasajero *pasajeros;
	pasajeros = listadoPasajeros;
	eTipoDePasajero tiposPas[TAM_TIPO] = { { 1, "Premium" }, { 2, "Economica" },
			{ 3, "Turista" }, { 4, "Ejecutiva" } };

	initPassengers(listadoPasajeros, TAM_PASAJERO);

	do {
		switch (menu()) {
		case 1:

			system("cls");
			printf("     **** Alta pasajeros ****\n\n");

			printf("Nombre: ");
			scanf("%s", name);

			printf("Apellido: ");
			scanf("%s", lastName);

			printf("Precio: ");
			scanf("%f", &price);

			printf("Codigo de vuelo: ");
			scanf("%s", flyCode);

			typePassenger = tipoDePasajero();

			addPassengers(listadoPasajeros, TAM_PASAJERO, contador, name,
					lastName, price, typePassenger, flyCode);
			contador++;
			banderaInicial = 1;
			break;
		case 2:
			if (banderaInicial == 1) {
				system("cls");
				modifycaEmployee(listadoPasajeros, TAM_PASAJERO);
			} else {
				printf(
						"  -- Hay que cargar un pasajero antes de modificar ! --  \n");
			}
			break;
		case 3:
			if (banderaInicial == 1) {
				system("cls");
				printPassengers(listadoPasajeros, TAM_PASAJERO);

				printf("Ingrese id de baja: ");
				scanf("%d", &idBaja);

				removePassenger(listadoPasajeros, TAM_PASAJERO, idBaja);
			} else {
				printf(
						"  -- Hay que cargar un pasajero antes de dar una baja ! --  \n");
			}
			break;
		case 4:
			if (banderaInicial == 1) {
				system("cls");
				switch (menuInformar()) {
				case 1:
					switch (submenuInformar()) {
					case 1:
						sortPassenger(listadoPasajeros, TAM_PASAJERO, 1);
						mostrarPasajerosConTipos(listadoPasajeros, TAM_PASAJERO,
								tiposPas, TAM_TIPO);
						break;
					case 2:
						sortPassenger(listadoPasajeros, TAM_PASAJERO, 0);
						mostrarPasajerosConTipos(listadoPasajeros, TAM_PASAJERO,
								tiposPas, TAM_TIPO);
						break;
					}
					break;
				case 2:
					promedioPasajes(listadoPasajeros, TAM_PASAJERO);
					pasajerosPrecioPromedio(listadoPasajeros, TAM_PASAJERO);
					break;
				case 3:
					pasajerosConVuelosActivos(listadoPasajeros, TAM_PASAJERO);
					break;
				}
			}
			else
			{
				printf("  -- Hay que cargar un pasajero antes de informar! --  \n");
			}
			break;
		case 5:
			if (hardcodearPasajeros(listadoPasajeros, TAM_PASAJERO, 10,
					contador) == 0) {
				printf("\nEmpleados predeterminados cargados con exito!!\n\n");
				banderaInicial=1;
			} else {
				printf(
						"\nNo se pudo cargar los empleados predeterminados!!\n\n");
			}
			break;
		case 6:
			seguir = 'n';
			break;
		default:
			printf("Esta no es una opcion valida\n");
			break;
		}
		system("pause");
	} while (seguir == 'y');

	return EXIT_SUCCESS;
}

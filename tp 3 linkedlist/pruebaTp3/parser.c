#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=0;
		Passenger* nuevoPasajero;
		char buffer[7][40];
		int cantidadDatos;

		if(pFile!=NULL && pArrayListPassenger!=NULL)
		{
			cantidadDatos=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

			while(!feof(pFile))
			{
				cantidadDatos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
				if(cantidadDatos==7)
				{
					nuevoPasajero = Passenger_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

					if(nuevoPasajero!=NULL)
					{
						ll_add(pArrayListPassenger, nuevoPasajero);
						retorno=1;
					}
				}
				else
				{
					printf("No lei la cantidad de datos");
					break;
					}
			}
		}
		else
		{
			printf("Los punteros devuelven null");
		}
		fclose(pFile);
	    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=0;
		Passenger* nuevoPasajero=NULL;
		int cantidad;

		if(pFile !=NULL && pArrayListPassenger !=NULL)
		{
			while(!feof(pFile))
		    {
				nuevoPasajero = Passenger_new();

		        if(nuevoPasajero !=NULL)
		        {
		        	cantidad = fread(nuevoPasajero, sizeof(Passenger), 1, pFile);
		        	/*

		            if(cantidad<1)
		            {
		            	if(feof(pFile))
		                {
		            		break;
		                }
		            	else
		            	{
		            		printf("  --------- Error al leer el archivo en modo binario ! ---------  \n");
		            	}
		            }
		            else
		            {
			            ll_add(pArrayListPassenger, nuevoPasajero);
			            retorno=1;
		            }
		            */
		        	if(cantidad==1)
		        	{
		        		ll_add(pArrayListPassenger, nuevoPasajero);
		        		retorno=1;
		        	}
		        }
		        else
		        {
		        	printf("Error al crear un nuevo pasajero");
		        }
		    }
		}
	   return retorno;
}

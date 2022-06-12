#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	FILE* punteroFile=NULL;

	if(path!=NULL && pArrayListPassenger!= NULL)
	{
		punteroFile=fopen(path,"r");

	    if(punteroFile!=NULL)
	    {
	    	if(parser_PassengerFromText(punteroFile, pArrayListPassenger))
	        {
	    		printf("  --------- Archivo cargado en modo texto exitosamente ! ---------  \n");
	    		retorno=1;
	        }
	        else
	        {
	        	printf("  --------- Error al cargar el archivo en modo texto ! ---------  \n");
	        }
	     }
	     else
	     {
	    	 printf("  --------- El archivo no se pudo abrir correctamente ! ---------  \n");
	     }
	     fclose(punteroFile);
	 }
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	FILE* punteroFile=NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		punteroFile=fopen(path,"rb");
	    if(punteroFile!=NULL)
	    {
	    	if(parser_PassengerFromBinary(punteroFile,pArrayListPassenger))
	        {
	    		printf("  --------- Archivo cargado en modo binario exitosamente ! ---------  \n");
	    		retorno=1;
	        }
	        else
	        {
	        	printf("  --------- Error al cargar el archivo en modo binario ! ---------  \n");
	        }
	     }
	     else
	     {
	    	 printf("  --------- El archivo no se pudo abrir correctamente ! ---------  \n");
	     }
	     fclose(punteroFile);
	 }
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	if(pArrayListPassenger!=NULL)
	{
		if(altaPasajero(pArrayListPassenger))
	    {
			printf("  --------- Alta pasajero exitosamente ! ---------  \n");
			return 1;
	    }
		else
		{
			printf("  --------- Alta pasajero fallida ! ---------  \n");
		}
	}
    return 0;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	if(pArrayListPassenger!=NULL)
	{
		if(modificarPasajero(pArrayListPassenger))
		{
			printf("  --------- Modificacion de pasajero exitosa ! ---------  \n");
			return 1;
		}
		else
		{
			printf("  --------- Modificacion pasajero fallida ! ---------  \n");
		}
	}
    return 0;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	if(pArrayListPassenger!=NULL)
	{
		if(bajaPasajero(pArrayListPassenger))
		{
			printf("  --------- Baja de pasajero exitosa ! ---------  \n");
			return 1;
		}
		else
		{
			printf("  --------- Baja de pasajero fallida ! ---------  \n");
		}
	}
    return 0;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	if(pArrayListPassenger!=NULL)
	{
		if(imprimirPasajeros(pArrayListPassenger))
		{
			printf("  --------- Listado de pasajeros exitoso ! ---------  \n");
			return 1;
		}
		else
		{
			printf("  --------- Listado de pasajero fallido ! ---------  \n");
		}
	}
    return 0;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */


/*
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	if(pArrayListPassenger!=NULL)
	{
		if(//FUNCION PARA DAR ALTA)
		{
			printf("  --------- Pasajeros ordenados exitosamente ! ---------  \n");
		}
		else
		{
			printf("  --------- Pasajeros ordenados fallido ! ---------  \n");
			return 0;
		}
	}
    return 1;
}
*/


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	Passenger* nuevoPasajero=NULL;
	FILE* punteroFile=NULL;
	char tipoPasajero[30];
	char estadoVuelo[30];

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		punteroFile=fopen(path,"w");

		if(punteroFile!=NULL)
		{
			fprintf(punteroFile,"Id,Nombre,Apellido,Precio,CodigoVuelo,TipoPasajero,EstadoVuelo\n");

			for(int i=0; i<ll_len(pArrayListPassenger); i++)
			{
				nuevoPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
				cargarDescripcionTipoDePasajero(tipoPasajero,nuevoPasajero->tipoPasajero);
				cargarDescripcionEstadoPasajero(estadoVuelo,nuevoPasajero->estadoVuelo);

				if(nuevoPasajero!=NULL)
				{
					fprintf(punteroFile,"%d,%s,%s,%f,%s,%s,%s\n",nuevoPasajero->id,nuevoPasajero->nombre,
					nuevoPasajero->apellido,nuevoPasajero->precio,nuevoPasajero->codigoVuelo,tipoPasajero,
					estadoVuelo);
				}
			}
			printf("  --------- Pasajeros cargados en modo texto exitosamente ! ---------  \n");
			retorno=1;
		}
		else
		{
			printf("  --------- Error al guardar el archivo en modo texto ! ---------  \n");
		}
		fclose(punteroFile);
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=0;
	Passenger* nuevoPasajero=NULL;
	FILE* punteroFile=NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		punteroFile=fopen(path,"wb");

		if(punteroFile!=NULL)
		{
			for(int i=0; i<ll_len(pArrayListPassenger); i++)
			{
				nuevoPasajero=(Passenger*)ll_get(pArrayListPassenger, i);

				if(nuevoPasajero!=NULL)
				{
					fwrite(nuevoPasajero,sizeof(Passenger),1,punteroFile);
				}
			}

			printf("  --------- Pasajeros cargados en modo binario exitosamente ! ---------  \n");
			retorno=1;
		}
		else
		{
			printf("  --------- Error al guardar el archivo en modo binario ! ---------  \n");
		}
	}
    return retorno;
}


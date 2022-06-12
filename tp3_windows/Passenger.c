/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "Passenger.h"
#include "LinkedList.h"

Passenger* Passenger_new()
{
	return (Passenger*)malloc(sizeof(Passenger));
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precio,char* codigoDeVuelo,char* tipoPasajeroStr,char* estadoDeVuelo)
{
	Passenger* nuevoPasajero = Passenger_new();

	if(nuevoPasajero!=NULL && Passenger_setId(nuevoPasajero, atoi(idStr))==1 && Passenger_setNombre(nuevoPasajero, nombreStr)==1 &&
	Passenger_setApellido(nuevoPasajero, apellidoStr)==0 && Passenger_setPrecio(nuevoPasajero, atoi(precio))==0 &&
	Passenger_setCodigoVuelo(nuevoPasajero, codigoDeVuelo)==0 && Passenger_setTipoPasajero(nuevoPasajero, atoi(tipoPasajeroStr))==0
	&& Passenger_setEstadoVuelo(nuevoPasajero, atoi(estadoDeVuelo))==0)
	{
		return nuevoPasajero;
	}
	Passenger_delete(nuevoPasajero);
	nuevoPasajero=NULL;
	return nuevoPasajero;
}

void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	if(this!=NULL && id>0)
	{
		this->id=id;
		return 0;
	}
	return -1;
}
int Passenger_getId(Passenger* this,int* id)
{
	if(this!=NULL && id!=NULL)
	{
		*id = this->id;
		return 0;
	}
	return -1;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		return 0;
	}
	return -1;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		return 0;
	}
	return -1;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido,apellido);
		return 0;
	}
	return -1;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido,this->apellido);
		return 0;
	}
	return -1;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		return 0;
	}
	return -1;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		return 0;
	}
	return -1;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	if(this!=NULL)
	{
		this->tipoPasajero = tipoPasajero;
		return 0;
	}
	return -1;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	if(this!=NULL && tipoPasajero!=NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		return 0;
	}
	return -1;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	if(this!=NULL && precio>0)
	{
		this->precio = precio;
		return 0;
	}
	return -1;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		return 0;
	}
	return -1;
}

int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo)
{
	if(this!=NULL)
	{
		this->estadoVuelo = estadoVuelo;
		return 0;
	}
	return -1;
}

int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
	if(this!=NULL && estadoVuelo!=NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		return 0;
	}
	return -1;
}

int buscarIdNuevo(int* idLibre)
{
	FILE* punteroFile=NULL;

	if(idLibre!=NULL)
	{
		punteroFile=fopen("idDisponible.bin","rb");
		*idLibre=1001;

		if(punteroFile!=NULL)
		{
			fread(idLibre,sizeof(int),1,punteroFile);
			fclose(punteroFile);
			return 1;
		}
	}
	return 0;
}

int actualizarId(int id)
{
	FILE* punteroFile=NULL;
	punteroFile=fopen("idDisponible.bin","wb");

	if(punteroFile!=NULL)
	{
		id++;
		fwrite(&id,sizeof(int),1,punteroFile);
		fclose(punteroFile);
		return 1;
	}
	return 0;
}

int MenuPrincipal()
{
    system("cls");
    int opcion;
    printf(" __________________________________________________________\n");
    printf("|                >>> LINKEDLIST PASAJEROS <<<              |\n");
    printf("|__________________________________________________________|\n\n");
    printf("|      1) Cargar los datos en data.csv (modo texto).       |\n");
    printf("|      2) Cargar los datos en data.csv (modo binario).     |\n");
    printf("|      3) Alta de pasajero                                 |\n");
    printf("|      4) Modificar datos de pasajero                      |\n");
    printf("|      5) Baja de pasajero                                 |\n");
    printf("|      6) Listar pasajeros                                 |\n");
    printf("|      7) Ordenar pasajeros                                |\n");
    printf("|      8) Guardar los datos en data.csv (modo texto).      |\n");
    printf("|      9) Guardar los datos en data.csv (modo binario).    |\n");
    printf("|     10) Salir                                            |\n");
    printf("|__________________________________________________________|\n\n");
    printf("-----------------------------------------------------------\n");
    printf(">>>>   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>10)
    {
        printf(">>>>   Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int altaPasajero(LinkedList* listadoPasajeros)
{
	int idPasajero;
	char nombrePasajero[50];
	char apellidoPasajero[50];
	char precioPasajeStr[20];
	float precioPasaje;
	char codigoDeVuelo[20];
	char tipoDePasajeroStr[20];
	int tipoDePasajero;
	char estadoDeVueloStr[20];
	int estadoDeVuelo;

	Passenger* nuevoPasajero=NULL;

	if(listadoPasajeros!=NULL)
	{
		printf(" ___________________________________________________________________________________\n");
		printf("|                           >>> ALTA PASAJERO <<<                                   |\n");
	    printf("|___________________________________________________________________________________|\n\n");

	    buscarIdNuevo(&idPasajero);
	    Passenger_setId(nuevoPasajero, idPasajero);
	    actualizarId(idPasajero);

	    printf("Ingrese nombre del pasajero: ");
	    fflush(stdin);
	    gets(nombrePasajero);
	    Passenger_setNombre(nuevoPasajero, nombrePasajero);

	    printf("Ingrese apellido del pasajero: ");
	    fflush(stdin);
	    gets(apellidoPasajero);
	    Passenger_setApellido(nuevoPasajero, apellidoPasajero);

	    printf("Ingrese precio del vuelo: ");
	    fflush(stdin);
	    gets(precioPasajeStr);
	    precioPasaje=atoi(precioPasajeStr);
	    Passenger_setPrecio(nuevoPasajero, precioPasaje);

	    printf("Ingrese codigo de vuelo: ");
	   	fflush(stdin);
	   	gets(codigoDeVuelo);
	   	Passenger_setCodigoVuelo(nuevoPasajero, codigoDeVuelo);

	   	printf("Ingrese tipo de pasajero: ");
	   	fflush(stdin);
	    gets(tipoDePasajeroStr);
	    tipoDePasajero=atoi(tipoDePasajeroStr);
	    Passenger_setTipoPasajero(nuevoPasajero, tipoDePasajero);

	    strcpy(estadoDeVueloStr,"3");
	    estadoDeVuelo=atoi(estadoDeVueloStr);
	    Passenger_setEstadoVuelo(nuevoPasajero, estadoDeVuelo);

	    ll_add(listadoPasajeros, nuevoPasajero);
	    return 1;
	}
	return 0;
}

void cargarDescripcionTipoDePasajero(char* tipoDePasajero, int tipoEntero)
{
    if(tipoDePasajero!=NULL && tipoEntero>0)
    {
    	if(tipoEntero==1)
        {
    		strcpy(tipoDePasajero, "FirstClass");
        }
    	else if(tipoEntero==2)
    	{
    		strcpy(tipoDePasajero, "ExecutiveClass");
    	}
    	else
    	{
    		strcpy(tipoDePasajero, "EconomyClass");
    	}
    }
}

void cargarDescripcionEstadoPasajero(char* estadoDePasajero, int estadoEntero)
{
    if(estadoDePasajero!=NULL && estadoEntero>0)
    {
    	if(estadoEntero==1)
        {
    		strcpy(estadoDePasajero, "Demorado");
        }
    	else if(estadoEntero==2)
    	{
    		strcpy(estadoDePasajero, "Aterrizado");
    	}
    	else
    	{
    		strcpy(estadoDePasajero, "En Horario");
    	}
    }
}

void imprimirPasajero(Passenger* pasajero)
{
	char descripcionTipoPasajero[30];
	char descripcionEstadoVuelo[30];
	int id;
	char nombre[30];
	char apellido[30];
	float precio;
	char codigoVuelo[30];
	int tipoPasajero;
	int estadoVuelo;

	if(pasajero!=NULL)
	{
		if(Passenger_getNombre(pasajero, nombre)==0 && Passenger_getApellido(pasajero, apellido)==0 &&
		Passenger_getPrecio(pasajero, &precio)==0 && Passenger_getCodigoVuelo(pasajero, codigoVuelo)==0 &&
		Passenger_getTipoPasajero(pasajero, &tipoPasajero)==0 && Passenger_getEstadoVuelo(pasajero, &estadoVuelo)==0
		&& Passenger_getId(pasajero, &id)==0)
		{
			cargarDescripcionEstadoPasajero(descripcionEstadoVuelo,estadoVuelo);
			cargarDescripcionTipoDePasajero(descripcionTipoPasajero,tipoPasajero);

			printf("%5d  -%15s -%15s  -%10f  -%15s -%15s -%15s\n",id,nombre,apellido,precio,codigoVuelo,descripcionTipoPasajero,descripcionEstadoVuelo);
		}
		printf("_____________________________________________________________________________________\n");
	}
}

int imprimirPasajeros(LinkedList* listadoPasajeros)
{
	Passenger* nuevoPasajero=NULL;
	int banderaPasajero=0;

	if(listadoPasajeros!=NULL)
	{
		printf(" ___________________________________________________________________________________\n");
		printf("|                           >>> LISTADO DE PASAJEROS <<<                            |\n");
	    printf("|___________________________________________________________________________________|\n\n");
		printf("|   Id      Nombre     Apellido     Precio     Codigo V     Tipo Pas     Estado V   |\n");
		printf("|___________________________________________________________________________________|\n");

		for(int i=0; i<ll_len(listadoPasajeros); i++)
		{
			nuevoPasajero=(Passenger*)ll_get(listadoPasajeros, i);

			if(nuevoPasajero!=NULL)
			{
				banderaPasajero=1;
				imprimirPasajero(nuevoPasajero);
			}
		}

		if(banderaPasajero==0)
		{
			printf("  --------- No hay pasajeros cargados en el sistema ! ---------  \n");
			return 0;
		}
	}
	return 1;
}

int buscarPasajeroId(LinkedList* listadoPasajeros, int id)
{
	Passenger* pasajero=NULL;
	int posicion=-1;

	if(listadoPasajeros!=NULL && id>0)
	{
		for(int i=0; i<ll_len(listadoPasajeros); i++)
		{
			pasajero=(Passenger*)ll_get(listadoPasajeros, i);

			if(pasajero!=NULL && pasajero->id==id)
			{
				posicion=i;
				break;

			}
		}
	}
	return posicion;
}

int bajaPasajero(LinkedList* listadoPasajeros)
{
	int id;
	char idStr[10];
	int posicion;
	char continuar;

	if(listadoPasajeros!=NULL)
	{
		printf(" ___________________________________________________________________________________\n");
		printf("|                           >>> BAJA PASAJERO <<<                                   |\n");
	    printf("|___________________________________________________________________________________|\n\n");

	    imprimirPasajeros(listadoPasajeros);

	    printf("Ingrese id del pasajero a dar de baja: ");
	    fflush(stdin);
	    gets(idStr);
	    id=atoi(idStr);

	    posicion=buscarPasajeroId(listadoPasajeros, id);

	    if(posicion==-1)
	    {
	    	printf("  --------- No hay pasajero con el ID ingresado ! ---------  \n");
	    }
	    else
	    {
	    	printf("Desea dar de baja el pasajero con id:%d? (1-SI/2-NO): ",id);
	    	scanf("%c",&continuar);
	    	continuar=tolower(continuar);

	    	switch(continuar)
	    	{
	    	case 's':
	    		ll_remove(listadoPasajeros, posicion);
	    		printf("  --------- Baja de pasajero exitosa ! ---------  \n");
	    		break;
	    	case 'n':
	    		printf("  --------- Baja de pasajero cancelada ! ---------  \n");
	    		return 0;
	    		break;
	    	default:
	    		printf("  --------- Caracter ingresado invalido ! ---------  \n");
	    		return -1;
	    		break;
	    	}
	    }
	}
	return 1;
}

int modificarPasajero(LinkedList* listadoPasajeros)
{
	int id;
    char idStr[10];
	int posicion;
	char nuevoNombre[50];
	char nuevoApellido[50];
	char nuevoPrecioStr[10];
	float nuevoPrecio;
	char nuevoEstadoStr[50];
	int nuevoEstado;
	Passenger* pasajero=NULL;

	if(listadoPasajeros!=NULL)
	{
		printf(" ___________________________________________________________________________________\n");
		printf("|                         >>> MODIFICAR PASAJERO <<<                                |\n");
		printf("|___________________________________________________________________________________|\n\n");

		imprimirPasajeros(listadoPasajeros);

		printf("Ingrese id del pasajero a modificar: ");
		fflush(stdin);
		gets(idStr);
		id=atoi(idStr);

		posicion=buscarPasajeroId(listadoPasajeros, id);

		if(posicion==-1)
		{
			printf("  --------- No hay pasajero con el ID ingresado ! ---------  \n");
		}
		else
		{
			pasajero=(Passenger*)ll_get(listadoPasajeros, posicion);

		    switch(menuModificar())
		    {
		    case 1:
		    	printf(">>>   Ingrese nuevo nombre: ");
		    	fflush(stdin);
		    	gets(nuevoNombre);
		    	strcpy(pasajero->nombre, nuevoNombre);
		    	break;
		    	return 1;
		    case 2:
		    	printf(">>>   Ingrese nuevo apellido: ");
		    	fflush(stdin);
		    	gets(nuevoApellido);
		    	strcpy(pasajero->apellido,nuevoApellido);
		    	break;
		    	return 1;
		    case 3:
		    	printf(">>>   Ingrese nuevo precio: ");
		    	fflush(stdin);
		        gets(nuevoPrecioStr);
		        nuevoPrecio=atoi(nuevoPrecioStr);
		        pasajero->precio=nuevoPrecio;
		    	break;
		    	return 1;
		    case 4:
		    	printf(">>>   Ingrese estado de vuelo (1-Demorado/2-Aterrizado/3-En horario:  ");
		    	fflush(stdin);
		    	gets(nuevoEstadoStr);
		    	nuevoEstado=atoi(nuevoEstadoStr);
		    	pasajero->estadoVuelo=nuevoEstado;
		    	break;
		    	return 1;
		    }
		}
	}
	return 0;
}

int menuModificar()
{
    int opcion;
    system("cls");
    printf(" ____________________________________________\n");
    printf("|                                            |\n");
    printf("|           >>> MENU MODIFICAR <<<           |\n");
    printf("|____________________________________________|\n");
    printf("|                                            |\n");
    printf("|                1)Nombre                    |\n");
    printf("|                2)Apellido                  |\n");
    printf("|                3)Precio                    |\n");
    printf("|                4)Estado Vuelo              |\n");
    printf("|____________________________________________|\n\n");
    printf("----------------------------------------------\n");
    printf(">>>   Ingrese opcion: ");
    scanf("%d",&opcion);
    while(opcion<1 || opcion>4 )
    {
        printf(">>>   Reingrese opcion: ");
        scanf("%d",&opcion);
    }
    return opcion;
}





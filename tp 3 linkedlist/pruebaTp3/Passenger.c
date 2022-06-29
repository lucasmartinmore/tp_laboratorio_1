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

int MenuPrincipal()
{
    system("cls");
    int opcion;
    printf(" __________________________________________________________\n");
    printf("|                >>> LINKEDLIST PASAJEROS <<<              |\n");
    printf("|__________________________________________________________|\n\n");
    printf("|      1) Cargar los datos en data.csv (modo texto).       |\n");
    printf("|      2) Cargar los datos en data.bin (modo binario).     |\n");
    printf("|      3) Alta de pasajero                                 |\n");
    printf("|      4) Modificar datos de pasajero                      |\n");
    printf("|      5) Baja de pasajero                                 |\n");
    printf("|      6) Listar pasajeros                                 |\n");
    printf("|      7) Ordenar pasajeros                                |\n");
    printf("|      8) Guardar los datos en data.csv (modo texto).      |\n");
    printf("|      9) Guardar los datos en data.bin (modo binario).    |\n");
    printf("|     10) Salir                                            |\n");
    printf("|__________________________________________________________|\n\n");
    printf("-----------------------------------------------------------\n");

    opcion=validarEntero(">>>>   Ingrese opcion: ",">>>>   Reingrese opcion: ",1,10);
    return opcion;
}

Passenger* Passenger_new()
{
	return (Passenger*)malloc(sizeof(Passenger));
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precio,char* codigoDeVuelo,char* tipoPasajeroStr,char* estadoDeVuelo)
{
	Passenger* nuevoPasajero = Passenger_new();

	if(nuevoPasajero!=NULL && Passenger_setId(nuevoPasajero, atoi(idStr))==0 && Passenger_setNombre(nuevoPasajero, nombreStr)==0 &&
	Passenger_setApellido(nuevoPasajero, apellidoStr)==0 && Passenger_setPrecio(nuevoPasajero, atoi(precio))==0 &&
	Passenger_setCodigoVuelo(nuevoPasajero, codigoDeVuelo)==0 && Passenger_setTipoPasajero(nuevoPasajero, tipoPasajeroStr)==0
	&& Passenger_setEstadoVuelo(nuevoPasajero, estadoDeVuelo)==0)
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

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	if(this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(this->tipoPasajero,tipoPasajero);
		return 0;
	}
	return -1;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	if(this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
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

int Passenger_setEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
		return 0;
	}
	return -1;
}

int Passenger_getEstadoVuelo(Passenger* this, char* estadoVuelo)
{
	if(this!=NULL && estadoVuelo!=NULL)
	{
		strcpy(estadoVuelo,this->estadoVuelo);
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
	int retorno=0;
	FILE* punteroFile=NULL;
	punteroFile=fopen("idDisponible.bin","wb");

	if(punteroFile!=NULL)
	{
		id++;
		fwrite(&id,sizeof(int),1,punteroFile);
		fclose(punteroFile);
		retorno=1;
	}
	return retorno;
}

int altaPasajero(LinkedList* listadoPasajeros)
{
	int retorno=0;
	int idPasajero;
	char nombrePasajero[50];
	char apellidoPasajero[50];
	char precioPasajeStr[20];
	float precioPasaje;
	char codigoDeVuelo[20];
	char tipoDePasajeroStr[20];
	char estadoDeVueloStr[20];

	Passenger* nuevoPasajero=Passenger_new();

	if(listadoPasajeros!=NULL)
	{
		printf(" ___________________________________________________________________________________\n");
		printf("|                           >>> ALTA PASAJERO <<<                                   |\n");
	    printf("|___________________________________________________________________________________|\n\n");

	    buscarIdNuevo(&idPasajero);
	    Passenger_setId(nuevoPasajero, idPasajero);
	    actualizarId(idPasajero);

	    validarCadena("Ingrese nombre del pasajero: ","Error. Ingrese nombre del pasajero: ",50,nombrePasajero);
	    Passenger_setNombre(nuevoPasajero, nombrePasajero);

	    validarCadena("Ingrese apellido del pasajero: ","Error. Ingrese apellido del pasajero: ",50,apellidoPasajero);
	    Passenger_setApellido(nuevoPasajero, apellidoPasajero);

	    validarCadena("Ingrese precio del vuelo: ","Error. Ingrese precio del vuelo: ",20,precioPasajeStr);
	    precioPasaje=atoi(precioPasajeStr);
	    Passenger_setPrecio(nuevoPasajero, precioPasaje);

	    validarCadena("Ingrese codigo de vuelo: ","Error. Ingrese codigo de vuelo: ",20,codigoDeVuelo);
	   	Passenger_setCodigoVuelo(nuevoPasajero, codigoDeVuelo);

	   	validarCadena("Ingrese tipo de pasajero(FirstClass/ExecutiveClass/EconomyClass): ","Error. Ingrese tipo de pasajero(FirstClass/ExecutiveClass/EconomyClass): ",20,tipoDePasajeroStr);
	   	while(!(strcmp(tipoDePasajeroStr,"firstclass")==0 || strcmp(tipoDePasajeroStr,"executiveclass")==0 || strcmp(tipoDePasajeroStr,"economyclass")==0))
	   	{
	   		validarCadena("Error, ingrese tipo de pasajero(FirstClass/ExecutiveClass/EconomyClass): ","Error, ingrese tipo de pasajero(FirstClass/ExecutiveClass/EconomyClass): ",20,tipoDePasajeroStr);
	   		for(int i=0; tipoDePasajeroStr[i]!='\0';i++)
	   		{
	   			tipoDePasajeroStr[i]=tolower(tipoDePasajeroStr[i]);
	   	    }
	   	}
	    Passenger_setTipoPasajero(nuevoPasajero, tipoDePasajeroStr);

	    strcpy(estadoDeVueloStr,"En horario");
	    Passenger_setEstadoVuelo(nuevoPasajero, estadoDeVueloStr);

	    ll_add(listadoPasajeros, nuevoPasajero);
	    retorno=1;

	}
	return retorno;
}

void imprimirPasajero(Passenger* pasajero)
{
	int id;
	char nombre[30];
	char apellido[30];
	float precio;
	char codigoVuelo[30];
	char tipoPasajero[30];
	char estadoVuelo[30];

	if(pasajero!=NULL)
	{
		if(Passenger_getNombre(pasajero, nombre)==0 && Passenger_getApellido(pasajero, apellido)==0 &&
		Passenger_getPrecio(pasajero, &precio)==0 && Passenger_getCodigoVuelo(pasajero, codigoVuelo)==0 &&
		Passenger_getTipoPasajero(pasajero, tipoPasajero)==0 && Passenger_getEstadoVuelo(pasajero, estadoVuelo)==0
		&& Passenger_getId(pasajero, &id)==0  )
		{
			printf("%5d  %15s  %15s   %10.2f  %15s   -%15s  -%15s\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
		}
		printf("___________________________________________________________________________________________________________\n");
	}
}

int imprimirPasajeros(LinkedList* listadoPasajeros)
{
	int retorno=0;
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
				retorno=1;
			}
		}

		if(banderaPasajero==0)
		{
			printf("  --------- No hay pasajeros cargados en el sistema ! ---------  \n");
		}
	}
	return retorno;
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
	int retorno=0;
	int id;
	char idStr[10];
	int posicion;
	int continuar;

	if(listadoPasajeros!=NULL)
	{
		printf(" ___________________________________________________________________________________\n");
		printf("|                           >>> BAJA PASAJERO <<<                                   |\n");
	    printf("|___________________________________________________________________________________|\n\n");

	    imprimirPasajeros(listadoPasajeros);

	    validarCadena("Ingrese id del pasajero a dar de baja: ","Error. Ingrese id del pasajero a dar de baja: ",10,idStr);
	    id=atoi(idStr);

	    posicion=buscarPasajeroId(listadoPasajeros, id);

	    if(posicion==-1)
	    {
	    	printf("  --------- No hay pasajero con el ID ingresado ! ---------  \n");
	    }
	    else
	    {
	    	printf("Desea dar de baja el pasajero con id:%d? (1-SI/2-NO): ",id);
	    	scanf("%d",&continuar);

	    	switch(continuar)
	    	{
	    	case 1:
	    		ll_remove(listadoPasajeros, posicion);
	    		retorno=1;
	    		break;
	    	case 2:
	    		printf("  --------- Baja de pasajero cancelada ! ---------  \n");
	    		break;
	    	default:
	    		printf("  --------- Caracter ingresado invalido ! ---------  \n");
	    		break;
	    	}
	    }
	}
	return retorno;
}

int modificarPasajero(LinkedList* listadoPasajeros)
{
	int retorno=0;
	int id;
    char idStr[10];
	int posicion;
	char nuevoNombre[50];
	char nuevoApellido[50];
	char nuevoPrecioStr[10];
	float nuevoPrecio;
	char nuevoEstadoStr[50];
	Passenger* pasajero=NULL;

	if(listadoPasajeros!=NULL)
	{
		printf(" ___________________________________________________________________________________\n");
		printf("|                         >>> MODIFICAR PASAJERO <<<                                |\n");
		printf("|___________________________________________________________________________________|\n\n");

		imprimirPasajeros(listadoPasajeros);

		validarCadena("Ingrese id del pasajero a modificar: ","Error. Ingrese id del pasajero a modificar: ",10,idStr);
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
		    	validarCadena(">>>   Ingrese nuevo nombre: ",">>>   Error. Ingrese nuevo nombre: ",50,nuevoNombre);
		    	strcpy(pasajero->nombre, nuevoNombre);
		    	retorno=1;
		    	break;
		    case 2:
		    	validarCadena(">>>   Ingrese nuevo apellido: ",">>>   Error. Ingrese nuevo apellido: ",50,nuevoApellido);
		    	strcpy(pasajero->apellido,nuevoApellido);
		    	retorno=1;
		    	break;
		    case 3:
		    	validarCadena(">>>   Ingrese nuevo precio: ",">>>   Error. Ingrese nuevo precio: ",10,nuevoPrecioStr);
		        nuevoPrecio=atoi(nuevoPrecioStr);
		        pasajero->precio=nuevoPrecio;
		    	retorno=1;
		    	break;
		    case 4:
		    	validarCadena(">>>   Ingrese estado de vuelo (Demorado/Aterrizado/En horario):  ",">>>   Error. Ingrese estado de vuelo (demorado/aterrizado/en horario):  ",50,nuevoEstadoStr);
		    	while(!(strcmp(nuevoEstadoStr,"demorado")==0 || strcmp(nuevoEstadoStr,"aterrizado")==0 || strcmp(nuevoEstadoStr,"en horario")==0))
		        {
		    		validarCadena(">>>   Ingrese estado de vuelo (Demorado/Aterrizado/En horario):  ",">>>   Error. Ingrese estado de vuelo (demorado/aterrizado/en horario):  ",50,nuevoEstadoStr);
		    		for(int i=0; nuevoEstadoStr[i]!='\0';i++)
		    		{
		    		   	nuevoEstadoStr[i]=tolower(nuevoEstadoStr[i]);
		    		}
		        }
		    	strcpy(pasajero->estadoVuelo,nuevoEstadoStr);
		    	retorno=1;
		    	break;
		    }
		}
	}
	return retorno;
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

    opcion=validarEntero(">>>   Ingrese opcion: ",">>>   Error. Ingrese opcion: ",1,4);
    return opcion;
}

int OrdenamientosPasajerosId(void* pasajero1, void* pasajero2)
{
    int retorno;
    int idPasajero1;
    int idPasajero2;

    if(pasajero1!=NULL && pasajero2!=NULL)
    {
        Passenger_getId((Passenger*)pasajero1, &idPasajero1);
        Passenger_getId((Passenger*)pasajero2, &idPasajero2);

        if(idPasajero1>idPasajero2)
        {
            retorno=1;
        }
        else if(idPasajero1<idPasajero2)
        {
            retorno=-1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

int menuOdenamiento()
{
    int opcion;
    system("cls");
    printf(" ____________________________________________\n");
    printf("|                                            |\n");
    printf("|          >>> MENU ORDENAMIENTO <<<         |\n");
    printf("|____________________________________________|\n");
    printf("|                                            |\n");
    printf("|                 1)Id                       |\n");
    printf("|                 2)Nombre                   |\n");
    printf("|                 3)Apellido                 |\n");
    printf("|                 4)Precio                   |\n");
    printf("|____________________________________________|\n\n");
    printf("----------------------------------------------\n");

    opcion=validarEntero(">>>   Ingrese opcion: ",">>>   Error. Ingrese opcion: ",1,4);
    return opcion;
}

int menuCriterio()
{
    int opcion;
    system("cls");
    printf(" ____________________________________________\n");
    printf("|                                            |\n");
    printf("|           >>> MENU CRITERIO <<<            |\n");
    printf("|____________________________________________|\n");
    printf("|                                            |\n");
    printf("|               1)Ascendente                 |\n");
    printf("|               2)Descendente                |\n");
    printf("|____________________________________________|\n\n");
    printf("----------------------------------------------\n");

    opcion=validarEntero(">>>   Ingrese opcion: ",">>>   Error. Ingrese opcion: ",1,2);
    return opcion;
 }

int OrdenamientosPasajerosNombre(void* pasajero1, void* pasajero2)
{
    int retorno=0;
    char nombrePasajero1[50];
    char nombrePasajero2[50];

    if(pasajero1!=NULL && pasajero2!=NULL)
    {
        Passenger_getNombre((Passenger*)pasajero1, nombrePasajero1);
        Passenger_getNombre((Passenger*)pasajero2, nombrePasajero2);
        retorno=strcmp(nombrePasajero1, nombrePasajero2);
    }
    return retorno;
}

int OrdenamientosPasajerosApellido(void* pasajero1, void* pasajero2)
{
    int retorno=0;
    char nombrePasajero1[50];
    char nombrePasajero2[50];

    if(pasajero1!=NULL && pasajero2!=NULL)
    {
        Passenger_getApellido((Passenger*)pasajero1, nombrePasajero1);
        Passenger_getApellido((Passenger*)pasajero2, nombrePasajero2);
        retorno=strcmp(nombrePasajero1, nombrePasajero2);
    }
    return retorno;
}

int OrdenamientosPasajerosPrecio(void* pasajero1, void* pasajero2)
{
    int retorno;
    float precioPasajero1;
    float precioPasajero2;

    if(pasajero1!=NULL && pasajero2!=NULL)
    {
        Passenger_getPrecio((Passenger*)pasajero1, &precioPasajero1);
        Passenger_getPrecio((Passenger*)pasajero2, &precioPasajero2);

        if(precioPasajero1>precioPasajero2)
        {
            retorno=1;
        }
        else if(precioPasajero1<precioPasajero2)
        {
            retorno=-1;
        }
        else
        {
            retorno=0;
        }
    }
    return retorno;
}

int ordenarPasajeros(LinkedList* listadoPasajeros)
{
	int retorno=0;

	if(listadoPasajeros!=NULL)
	{
		switch(menuOdenamiento())
		{
		case 1:
			switch(menuCriterio())
			{
			case 1:
				ll_sort(listadoPasajeros, OrdenamientosPasajerosId,1);
				break;
			case 2:
				ll_sort(listadoPasajeros, OrdenamientosPasajerosId,0);
				break;
			}
			retorno=1;
			break;
		case 2:
			switch(menuCriterio())
			{
			case 1:
				ll_sort(listadoPasajeros, OrdenamientosPasajerosNombre,1);
				break;
			case 2:
				ll_sort(listadoPasajeros, OrdenamientosPasajerosNombre,0);
				break;
			}
			retorno=1;
			break;
		case 3:
			switch(menuCriterio())
			{
			case 1:
				ll_sort(listadoPasajeros, OrdenamientosPasajerosApellido,1);
				break;
			case 2:
				ll_sort(listadoPasajeros, OrdenamientosPasajerosApellido,0);
				break;
			}
			retorno=1;
			break;
		case 4:
			switch(menuCriterio())
			{
			case 1:
				ll_sort(listadoPasajeros, OrdenamientosPasajerosPrecio,1);
				break;
			case 2:
				ll_sort(listadoPasajeros, OrdenamientosPasajerosPrecio,0);
				break;
			}
			retorno=1;
			break;
		}
	}
	return retorno;
}

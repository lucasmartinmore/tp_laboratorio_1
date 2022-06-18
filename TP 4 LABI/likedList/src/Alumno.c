/*
 * Alumno.c
 *
 *  Created on: 18 jun. 2022
 *      Author: Lucas
 */
#include "Alumno.h"
#include "../inc/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int MenuPrincipal()
{
    int opcion;
    printf(" ________________________________________________________\n");
    printf("|              >>> LINKEDLIST ALUMNOS <<<                |\n");
    printf("|________________________________________________________|\n\n");
    printf("|      1) Cargar los datos modo texto                    |\n");
    printf("|      2) Mostrar los alumnos                            |\n");
    printf("|      3) Informar cantidad de alumnos                   |\n");
    printf("|      4) Cargar desaprobados e informar                 |\n");
    printf("|      5) Informar alumnos aprobados                     |\n");
    printf("|      6) Chequear desaprobados en lista alumno          |\n");
    printf("|      7) Informar alumno por indice                     |\n");
    printf("|      8) Cambiar primero por ultimo                     |\n");
    printf("|      9) Eliminar desaprobados                          |\n");
    printf("|     10) Vaciar lista desaprobados                      |\n");
    printf("|     11) Informar indice alumno ejemplar                |\n");
    printf("|     12) Informar recarga alumnos desaprobado           |\n");
    printf("|     13) Duplicar ultimo alumno                         |\n");
    printf("|     14) Eliminar ultimo alumno y mostrar               |\n");
    printf("|     15) Crear sublista primeros 5,muestro y elimino    |\n");
    printf("|     16) Clonar alumnos, ordenarxN, muestro y elimino   |\n");
    printf("|     17) Salir del menu                                 |\n");
    printf("|________________________________________________________|\n\n");
    printf("---------------------------------------------------------\n");
    printf(">>>>   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>17)
    {
        printf(">>>>   Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

Alumno* alumno_new()
{
    return (Alumno*)malloc(sizeof(Alumno));
}

Alumno* alumno_newParam(char* idStr, char* nombre, char* apellido, char* edadStr, char* notasStr)
{
	Alumno* nuevoAlumno=alumno_new();

	if(nuevoAlumno!=NULL && alumno_setId(nuevoAlumno,atoi(idStr)) && alumno_setNombre(nuevoAlumno, nombre) && alumno_setApellido(nuevoAlumno, apellido)
	&& alumno_setEdad(nuevoAlumno, atoi(edadStr)) && alumno_setNotas(nuevoAlumno, atoi(notasStr)))
	{
		return nuevoAlumno;
	}
	free(nuevoAlumno);
    nuevoAlumno=NULL;

	return nuevoAlumno;
}

void alumno_delete(Alumno* this)
{
	free(this);
}

int alumno_setId(Alumno* this, int id)
{
	int retorno=0;

	if(this!=NULL && id>0)
	{
		this->id=id;
	    retorno=1;
	}
	return retorno;
}

int alumno_getId(Alumno* this, int* id)
{
	int retorno=0;
	if(this!=NULL && id!=NULL)
	{
	    *id=this->id;
		retorno=1;
	}
	return retorno;
}

int alumno_setNombre(Alumno* this,char* nombre)
{
	int retorno=0;

	if(this!=NULL && nombre!=NULL && strlen(nombre)<50 && strlen(nombre)>0)
	{
		strcpy(this->nombre, nombre);
	    retorno=1;
	}
	return retorno;
}

int alumno_getNombre(Alumno* this,char* nombre)
{
	int retorno=0;

	if(this!=NULL && nombre!=NULL && strlen(nombre)<50 && strlen(nombre)>0)
	{
		strcpy(nombre, this->nombre);
	    retorno=1;
	}
	return retorno;
}

int alumno_setApellido(Alumno* this,char* apellido)
{
	int retorno=0;

	if(this!=NULL && apellido!=NULL && strlen(apellido)<50 && strlen(apellido)>0)
	{
		strcpy(this->apellido, apellido);
		retorno=1;
	}
	return retorno;
}

int alumno_getApellido(Alumno* this,char* apellido)
{
	int retorno=0;

	if(this!=NULL && apellido!=NULL && strlen(apellido)<50 && strlen(apellido)>0)
	{
		strcpy(apellido, this->apellido);
		retorno=1;
	}
	return retorno;
}

int alumno_setEdad(Alumno* this,int edad)
{
	int retorno=0;

	if(this!=NULL && edad>0)
	{
		this->edad=edad;
		retorno=1;
	}
	return retorno;
}

int alumno_getEdad(Alumno* this,int* edad)
{
	int retorno=0;

	if(this!=NULL && edad!=NULL)
	{
		*edad=this->edad;
		retorno=1;
	}
	return retorno;
}

int alumno_setNotas(Alumno* this, int notas)
{
	int retorno=0;

	if(this!=NULL && notas>0)
	{
		this->notas=notas;
		retorno=1;
	}
	return retorno;
}

int alumno_getNotas(Alumno* this, int* notas)
{
	int retorno=0;

	if(this!=NULL && notas!=NULL)
	{
		*notas=this->notas;
		retorno=1;
	}
	return retorno;
}

void mostrarAlumno(Alumno* unAlumno)
{
	printf("       %2d  %12s %12s      %2d      %2d\n",unAlumno->id,unAlumno->nombre,unAlumno->apellido,unAlumno->edad,unAlumno->notas);
	printf("___________________________________________________________\n");
}

void mostrarAlumnos(LinkedList* listadoAlumnos)
{
	if(listadoAlumnos!=NULL)
	{
		printf(" __________________________________________________________\n");
		printf("|                >>> LISTADO DE ALUMNOS <<<                |\n");
		printf("|__________________________________________________________|\n\n");
		printf("|      Id      Nombre        Apellido    Edad    Notas     |\n");
		printf("|__________________________________________________________|\n");

		for(int i=0; i<ll_len(listadoAlumnos); i++)
		{
			mostrarAlumno(ll_get(listadoAlumnos, i));

		}
	}
}

int alumno_imprimirCantidadTotal(LinkedList* listadoAlumnos)
{
	int retorno=0;

	if(listadoAlumnos!=NULL)
	{
		printf("\n--------- La cantidad total de alumnos es de %d ! ---------  \n",ll_len(listadoAlumnos));
	    retorno=1;
	}
	return retorno;
}

int parser_AlumnoFromText(FILE* pFile, LinkedList* listadoAlumnos)
{
    int retorno=-1;
    int cantidad;
    char buffer[5][50];
    Alumno* unAlumno=NULL;

    if(pFile!=NULL && listadoAlumnos!=NULL)
    {
        cantidad=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

        while(!feof(pFile))
        {
        	cantidad=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

        	if(cantidad==5)
        	{
        		unAlumno=alumno_newParam(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

        	    if(unAlumno!=NULL)
        	    {
        	    	ll_add(listadoAlumnos, unAlumno);
        	        retorno=1;
        	    }
        	}
        	else
        	{
        		printf("No pude leer alumno\n");
        	    break;
        	}
        }

    }
    fclose(pFile);
    return retorno;
}

int load_AlumnoFromText(char* path, LinkedList* listadoAlumnos)
{
	int retorno=0;
	FILE* pFile=NULL;

	if(path!=NULL && listadoAlumnos!=NULL)
	{
		pFile=fopen(path,"r");

	    if(pFile!=NULL)
	    {
	    	if(parser_AlumnoFromText(pFile,listadoAlumnos))
	        {
	    		retorno=1;
	        }
	    	else
	    	{
	    		printf("Error al cargar el archivo\n");
	    	}
	    }
	    else
	    {
	    	printf("El archivo no se pudo abrir correctamente\n");
	    }
        fclose(pFile);
	}
	return retorno;
}

int alumno_informarPosicion(LinkedList* listadoAlumnos, int indice)
{
	 int retorno=0;

	 if(listadoAlumnos!=NULL && indice >=0 && ll_len(listadoAlumnos)>=indice)
	 {
		 mostrarAlumno((Alumno*)ll_get(listadoAlumnos, indice-1));
	     retorno=1;
	 }
	 return retorno;
}

int alumno_intercambioUltimoxPrimero(LinkedList* listadoAlumnos)
{
	int retorno=0;
	Alumno* unAlumno=NULL;
	int tamaniooListado=ll_len(listadoAlumnos);

	if(listadoAlumnos!=NULL)
	{
		unAlumno=ll_get(listadoAlumnos, 0); //devuelvo el primer alumno
	    ll_set(listadoAlumnos, 0, ll_get(listadoAlumnos, tamaniooListado-1)); //modifico el primer alumno y agrego el ultimo alumno
	    ll_set(listadoAlumnos, tamaniooListado-1, unAlumno); //modifico el ultimo alumno y agrego el primero
	    retorno=1;
	}
	return retorno;
}

int alumno_eliminarDesaprobados(LinkedList* listadoAlumnos)
{
	int retorno=0;
	Alumno* unAlumno=NULL;

	if(listadoAlumnos!=NULL)
	{
	    for(int i=0; i<ll_len(listadoAlumnos); i++)
	    {
	    	unAlumno=ll_get(listadoAlumnos, i);
	        if(unAlumno->notas<4)
	        {
	        	ll_remove(listadoAlumnos, i);
	            retorno=1;
	        }
	    }
	}
	return retorno;
}

int alumnos_vaciarListaDesaprobados(LinkedList* alumnosDesaprobados)
{
	int retorno=0;

	if(alumnosDesaprobados!=NULL)
	{
		if(!ll_clear(alumnosDesaprobados))
	    {
			retorno=1;
	    }
	}
	return retorno;
}

int alumno_posicionAlumnoEjemplar(LinkedList* listadoAlumnos)
{
	int retorno=-1;
	Alumno* unAlumno=NULL;

	if(listadoAlumnos!=NULL)
	{
	    for(int i=0; i<ll_len(listadoAlumnos); i++)
	    {
	    	unAlumno=ll_get(listadoAlumnos, i);

	        if(unAlumno->notas==10)
	        {
	        	retorno=ll_indexOf(listadoAlumnos, unAlumno);
	        }
	    }
	}
	return retorno;
}

int alumno_duplicarUltimoAlumno(LinkedList* listadoAlumnos)
{
	int retorno=0;
	Alumno* unAlumno=NULL;

	if(listadoAlumnos!=NULL)
	{
		unAlumno=ll_get(listadoAlumnos, ll_len(listadoAlumnos)-1); //me devuelve el ultimo alumno
	    ll_push(listadoAlumnos, ll_len(listadoAlumnos), unAlumno); //inserto al ultimo otra el ultimo alumno
	    retorno=1;
	}
	return retorno;
}

int alumno_eliminarUltimoAlumno(LinkedList* listadoAlumnos)
{
	int retorno=0;
	Alumno* unAlumno=NULL;

	if(listadoAlumnos!=NULL)
	{
	    unAlumno=ll_pop(listadoAlumnos, ll_len(listadoAlumnos)-1); //elimina el ultimo alumno y lo retorna
	    mostrarAlumno(unAlumno); //muestro el alumno eliminado
	    retorno=1;
	}
	return retorno;
}

int alumno_checkDesaprobados(LinkedList* listadoAlumnos, LinkedList* listadoDesaprobados)
{
	int retorno=0;
	if(listadoAlumnos!=NULL && listadoDesaprobados!=NULL)
	{
		retorno=ll_containsAll(listadoAlumnos, listadoDesaprobados);
	}
	return retorno;
}

LinkedList* alumno_subListaPrimerosCinco(LinkedList* listadoAlumnos)
{
	LinkedList* primerosCincos=NULL;

	if(listadoAlumnos!=NULL && ll_len(listadoAlumnos)>=5)
	{
		primerosCincos=ll_newLinkedList();

	    if(primerosCincos!=NULL)
	    {
	    	primerosCincos=ll_subList(listadoAlumnos, 0, 5);
	    }
	 }
	 return primerosCincos;
}

LinkedList* alumno_clonarLista(LinkedList* listadoAlumnos)
{
	LinkedList* listaClonada=NULL;

	if(listadoAlumnos!=NULL)
	{
		listaClonada=ll_newLinkedList();

	    if(listaClonada!=NULL)
	    {
	    	listaClonada= ll_clone(listadoAlumnos);
	    }
	}
	return listaClonada;
}

int alumno_compararxNota(void* pElement1, void* pElement2)
{
	int retorno=0;
	int nota1;
	int nota2;

	if(pElement1!=NULL && pElement2!=NULL)
	{
		alumno_getNotas((Alumno*)pElement1, &nota1);
		alumno_getNotas((Alumno*)pElement2, &nota2);

	    if(nota1>nota2)
	    {
	    	retorno=1;
	    }
	    else if(nota1<nota2)
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

int alumno_ordenarPorNotas(LinkedList* listadoAlumnos)
{
	int retorno=0;

	if(listadoAlumnos!=NULL)
	{
		if(!ll_sort(listadoAlumnos,alumno_compararxNota,1))
	    {
			retorno=1;
	    }
	}
	return retorno;
}

int desaprobados(void* pElement)
{
	int retorno=0;
	Alumno* alumno=NULL;

	if(pElement!=NULL)
	{
		alumno=(Alumno*)pElement;

	    if(alumno->notas<4)
	    {
	    	retorno=1;
	    }
	}
	return retorno;
}

int aprobados(void* pElement)
{
	int retorno=0;
	Alumno* alumno=NULL;

	if(pElement!=NULL)
	{
		alumno=(Alumno*)pElement;

		if(alumno->notas>=4)
		{
			retorno=1;
		}
	}
	return retorno;
}



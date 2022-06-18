/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Alumno.h"


int main(void)
{
	/*
	startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort
	*/

	setbuf(stdout, NULL);
	int opcion=0;
	int banderaCarga=1;
	LinkedList* listadoAlumnos=NULL;
	LinkedList* alumnosDesaprobados=NULL;
	LinkedList* alumnosAprobados=NULL;
	LinkedList* alumnosPrimeros5=NULL;
	LinkedList* alumnosClonados=NULL;

		do
		{
			switch(MenuPrincipal())
			{
			case 1:
				if(banderaCarga)
				{
					listadoAlumnos=ll_newLinkedList();//uso ll_newLinkedList
					if(load_AlumnoFromText("Alumno.csv", listadoAlumnos))
					{
						printf("\n--------- Listado cargado con exito ! ---------  \n");
						banderaCarga=0;
					}
				}
				else
				{
					printf("\n--------- Listado ya cargado ! ---------  \n");
				}
				break;
			case 2:
				mostrarAlumnos(listadoAlumnos);
				break;
			case 3:
				alumno_imprimirCantidadTotal(listadoAlumnos);
				break;
			case 4:
				alumnosDesaprobados=ll_newLinkedList();
				alumnosDesaprobados=ll_filter(listadoAlumnos, desaprobados);
				mostrarAlumnos(alumnosDesaprobados);
				break;
			case 5:
				alumnosAprobados=ll_newLinkedList();
				alumnosAprobados=ll_filter(listadoAlumnos, aprobados);
				mostrarAlumnos(alumnosAprobados);
				break;
			case 6:
				if(listadoAlumnos!=NULL && alumnosDesaprobados!=NULL)
				{
					if(alumno_checkDesaprobados(listadoAlumnos, alumnosDesaprobados))
					{
						printf("\n--------- Los alumnos desaprobados se encuentran en el sistema ! ---------  \n");
					}
				}
				else
				{
					printf("\n--------- Se deben cargar las listas antes de chequear ! ---------  \n");
				}
				break;
			case 7:
				alumno_informarPosicion(listadoAlumnos, 7);
				break;
			case 8:
				alumno_intercambioUltimoxPrimero(listadoAlumnos);
				mostrarAlumnos(listadoAlumnos);
				break;
			case 9:
				if(alumno_eliminarDesaprobados(listadoAlumnos))
				{
					printf("\n--------- Alumnos desaprobados eliminados del sistema ! ---------  \n");
				}
				break;
			case 10:
				if(alumnosDesaprobados!=NULL)
				{
					mostrarAlumnos(alumnosDesaprobados);
					if(alumnos_vaciarListaDesaprobados(alumnosDesaprobados))
					{
						printf("\n--------- Alumnos desaprobados vaciados del sistema ! ---------  \n");
					}
				}
				break;
			case 11:
				if(listadoAlumnos!=NULL)
				{
					printf("\n--------- El indice del alumnos ejemplar en el sistema es el %d ! ---------  \n",alumno_posicionAlumnoEjemplar(listadoAlumnos));
				}
				break;
			case 12:
				if(alumnosDesaprobados!=NULL && ll_isEmpty(alumnosDesaprobados))//->Utilizo isEmpty para saber si la lista esta vacia
				{
					printf("\n--------- El listado de alumnos desaprobados se encuentra vacio, por favor carguelos nuevamente ! ---------  \n");
				}
				break;
			case 13:
				alumno_duplicarUltimoAlumno(listadoAlumnos);
				mostrarAlumnos(listadoAlumnos);
				break;
			case 14:
				if(!ll_isEmpty(listadoAlumnos))
				{
					alumno_eliminarUltimoAlumno(listadoAlumnos);
				}
				break;
			case 15:
				alumnosPrimeros5=ll_newLinkedList();
				if(alumnosPrimeros5!=NULL)
				{
					alumnosPrimeros5=alumno_subListaPrimerosCinco(listadoAlumnos);
					mostrarAlumnos(alumnosPrimeros5);
					ll_deleteLinkedList(alumnosPrimeros5);
				}
				break;
			case 16:
				alumnosClonados=ll_newLinkedList();
				if(alumnosClonados!=NULL)
				{
					alumnosClonados=alumno_clonarLista(listadoAlumnos);
					mostrarAlumnos(alumnosClonados);
					alumno_ordenarPorNotas(alumnosClonados);
					mostrarAlumnos(alumnosClonados);
					ll_deleteLinkedList(alumnosClonados);
				}
				break;
			case 17:
				ll_deleteLinkedList(listadoAlumnos);//->Utilizo ll_deleteLinkedList para eliminar mis linkedlist creadas
				ll_deleteLinkedList(alumnosDesaprobados);
				ll_deleteLinkedList(alumnosAprobados);
				break;
			}
		}while(opcion!=17);


    return 0;
}


































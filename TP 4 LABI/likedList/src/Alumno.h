/*
 * Alumno.h
 *
 *  Created on: 18 jun. 2022
 *      Author: Lucas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

#ifndef SRC_ALUMNO_H_
#define SRC_ALUMNO_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	int edad;
	int notas;
}Alumno;

int MenuPrincipal();

Alumno* alumno_new();
Alumno* alumno_newParam(char* idStr, char* nombre, char* apellido, char* edadStr, char* notasStr);
void alumno_delete(Alumno* this);

int alumno_setId(Alumno* this, int id);
int alumno_getId(Alumno* this, int* id);
int alumno_setNombre(Alumno* this,char* nombre);
int alumno_getNombre(Alumno* this,char* nombre);
int alumno_setApellido(Alumno* this,char* apellido);
int alumno_getApellido(Alumno* this,char* apellido);
int alumno_setEdad(Alumno* this,int edad);
int alumno_getEdad(Alumno* this,int* edad);
int alumno_setNotas(Alumno* this, int notas);
int alumno_getNotas(Alumno* this, int* notas);

void mostrarAlumno(Alumno* unAlumno);
void mostrarAlumnos(LinkedList* listadoAlumnos);

int alumno_imprimirCantidadTotal(LinkedList* listadoAlumnos); //->ll_len para contar
int load_AlumnoFromText(char* path, LinkedList* listadoAlumnos);//->Utilizo ll_add y add node para agregar alumno
int parser_AlumnoFromText(FILE* pFile, LinkedList* listadoAlumnos);//->Utilizo ll_add y add node para agregar alumno
int alumno_informarPosicion(LinkedList* listadoAlumnos, int indice);//->Utilizo ll_get para devolver un alumno
int alumno_intercambioUltimoxPrimero(LinkedList* listadoAlumnos);//->Utilizo ll_set para modificar las posiciones
int alumno_eliminarDesaprobados(LinkedList* listadoAlumnos);//->Utilizo ll_remove remover el alumno desaprobado
int alumnos_vaciarListaDesaprobados(LinkedList* listadoAlumnos);//->Utilizo ll_clear para eliminar el alumno desaprobado
int alumno_posicionAlumnoEjemplar(LinkedList* listadoAlumnos);//->Utilizo ll_indexOf para devolver la posicion con la condicion solicitada
int alumno_duplicarUltimoAlumno(LinkedList* listadoAlumnos);//->Utilizo push para insertar al ultimo el mismo alumno copiado
int alumno_eliminarUltimoAlumno(LinkedList* listadoAlumnos);//->Utilizo pop para eliminar el ultimo alumno copiado y lo retorno
int alumno_checkDesaprobados(LinkedList* listadoAlumnos, LinkedList* listadoDesaprobados);//->Utilizo ll_contain y containAll para saber si los pElement de mi 2 listado se encuentra dentro del listado original
LinkedList* alumno_subListaPrimerosCinco(LinkedList* listadoAlumnos);//->Utilizo subList para decirle al nuevo linkedist de donde hasta donde quiero copiar
LinkedList* alumno_clonarLista(LinkedList* listadoAlumnos);//->Utilizo ll_clone para clonar en mi nueva linkedlist los pElement de mi linkedlist original
int alumno_compararxNota(void* pElement1, void* pElement2);//->Funcion que utilizo para usar de parametro en el sort
int alumno_ordenarPorNotas(LinkedList* listadoAlumnos);//->Utilizo ll_sort para hacer las comparaciones segun el criterio indicado
int desaprobados(void* pElement);//->Funcion utilizada para usar como criterio de ll_filter para agregar los elementos a mi nueva linkedlist
int aprobados(void* pElement);int desaprobados(void* pElement);//->Funcion utilizada para usar como criterio de ll_filter para agregar los elementos a mi nueva linkedlist

#endif /* SRC_ALUMNO_H_ */

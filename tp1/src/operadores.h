/*
 * operadores.h
 *
 *  Created on: 7 sep. 2021
 *      Author: ACantarini
 */

#ifndef OPERADORES_H_
#define OPERADORES_H_



#endif /* OPERADORES_H_ */

/** \ //Invoco mi menu con las opciones disponibles (llamando a mis banderas que van a habilitar
 * //el reemplazo de X,Y,Z y primer y segundo son mis variables para validar que los datos se hayan ingresado
 * \param
 * \param
 * \return //No retorno ningun dato, pero imprimo el menu principal.
 *
 */

void menu(int primer, int segundo, int km, int importeAerolineas, int importeLatam);

/** \brief //Paso los operandos cargado/s para procesar el dato
 *
 * \param //
 * \param //
 * \return  //Retorno el valor del/de los operando cargado
 *
 */

float operandos();

/** \brief //Realizo el descuento utilizando mi variable precio
 *
 * \param
 * \param
 * \return  //Retorno el resultado de la operacion
 *
 */


float descuentoDebito(float precio);

/** \brief //Realizo el interes utilizando mi variable precio
 *
 * \param
 * \param
 * \return  //Retorno el resultado de la operacion
 *
 */

float interesCredito(float precio);

/** \brief //Realizo la convercion a bitcoin utilizando mi variable precio
 *
 * \param //valido los el valor de mis variables cargadas
 * \param
 * \return  //Retorno el resultado de la operacion
 *
 */

float conversorBitcoin(int precio);

/** \brief //Realizo la operacion para calcular el importe por km utilizando mi variable ImporteTotal y km
 *
 * \param
 * \param
 * \return  //Retorno el resultado de la operacion
 *
 */

float precioUnitario(float km, float importeTotal);

/** \brief //Realizo la operacion para saber la difencia de ambos importe utilizando ambos importes como variables
 *
 * \param //valido los el valor de mi variable cargada.
 * \param
 * \return  //Retorno el resultado de la operacion
 *
 */

float diferenciaImporte(float importe1, float importe2);

/** \brief //Realizo el informe final con las vaiables cargadas con los resultados de las funciones anteriores.
 *
 * \param
 * \param
 * \return  //No retorno nada, solo imprimo los valores
 *
 */

void informeFinal(float km, float importeAerolineas, float importeLatam, float descuentoA, float descuentoC,
float interesA, float interesC, float bitcoinA, float bitcoinC, float precioUnitarioA,
float precioUnitarioC, float direnciaImporte);

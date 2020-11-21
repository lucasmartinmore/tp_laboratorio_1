#ifndef OPERADORES_H_INCLUDED
#define OPERADORES_H_INCLUDED



#endif // OPERADORES_H_INCLUDED

/** \ //Invoco mi menu con las opciones disponibles (llamando a mis banderas que van a habilitar
 *    //el reemplazo de A=X y B=Y
 * \param
 * \param
 * \return //No retorno ningun dato, pero imprimo el menu principal.
 *
 */

void menu();

/** \brief //Paso los operandos cargado/s para procesar el dato
 *
 * \param //
 * \param //
 * \return  //Retorno el valor del/de los operando cargado
 *
 */

int operandos();

/** \brief //Realizo la suma entre A y B
 *
 * \param
 * \param
 * \return  //Retorno el resultado de la operacion
 *
 */


int suma(int a, int b);

/** \brief //Realizo la resta entre A y B
 *
 * \param
 * \param
 * \return  //Retorno el resultado de la operacion
 *
 */

int resta(int a, int b);

/** \brief //Realizo la division entre A y B
 *
 * \param //valido los el valor de mis variables cargadas
 * \param
 * \return  //Retorno el resultado de la operacion
 *
 */

float division(int a, int b);

/** \brief //Realizo la multiplicacion entre A y B
 *
 * \param
 * \param
 * \return  //Retorno el resultado de la operacion
 *
 */

int multiplicacion(int a, int b);

/** \brief //Realizo el factorial de mi variable cargada
 *
 * \param //valido los el valor de mi variable cargada.
 * \param
 * \return  //Retorno el resultado de la operacion
 *
 */

int factorial(int x);

/** \brief //Realizo el informe final con las vaiables cargadas con los resultados de las funciones anteriores.
 *
 * \param
 * \param
 * \return  //No retorno nada, solo imprimo los valores
 *
 */

void informeFinal(int a, int b, int resultadoSuma, int resultadoResta, int resultadoMultiplicacion, float resultadoDivision, int resultadoFactorialA, int resultadoFactorialB);


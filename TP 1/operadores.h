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

/** \brief //Paso los operandos A y B para procesar el dato
 *
 * \param //
 * \param //
 * \return  //No retorno dato solo imprimo un mensaje de ejecucion
 *
 */

void calcular(int a, int b);

/** \brief //Solicito mi primer operando a evaluar
 *
 * \param //operando A
 * \param
 * \return //retorno mi operando A solicitado dentro de mi funcion.
 *
 */

int operandoA();

/** \brief //Solicito mi segundo operando a evaluar
 *
 * \param //operando B
 * \param
 * \return //retorno mi operando B solicitado dentro de mi funcion.
 *
 */

int operandoB();

/** \brief //Paso los operando para realizar todas las operaciones disponible
//dentro de mi funcion(SUMA, RESTA, DIVISION, MULTIPLICACION Y FACTORIAL).
 *
 * \param //operando A
 * \param //operando B
 * \return //No retorno dato especifico, pero imprimo todas las operaciones realizadas
 //dentro de mi funcion.
 *
 */

void calculos(int a, int b);

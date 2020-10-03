#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \ //Esta funcion llama al Menu principa
 *
 * \param //Captura el parametro elegido
 * \param
 * \return //Retorna el parametro
 *
 */
int menu();

/** \brief //Esta funcion inicia mi list asignando 1 a cada array de estructura vacio.
 *
 * \param
 * \param
 * \return // retorna -1 si los parametros pasados son incorrecto o 0 si se pudo ejecturar con exito
 *
 */
int initEmployees(Employee* list, int len);

//Esta funcion pasa los parametros pedidos asigandoselo al primer espacio vacio
//y cargando con 0 en caso de realizarse.
/** \brief
 *
 * \param
 * \param
 * \return retorna -1 si los parametros pasados son incorrecto o 0 si se pudo ejecturar con exito
 *
 */

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int printEmployees(Employee* list, int len);

/** \//Esta funcion imprime los empleados cargados unicamente
 *
 * \param
 * \param
 * \return //Retorna -1 si los parametros pasados son incorrecto o 0 si se pudo ejecturar con exito
 *
 */

int findEmployeeById(Employee* list, int len, int legajo);

/** \//Esta funcion remueve al empleado seleccionado
 *
 * \param
 * \param
 * \return //Retorna -1 si los parametros pasados no se encuentran o 0 si se pudo ejecturar con exito.
 *
 */

int removeEmployee(Employee* list, int len, int id);

/** \//Esta funcion invoca a la funcion findEmployeeById() y solicita el dato a modificar
 *
 * \param
 * \param
 * \return //Retorna -1 si los parametros pasados no se encuentran o 0 si se pudo ejecturar con exito.
 *
 */

int modifycaEmployee(Employee* list, int len);

/** \brief //Esta funcion recibe parametros a para ordenar el listado. Y solicita los datos a ordenar.
 *
 * \param
 * \param
 * \return //Retorna -1 si los parametros pasados son incorrecto o 0 si se pudo ejecturar con exito
 *
 */

int sortEmployees(Employee* list, int len, int order);

/** \brief //Esta funcion recibe los parametros a analizar y evalua los salarios cargados unicamente
 *
 * \param
 * \param
 * \return //Retorna -1 si los parametros pasados son incorrecto o 0 si se pudo ejecturar con exito
 *
 */

int totalSalarysalary(Employee* list, int len);


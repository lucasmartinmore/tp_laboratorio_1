#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int flagCargaTexto=0;
    int flagCargaBinario=0;
    int flagCarga=0;

    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
        switch(MenuPrincipal())
        {
            case 1:
            	if(flagCarga==0 && flagCargaTexto==0)
            	{
                    controller_loadFromText("data.csv",listaPasajeros);
                    flagCargaTexto=1;
                    flagCarga=1;
            	}
            	else
            	{
            		printf("  --------- No se puede cargar mas de una vez ! ---------  \n");
            	}
                break;
            case 2:
            	if(flagCarga==0 && flagCargaBinario==0)
            	{
                	controller_loadFromBinary("data.csv", listaPasajeros);
                	flagCargaBinario=1;
                	flagCarga=1;
            	}
            	else
            	{
            		printf("  --------- No se puede cargar mas de una vez ! ---------  \n");
            	}
            	break;
            case 3:
            	if(flagCargaTexto==1 || flagCargaBinario==1)
            	{
                	controller_addPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("  --------- Se debe cargar el archivo antes de agregar pasajero ! ---------  \n");
            	}
            	break;
            case 4:
            	if(flagCargaBinario==1 || flagCargaTexto==1)
            	{
            		if(ll_len(listaPasajeros)==0)
            		{
            			printf("  --------- No se encuentran pasajeros en el sistema ! ---------  \n");
            		}
            		else
            		{
                    	controller_editPassenger(listaPasajeros);
            		}
            	}
            	else
            	{
            		printf("  --------- Se debe cargar el archivo antes de modificar pasajero ! ---------  \n");
            	}
                break;
            case 5:
            	if(flagCargaTexto==1 || flagCargaBinario==1)
            	{
            		if(ll_len(listaPasajeros)==0)
            		{
            			printf("  --------- No se encuentran pasajeros en el sistema ! ---------  \n");
            		}
            		else
            		{
                    	controller_removePassenger(listaPasajeros);
            		}
            	}
            	else
            	{
            		printf("  --------- Se debe cargar el archivo antes de dar de baja ! ---------  \n");
            	}
                break;
            case 6:
            	if(flagCargaTexto==1 || flagCargaBinario==1)
            	{
            		if(ll_len(listaPasajeros)==0)
            		{
            			printf("  --------- No se encuentran pasajeros en el sistema ! ---------  \n");
            		}
            		else
            		{
            			controller_ListPassenger(listaPasajeros);
            		}
            	}
            	else
            	{
            		printf("  --------- Se debe cargar el archivo antes de mostrar pasajeros ! ---------  \n");
            	}
                break;
            case 7:
            	if(flagCargaTexto==1 || flagCargaBinario==1)
            	{
            		if(ll_len(listaPasajeros)==0)
            		{
            			printf("  --------- No se encuentran pasajeros en el sistema ! ---------  \n");
            		}
            		else
            		{
                    	controller_sortPassenger(listaPasajeros);
            		}
            	}
            	else
            	{
            		printf("  --------- Se debe cargar el archivo antes de ordenar pasajeros ! ---------  \n");
            	}
             	break;
            case 8:
            	if(flagCargaTexto==1 || flagCargaBinario==1)
            	{
                	controller_saveAsText("data.csv", listaPasajeros);
            	}
            	else
            	{
            		printf("  --------- Se debe cargar el archivo antes guardarlo modo texto! ---------  \n");
            	}
                break;
            case 9:
            	if(flagCargaTexto==1 || flagCargaBinario==1)
            	{
                	controller_saveAsBinary("data.bin", listaPasajeros);
            	}
            	else
            	{
            		printf("  --------- Se debe cargar el archivo antes guardarlo modo binario! ---------  \n");
            	}
                break;
            case 10:
            	printf(" ___________________________________________________________________________________\n");
            	printf("|                            >>> SALIENDO DEL MENU <<<                              |\n");
            	printf("|___________________________________________________________________________________|\n\n");
            	ll_deleteLinkedList(listaPasajeros);
            	break;
        }
    }while(option != 10);
    return 0;
}

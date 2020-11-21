#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operadores.h"

void menu(int primer, int segundo, int a,int b)
{
    printf("*****MENU*****\n\n");
    if(primer==1)
    {
        printf("1. Ingresar 1er operando (A=X)\n");
    }
    else
    {
        printf("1. Ingresar 1er operando (A=%d)\n",a);
    }
    if(segundo==1)
    {
        printf("2. Ingresar 2do operando (B=Y)\n");
    }
    else
    {
        printf("2. Ingresar 2do operando (B=%d)\n",b);
    }
    printf("3. Calcular todas las operaciones\n");
    printf("a) Calcular la suma (A + B)\n");
    printf("b) Calcular la resta (A - B)\n");
    printf("c) Calcular la division (A / B)\n");
    printf("d) Calcular la multiplicacion (A * B)\n");
    printf("e) Calcular el factorial (A!) y El factorial (B!)\n");
    printf("4. Informar resultados\n");
    printf("a: El resultado de A + B es:r\n");
    printf("b: El resultado de A - B es:r\n");
    printf("c: El resultado de A / B es:r o (No es posible dividir por cero)\n");
    printf("d: El resultado de A * B es:r\n");
    printf("e: El factorial de A es:r1 y El factorial de B es:r2\n");
    printf("5. Salir\n\n");
}

int operandos()
{
    int a;
    printf("Ingrese operando: ");
    scanf("%d",&a);
    return a;
}
int suma(int a, int b)
{
    int suma=(a+b);
    return suma;
}
int resta(int a, int b)
{
    int resta=(a-b);
    return resta;
}
float division(int a, int b)
{
    float division;
    if(b==0)
    {
        division=printf("No es posible dividir por 0\n");
    }
    else
    {
        division=(float)a/b;
    }
    return division;
}
int multiplicacion(int a, int b)
{
    int multiplicacion=(a*b);
    return multiplicacion;
}
int factorial(int x)
{
    long long int factorial=1;
    if(x<0)
    {
        factorial=printf("No se puede sacar el factorial de un entero negativo\n");
    }
    else
    {
        for (int i=1; i<=x; i++)
        {
            factorial=factorial*i;
        }
    }
    return factorial;
}

void informeFinal(int a, int b, int resultadoSuma, int resultadoResta, int resultadoMultiplicacion, float resultadoDivision, int resultadoFactorialA, int resultadoFactorialB)
{
    printf("El resultado de %d + %d es %d\n",a,b,resultadoSuma);
    printf("El resultado de %d - %d es %d\n",a,b,resultadoResta);
    printf("El resultado de %d / %d es %.2f\n",a,b,resultadoDivision);
    printf("El resultado de %d * %d es %d\n",a,b,resultadoMultiplicacion);
    printf("El resultado de factorial de %d es %d\n",a,resultadoFactorialA);
    printf("El resultado de factorial de %d es %d\n",b,resultadoFactorialB);
}


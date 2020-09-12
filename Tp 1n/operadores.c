#include "operadores.h"

void menu(int primer, int segundo, int a,int b)
{
    printf("*****MENU*****\n\n");
    if(primer==1 && segundo==1)
    {
        printf("1. Ingresar 1er operando (A=X)\n");
    }
    else
    {
        printf("1. Ingresar 1er operando (A=%d)\n",a);
    }
    if(segundo==1)
    {
        printf("1. Ingresar 1er operando (B=Y)\n");
    }
    else
    {
        printf("1. Ingresar 1er operando (B=%d)\n",b);
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

int operandoA()
{
    int a;
    printf("Ingrese 1er operando A=");
    scanf("%d",&a);
    return a;
}

int operandoB()
{
    int b;
    printf("Ingrese 2do operando B=");
    scanf("%d",&b);
    return b;
}

void calcular(int a, int b)
{
    printf("Se esta realizando las operaciones posibles entre %d y %d ...\n",a,b);
}

void calculos(int a, int b)
{
    int suma;
    int resta;
    float division;
    int multiplicacion;
    long long int factorialA=1;
    long long int factorialB=1;
    suma=(a+b);
    resta=(a-b);
    multiplicacion=(a*b);

    printf("El resultado de %d + %d es: %d \n",a,b,suma);
    printf("El resultado de %d - %d es: %d \n",a,b,resta);
    if(b==0)
    {
        division=printf("No es posible dividir por 0\n");
    }
    else
    {

        division=(float)a/b;
        printf("El resultado de %d / %d es: %.2f \n",a,b,division);
    }

    printf("El resultado de %d * %d es: %d \n",a,b,multiplicacion);
    if(a<0)
    {
        factorialA=printf("No se puede sacar el factorial de un entero negativo\n");
    }
    else
    {
        for (int i=1; i<=a; i++)
        {
            factorialA=factorialA*i;
        }
        printf("El factorial de %d es: %lld \n",a,factorialA);
    }
    if(b<0)
    {
        factorialA=printf("No se puede sacar el factorial de un entero negativo\n");
    }
    else
    {
        for (int i=1; i<=b; i++)
        {
            factorialB=factorialB*i;
        }
        printf("El factorial de %d es: %lld \n",b,factorialB);
    }
}

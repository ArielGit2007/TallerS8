#include <stdio.h>
#include "funciones.h"
#include <string.h>

void LimitacionesIniciales(int *tiempo, int *Pantallas, int *Procesadores, int *Memorias, int *Targetas) // Toma la cantidad de recursos FIJOS que se disponen inicialmente y de tiempo
{
    int Validar = 0;

    printf("Ingresar las limitaciones de tiempo y recursos\n");
    printf("Tiempo(Minutos): ");
    Validar = scanf("%d", tiempo);
    validardatos(Validar, tiempo, 'i');

    printf("Cantidad de Pantallas en stock: ");
    Validar = scanf("%d", Pantallas);
    validardatos(Validar, Pantallas, 'i');

    printf("Cantidad de Procesadores en stock: ");
    Validar = scanf("%d", Procesadores);
    validardatos(Validar, Procesadores, 'i');

    printf("Cantidad de Memorias en stock: ");
    Validar = scanf("%d", Memorias);
    validardatos(Validar, Memorias, 'i');

    printf("Cantidad de Targetas Gráficas en stock: ");
    Validar = scanf("%d", Targetas);
    validardatos(Validar, Targetas, 'i');
}

void validardatos(int x, void *y, char tipo)
{
    int c;
    while (x != 1)
    {
        printf("Ingrese un valor valido\n");
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }
        if (tipo == 'i')
        {
            x = scanf("%d", y);
        }
        else if (tipo == 'f')
        {
            x = scanf("%f", y);
        }
    }
}

void RegistroProductos(char Nombre[][50], int *Pantalla, int *Procesadores, int *Memorias, int *Targetas, int *Tiempo, int *cont)
{
    int validar=0;
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
    do
    {
    printf("Ingrese el nombre del producto: \n");
    fgets(Nombre[*cont], 50, stdin);
    BorrarSaltolinea(Nombre[*cont]);
    } while (Nombre[*cont][0]=='\0');
    printf("Ingrese la cantidad de pantallas que se necesitan\n");
    validar=scanf("%d",&Pantalla[*cont]);
    validardatos(validar, &Pantalla[*cont], 'i');

    printf("Ingrese la cantidad de procesadores que se necesitan\n");
    validar=("%d",&Procesadores[*cont]);
    validardatos(validar)
    printf("Ingrese la cantidad de memorias que se necesitan\n");

    printf("Ingrese la cantidad de targetas graficas que se necesitan\n");
}
void BorrarSaltolinea(char *a)
{
    int len = strlen(a);
    if (len > 0 && a[len - 1] == '\n')
    {                      // se asegura de que la cadena no este vacia y de que el ultimo caracter si sea un salto de linea
        a[len - 1] = '\0'; // De haber un salto de linea, lo cambia por el valor nulo
    }
}
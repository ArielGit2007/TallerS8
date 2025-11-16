#include <stdio.h>
#include "funciones.h"

void main(){

int Demanda[5], opc1=0, opc2=0, Pantallas=0, Procesadores=0, Memorias=0, TargetaGráfica=0;
int tiempoLimite=0,cont=0, Validar=0, TiempoProduccion=0;
char Producto[5][50], PantallasProducto[5], ProduProcesadores[5], ProduMemorias[5],
ProduTargetas[5];

LimitacionesIniciales(&tiempoLimite, &Pantallas, &Procesadores, &Memorias, &TargetaGráfica);

do
{
printf("<<OPTMIZACION DE PRODUCCION DE COMPONENTES ELECTRONICOS>>\n");
printf("Puede elegir las siguientes opciones\n");
printf("1. Ingresar los datos del producto\n");
printf("2. Editar los datos ingresados\n");
printf("3. Eliminar un producto \n");
printf("4. Ingresar la demanda de productos\n");
Validar=scanf("%d",&opc1);
validardatos(Validar,&opc1,'i');

switch (opc1)
{
case 1:
    
    break;

case 2:

    break;
case 3:

    break;
case 4:

    break;
case 5:

    break;
default:
    break;
}

printf("Desea continuar");
scanf("%d",&opc2);

} while (opc2==1);
}
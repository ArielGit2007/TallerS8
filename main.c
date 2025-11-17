#include <stdio.h>
#include "funciones.h"

void main(){

int Demanda[5], opc1=0, opc2=0, Pantallas=0, Procesadores=0, Memorias=0, TargetaGráfica=0;
int tiempoLimite=0,cont=0, Validar=0, TiempoProduccion[5]={0};
char Producto[5][50];
int PantallasProducto[5], ProduProcesadores[5], ProduMemorias[5],
ProduTargetas[5];

LimitacionesIniciales(&tiempoLimite, &Pantallas, &Procesadores, &Memorias, &TargetaGráfica);

do
{
printf("<<OPTMIZACION DE PRODUCCION DE COMPONENTES ELECTRONICOS>>\n");
printf("Puede elegir las siguientes opciones\n");
printf("1. Ingresar los datos del producto\n");
printf("2. Editar los datos ingresados\n");
printf("3. Editar limitaciones de produccion\n");
printf("4. Eliminar un producto\n");
printf("5. Ingresar la demanda de productos\n");
Validar=scanf("%d",&opc1);
validardatos(Validar,&opc1,'i');

switch (opc1)
{
case 1:
    RegistroProductos(Producto,PantallasProducto, ProduProcesadores, ProduMemorias, ProduTargetas, TiempoProduccion, &cont);    
    break;
case 2:
    editarproducto(Producto, PantallasProducto, ProduProcesadores, ProduMemorias, ProduTargetas, TiempoProduccion, &cont);
    break;
case 3:
    Editarlimitaciones(&tiempoLimite, &Pantallas, &Procesadores, &Memorias, &TargetaGráfica);
    break;
case 4:
    Eliminarproductos(Producto, PantallasProducto, ProduProcesadores, ProduMemorias, ProduTargetas, TiempoProduccion, &cont);
    break;
case 5:
    Pedidoproductos(Producto, &Pantallas, &Procesadores, &Memorias, &TargetaGráfica, PantallasProducto, ProduProcesadores, ProduMemorias, ProduTargetas, TiempoProduccion, &tiempoLimite, &cont);
    break;
default:
    break;
}

printf("Desea continuar 1.Si 2.No: ");
Validar=scanf("%d",&opc2);
validardatos(Validar, &opc2,'i');

} while (opc2==1);
}
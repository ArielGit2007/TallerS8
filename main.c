#include <stdio.h>

void main(){

int Demanda[5], opc1=0, opc2=0;
char Prodcuto[5][50];

do
{
printf("<<OPTMIZACION DE PRODUCCION DE COMPONENTES ELECTRONICOS>>\n");
printf("Puede elegir las siguientes opciones\n");
printf("1.Ingresar las limitaciones de tiempo y recursos\n");
printf("2.Ingresar los datos del producto\n");
printf("3.Editar los datos ingresados\n");
printf("4. Eliminación de los productos ingresados \n");
printf("5.Tiempo y cantidad de recursos para cumplir con la demanda\n");

scanf("%d",&opc1);

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
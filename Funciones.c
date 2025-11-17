#include <stdio.h>
#include "funciones.h"
#include <string.h>

void LimitacionesIniciales(int *tiempo, int *Pantallas, int *Procesadores, int *Memorias, int *Targetas) // Toma la cantidad de recursos FIJOS que se disponen inicialmente y de tiempo
{
    int c, Validar = 0;

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

    printf("Cantidad de Targetas Graficas en stock: ");
    Validar = scanf("%d", Targetas);
    validardatos(Validar, Targetas, 'i');
}

void validardatos(int x, void *y, char tipo)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    while (x != 1)
    {
        printf("Ingrese un valor valido\n");
        {
        }
        if (tipo == 'i')
        {
            x = scanf("%d", y);
            while ((c = getchar()) != '\n' && c != EOF);
        }
        else if (tipo == 'f')
        {
            x = scanf("%f", y);
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}

void RegistroProductos(char Nombre[][50], int *Pantalla, int *Procesadores, int *Memorias, int *Targetas, int *Tiempo, int *cont)
{
    int validar=0;

    do
    {
    printf("Ingrese el nombre del producto:\n");
    fgets(Nombre[*cont], 50, stdin);
    BorrarSaltolinea(Nombre[*cont]);
    } while (Nombre[*cont][0]=='\0');

    printf("Ingrese la cantidad de pantallas que se necesitan\n");
    validar=scanf("%d",&Pantalla[*cont]);
    validardatos(validar, &Pantalla[*cont], 'i');

    printf("Ingrese la cantidad de procesadores que se necesitan\n");
    validar=scanf("%d",&Procesadores[*cont]);
    validardatos(validar, &Procesadores[*cont], 'i');

    printf("Ingrese la cantidad de memorias que se necesitan\n");
    validar=scanf("%d",&Memorias[*cont]);
    validardatos(validar,&Memorias[*cont], 'i');

    printf("Ingrese la cantidad de targetas graficas que se necesitan\n");
    validar=scanf("%d", &Targetas[*cont]);
    validardatos(validar, &Targetas[*cont], 'i');

    printf("Ingrese el tiempo de produccion:\n");
    validar=scanf("%d",&Tiempo[*cont]);
    validardatos(validar,&Tiempo[*cont], 'i');

    (*cont)++;
}
void editarproducto(char Nombre [][50], int *Pantalla, int *Procesadores, int *Memorias, int *Targetas, int *Tiempo, int *cont){

    if (*cont == 0)
    {
        printf("No hay productos registrados para editar.\n");
        return;
    }

    int opc=0,opc1=1, validar=0, posicion;


   posicion=Buscarnombre(Nombre, Pantalla, Procesadores, Memorias, Targetas, Tiempo, cont);
    
    if(posicion!=-1){
    do
    {
    printf("Seleccione el campo a editar:\n");
    printf("1. Nombre\n");
    printf("2. Cantidad de pantallas\n");
    printf("3. Cantidad de procesadores\n");
    printf("4. Cantidad de memorias\n");
    printf("5. Cantidad de tarjetas graficas\n");
    printf("6. Tiempo de produccion\n");
    validar = scanf("%d", &opc);
    validardatos(validar, &opc, 'i');


    switch (opc)
    {
    case 1:
        printf("Ingrese el nuevo nombre: ");
        fgets(Nombre[posicion], 50, stdin);
        BorrarSaltolinea(Nombre[posicion]);
        break;

    case 2:
        printf("Nueva cantidad de pantallas: ");
        validar = scanf("%d", &Pantalla[posicion]);
        validardatos(validar, &Pantalla[posicion], 'i');
        break;

    case 3:
        printf("Nueva cantidad de procesadores: ");
        validar = scanf("%d", &Procesadores[posicion]);
        validardatos(validar, &Procesadores[posicion], 'i');
        break;
    
    case 4:
        printf("Nueva cantidad de memorias: ");
        validar = scanf("%d", &Memorias[posicion]);
        validardatos(validar, &Memorias[posicion], 'i');
        break;

    case 5:
        printf("Nueva cantidad de tarjetas graficas: ");
        validar = scanf("%d", &Targetas[posicion]);
        validardatos(validar, &Targetas[posicion], 'i');
        break;

    case 6:
        printf("Nueva tiempo de produccion: ");
        validar = scanf("%d", &Tiempo[posicion]);
        validardatos(validar, &Tiempo[posicion], 'i');
        break;

    default:
        printf("Opción invalida.\n");
        break;
    }
    printf("Producto editado correctamente.\n");

    printf("Desea seguir editando. 1.Si 2.No");
    validar=scanf("%d",&opc1);
    validardatos(validar,&opc1,'i');

    } while (opc1==1);
    
    }
}

int Buscarnombre(char Nombre [][50], int *Pantalla, int *Procesadores, int *Memorias, int *Targetas, int *Tiempo, int *cont){
    char BuscarProducto[1][50]={0};
    int Encontrado=-1; //En esta variable se guardará el indice del producto
    char c[1][100];

    printf("Ingrese el nombre del producto que desea encontrar (tenga cuidado con los espacios)\n");
    fgets(BuscarProducto[0],50, stdin);
    BorrarSaltolinea (BuscarProducto[0]);//Borrar el salto de linea
    
    for (int i = 0; i < *cont; i++) //Con el for se compara todas las cadenas de nombre con la que tu ingresaste
    {
        if(_stricmp(Nombre[i], BuscarProducto[0])==0){ //la función _stricmp compara dos cadenas, retorna el valor de 0 si son iguales (no distingue mayusculas)
            Encontrado=i; //Si encuentra el producto deja de comparar y sale de for, encontrado sera igual al indice de la cadena encontrada
            break;
        }
    }
    if (Encontrado!=-1)// si se encotro la cadena, el indice sera de 0 en adelante
    {
        printf("Producto encontrado:\n");
        printf("N\tNombre\t\tPantallas\tProcesadores\tMemorias\tTargetas\tTiempo\n");
        printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",Encontrado, Nombre[Encontrado],Pantalla[Encontrado], Procesadores[Encontrado],Memorias[Encontrado],Targetas[Encontrado], Tiempo[Encontrado] );
        return Encontrado;
    }
    else{ // si no se ha encontrado la cadena buscada te pide intetarlo nuevamente
        printf("Producto no encontrado, intente de nuevo\n");
        return -1;
    }
    
}

void Editarlimitaciones(int *Tiempo, int *Pantalla, int *Procesadores, int *Memorias, int *Targetas){
    int opc, opc2=1, validar;

   do
   {
     printf("Elija que quiere editar\n");
    printf("1. Tiempo limite para la produccion: %d\n", *Tiempo);
    printf("2. Cantidad de pantallas disponibles: %d\n", *Pantalla);
    printf("3. Cantidad de procesadores disponibles: %d\n", *Procesadores);
    printf("4. Cantidad de memorias disponibles: %d\n", *Memorias);
    printf("5. Cantidad de targetas graficas disponibles: %d\n", *Targetas);
    validar=scanf("%d",&opc);
    validardatos(validar,&opc,'i');

    switch (opc)
    {
    case 1:
        printf("Ingrese el nuevo tiempo limite para la produccion: ");
        validar=scanf("%d",Tiempo);
        validardatos(validar,Tiempo,'i');
        break;
    case 2:
        printf("Ingrese la nueva cantidad de pantalas: ");
        validar=scanf("%d",Pantalla);
        validardatos(validar,Pantalla,'i');
        break;
    case 3:
        printf("Ingrese la nueva cantidad de procesadores: ");
        validar=scanf("%d",Procesadores);
        validardatos(validar,Procesadores,'i');
        break;
    case 4: 
        printf("Ingrese la nueva cantidad de memorias: ");
        validar=scanf("%d",Memorias);
        validardatos(validar,Memorias,'i');
        break;
    case 5: 
        printf("Ingrese la nueva cantidad de targetas graficas: ");
        validar=scanf("%d",Targetas);
        validardatos(validar,Targetas,'i');
        break;
    default:
        break;
    }

    printf("Seguir editando 1.Si 2.No: ");
    validar=scanf("%d",&opc2);

   } while (opc2==1);
}

void Eliminarproductos(char Nombre [][50], int *Pantalla, int *Procesadores, int *Memorias, int *Targetas, int *Tiempo, int *cont){
  
    if (*cont == 0)
    {
        printf("No hay productos registrados para eliminar.\n");
        return;
    }

    int posicion;

    posicion=Buscarnombre(Nombre, Pantalla, Procesadores, Memorias, Targetas, Tiempo, cont);

    
    if (posicion!=-1)
    {
        for (int i = posicion; i < *cont-1; i++)
    {
        strcpy(Nombre[i], Nombre[i+1]); //strcpy o copiar cadena copia el contenido de una cadena de caracteres a otra
        Pantalla[i]= Pantalla[i+1];
        Procesadores[i]= Procesadores[i+1];
        Memorias[i]= Memorias[i+1];
        Targetas[i]= Targetas[i+1];
        Tiempo[i]= Tiempo[i+1]; //los datos del siguiente se copian al lugar del producto eliminado
    }

    (*cont)--; //disminuye el contador de productos

    printf("producto eliminado correctamente \n");
    }

}

void BorrarSaltolinea(char *a)
{
    int len = strlen(a);
    if (len > 0 && a[len - 1] == '\n'){ // se asegura de que la cadena no este vacia y de que el ultimo caracter si sea un salto de linea
        a[len - 1] = '\0'; // De haber un salto de linea, lo cambia por el valor nulo
    }
}


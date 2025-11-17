void LimitacionesIniciales(int *tiempo, int *Pantallas, int *Procesadores, int *Memorias, int *Targetas);
void validardatos(int x, void *y, char tipo);
void RegistroProductos(char Nombre[][50], int *Pantalla, int *Procesadores, int *Memorias, int *Targetas, int *Tiempo, int *cont);
void BorrarSaltolinea(char *a);
void editarproducto(char Nombre [][50], int *Pantalla, int *Procesadores, int *Memorias, int *Targetas, int *Tiempo, int *cont);
int Buscarnombre(char Nombre [][50], int *Pantalla, int *Procesadores, int *Memorias, int *Targetas, int *Tiempo, int *cont);
void Editarlimitaciones(int *Tiempo, int *Pantalla, int *Procesadores, int *Memorias, int *Targetas);
void Eliminarproductos(char Nombre [][50], int *Pantalla, int *Procesadores, int *Memorias, int *Targetas, int *Tiempo, int *cont);
void Pedidoproductos(char Nombre[][50], int *Pantallas, int *Procesadores, int *Memorias, int *Targetas,int PantallasProducto[], int ProduProcesadores[], int ProduMemorias[], int ProduTargetas[], int TiempoProduccion[], int *tiempoLimite ,int *cont);

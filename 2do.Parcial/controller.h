

int controller_CargarTexto( LinkedList* pArrayListbici);
int controller_GuardarText(char* path, LinkedList* pArrayListbici);
int ComparaTipoYTiempo(void* a, void* b);
void MostrarPosiciones(LinkedList* lista);

int mostrarBicis( LinkedList* lista);
void mostrarBici( LinkedList* lista,int indice);

int ordenarXtipo(void* a, void* b);
int filterTipoBMX(void* a);
int filterTipoMTB(void* a);
int filterTipoPlAYERA(void* a);
int filterTipoPASEO(void* a);

int menuFiltrado();
void filtrarPorTipos(LinkedList* a);

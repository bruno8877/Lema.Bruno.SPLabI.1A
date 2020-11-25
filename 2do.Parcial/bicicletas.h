
#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char tipo[51];
    int tiempo;
}eBicicleta;

#endif // PAISES_H_INCLUDED


int bici_getId(eBicicleta* this,int* id);
int bici_setId(eBicicleta* this,int id);

int bici_getNombre(eBicicleta* this,char* nombre);
int bici_setNombre(eBicicleta* this,char* nombre);

int bici_setTipo(eBicicleta* this,char* tipo);
int bici_getTipo(eBicicleta* this,char* tipo);

int bici_setTiempos(eBicicleta* this,int tiempo);
int bici_getTiempos(eBicicleta* this,int* tiempo);

eBicicleta* nueva_bici();
eBicicleta* bicisParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr);

int get_AleatorioTiempo();
void* setTiempo(void* tiempo);

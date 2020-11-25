  #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "parser.h"
//#include "controller.h"

/** \brief carga los tiempo
 *
 * \param this eBicicleta*
 * \param tiempo int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int bici_setTiempos(eBicicleta* this,int tiempo)
{
    int todoOk = 1;

    if(this != NULL && tiempo >= 0)
    {
        this->tiempo = tiempo;
        todoOk = 0;
    }
    return todoOk;
}

/** \brief asigna la cantidad de tiempo
 *
 * \param this eBicicleta*
 * \param tiempo int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int bici_getTiempos(eBicicleta* this, int* tiempo)
{
    int todoOk = 1;

    if(this != NULL && tiempo != NULL)
    {
        *tiempo = this->tiempo;
        todoOk = 0;
    }
    return todoOk;
}
//--------------------------------------------------------------------------------------------------

/** \brief carga el tipo
 *
 * \param this eBicicleta*
 * \param tipo char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int bici_setTipo(eBicicleta* this,char* tipo)
{
    int todoOk = 1;

    if(this != NULL && tipo != NULL && strlen(tipo) <= 50)
    {
        strcpy(this->tipo,tipo);
        todoOk = 0;
    }
    return todoOk;
}

/** \brief asigna el tipo a una bici
 *
 * \param this eBicicleta*
 * \param tipo char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int bici_getTipo(eBicicleta* this,char* tipo)
{
    int todoOk = 1;

    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo,this->tipo);
        todoOk = 0;
    }
    return todoOk;
}
//--------------------------------------------------------------------------------------------------

/** \brief carga el nombre
 *
 * \param this eBicicleta*
 * \param nombre char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int bici_setNombre(eBicicleta* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL && strlen(nombre) <= 50)
    {
        strcpy(this->nombre,nombre);
        todoOk = 0;
    }
    return todoOk;
}

/** \brief asigna el nombre a una bici
 *
 * \param this eBicicleta*
 * \param nombre char*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int bici_getNombre(eBicicleta* this,char* nombre)
{
    int todoOk = 1;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 0;
    }
    return todoOk;
}
//--------------------------------------------------------------------------------------------------

/** \brief carga el id
 *
 * \param this eBicicleta*
 * \param id int
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int bici_setId(eBicicleta* this,int id)
{
    int todoOk = 1;
    if(this != NULL && id>0)
    {
        this->id = id;
        todoOk=0;
    }
    return todoOk;
}

/** \brief asigna el id a una bici
 *
 * \param this eBicicleta*
 * \param id int*
 * \return int exito [1] si hubo error, [0] si no hubo error
 *
 */
int bici_getId(eBicicleta* this,int* id)
{
    int todoOk = 1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 0;
    }
    return todoOk;
}
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
/** \brief Guarda espacio en memoria para el nuevo bicis
 *
 * \return eBicicleta*
 *
 */

eBicicleta* nueva_bici()
{
    eBicicleta* bicis = (eBicicleta*) malloc(sizeof(eBicicleta));

    if(bicis != NULL)
    {
        bici_setId(bicis, 0);
        bici_setNombre(bicis, " ");
        bici_setTipo(bicis, " ");
        bici_setTiempos(bicis, 0);

    }

    return bicis;
}

eBicicleta* bicisParametros(char* idStr, char* nombreStr, char* tipoStr, char* tiempoStr)
{
    eBicicleta* bicis = nueva_bici();

    if(bicis != NULL && idStr != NULL && nombreStr != NULL && tipoStr != NULL && tiempoStr != NULL)
    {
        bici_setId(bicis, atoi(idStr));
        bici_setNombre(bicis, nombreStr);
        bici_setTipo(bicis, tipoStr);
        bici_setTiempos(bicis, atoi(tiempoStr));

    }
    else
    {
        free(bicis);
        bicis = NULL;
    }

    return bicis;
}
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
/** \brief Asigna cantidad aleatoria a tiempo
 *
 * \return int
 *
 */
int get_AleatorioTiempo()
{
    int tiempo;

    tiempo = rand() % (50 + 1 - 120) + 50;

    return tiempo;
}

/** \brief Carga cantidad aleatoria a tiempo
 *
 * \param
 * \param
 * \return
 *
 */
void* setTiempo(void* tiempo)
{
    eBicicleta* tiemp = NULL;

    if(tiempo != NULL)
    {
        tiemp = (eBicicleta*)tiempo;
        bici_setTiempos(tiemp, get_AleatorioTiempo());
    }

    return tiemp;
}

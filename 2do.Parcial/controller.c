#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "parser.h"
#include "controller.h"


/** \brief Carga los datos de las bicis desde el archivo (modo texto).
 *
 * \param path char*
 * \param pArrayListbici LinkedList*
 * \return int
 *
 */
int controller_CargarTexto( LinkedList* pArrayListbici)
{
    FILE* pFile;
    int exito = 1;
    char path[128];

    printf("Ingrese el nombre del archivo a cargar: ");
    fflush(stdin);
    scanf("%s",path);

    strcat(path,".csv");
    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        if(parser_BicisAtexto(pFile, pArrayListbici) )
        {
            exito = 0;
            printf("\nLos datos de las bicis en modo texto fueron cargados corretamente\n\n");
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
    }
    else
    {
        printf("Error\n");
    }

    fclose(pFile);

    return exito;
}


/** \brief Guarda los datos de las bicicletas en un archivo (modo texto).
 *
 * \param path char*
 * \param pArrayListbici LinkedList*
 * \return int
 *
 */
int controller_GuardarText(char* path, LinkedList* pArrayListbici)
{
    FILE* pFile;
    int tamList;
    int todoOK=1;
    int AuxId;
    char auxNombre[51];
    char auxTipo[51];
    int auxTiempo;

    eBicicleta* auxbici;

    tamList = ll_len(pArrayListbici);

    if(pArrayListbici != NULL && path !=NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {
            todoOK =0;
            fprintf(pFile, "id,nombre,tipo,tiempo\n");


            for(int i=0; i<tamList; i++)
            {
                auxbici = (eBicicleta*)ll_get(pArrayListbici, i);

                bici_getId(auxbici, &AuxId);
                bici_getNombre(auxbici, auxNombre);
                bici_getTipo(auxbici, auxTipo);
                bici_getTiempos(auxbici,&auxTiempo);

                fprintf(pFile, "%d,%s,%s,%d\n", AuxId, auxNombre, auxTipo,auxTiempo);


            }
            fclose(pFile);
            printf("\nArchivo guardado...\n");
        }


    }

    return todoOK;
}
//--------------------------------------------------------------------------------------------------
int ComparaTipoYTiempo(void* a, void* b)
{
    int todoOk;

    eBicicleta* bici1;
    eBicicleta* bici2;

    if (a != NULL && b != NULL)
    {
        bici1 = (eBicicleta*) a;
        bici2 = (eBicicleta*) b;

        if (strcmp(bici1->tipo, bici2->tipo) == 0 && bici1->tiempo > bici2->tiempo)
        {
            todoOk = 1;
        }
        else if (strcmp(bici1->tipo, bici2->tipo) == 0 && bici1->tiempo < bici2->tiempo)
        {
            todoOk = -1;
        }
        else
        {
            todoOk =0;
        }

    }
    return todoOk;
}
void MostrarPosiciones(LinkedList* lista)
{
    printf("******** LISTA ORDENADA POR POR TIPO Y TIEMPO ********\n\n");

    if (!ll_sort(lista, ordenarXtipo, 1) && !ll_sort(lista, ComparaTipoYTiempo, 1))
    {
        mostrarBicis(lista);
    }
}

//--------------------------------------------------------------------------------------------------
/** \brief Listar los bicis
 *
 * \param lista LinkedList*
 * \return int
 *
 */
int mostrarBicis( LinkedList* lista)
{
    int todoOk = 1;
    int tam;

    if(lista != NULL)
    {
        todoOk = 0;
        printf("  ID     NOMBRE                    TIPO                           TIEMPO\n");
        tam = ll_len(lista);

        for (int i=0; i<tam; i++)
        {
            mostrarBici(lista, i);
        }
    }
    else
    {
        printf("No hay articulos que listar\n");
    }
    return todoOk;
}

/** \brief Muestra una bici
 *
 * \param lista LinkedList*
 * \param indice int
 * \return void
 *
 */
void mostrarBici( LinkedList* lista,int indice)
{
    eBicicleta* bici;

    bici = ll_get(lista, indice);

    printf("%4d     %-20s      %-20s           %-10d\n", bici->id, bici->nombre,bici->tipo, bici->tiempo);

}
//--------------------------------------------------------------------------------------------------

/** \brief filtrar por tipo
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int ordenarXtipo(void* a, void* b)
{
    int todoOk;
    eBicicleta* auxBici1;

    eBicicleta* auxBici2;

    if (a != NULL && b != NULL)
    {
        auxBici1 = (eBicicleta*) a;
        auxBici2 = (eBicicleta*) b;

        todoOk = strcmp(auxBici1->tipo, auxBici2->tipo);
    }
    return todoOk;
}
//--------------------------------------------------------------------------------------------------

int filterTipoBMX(void* a)
{
    int todoOk=0;
    if(a!=NULL)
    {
        eBicicleta* pBicicleta=(eBicicleta*)a;
        if(strcmp(pBicicleta->tipo,"BMX") == 0)
        {
            todoOk=1;
        }
    }
    return todoOk;
}

int filterTipoMTB(void* a)
{
    int todoOk=0;
    if(a!=NULL)
    {
        eBicicleta* pBicicleta=(eBicicleta*)a;
        if(strcmp(pBicicleta->tipo,"MTB") == 0)
        {
            todoOk=1;
        }
    }
    return todoOk;
}
int filterTipoPlAYERA(void* a)
{
    int todoOk=0;
    if(a!=NULL)
    {
        eBicicleta* pBicicleta=(eBicicleta*)a;
        if(strcmp(pBicicleta->tipo,"PLAYERA") == 0)
        {
            todoOk=1;
        }
    }
    return todoOk;
}
int filterTipoPASEO(void* a)
{
    int todoOk=0;
    if(a!=NULL)
    {
        eBicicleta* pBicicleta=(eBicicleta*)a;
        if(strcmp(pBicicleta->tipo,"PASEO") == 0)
        {
            todoOk=1;
        }
    }
    return todoOk;
}
int menuFiltrado()
{
    int opcion;

    system("cls");
    printf("\n***** FILTRADO TIPOS *****\n");
    printf("1. BMX\n");
    printf("2. MTB\n");
    printf("3. PLAYERA\n");
    printf("4. PASEO\n");
    printf("5- Salir\n\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void filtrarPorTipos(LinkedList* a)
{
    LinkedList* listaFILTRADA=NULL;
    char seguir = 's';
    char confirma;

    do
    {
        switch(menuFiltrado())
        {
        case 1:
            listaFILTRADA=ll_filter(a,filterTipoBMX);
            mostrarBicis(listaFILTRADA);
            break;
        case 2:
            listaFILTRADA=ll_filter(a,filterTipoMTB);
            mostrarBicis(listaFILTRADA);
            break;
        case 3:
            listaFILTRADA=ll_filter(a,filterTipoPlAYERA);
            mostrarBicis(listaFILTRADA);
            break;
        case 4:
            listaFILTRADA=ll_filter(a,filterTipoPASEO);
            mostrarBicis(listaFILTRADA);
            break;

        case 5:
            printf("Confirme salida (s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }

        system("pause");

    }
    while(seguir == 's');
}

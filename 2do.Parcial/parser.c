
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los bicis desde el archivo  (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListbici LinkedList*
 * \return int
 *
 */
int parser_BicisAtexto(FILE* pFile, LinkedList* pArrayListbici)
{
    int todoOK =0;
    int cont=0;
	char id[200];
	char nombre[200];
	char tipo[200];
	char tiempo[200];
    eBicicleta* auxBici;
    auxBici = nueva_bici();
    int r;

    if(pFile == NULL || pArrayListbici == NULL)
    {
        todoOK =0;
    }

    while(!feof(pFile))
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, tipo, tiempo);
        if(r == 4)
        {
            auxBici = bicisParametros(id, nombre, tipo, tiempo);
            if(auxBici !=NULL)
            {
                ll_add(pArrayListbici, auxBici);
                cont++;
                todoOK =1;
            }

        }

    }
    return todoOK;
}

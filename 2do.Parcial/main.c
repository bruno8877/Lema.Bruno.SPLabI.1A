#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "bicicletas.h"

int main()
{
    LinkedList* lista = ll_newLinkedList();

    int option = 0;
    char seguir = 's';
    char confirma;
    int flagText = 0;

    do
    {
        printf("\n***** MENU DE OPCIONES *****\n");
        printf("1- Cargar archivo (Modo texto)\n");
        printf("2- Imprimir lista\n");
        printf("3- Asignar tiempos\n");
        printf("4- Filtrar por tipo\n");
        printf("5- Mostrar posiciones\n");
        printf("6- Guardar posiciones\n");
        printf("7- Salir\n\n");
        printf("Elija una opcion\n");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            //CARGAR LOS DATOS MODO TEXTO

            if(flagText==0)
            {
                controller_CargarTexto(lista);
                flagText = 1;
            }
           else
            {
                printf("\nEl archivo modo texto ya fue cargado...\n");
            }

            break;
        case 2:
            if(flagText)
            {
                mostrarBicis(lista);
            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;
        case 3:
            if(flagText)
            {
                ll_map(lista,setTiempo);
                printf("\nSe cargo con exito los tiempos!!!!\n");
            }
            else
            {
                printf("Aun no se cargaron los datos...\n");
            }

            break;
        case 4:
            if(flagText)
            {
                printf("No terminado...");
                //filtrarPorTipos(lista);
                //mostrarBicis(lista);

            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;
        case 5:
           if (flagText)
            {
                MostrarPosiciones(lista);
            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;
        case 6:
            if(flagText)
            {
                MostrarPosiciones(lista);
                controller_GuardarText("PosicionesGuardadas.csv",lista);
            }
            else
            {

                printf("Aun no se cargaron los datos...\n");
            }
            break;


        case 7:
            //SALIR
            printf("Confirma salida (s/n): ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='n';
            }
            break;

        default:
            printf("Opcion invalida...");
            break;
        }
        system("pause");//pone pausa
        system("cls");//limpia la consola
    }
    while(seguir=='s');
    return 0;

}

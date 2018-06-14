#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "ArrayList.h"
#include "lib.h"


int main()
{
    int opcion;
    char* nombreArchivo=(char*)malloc(sizeof(char)*50);
    ArrayList* pList=al_newArrayList();
    ArrayList* bList=al_newArrayList();
    //ArrayList* dList=al_newArrayList();
    char respuesta='s';
    do
    {
        opcion=0;
        menu();
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                strcpy(nombreArchivo,"empleados.csv");
                if(cargarLista(nombreArchivo,pList)==0)
                {
                    printf("La lista de empleados se cargo con exito\n");
                }
                break;
            case 2:
                strcpy(nombreArchivo,"programadores.csv");
                if(cargarLista(nombreArchivo,bList)==0)
                {
                    printf("La black list se cargo con exito\n");
                }
                break;
            case 3:
                bList=al_filter(pList,funcionQueFiltra);
                printf("Se filtro la lista correctamente\n");
                break;
            case 4:
                mostrarListaEmpleados(pList);
                break;
            case 5:
                EscribirTexto(bList);
                mostrarListaEmpleados(bList);
                break;
            case 6:
                respuesta='n';
                break;
            default:
                break;
        }
        system("pause");
        system("cls");
    }
    while(respuesta!='n');
    return 0;
}

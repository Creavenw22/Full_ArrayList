#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "ArrayList.h"
#include "lib.h"

void menu(void)
{
    printf("1- CARGAR LISTA EMPLEADOS\n");
    printf("2- CARGAR PROGRAMADORES\n");
    printf("3- FILTRAR LISTA EMPLEADOS\n");
    printf("4- LISTAR EMPLEADOS\n");
    printf("5- LISTAR PROGRAMADORES\n");
    printf("6- SALIR\n");
}


int cargarLista(char* FileName,ArrayList* pList)
{
    int returnAux=-1;
    FILE* pFile;
    char id[3]="";
    char nombre[150]="";
    char puesto[150]="";
    char edad[3]="";
    pFile=fopen(FileName,"r");
    ePersona* Empleado;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            Empleado=(ePersona*)malloc(sizeof(ePersona));
            if (Empleado!=NULL)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,puesto,edad);

                Empleado->id=atoi(id);
                strcpy(Empleado->nombre,nombre);
                strcpy(Empleado->puesto,puesto);
                Empleado->edad=atoi(edad);

                pList->add(pList,Empleado);
            }
        }
        returnAux=0;
    }

    fclose(pFile);
    return returnAux;
}

void mostrarEmpleado(ePersona* empleado)
{
    printf("ID: %d / NOMBRE: %s / PUESTO: %s / EDAD: %d \n", empleado->id,empleado->nombre,empleado->puesto,empleado->edad);
}

void mostrarListaEmpleados(ArrayList* pList)
{
    int i;
    for(i=0;i<pList->len(pList);i++)
    {
        mostrarEmpleado(pList->pElements[i]);
    }
}

int funcionQueFiltra(void* empleado)
{
    int retorno=0;
    if(((ePersona*)empleado)->edad>30)
    {
        if(strcmp(((ePersona*)empleado)->puesto,"Programador")==0)
        {
           retorno=1;
        }
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

/*int filtrarProgramadores(ArrayList* pList, ArrayList* bList)
{
    int returnAux=0;

    if(pList!=NULL)
    {
         bList=al_filter(pList,filtro);

         returnAux=1;


    }


    return returnAux;
}

*/
void EscribirTexto(ArrayList* listaFil)
{
    ePersona* empleadoAux;
    FILE* archivo;
    int i;
    char fileName[50]="out.csv";
    if(listaFil!=NULL)
    {
        archivo=fopen(fileName,"wa");
        if(archivo!=NULL)
        {
            for(i=0;i<al_len(listaFil);i++)
            {
                    empleadoAux=(ePersona*) al_get(listaFil,i);
                    fprintf(archivo,"%d,%s,%s,%d\n",empleadoAux->id,empleadoAux->nombre,empleadoAux->puesto,empleadoAux->edad);
            }

        }

        fclose(archivo);
    }
    else
    {
        printf("No se pudo generas el archivo");
        exit(0);
    }
}

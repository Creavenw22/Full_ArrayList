#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "ArrayList.h"
#include "lib.h"

void menu(void)
{
    printf("1- CARGAR DESTINATARIOS\n");
    printf("2- CARGAR LISTA NEGRA\n");
    printf("3- DEPURAR\n");
    printf("4- LISTA\n");
    printf("5- SALIR\n");
}

int cargarLista(char* nombreArchivo,ArrayList* listaParaCargar)
{
    FILE *fp;
    int returnAux=-1;
    char nombre[50]="";
    char mail[150]="";
    fp = fopen(nombreArchivo,"r");
    eDestinatario* unDestinatario;
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            unDestinatario=(eDestinatario*)malloc(sizeof(eDestinatario));
            if(unDestinatario!=NULL)
            {
                fscanf(fp,"%[^,],%[^\n]\n",nombre,mail);

                strcpy(unDestinatario->nombre,nombre);
                strcpy(unDestinatario->mail,mail);

                listaParaCargar->add(listaParaCargar,unDestinatario);
            }
        }
        returnAux=0;
    }
    fclose(fp);
    return returnAux;
}

void mostrarUnDestinatario(eDestinatario* unDestinatario)
{
    printf("NOMBRE: %s / MAIL: %s\n",unDestinatario->nombre,unDestinatario->mail);
}

void mostrarListaDestinatarios(ArrayList* listaDestinatarios)
{
    int i;
    for(i=0;i<listaDestinatarios->len(listaDestinatarios);i++)
    {
        mostrarUnDestinatario(listaDestinatarios->pElements[i]);
    }
}

void depurarLista(ArrayList* listaDestinatarios, ArrayList* blackList, ArrayList* listaDepurada)
{
    int i,j;
    int flagAdd;
    eDestinatario* destinatarioA;
    eDestinatario* destinatarioB;
    for(i=0;i<(listaDestinatarios->len(listaDestinatarios));i++)
    {
        destinatarioA=listaDestinatarios->get(listaDestinatarios,i);
        flagAdd=0;
        for(j=0;j<(blackList->len(blackList));j++)
        {
            destinatarioB=blackList->get(blackList,j);
            if(strcmp(destinatarioA->mail,destinatarioB->mail)==0 && strcmp(destinatarioA->nombre,destinatarioB->nombre)==0)
            {
                flagAdd=1;
                break;
            }
        }
        if(flagAdd==0)
        {
            listaDepurada->add(listaDepurada,destinatarioA);
        }
    }
}

void eliminarRepetidos(ArrayList* listaDepurada)
{
    int i,j;
    eDestinatario* destinatarioA;
    eDestinatario* destinatarioB;
    for(i=0;i<(listaDepurada->len(listaDepurada)-1);i++)
    {
        destinatarioA=listaDepurada->get(listaDepurada,i);
        for(j=i+1;j<listaDepurada->len(listaDepurada);j++)
        {
            destinatarioB=listaDepurada->get(listaDepurada,j);
            if(strcmp(destinatarioA->nombre,destinatarioB->nombre)==0 && strcmp(destinatarioA->mail,destinatarioB->mail)==0)
            {
                listaDepurada->remove(listaDepurada,j);
            }
        }
    }
}

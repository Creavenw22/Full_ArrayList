#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"

typedef struct
{
    char nombre[50];
    char mail[150];
}eDestinatario;

void menu(void);

int cargarLista(char* nombreArchivo,ArrayList* listaParaCargar);

void mostrarUnDestinatario(eDestinatario* unDestinatario);

void mostrarListaDestinatarios(ArrayList* listaDestinatarios);

void depurarLista(ArrayList* listaDestinatarios, ArrayList* blackList, ArrayList* listaDepurada);

void eliminarRepetidos(ArrayList* listaDepurada);

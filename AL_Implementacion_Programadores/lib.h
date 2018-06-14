#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"

typedef struct
{
    int id;
    char nombre[150];
    char puesto[150];
    int edad;
}ePersona;



/** \brief MUESTA EL MENU.
 * \param NONE
 * \return NONE
 *
 */

 void menu(void);


/** \brief CARGA EL ARCHIVO EN EL ARRAY LIST
 * \param PIDE EL NOMBRE DEL ARCHIVO
 * \param PIDE EL NOMBRE DEL ARRAY LIST
 * \return RETORNA (-1) SI HUBO UN ERROR EN LA CARGA
                   (0) SI LA CARGA SE REALIZO CON EXITO
 */

int cargarLista(char* FileName,ArrayList* pList);

/** \brief MUESTRA UN EMPLEADO
 * \param PIDE LA ESTRUCTURA EMPLEADO
 * \return NONE
 */

 void mostrarEmpleado(ePersona* empleado);

 /** \brief MUESTRA LA LISTA DE EMPLEADOS
 * \param PIDE EL ARRAYLIST
 * \return NONE
 */
 void mostrarListaEmpleados(ArrayList* pList);

 int filtro(void* pElement);

 int filtrarProgramadores(ArrayList* pList, ArrayList* bList);

 int funcionQueFiltra(void* empleado);
void EscribirTexto(ArrayList* listaFil);

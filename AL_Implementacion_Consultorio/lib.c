#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "ArrayList.h"
#include "lib.h"

void menu(void)
{
    printf("\n\t\t\t~Sistema de turnos de consultorio~\n\n");
    printf("1- Ingresar un cliente\n");
    printf("2- Proximo cliente\n");
    printf("3- Clientes pendientes\n");
    printf("4- Lista de clientes atendidos\n");
    printf("5- Salir\n");
}


void validarString(char stringAValid[], int maximo)
{
    int largo=strlen(stringAValid);
    while(largo>maximo)
    {
        printf("Se excedio del tamano reingrese: ");
        stringAValid=gets(stringAValid);
        largo=strlen(stringAValid);
    }
}

int validarDigitoRango(char* numero,int minimo,int maximo)
{
    int i;
    int largo=strlen(numero);
    int flag;
    int numCheck;
    do
    {
        do
        {
            flag=0;
            for(i=0; i<largo; i++)
            {
                if(!isdigit(numero[i]))
                {
                    flag=1;
                    break;
                }
            }
            if(flag!=0)
            {
                printf("Por Favor reingrese: ");
                fflush(stdin);
                gets(numero);
            }
            numCheck=atoi(numero);
            if(numCheck<minimo || numCheck>maximo)
            {
                printf("Por Favor reingrese: ");
                fflush(stdin);
                gets(numero);
            }
        }
        while(flag!=0);
    }
    while(numCheck<minimo || numCheck>maximo);
    return numCheck;
}

int checkearDni(ArrayList* listaUrgentes, ArrayList* listaRegular,int dni)
{
    int i;
    int returnAux=0;
    eCliente* clienteAux;
    if(dni>0)
    {
        for(i=0; i<listaUrgentes->len(listaUrgentes); i++)
        {
            clienteAux=listaUrgentes->get(listaUrgentes,i);
            if(clienteAux->dni==dni)
            {
                returnAux=1;
                break;
            }
        }
        if(returnAux!=1)
        {
            for(i=0; i<listaRegular->len(listaRegular); i++)
            {
                clienteAux=listaRegular->get(listaRegular,i);
                if(clienteAux->dni==dni)
                {
                    returnAux=1;
                    break;
                }
            }
        }
    }
    return returnAux;
}

eCliente* newCliente(int dni,int tipoTramite,int turno)
{
    eCliente* returnAux=NULL;
    eCliente* nuevoCliente=(eCliente*)malloc(sizeof(eCliente));
    if(nuevoCliente!=NULL)
    {
        nuevoCliente->dni=dni;
        nuevoCliente->tipoTramite=tipoTramite;
        nuevoCliente->numeroTurno=turno;
        nuevoCliente->estado=1;
        returnAux=nuevoCliente;
    }
    return returnAux;
}

void ingresoCliente(ArrayList* listaUrgentes, ArrayList* listaRegular,int* punteroTurno)
{
    eCliente* nuevoCliente;
    int max=INT_MAX;
    char* dni=(char*)malloc(sizeof(char)*10);
    char* tipoTramite=(char*)malloc(sizeof(char)*10);
    int dniNum;
    int tramiteNum;
    system("cls");
    printf("\n\nIngrese su DNI: ");
    fflush(stdin);
    gets(dni);
    dniNum=validarDigitoRango(dni,100000,max);
    while(checkearDni(listaUrgentes,listaRegular,dniNum)==1)
    {
        printf("Error, el DNI ya se encuentra ingresado, reingrese: ");
        fflush(stdin);
        gets(dni);
        dniNum=validarDigitoRango(dni,100000,max);
    }
    system("cls");
    printf("Ingrese el tipo de tramite a realizar\n");
    printf("1- TRAMITE URGENTE\n");
    printf("2- TRAMITE REGULAR\n");
    fflush(stdin);
    gets(tipoTramite);
    tramiteNum=validarDigitoRango(tipoTramite,1,2);
    *punteroTurno+=1;
    nuevoCliente=newCliente(dniNum,tramiteNum,*punteroTurno);
    if(nuevoCliente!=NULL)
    {
        if(tramiteNum==1)
        {
            if(listaUrgentes->add(listaUrgentes,nuevoCliente)==0)
            {
                system("cls");
                printf("\nDNI: %d. SU NUMERO DE TURNO ES %d.\n\nAGUARDE, EN UNOS MOMENTOS SERA ATENDIDO... O NO?\n\n\n\n",dniNum,*punteroTurno);
            }
        }
        else
        {
            if(listaRegular->add(listaRegular,nuevoCliente)==0)
            {
                system("cls");
                printf("\nDNI: %d. SU NUMERO DE TURNO ES %d.\n\nAGUARDE, EN UNOS MOMENTOS SERA ATENDIDO... O NO?\n\n\n\n",dniNum,*punteroTurno);
            }
        }
    }
    //mostrarUnCliente(nuevoCliente);
}

void proximoCliente(ArrayList* listaUrgentes, ArrayList* listaRegular, ArrayList* totalPacientes)
{
    system("cls");
    printf("\n\n");
    eCliente* proximoCliente=NULL;
    if(listaUrgentes->size>0)
    {
        proximoCliente=listaUrgentes->pop(listaUrgentes,0);
    }
    else
    {
        if(listaRegular->size>0)
        {
            proximoCliente=listaRegular->pop(listaRegular,0);
        }
    }
    if(proximoCliente!=NULL)
    {
        proximoCliente->estado=0;
        totalPacientes->add(totalPacientes,proximoCliente);
        mostrarUnCliente(proximoCliente);
    }
    else
    {
        printf("\n\nNO HAY PACIENTES EN ESPERA\n");
    }
}

void mostrarUnCliente(eCliente* unCliente)
{
    char tipoTramite[]="";
    switch(unCliente->tipoTramite)
    {
    case 1:
        strcpy(tipoTramite,"URGENTE");
        break;
    case 2:
        strcpy(tipoTramite,"REGULAR");
        break;
    }
    printf("DNI: %d / TIPO DE TRAMITE: %s / TURNO: %d\n",unCliente->dni,tipoTramite,unCliente->numeroTurno);
}

void clientesEnEspera(ArrayList* listaUrgentes, ArrayList* listaRegular)
{
    system("cls");
    int i;
    if(listaUrgentes->size>0)
    {
        printf("\n\nPACIENTES URGENTES EN ESPERA: \n");
        for(i=0; i<listaUrgentes->len(listaUrgentes); i++)
        {
            mostrarUnCliente(listaUrgentes->pElements[i]);
        }
    }
    else
    {

        printf("\n\nNO HAY PACIENTES URGENTES EN ESPERA\n");
    }
    if(listaRegular->size>0)
    {
        printf("\n\nPACIENTES REGULARES EN ESPERA: \n");
        for(i=0; i<listaRegular->len(listaRegular); i++)
        {
            mostrarUnCliente(listaRegular->pElements[i]);
        }
    }
    else
    {
        printf("\n\nNO HAY PACIENTES REGULARES EN ESPERA\n");
    }
}

void clientesAtendidos(ArrayList* totalClientes)
{
    int i;
    if(totalClientes->size>0)
    {
        printf("Lista de clientes atendidos: \n");
        for(i=0; i<totalClientes->len(totalClientes); i++)
        {
            mostrarUnCliente(totalClientes->pElements[i]);
        }
    }
    else
    {
        printf("Todavia no se atendieron pacientes\n");
    }
}

int compararClientes(void* clienteA,void* clienteB)
{

    if(((eCliente*)clienteA)->dni > ((eCliente*)clienteB)->dni)
    {
        return 1;
    }
    if(((eCliente*)clienteA)->dni < ((eCliente*)clienteB)->dni)
    {
        return -1;
    }
    return 0;
}

void guardarTurnos(ArrayList* listaUrgentes, ArrayList* listaRegulares, ArrayList* totalClientes)
{
    FILE *f;
    int i;
    eCliente* unCliente;
    f=fopen("listaTurnos.csv","w");
    if(f == NULL)
    {
        printf("No se pudo crear el archivo");
        exit(1);
    }
    for(i=0; i<listaUrgentes->len(listaUrgentes); i++)
    {
        unCliente=listaUrgentes->get(listaUrgentes,i);
        fprintf(f,"%d,%d,%d,%d\n",unCliente->estado,unCliente->dni,unCliente->tipoTramite,unCliente->numeroTurno);
    }
    for(i=0; i<listaRegulares->len(listaRegulares); i++)
    {
        unCliente=listaRegulares->get(listaRegulares,i);
        fprintf(f,"%d,%d,%d,%d\n",unCliente->estado,unCliente->dni,unCliente->tipoTramite,unCliente->numeroTurno);
    }
    for(i=0; i<totalClientes->len(totalClientes); i++)
    {
        unCliente=totalClientes->get(totalClientes,i);
        fprintf(f,"%d,%d,%d,%d\n",unCliente->estado,unCliente->dni,unCliente->tipoTramite,unCliente->numeroTurno);
    }
    fclose(f);
}

void guardarTurnosBinario(ArrayList* listaUrgentes, ArrayList* listaRegulares, ArrayList* totalClientes)
{
    FILE *f;
    int i;
    eCliente* unCliente;
    f=fopen("listaTurnosBin.dat","wb");
    if(f == NULL)
    {
        printf("No se pudo crear el archivo");
        exit(1);
    }
    if(listaUrgentes->len(listaUrgentes)>0)
    {
        for(i=0; i<listaUrgentes->len(listaUrgentes); i++)
        {
            unCliente=listaUrgentes->get(listaUrgentes,i);
            fwrite(unCliente,sizeof(eCliente),1,f);
        }
    }
    if(listaRegulares->len(listaRegulares)>0)
    {
        for(i=0; i<listaRegulares->len(listaRegulares); i++)
        {
            unCliente=listaUrgentes->get(listaRegulares,i);
            fwrite(unCliente,sizeof(eCliente),1,f);
        }
    }
    if(totalClientes->len(totalClientes)>0)
    {
        for(i=0; i<totalClientes->len(totalClientes); i++)
        {
            unCliente=listaUrgentes->get(totalClientes,i);
            fwrite(unCliente,sizeof(eCliente),1,f);
        }
    }
    fclose(f);
}

int cargarTurnos(ArrayList* listaUrgentes, ArrayList* listaRegulares, ArrayList* totalClientes)
{
    FILE *fp;
    int returnAux=-1;
    char* estado=(char*)malloc(sizeof(char)*10);
    char* dni=(char*)malloc(sizeof(char)*10);
    char* tipoTramite=(char*)malloc(sizeof(char)*10);
    char* numeroTurno=(char*)malloc(sizeof(char)*10);
    eCliente* unCliente;
    fp = fopen("listaTurnos.csv","r");
    if(fp!=NULL)
    {
        while(!feof(fp))
        {
            unCliente=(eCliente*)malloc(sizeof(eCliente));
            if(unCliente!=NULL)
            {
                if(feof(fp))
                {
                    break;
                }
                fscanf(fp,"%[^,],%[^,],%[^,],%[^\n]\n",estado,dni,tipoTramite,numeroTurno);

                unCliente->estado=atoi(estado);
                unCliente->dni=atoi(dni);
                unCliente->tipoTramite=atoi(tipoTramite);
                unCliente->numeroTurno=atoi(numeroTurno);

                if(unCliente->estado==1)
                {
                    if(unCliente->tipoTramite==1)
                    {
                        listaUrgentes->add(listaUrgentes,unCliente);
                    }
                    else
                    {
                        listaRegulares->add(listaRegulares,unCliente);
                    }
                }
                else
                {
                    totalClientes->add(totalClientes,unCliente);
                }
                returnAux=0;
            }
        }

    }
    fclose(fp);
    return returnAux;
}

int cargarTurnosBinario(ArrayList* listaUrgentes, ArrayList* listaRegulares, ArrayList* totalClientes)
{
    FILE *f;
    int returnAux=-1;
    eCliente* unCliente;
    f = fopen("listaTurnosBin.dat","rb");
    if(f!=NULL)
    {
        while(!feof(f))
        {
            unCliente=(eCliente*)malloc(sizeof(eCliente));
            if(unCliente!=NULL)
            {
                fread(unCliente,sizeof(eCliente),1,f);
                if(feof(f))
                {
                    break;
                }
                if(unCliente->estado==1)
                {
                    if(unCliente->tipoTramite==1)
                    {
                        listaUrgentes->add(listaUrgentes,unCliente);
                    }
                    else
                    {
                        listaRegulares->add(listaRegulares,unCliente);
                    }
                }
                else
                {
                    totalClientes->add(totalClientes,unCliente);
                }
                returnAux=0;
            }
        }

    }
    fclose(f);
    return returnAux;
}


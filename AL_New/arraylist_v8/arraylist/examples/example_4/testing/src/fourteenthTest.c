/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <utest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//INCLUDE LIBRARY TO TEST

#include "../../inc/ArrayList.h"
#include "../../inc/Employee.h"

//DEFINES OF THIS TEST
#define LENGTH 5


static char* unsortedList[] = {"Za","Zb","Xd","Xb","Ya","Yc"};
static int sector[] = {1,1,2,3,4,6};
static float salary[] = {1000,1000,2000,3000,4000,8000};
static int id[] = {11,20,3,4,9,99};


void fourteenthTestSetup(void)
{
	utest_print("Setup...\r\n");
}


void fourteenthTestCase01(void)
{
    int i;
    ArrayList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxToPop;


    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    pAuxToPop = list->pop(list,0);
    utest_assertNotNullMsg(pAuxToPop,"Error in return value of <pop> if ok the correct value is not NULL");


    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}


void fourteenthTestCase02(void)
{
    int i;
    ArrayList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxGet[LENGTH];

    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->push(list,i,pAux[i]);
    }

    for(i=LENGTH-1; i >= 0; i--)
    {
        pAuxGet[i] = list->pop(list,i);
        utest_assertNotNullMsg(pAuxGet[i],"Error in return value of <pop> if ok the correct value is not NULL");
    }

    for (i=0;i < LENGTH;i++)
    {
        utest_assertEqualsIntMsg(((Employee*)pAuxGet[i])->id,id[i],"Error value in <.id>");
        utest_assertEqualsStringMsg(((Employee*)pAuxGet[i])->name,unsortedList[i],2,"Error value in <.name>");
        utest_assertEqualsStringMsg(((Employee*)pAuxGet[i])->lastName,unsortedList[i],2,"Error value in <.lastName>");
        utest_assertEqualsFloatMsg(((Employee*)pAuxGet[i])->salary,salary[i],"Error value in <.salary>");
        utest_assertEqualsIntMsg(((Employee*)pAuxGet[i])->sector,sector[i],"Error value in <.sector>");
        utest_assertEqualsIntMsg(((Employee*)pAuxGet[i])->isEmpty,0,"Error value in <.isEmpty> the correct value is: (0)");

    }

    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);



}

void fourteenthTestCase03(void)
{
    int i;
    ArrayList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxToPop;


    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    pAuxToPop = list->pop(list,7);
    utest_assertNullMsg(pAuxToPop,"Error in return value of <pop> if the Element is not inclued the correct value to return is NULL");


    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}

void fourteenthTestCase04(void)
{
    int i;
    ArrayList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxToPop;


    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    pAuxToPop = list->pop(NULL,0);
    utest_assertNullMsg(pAuxToPop,"Error in return value of <pop> if the pointer to array is NULL the correct value to return is NULL");


    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}
void fourteenthTestCase05(void)
{
    int i;
    ArrayList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxToPop;


    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    pAuxToPop = list->pop(list,-1);
    utest_assertNullMsg(pAuxToPop,"Error in return value of <pop> if the index is invalid the correct value to return is NULL");


    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}

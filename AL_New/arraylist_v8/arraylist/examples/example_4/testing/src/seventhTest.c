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


void seventhTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void seventhTestCase01(void)
{
    int i, r;
    ArrayList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxToSet;


    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }
    pAuxToSet = newEmployee(id[5],unsortedList[5],unsortedList[5],salary[5],sector[5]);

    for(i=0; i < LENGTH; i++)
    {
        r = list->set(list,i,pAuxToSet);
        utest_assertEqualsIntMsg(r,0,"Error in return value <set> if ok the correct value to return is 0");
    }

    free(list);
    free(pAuxToSet);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}





void seventhTestCase02(void)
{
    int i, r;
    ArrayList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxToSet;
    Employee* pAuxGet;

    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }
    pAuxToSet = newEmployee(id[5],unsortedList[5],unsortedList[5],salary[5],sector[5]);

    for(i=0; i < LENGTH; i++)
    {
        r = list->set(list,i,pAuxToSet);
        utest_assertEqualsIntMsg(r,0,"Error in return value <set> if ok the correct value to return is 0");
    }

    for (i=0;i < LENGTH;i++)
    {
        pAuxGet = list->get(list,i);
        utest_assertEqualsIntMsg(((Employee*)pAuxGet)->id,id[5],"Error value in <.id>");
        utest_assertEqualsStringMsg(((Employee*)pAuxGet)->name,unsortedList[5],2,"Error value in <.name>");
        utest_assertEqualsStringMsg(((Employee*)pAuxGet)->lastName,unsortedList[5],2,"Error value in <.lastName>");
        utest_assertEqualsFloatMsg(((Employee*)pAuxGet)->salary,salary[5],"Error value in <.salary>");
        utest_assertEqualsIntMsg(((Employee*)pAuxGet)->sector,sector[5],"Error value in <.sector>");
        utest_assertEqualsIntMsg(((Employee*)pAuxGet)->isEmpty,0,"Error value in <.isEmpty> the correct value is: (0)");

    }


    free(list);
    free(pAuxToSet);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}


void seventhTestCase03(void)
{
    int i, r;
    ArrayList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxToSet;



    list = al_newArrayList();


    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }
    pAuxToSet = newEmployee(id[5],unsortedList[5],unsortedList[5],salary[5],sector[5]);


    r = list->set(list,9,pAuxToSet);
    utest_assertEqualsIntMsg(r,-1,"Error in return value <set> if the index is invalid the correct value to return is -1");

    free(list);

}

void seventhTestCase04(void)
{
    int i, r;
    ArrayList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxToSet;



    list = al_newArrayList();


    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }
    pAuxToSet = newEmployee(id[5],unsortedList[5],unsortedList[5],salary[5],sector[5]);


    r = list->set(NULL,0,pAuxToSet);
    utest_assertEqualsIntMsg(r,-1,"Error in return value <set> if the pointer to the new Element is NULL the correct value to return is -1");

    free(list);

}

void seventhTestCase05(void)
{
    int i, r;
    ArrayList* list;
    Employee* pAux[LENGTH];

    list = al_newArrayList();


    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    r = list->set(list,0,NULL);
    utest_assertEqualsIntMsg(r,-1,"Error in return value <set> if the pointer to array is NULL the correct value to return is -1");

    free(list);

}

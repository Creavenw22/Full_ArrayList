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


void fifteenthTestSetup(void)
{
	utest_print("Setup...\r\n");
}


void fifteenthTestCase01(void)
{
    int i;
    ArrayList* list;
    ArrayList* pSubList;
    Employee* pAux[LENGTH];



    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    pSubList = list->subList(list,0,3);
    utest_assertNotNullMsg(pSubList ,"Error in return value of <subList> if ok the correct value is not NULL");


    free(list);
    free(pSubList);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}


void fifteenthTestCase02(void)
{
    int i;
    ArrayList* list;
    ArrayList* pSubList;
    Employee* pAux[LENGTH];
    Employee* pAuxGet[LENGTH];



    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    pSubList = list->subList(list,0,5);
    utest_assertNotNullMsg(pSubList ,"Error in return value of <subList> if ok the correct value is not NULL");

    for(i=0; i < LENGTH; i++)
    {
        pAuxGet[i] = pSubList->get(pSubList,i);
        utest_assertNotNullMsg(pAuxGet[i],"Error in return value of <get> if ok the correct value is not NULL");
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
    free(pSubList);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);


}

void fifteenthTestCase03(void)
{

    int i;
    ArrayList* list;
    ArrayList* pSubList;
    Employee* pAux[LENGTH];



    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    pSubList = list->subList(NULL,0,3);
    utest_assertNullMsg(pSubList ,"Error in return value of <subList> if the array pointer is NULL the correct value to return is NULL");


    free(list);
    free(pSubList);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}

void fifteenthTestCase04(void)
{

    int i;
    ArrayList* list;
    ArrayList* pSubList;
    Employee* pAux[LENGTH];



    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    pSubList = list->subList(list,-1,3);
    utest_assertNullMsg(pSubList ,"Error in return value of <subList> if the array pointer is NULL the correct value to return is NULL");

    pSubList = list->subList(list,4,3);
    utest_assertNullMsg(pSubList ,"Error in return value of <subList> if the array pointer is NULL the correct value to return is NULL");


    free(list);
    free(pSubList);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}

void fifteenthTestCase05(void)
{

    int i;
    ArrayList* list;
    ArrayList* pSubList;
    Employee* pAux[LENGTH];



    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    pSubList = list->subList(list,2,1);
    utest_assertNullMsg(pSubList ,"Error in return value of <subList(list,2,1)> if the array pointer is NULL the correct value to return is NULL");

    pSubList = list->subList(list,2,-1);
    utest_assertNullMsg(pSubList ,"Error in return value of <subList(list,2,-1)> if the array pointer is NULL the correct value to return is NULL");


    free(list);
    free(pSubList);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}


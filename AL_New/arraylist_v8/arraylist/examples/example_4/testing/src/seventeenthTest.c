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
#define LENGTH 6


static char* unsortedList[] = {"Za","Zb","Xd","Xb","Ya","Yc"};
static int sector[] = {1,1,2,3,4,6};
static float salary[] = {1001,2000,1002,3000,4000,8000};
static float salarySortedUp[] = {8000,4000,3000,2000,1002,1001};
//static float salarySortedDown[] = {1000,1000,2000,3000,4000,8000};
static int id[] = {11,20,3,4,9,99};


void seventeenthTestSetup(void)
{
	utest_print("Setup...\r\n");
}


void seventeenthTestCase01(void)
{
    int i,r;
    ArrayList* list;
    Employee* pAux[LENGTH];

    list = al_newArrayList();


    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    r = list->sort(list, compareEmployee,1);
    utest_assertEqualsIntMsg(r, 0 ,"Error in return value of <sort> if the list is contained the correct value is 1");

    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}


void seventeenthTestCase02(void)
{
    int i;
    ArrayList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxGet[LENGTH];

    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    list->sort(list, compareEmployee,0);

    for(i=0; i < LENGTH; i++)
    {
        pAuxGet[i] = list->get(list,i);
        utest_assertNotNullMsg(pAuxGet[i],"Error in return value <get> if ok the correct value to return is not NULL");
    }

    for (i=0;i < LENGTH;i++)
    {
        utest_assertEqualsFloatMsg(((Employee*)pAuxGet[i])->salary,salarySortedUp[i],"Error value in <.salary> after sort");
    }

    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);



}
void seventeenthTestCase03(void)
{

    int i,r;
    ArrayList* list;
    Employee* pAux[LENGTH];

    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    r = list->sort(NULL, compareEmployee,1);
    utest_assertEqualsIntMsg(r, -1 ,"Error in return value of <sort> if the pointer to Array is Null the correct value is -1");

    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);


}

void seventeenthTestCase04(void)
{

    int i,r;
    ArrayList* list;
    Employee* pAux[LENGTH];

    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    r = list->sort(list, NULL,1);
    utest_assertEqualsIntMsg(r, -1 ,"Error in return value of <sort> if the pointer to Function is Null the correct value is -1");

    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}

void seventeenthTestCase05(void)
{

    int i,r;
    ArrayList* list;
    Employee* pAux[LENGTH];

    list = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
    }

    r = list->sort(list, compareEmployee,-1);
    utest_assertEqualsIntMsg(r, -1 ,"Error in return value of <sort> if the order is invalid the correct value is -1");

    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}

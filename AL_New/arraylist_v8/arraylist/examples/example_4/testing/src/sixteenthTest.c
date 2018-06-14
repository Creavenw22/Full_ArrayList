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


void sixteenthTestSetup(void)
{
	utest_print("Setup...\r\n");
}


void sixteenthTestCase01(void)
{
    int i,r;
    ArrayList* list;
    ArrayList* pOtherList;
    Employee* pAux[LENGTH];

    list = al_newArrayList();
    pOtherList = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
        pOtherList->add(pOtherList,pAux[i]);
    }

    r = list->containsAll(list,pOtherList);
    utest_assertEqualsIntMsg(r, 1 ,"Error in return value of <containsAll> if the list is contained the correct value is 1");

    free(list);
    free(pOtherList);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}


void sixteenthTestCase02(void)
{
    int i,r;
    ArrayList* list;
    ArrayList* pOtherList;
    Employee* pAux[LENGTH];

    list = al_newArrayList();
    pOtherList = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
        pOtherList->add(pOtherList,pAux[i]);
    }

    list->remove(list,0);

    r = list->containsAll(list,pOtherList);
    utest_assertEqualsIntMsg(r, 0 ,"Error in return value of <containsAll> if the list is not contained the correct value is 0");

    free(list);
    free(pOtherList);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);


}

void sixteenthTestCase03(void)
{

    int i,r;
    ArrayList* list;
    ArrayList* pOtherList;
    Employee* pAux[LENGTH];

    list = al_newArrayList();
    pOtherList = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
        pOtherList->add(pOtherList,pAux[i]);
    }


    r = list->containsAll(NULL,pOtherList);
    utest_assertEqualsIntMsg(r, -1 ,"Error in return value of <containsAll> if the pointer to Array is Null the correct value is -1");

    free(list);
    free(pOtherList);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);


}

void sixteenthTestCase04(void)
{

    int i,r;
    ArrayList* list;
    ArrayList* pOtherList;
    Employee* pAux[LENGTH];

    list = al_newArrayList();
    pOtherList = al_newArrayList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        list->add(list,pAux[i]);
        pOtherList->add(pOtherList,pAux[i]);
    }

    r = list->containsAll(list,NULL);
    utest_assertEqualsIntMsg(r, -1 ,"Error in return value of <containsAll> if the pointer to contained array is Null the correct value is -1");

    free(list);
    free(pOtherList);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}

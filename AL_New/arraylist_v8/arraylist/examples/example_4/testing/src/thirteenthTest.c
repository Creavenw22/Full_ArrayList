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


void thirteenthTestSetup(void)
{
	utest_print("Setup...\r\n");
}


/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok

 int al_push(ArrayList* pList, int index, void* pElement)
 */


void thirteenthTestCase01(void)
{
    int r;
    ArrayList* list;

    list = al_newArrayList();


    r = list->isEmpty(list);
    utest_assertEqualsIntMsg(r,1,"Error in return value of <isEmpty> the correct value when isn't empty is 0");

    free(list);

}


void thirteenthTestCase02(void)
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

    r = list->isEmpty(list);
    utest_assertEqualsIntMsg(r,0,"Error in return value of <isEmpty> the correct value when is empty is 0");


    free(list);
    for(i=0; i < LENGTH; i++)
        free(pAux[i]);
}

void thirteenthTestCase03(void)
{
    int r;
    ArrayList* list;

    list = al_newArrayList();

    r = list->isEmpty(NULL);
    utest_assertEqualsIntMsg(r,-1,"Error in return value of <isEmpty> when the pointer to arrray is NULL the correct value to return is -1");

    free(list);

}

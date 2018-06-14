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


void thirdTestSetup(void)
{
	utest_print("Setup...\r\n");
}


void thirdTestCase01(void)
{

    int r;
    ArrayList* list=NULL;

    r = al_deleteArrayList(list);
    utest_assertEqualsIntMsg(r,-1,"Error in return value <deleteArrayList> if array pointer is NULL, the correct value to return is: (-1)");


}
void thirdTestCase02(void)
{

    int r;
    ArrayList* list;
    list = al_newArrayList();

    r = al_deleteArrayList(list);
    utest_assertEqualsIntMsg(r,0,"Error in return value <deleteArrayList> if array pointer is valid, the correct value to return is: (0)");

    if(r != 0)
        free(list);

}





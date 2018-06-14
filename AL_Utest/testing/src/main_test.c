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
//**********LISTAS***********
#include "../inc/firstTest.h"
#include "../inc/secondTest.h"
#include "../inc/thirdTest.h"
#include "../inc/fourthTest.h"
#include "../inc/fifthTest.h"
#include "../inc/sixthTest.h"
#include "../inc/seventhTest.h"
#include "../inc/eighthTest.h"
#include "../inc/ninthTest.h"
#include "../inc/tenthTest.h"
#include "../inc/eleventhTest.h"
#include "../inc/twelfthTest.h"
#include "../inc/thirteenthTest.h"
#include "../inc/fourteenthTest.h"
#include "../inc/fifteenthTest.h"
//**********LISTAS***********
#include "../inc/sixteenthTest.h"
#include "../inc/seventeenthTest.h"


void startTesting(int testGroup)
{


    switch(testGroup)
    {
        case 1:
            // Start Group 01
            utest_printStartTesting("al_newArrayList()");
            utest_init();
            utest_startTest(firstTestCase01,firstTestSetup,">Case[Return of newArrayList]");
            utest_printStatistics("al_newArrayList()");
            // End Group 01
            break;

        case 2:
            // Start Group 02
            utest_printStartTesting("al_add()");
            utest_init();
            utest_startTest(secondTestCase01,secondTestSetup,">Case[Return of add Employees]");
            utest_startTest(secondTestCase02,secondTestSetup,">Case[Content of added Employees]");
            utest_startTest(secondTestCase03,secondTestSetup,">Case[Return of add 10000 Employees to force resizeUP]");
            utest_startTest(secondTestCase04,secondTestSetup,">Case[Return of add Employees with NULL pointer to array]");
            utest_printStatistics("al_add()");
            // End Group 02
            break;

        case 3:
            // Start Group 03
            utest_printStartTesting("al_deleteArrayList()");
            utest_init();
            utest_startTest(thirdTestCase01,thirdTestSetup,">Case[Return of deleteArrayList with NULL pointer to array]");
            utest_startTest(thirdTestCase02,thirdTestSetup,">Case[Return of deleteArrayList with correct pointer to array]");
            utest_printStatistics("al_deleteArrayList()");
            // End Group 03
            break;

        case 4:
            // Start Group 04
            utest_printStartTesting("al_len()");
            utest_init();
            utest_startTest(fourthTestCase01,fourthTestSetup,">Case[Return of len with an array with Elements]");
            utest_startTest(fourthTestCase02,fourthTestSetup,">Case[Return of len with an Empty array]");
            utest_startTest(fourthTestCase03,fourthTestSetup,">Case[Return of len with NULL pointer to array]");
            utest_printStatistics("al_len()");
            // End Group 04
            break;

        case 5:
            // Start Group 05
            utest_printStartTesting("al_get()");
            utest_init();
            utest_startTest(fifthTestCase01,fifthTestSetup,">Case[Return of get a valid Employee]");
            utest_startTest(fifthTestCase02,fifthTestSetup,">Case[Content of a valid Employee]");
            utest_startTest(fifthTestCase03,fifthTestSetup,">Case[Return of a invalid Employee]");
            utest_startTest(fifthTestCase04,fifthTestSetup,">Case[Return of get with NULL pointer to array]");
            utest_printStatistics("al_get()");
            // End Group 05
            break;

        case 6:
            // Start Group 06
            utest_printStartTesting("al_contains()");
            utest_init();
            utest_startTest(sixthTestCase01,sixthTestSetup,">Case[Return of contains with a contend Element]");
            utest_startTest(sixthTestCase02,sixthTestSetup,">Case[Return of contains with a not contend Element]");
            utest_startTest(sixthTestCase03,sixthTestSetup,">Case[Return of get with NULL pointer to element]");
            utest_startTest(sixthTestCase04,sixthTestSetup,">Case[Return of get with NULL pointer to array]");
            utest_printStatistics("al_contains()");
            // End Group 06
            break;
        case 7:
            // Start Group 07
            utest_printStartTesting("al_set()");
            utest_init();
            utest_startTest(seventhTestCase01,seventhTestSetup,">Case[Return of set an correct Element]");
            utest_startTest(seventhTestCase02,seventhTestSetup,">Case[Content of a valid Employee that was previously set]");
            utest_startTest(seventhTestCase03,seventhTestSetup,">Case[Return of set with invalid index]");
            utest_startTest(seventhTestCase04,seventhTestSetup,">Case[Return of set with NULL pointer to element]");
            utest_startTest(seventhTestCase05,seventhTestSetup,">Case[Return of set with NULL pointer to array]");
            utest_printStatistics("al_set()");
            // End Group 07
            break;

        case 8:
            // Start Group 08
            utest_printStartTesting("al_remove()");
            utest_init();
            utest_startTest(eighthTestCase01,eighthTestSetup,">Case[Return of remove a correct Element]");
            utest_startTest(eighthTestCase02,eighthTestSetup,">Case[Value of the size of the array after remove an element]");
            utest_startTest(eighthTestCase03,eighthTestSetup,">Case[Return of remove with invalid index]");
            utest_startTest(eighthTestCase04,eighthTestSetup,">Case[Return of remove with NULL pointer to array]");
            utest_printStatistics("al_remove()");
            // End Group 08
            break;

        case 9:
            // Start Group 09
            utest_printStartTesting("al_clear()");
            utest_init();
            utest_startTest(ninthTestCase01,ninthTestSetup,">Case[Return of clear]");
            utest_startTest(ninthTestCase02,ninthTestSetup,">Case[Value of the size of the array after clear]");
            utest_startTest(ninthTestCase03,ninthTestSetup,">Case[Return of clear with NULL pointer to array]");
            utest_printStatistics("al_clear()");
            // End Group 09
            break;

        case 10:
            // Start Group 10
            utest_printStartTesting("al_clone()");
            utest_init();
            utest_startTest(tenthTestCase01,tenthTestSetup,">Case[Return of clone]");
            utest_startTest(tenthTestCase02,tenthTestSetup,">Case[Content of a cloned list]");
            utest_startTest(tenthTestCase03,tenthTestSetup,">Case[Return of clone with NULL pointer to array]");
            utest_printStatistics("al_clone()");
            // End Group 10
            break;

        case 11:
            // Start Group 11
            utest_printStartTesting("al_push()");
            utest_init();
            utest_startTest(eleventhTestCase01,eleventhTestSetup,">Case[Return of push a valid Employee]");
            utest_startTest(eleventhTestCase02,eleventhTestSetup,">Case[Content of a valid Employee]");
            utest_startTest(eleventhTestCase03,eleventhTestSetup,">Case[Return of a push invalid Employee]");
            utest_startTest(eleventhTestCase04,eleventhTestSetup,">Case[Return of push with NULL pointer to array]");
            utest_startTest(eleventhTestCase05,eleventhTestSetup,">Case[Return of push in invadid index]");
            utest_printStatistics("al_push()");
            // End Group 11
            break;

        case 12:
            // Start Group 12
            utest_printStartTesting("al_indexOf()");
            utest_init();
            utest_startTest(twelfthTestCase01,twelfthTestSetup,">Case[Return of indexOf a valid Employee]");
            utest_startTest(twelfthTestCase02,twelfthTestSetup,">Case[Return of indexOf a valid Employees]");
            utest_startTest(twelfthTestCase03,twelfthTestSetup,">Case[Return of indexOf with NULL pointer to array]");
            utest_startTest(twelfthTestCase04,twelfthTestSetup,">Case[Return of indexOf with NULL pointer to Employee]");
            utest_printStatistics("al_indexOf()");
            // End Group 12
            break;

        case 13:
            // Start Group 13
            utest_printStartTesting("al_isEmpty()");
            utest_init();
            utest_startTest(thirteenthTestCase01,thirteenthTestSetup,">Case[Return of isEmpty with an empty Array]");
            utest_startTest(thirteenthTestCase02,thirteenthTestSetup,">Case[Return of isEmpty with an Not empty Array]");
            utest_startTest(thirteenthTestCase03,thirteenthTestSetup,">Case[Return of isEmpty with NULL pointer to array]");
            utest_printStatistics("al_isEmpty()");
            // End Group 13
            break;

        case 14:
            // Start Group 14
            utest_printStartTesting("al_pop()");
            utest_init();
            utest_startTest(fourteenthTestCase01,fourteenthTestSetup,">Case[Return of pop a valid Element]");
            utest_startTest(fourteenthTestCase02,fourteenthTestSetup,">Case[Return of pop a valid Elements]");
            utest_startTest(fourteenthTestCase03,fourteenthTestSetup,">Case[Return of pop an not inclued Element]");
            utest_startTest(fourteenthTestCase04,fourteenthTestSetup,">Case[Return of pop with NULL pointer to array]");
            utest_startTest(fourteenthTestCase05,fourteenthTestSetup,">Case[Return of pop an invalid Element]");
            utest_printStatistics("al_pop()");
            // End Group 14
            break;

        case 15:
            // Start Group 15
            utest_printStartTesting("al_subList()");
            utest_init();
            utest_startTest(fifteenthTestCase01,fifteenthTestSetup,">Case[Return of subList of a valid Array]");
            utest_startTest(fifteenthTestCase02,fifteenthTestSetup,">Case[Content of a valid subList]");
            utest_startTest(fifteenthTestCase03,fifteenthTestSetup,">Case[Return of subList with NULL pointer to array]");
            utest_startTest(fifteenthTestCase04,fifteenthTestSetup,">Case[Return of subList with invalid From]");
            utest_startTest(fifteenthTestCase05,fifteenthTestSetup,">Case[Return of subList with invalid To]");
            utest_printStatistics("al_subList()");
            // End Group 15
            break;

        case 16:
            // Start Group 14
            utest_printStartTesting("al_containsAll()");
            utest_init();
            utest_startTest(sixteenthTestCase01,sixteenthTestSetup,">Case[Return of containsAll of a valid contained Array]");
            utest_startTest(sixteenthTestCase02,sixteenthTestSetup,">Case[Return of containsAll of a valid NOT contained Array]");
            utest_startTest(sixteenthTestCase03,sixteenthTestSetup,">Case[Return of containsAll with NULL pointer to array]");
            utest_startTest(sixteenthTestCase04,sixteenthTestSetup,">Case[Return of containsAll with NULL pointer to contained array]");
            utest_printStatistics("al_containsAll()");
            // End Group 14
            break;
        case 17:
            // Start Group 14
            utest_printStartTesting("-al_sort()");
            utest_init();
            utest_startTest(seventeenthTestCase01,seventeenthTestSetup,">Case[Return of sort an Array in right way]");
            utest_startTest(seventeenthTestCase02,seventeenthTestSetup,">Case[Content of sorted an Array in right way]");
            utest_startTest(seventeenthTestCase03,seventeenthTestSetup,">Case[Return of sorted with NULL pointer to array]");
            utest_startTest(seventeenthTestCase04,seventeenthTestSetup,">Case[Return of sorted with NULL pointer to sort function]");
            utest_startTest(seventeenthTestCase05,seventeenthTestSetup,">Case[Return of sorted with invalid order]");
            utest_printStatistics("al_sort()");
            // End Group 14
            break;
    }


}

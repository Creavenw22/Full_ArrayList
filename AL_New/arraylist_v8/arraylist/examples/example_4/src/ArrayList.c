#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList = (ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            pList->filter = al_filter;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList, void* pElement)
{
    int returnAux = -1;

    if(pElement!=NULL && pList!=NULL)
    {
        resizeUp(pList);
        pList->pElements[pList->size]=pElement;
        pList->size++;
        returnAux=0;

    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)
{
    int returnAux = -1;

    if(pList!=NULL)
    {
        if(pList->pElements!=NULL)
        {
        free(pList->pElements);
        pList->pElements=NULL;
        }
        free(pList);
        pList=NULL;
        returnAux=0;
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList)
{
    int returnAux = -1;

    if(pList!=NULL)
    {
        returnAux=pList->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList, int index)
{
    void* returnAux = NULL;

    if(pList!=NULL)
    {
        if(index<pList->size && index>=0)
        {
        returnAux=pList->pElements[index];
        }
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement)
{
    int returnAux = -1;

    if(pList!=NULL && pElement!=NULL)
    {
        for(int i = 0; i <pList->len(pList);i++)
        {
            returnAux=0;

            if(*(pList->pElements+i)==pElement)
            {
            returnAux=1;
            break;
            }
        }

    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)
{
    int returnAux = -1;

    if(pList!=NULL && pElement!=NULL && (index >=0 && index <= pList->size))
    {
        if(index==pList->len(pList))
        {
            if(pList->add(pList,pElement)==0)
            {
            returnAux=0;
            }
        }

        else
        {
            pList->pElements[index]=pElement;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index)
{
    int returnAux = -1;

    if(pList!=NULL && (index >=0 && index<pList->len(pList)) && pList->pElements!=NULL)
    {
        if(contract(pList,index)==0)
            {
                returnAux=0;
            }
    }


    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList)
{
    int returnAux = -1;

    if(pList!=NULL && pList->pElements!=NULL)
    {

    free(pList->pElements);
    pList->size=0;
    pList->reservedSize=AL_INITIAL_VALUE;
    pList->pElements = (void**)malloc(sizeof(void*)*AL_INITIAL_VALUE);
    returnAux = 0;
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)
{
    int returnAux = -1;

    if(pList!=NULL && (index>=0 && index <= pList->len(pList)) && pElement!=NULL)
    {

        if(index==pList->len(pList))
        {
                if(pList->add(pList,pElement)==0)
                {
                returnAux=0;
                }
        }

        else
        {
            if(expand(pList,index)==0)
            {
            pList->set(pList,index,pElement);
            returnAux=0;
            }
        }

    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement)
{
    int returnAux = -1;

    if(pList!=NULL && pElement!=NULL)
    {
        for(int i=0; i <= pList->len(pList);i++)
        {
            if(pList->pElements[i]==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }


    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)
{
    int returnAux = -1;

    if(pList!=NULL)
    {
        if(pList->len(pList)>0)
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)
{
    void* returnAux = NULL;

    if(pList!=NULL && (index>=0 && index < pList->len(pList) && pList->pElements !=NULL))
       {
           returnAux=pList->get(pList,index);
           contract(pList,index);
       }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    ArrayList* returnAux=NULL;

    void* aux = NULL;


    if(pList!=NULL && from>=0 && to <= pList->len(pList) && from < to)
    {
      returnAux=al_newArrayList();
      if(returnAux!=NULL)
      {
          for(int i=from; i < to;i++)
          {
              resizeUp(returnAux);
              aux=pList->get(pList,i);
              returnAux->add(returnAux,aux);
          }
      }
    }

    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
    int returnAux = -1;
    int counter=0;

    if(pList!=NULL && pList2 != NULL)
    {
        for(int i=0;i<pList->len(pList);i++)
        {
            for(int j=0; j<pList2->len(pList2);j++)
            {
                if(pList->pElements[i]==pList2->pElements[j])
                {
                    counter++;
                    break;
                }
            }
        }

        if(counter==pList2->len(pList2))
        {
            returnAux=1;
        }

        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* pElementAux=NULL;
    void* pElementA=NULL;
    void* pElementB=NULL;

    if(pList!=NULL && pFunc!=NULL && (order == 1 || order == 0))
    {
        for(int i=0;i<pList->len(pList)-1;i++)
        {
            for(int j=i+1; j<pList->len(pList);j++)
            {
                pElementA=pList->get(pList,i);
                pElementB=pList->get(pList,j);

                if(order==1)
                {
                    if(pFunc(pElementA,pElementB))
                    {
                        pElementAux=pList->pElements[i];
                        pList->pElements[i]=pList->pElements[j];
                        pList->pElements[j]=pElementAux;

                    }
                }

                if(order==0)
                {
                    if(pFunc(pElementA,pElementB)==-1)
                    {
                        pElementAux=pList->pElements[i];
                        pList->pElements[i]=pList->pElements[j];
                        pList->pElements[j]=pElementAux;

                    }
                }
            }
        }
        returnAux=0;
    }

    return returnAux;
}


/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList)
{
    ArrayList* returnAux = NULL;
    //void* aux=NULL;

    if(pList!=NULL)
    {
        returnAux= al_newArrayList();
        if(returnAux!=NULL)
        {
            for(int i=0;i<pList->len(pList);i++)
            {
            //resizeUp(returnAux);
            //aux=pList->get(pList,i);
            al_add(returnAux,pList->pElements[i]);
            }
        }
    }

    return returnAux;
}




ArrayList* al_filter(ArrayList* pList, int(*filtro)(void*))
{
    ArrayList* returnAux=NULL;
    if(pList!=NULL && filtro!=NULL)
    {
        returnAux=al_newArrayList();
        for(int i=0;i<pList->len(pList);i++)
        {

            if(filtro(pList->pElements[i]))
            {
                returnAux->add(returnAux,pList->pElements[i]);

            }
        }
    }
    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList)
{


    int returnAux = -1;
    void* aux=NULL;

    if(pList->size==pList->reservedSize)
    {
    aux=(void*)realloc(pList->pElements,sizeof(void*)*(pList->reservedSize+AL_INCREMENT));

        if(aux!=NULL)
        {
        pList->pElements=aux;
        pList->reservedSize+=AL_INCREMENT;
        returnAux=0;
        }


    }



    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)
{
    int returnAux = -1;

    if(pList!=NULL)
    {

    pList->size++;
    resizeUp(pList);
        for(int i = pList->size; i > index;i--)
        {
            pList->pElements[i]=pList->pElements[i-1];
        }
        returnAux=0;
    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)
{
    int returnAux = -1;

    if(pList!=NULL)
    {

    pList->size--;
        for(int i = index; i < pList->size;i++)
        {
            pList->pElements[i]=pList->pElements[i+1];
        }
        returnAux=0;
    }

    return returnAux;
}

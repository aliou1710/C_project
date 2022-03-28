/*
 * list.c
 *
 * 
 * Author: mattens
 */
/* ------------------------------------------------------------------------- */
#define __DEBUG 0
/* ------------------------------------------------------------------------- */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"
/* ------------------------------------------------------------------------- */
typedef int bool;
#define false 0
#define true 1
/* ------------------------------------------------------------------------- */
/*premiere liste*/
struct TList {
	struct __TNodeList* _pEndNode;
	size_t _nodeCount;
};

/* ------------------------------------------------------------------------- */

typedef struct __TNodeList _TNode;
typedef struct __TNodeList* _TPNode;
/*liste chainée*/
 

struct __TNodeList {
	struct __TNodeList * pPrevious;
	struct __TNodeList * pNext;
	TValueList value;
};
/* ------------------------------------------------------------------------- */
/* Declaration of prototypes of utilities funtions                           */
static _TPNode _CreateHeaderNode(){
	_TPNode element=NULL; 
                      
	element= (_TPNode)malloc(sizeof(_TNode));
	element->pPrevious = element;
	element->pNext = element;
	return element;
	}
	
	struct TList* CreateList(){
		struct TList* Lists;
		Lists->_nodeCount = 0; 
		/*pointe vers le noeud garde fou ( dernier element vide)*/
		Lists->_pEndNode = _CreateHeaderNode();
		return Lists;
	}
	
	
	
static _TPNode _CreateNode(const TValueList* pv, const _TPNode _pPrevious,const _TPNode _pNext){
			
			_TPNode	_N=NULL;
			_TPNode element= (_TPNode)malloc(sizeof(_TNode));
			element->pPrevious= _pPrevious;
			element->pNext= _pNext;
			memcpy(&(element->value), pv , sizeof(*pv));
			
			}
/* ------------------------------------------------------------------------- */
/* Definition of funtions declared in list.h                                 */
/* ...                                                                       */
TIteratorList BeginOfList(struct TList* pList){
			/*le premier element de la liste*/
			return pList->_pEndNode->pNext;
			
		}

	
TIteratorList EndOfList(struct TList* pList){	
		/*le dernier element de la listequi est le noeud garde fou*/
		return pList->_pEndNode;
			
		}
		



 TValueList* GetPDataInList(TIteratorList iter){
	  return &(iter->value);
	 }
 

	
TIteratorList PreviousInList(TIteratorList iter){
		return iter->pPrevious;	
	}
	
TIteratorList NextInList(TIteratorList iter){
		return iter->pNext;	
}


void WalkSequenceList(void (*FCallbackOnValue)(TValueList*), TIteratorList iter1,TIteratorList iter2){
	/*on doit applique cette fonction de cet iterateur là jusqu'au deuxième iterateur. la fonction =(*FCallbackOnValue)(TValueList*)*/
	TIteratorList tmp=NULL;
	tmp= iter1;
	while(tmp != iter2){
		(*FCallbackOnValue)(&(tmp->value));
		tmp = tmp->pNext;
		}
	
	}


void EraseSequenceInList(struct TList* pList, TIteratorList iter1, TIteratorList iter2){
	TIteratorList tmp =NULL;
	tmp = iter1;
	/*supprime chaque element de cette boucle*/
	while(tmp != iter2 ){
		tmp = EraseInList(pList, tmp);
		/*printf(";%d", pList->_nodeCount);*/
		}
	
	}


int IsEmptyList(struct TList* pList){
	
	if(pList->_nodeCount==0 ){
	
		return 1;
		
		}else{
			
			return 0;
			}
			
	}
	
	
int SizeOfList(struct TList* pList){
	
	return pList->_nodeCount;
	}



TIteratorList EraseInList(struct TList* pList, TIteratorList ElementTodelete){
	
	
	
	TIteratorList tmpP=NULL;
	TIteratorList tmpN=NULL;
    
	
	tmpN= ElementTodelete->pNext;
	tmpP= ElementTodelete->pPrevious;
	
	tmpP->pNext=ElementTodelete->pNext;
	tmpN->pPrevious=ElementTodelete->pPrevious ;
	
	
	
	free(&ElementTodelete);
	pList->_nodeCount-=1;
	return tmpN;
}
void DestroyList(struct TList* pList){
	free(pList);
	}
	
	
void InsertInList(struct TList* plist, TIteratorList NextElement, TValueList* s){
	
	_TPNode	_N=NULL;
	_TPNode	element=NULL;
	/*_TPNode est un pointeur  et  _TNode est une structure (cad un noeud)*/
	element= (_TPNode)malloc(sizeof(_TNode));
	/*nextelement est l'element avant lequel on va inserer un noeur*/
	element->pNext= NextElement;
	element->pPrevious= NextElement->pPrevious;
	/*je copie le contenu de s dans element->value*/
	memcpy(&(element->value), s , sizeof(*s));
	
	_N = NextElement->pPrevious;
	 NextElement->pPrevious=element;
	_N->pNext =  element;
	
	
	plist->_nodeCount+=1 ;
	}
/* ...                                                                       */
/* ...                                                                       */
/* ------------------------------------------------------------------------- */
/* Definition of utilities funtions                                          */
/* ...                                                                       */
/* ...                                                                       */
/* ...                                                                       */
/* ------------------------------------------------------------------------- */


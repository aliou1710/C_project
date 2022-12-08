/*
 * tree.c
 *
 *  Created on:
 *  Author: 
 */
/* ------------------------------------------------------------------------- */
#define __DEBUG 0
/* ------------------------------------------------------------------------- */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"
#include "allocator.h"
/* ------------------------------------------------------------------------- */
typedef int bool;
#define false 0
#define true 1

typedef int checkleft;
#define checkleftfalse 0
#define checklefttrue 1
/* ------------------------------------------------------------------------- */
struct TTree {
	struct __TNodeTree* _header;
	size_t _nodeCount;
	TKeyOf _KeyOf;
	TComp _KeyCompare;
	struct TAllocator* _pAllocator;
};
/* ------------------------------------------------------------------------- */
typedef struct __TNodeTree _TNode;
typedef struct __TNodeTree* _TPNode;
enum __TColorType {
	_ctRed, _ctBlack
};
typedef enum __TColorType _TColorType;
struct __TNodeTree {
	_TColorType color;
	struct __TNodeTree * pParent;
	struct __TNodeTree * pLeft;
	struct __TNodeTree * pRight;
	TValueTree value;
};
/* ------------------------------------------------------------------------- */
/* Declaration of prototypes of utilities funtions                           */



/* ...                                                                       */
/* ...                                                                       */
/* ...                                                                       */

static _TPNode _CreateNode(const TValueTree* pv, const _TPNode _pParent,
		const _TPNode _pLeft, const _TPNode _pRight, _TColorType _color,
		struct TAllocator* pAllocator);
static _TPNode _CreateHeaderNode(struct TAllocator* pAllocator);
static void _RecurInfix(_TPNode iter);
/* ------------------------------------------------------------------------- */
static void __RecurPrefix(_TPNode iter);
static void __RecurPostfix(_TPNode iter);
static int __GetRecurDeep(_TPNode iter);
static _TPNode __GetNodeByLevelAndNumber(_TPNode iter, int level, int number);
/* ------------------------------------------------------------------------- */
static bool _isCallOnLeave = false;
static FCallbackOnValue _fCallbackInfix = 0;
static FCallbackOnValue __fCallbackPrefix = 0;
static FCallbackOnValue __fCallbackPostfix = 0;
/* ------------------------------------------------------------------------- */
/* Definition of funtions declared in tree.h                                 */



struct TTree* CreateTree(TKeyOf TkeyOf , TComp compare){
		struct TTree* tree =  malloc(sizeof(struct TTree));
		
		tree->_nodeCount = 0;
		tree->_pAllocator=CreateAllocator(sizeof(_TNode));
		tree->_KeyCompare=compare;
		tree->_KeyOf = TkeyOf;

		/*pointe vers le noeud garde fou ( dernier element vide)*/
		tree->_header= _CreateHeaderNode(tree->_pAllocator);
		return tree;
	}

int IsEmptyTree(struct TTree* pTree){ 

	if(pTree->_nodeCount==0 ){
	
		return 1;
		
		}else{
			
			return 0;
			}
}


_TPNode _Root(struct TTree* pTree){
	
	return   pTree->_header->pParent;
	
	}

	static _TPNode _CreateNode(const TValueTree* pv, const _TPNode _pParent,const _TPNode _pLeft, const _TPNode _pRight, _TColorType _color,
struct TAllocator* pAllocator){
	
	_TPNode element=NULL; 
	/*element = Allocate(pAllocator);*/
	element= (_TPNode)malloc(sizeof(_TNode));
	element->value=*pv;
	element->pLeft=_pLeft;
	element->pRight =_pRight;
	element->pParent = _pParent;
	element->color = _color;
	
	 
	return element;
	/*_TPNode element=NULL; 
	element = Allocate(pAllocator);

	element->value= data;
	element->pParent = parent;
	element->pLeft = NULL;
	element->pRight = NULL;*/
	
	}


static _TPNode _CreateHeaderNode(struct TAllocator* pAllocator){
	
	_TPNode element=NULL; 
                      
	element = Allocate(pAllocator);
	memset(&(element->value), 0 , sizeof(TValueTree));
	element->pParent = NULL;
	element->pLeft = element;
	element->pRight = element;
	
	return element;
	}

TIteratorTree BeginOfTree(struct TTree* pTree){

			return pTree->_header->pLeft;	
	}
TIteratorTree EndOfTree(struct TTree* pTree){

			return pTree->_header->pRight;
	}

TIteratorTree NextInTree(TIteratorTree tree){
	
	TIteratorTree it =NULL;
	it = tree;
	/*on verifie s'il y a un element à droite*/
	if(it->pRight != NULL){
		/*it devient l'element à droite (node en question) */
		it = it->pRight;
		/*on choisit l'enfant le plus (bas) à gauche de l'enfant de droite => it est donc à droite */
		while(it->pLeft != NULL && it->pLeft != it){
			/*on descend en profondeur jusqu'à trouvé le dernier element à gauche*/
			it= it->pLeft;
			}
			return it;
		
		
		}else{
		/*donc it->pRight == NULL  donc l'element est à gauche*/
		/*tant qu'on est pas l'enfant qui se trouve à gauche , mais aussi différent du noeud parent , on monte*/
		/*it = it->pParent->pLeft ==> signifie que l'enfant est lui même à gauche*/
			while( (it != it->pParent->pLeft) &&  (it != it->pParent->pParent)){
					it = it->pParent;
				}
			return it->pParent;
			
			}
	
	}
		
TIteratorTree PreviousInTree(TIteratorTree tree){
	
	TIteratorTree it =NULL;
	it = tree;
	if(it->pLeft != NULL){
		it = it->pLeft;
		while(it->pRight != NULL && it->pRight != it){
			
			it= it->pRight;
			}
			return it;
		
		
		}else{
			
			while( (it != it->pParent->pRight) &&  (it != it->pParent->pParent)){
					it = it->pParent;
				}
			return it->pParent;
			
			}
	}
size_t SizeOfTree(struct TTree* pTree){
		return pTree->_nodeCount;
	}

const void* GetKeyInTree( struct TTree* pTree, TIteratorTree it){
			return pTree->_KeyOf(&(it->value));
	}
	
TValueTree* GetPDataInTree(TIteratorTree it){
	return  &(it->value);
	}
	
	
	
	
	
void InsertInTree(struct TTree* pTree, TValueTree* data){
		_TPNode it =NULL;
		_TPNode element=NULL;
		int boolcompare = 0;
		it = _Root( pTree);
		
		/*check si c'est un root ou pas*/
		 if(it == NULL){
			/*creer un noeud*/
			pTree->_header->pParent= _CreateNode(data, pTree->_header,NULL, NULL, _ctRed,pTree->_pAllocator);
			pTree->_nodeCount+=1 ;
			/*on repositionne les pointeurs du dernier element à gauche et dernier element à droite */
			pTree->_header->pLeft = pTree->_header->pParent;
			pTree->_header->pRight = pTree->_header->pParent;
			

	
		}else{
		 /*on verifie que le dernier element inséré est tout à gauche ou tout à droite*/
		int boolchecksideLastLeft = true;	
		int boolchecksideLastRight = true;		
		
		while(true){
			/*keyof permet d'extraire la clé*/
		TKeyTree key1 = pTree->_KeyOf(&(it->value));
		TKeyTree key2 =  pTree->_KeyOf(data);
	
		
		boolcompare = pTree->_KeyCompare(key2,key1);
		
		
	 if(boolcompare == 1 ){
		 /*cvd key2<key1 -> il va a gauche*/ 
		 boolchecksideLastRight= false;
			if(it->pLeft != NULL){
			
				it = it->pLeft;
				}else{
					
				   /*on cree le node
				   )
	               /*_TPNode est un pointeur  et  _TNode est une structure (cad un noeud)*/
	               element= (_TPNode)malloc(sizeof(_TNode));
	                /*nextelement est l'element avant lequel on va inserer un noeur*/
					element->pParent= it;
					element->pParent->pLeft = element;
				
					
					element->pLeft = NULL;
					element->pRight=NULL;
					element->value = *data;
					
					
					if(boolchecksideLastLeft==true){
						pTree->_header->pLeft=element;
					}
					pTree->_nodeCount+=1 ;
					break;
					}
		 }else if (boolcompare ==0 ){
			 /*cvd  key2 > key1  il va à droite */
			 boolchecksideLastLeft= false;
			if(it->pRight != NULL){
				/*while*/
				
				it = it->pRight;
				}else{
					
					
					
	               /*_TPNode est un pointeur  et  _TNode est une structure (cad un noeud)*/
	               element= (_TPNode)malloc(sizeof(_TNode));
	                /*nextelement est l'element avant lequel on va inserer un noeur*/
					element->pParent= it;
					
					element->pParent->pRight = element;
					
					
					
					element->pLeft = NULL;
					
					element->pRight=NULL;
					element->value = *data;
					/*memcpy(&(element->value), data , sizeof(*data));*/
					if(boolchecksideLastRight ==true){
					  pTree->_header->pRight=element;
					}
					pTree->_nodeCount+=1 ;
					
					break;
					}	
		}
		}
		}
	}
	
TIteratorTree LowerBoundInTree(struct TTree* pTree,TKeyTree key){
	
	TIteratorTree endOfTree =	EndOfTree(pTree);
	TIteratorTree beginOfTree = BeginOfTree(pTree);
    
    while(pTree->_KeyCompare(pTree->_KeyOf(&beginOfTree->value), key) && beginOfTree != endOfTree)
        beginOfTree = NextInTree(beginOfTree);
    return beginOfTree;
	}
	
	
TIteratorTree UpperBoundInTree(struct TTree* pTree,TKeyTree key){
	
	 TIteratorTree endOfTree =	EndOfTree(pTree);
	TIteratorTree beginOfTree = BeginOfTree(pTree);
    
    while((!pTree->_KeyCompare(key, pTree->_KeyOf(&beginOfTree->value))) && beginOfTree != endOfTree)
        beginOfTree = NextInTree(beginOfTree);
    return beginOfTree;
	}
	
	
	

void ErasekeyInTree(struct TTree* pTree, TKeyTree key){
	TIteratorTree it =NULL;
		int boolcompare = 0;
		it=BeginOfTree(pTree);
	while(true){
		TKeyTree keyIntree = pTree->_KeyOf(&(it->value));
		/*savoir si la clé est la meme qu'une des clés de l'arbre*/
		if( keyIntree == key) {
			EraseInTree(pTree,it);
			break;
		}else{
				
				it = NextInTree(it);
			}		
     }
	
	}
	
void EraseKeysInTree(struct TTree* pTree, TKeyTree keys){
	 /*on commence avec le noeud qui est tout a gauche */
	 TIteratorTree it =pTree->_header->pLeft;
	 

    if(it != pTree->_header) {
		/*on verifie que les clés soient les mêmes avant de supprimer*/
        while(pTree->_KeyOf(&it->value) == keys) {
			it = EraseInTree(pTree, it);
			
        }
    }
}

void EraseSequenceInTree(struct TTree* pTree, TIteratorTree iter1, TIteratorTree iter2){
	
	TIteratorTree tmp =NULL;
	tmp = iter1;
	/*supprime chaque element de cette boucle*/
	while(tmp != iter2 ){
		tmp = EraseInTree(pTree, tmp);
		/*printf(";%d", pList->_nodeCount);*/
		}
	
	}

TIteratorTree EraseInTree(struct TTree* pTree,TIteratorTree elementToDelete){
	
    TIteratorTree nextintree = NextInTree(elementToDelete);
    TIteratorTree previntree = PreviousInTree(elementToDelete);

   
    if(elementToDelete == pTree->_header->pLeft) 
        previntree = pTree->_header;

   /*on verifie que l'element n'a pas d'enfant*/
    if(  elementToDelete->pRight == NULL && elementToDelete->pLeft == NULL) {

        /**je verifie que c'est le root**/
        if(pTree->_header->pRight == pTree->_header->pLeft) {
            pTree->_header->pParent = NULL;
			 pTree->_header->pRight = pTree->_header;
            pTree->_header->pLeft = pTree->_header;
           
        }

       /* Je verifie que l'element est à gauche*/
        if(elementToDelete->pParent->pLeft == elementToDelete) {
            elementToDelete->pParent->pLeft = NULL; 
            if(pTree->_header->pLeft == elementToDelete)
                /*pleft va pointer sur le noeud suivant de elementTodelete*/
				pTree->_header->pLeft = nextintree;
        }
        /* Je verifie que l'element est à droite*/
	   else if(elementToDelete->pParent->pRight == elementToDelete) {
            elementToDelete->pParent->pRight = NULL; 
            if(pTree->_header->pRight == elementToDelete) {
                pTree->_header->pRight = previntree;
            }
        }
       

      
    }
	/* Dans le cas où l'element a un enfant*/
	 /* Je verifie que l'element est à gauche*/
    else if(elementToDelete->pLeft != NULL && elementToDelete->pRight == NULL) {

        
        /*Si l'element est à gauche*/
         if(elementToDelete->pParent->pLeft == elementToDelete) {
            elementToDelete->pParent->pLeft = elementToDelete->pLeft;   
            elementToDelete->pLeft->pParent = elementToDelete->pParent;
        }
        /* Sinon l'element se trouve à droite*/
        else if(elementToDelete->pParent->pRight == elementToDelete) {
            elementToDelete->pParent->pRight = elementToDelete->pLeft; 
            elementToDelete->pLeft->pParent = elementToDelete->pParent;
        }
		/*je verifie si je suis le root*/
        else if(elementToDelete->pParent->pParent == elementToDelete) {
            elementToDelete->pParent->pParent = elementToDelete->pLeft; 
            elementToDelete->pLeft->pParent = elementToDelete->pParent;
        }

        /* mettre a jour la fin d'arbre */
        if(pTree->_header->pRight == elementToDelete) {
            pTree->_header->pRight = previntree;
        }
    }
  /* Je verifie que l'element est à gauche*/
    else if(elementToDelete->pRight != NULL && elementToDelete->pLeft == NULL) {

        /* Si je suis le root*/
        if(elementToDelete->pParent->pParent == elementToDelete) {
            elementToDelete->pParent->pParent = elementToDelete->pRight;
            elementToDelete->pRight->pParent = elementToDelete->pParent;
        }
       /*Sinon l'element est à gauche*/
        else if(elementToDelete->pParent->pLeft == elementToDelete) {
            elementToDelete->pParent->pLeft = elementToDelete->pRight; 
            elementToDelete->pRight->pParent = elementToDelete->pParent;
        }
         /* Sinon l'element se trouve à droite*/
        else if(elementToDelete->pParent->pRight == elementToDelete) {
            elementToDelete->pParent->pRight = elementToDelete->pRight; 
            elementToDelete->pRight->pParent = elementToDelete->pParent;
        }

		/* mettre a jour la fin d'arbre */
        if(pTree->_header->pLeft == elementToDelete)
            pTree->_header->pLeft = nextintree;
    }

    
     /* Sinon on verifie que l'element a deux enfants*/
    else {
        /* mon suivant prends ma place puisque y a un trou*/
        elementToDelete->pLeft->pParent = nextintree;
        nextintree->pLeft = elementToDelete->pLeft; 
        elementToDelete->pRight->pParent = elementToDelete->pParent; 
		

        if(elementToDelete == elementToDelete->pParent->pParent) {
            elementToDelete->pParent->pParent = elementToDelete->pRight; 
        } else if(elementToDelete == elementToDelete->pParent->pLeft) 
            elementToDelete->pParent->pLeft = elementToDelete->pRight; 
        else
            elementToDelete->pParent->pRight = elementToDelete->pRight; 
    }

	/*maj*/
    if(pTree->_header->pLeft == elementToDelete)
        pTree->_header->pLeft = nextintree;
    if(pTree->_header->pRight == elementToDelete) { 
		previntree->pRight = pTree->_header; 
		pTree->_header->pRight = previntree;
		
		 
    }

    pTree->_nodeCount--; 
    Deallocate(pTree->_pAllocator, elementToDelete); 

    return nextintree; 
}



void _RecurInfix(_TPNode iter){
	/*parcours à gauche*/
	
	if( iter != NULL){
		
		if(iter->pLeft != NULL){
			_RecurInfix(iter->pLeft);
	}
		/*root*/
		/*printf("%s ",iter->value);*/
		/*printf("(%02d) ",GetPDataInTree(iter)->size);*/
		_fCallbackInfix(&iter->value);
		/*parcours à droite*/
		if(iter->pRight != NULL){
			_RecurInfix(iter->pRight);
		}	
	}
}
	
	
 void __RecurPrefix(_TPNode iter){
	
	 if( iter != NULL){
	 	
		 __fCallbackPrefix(&iter->value);
		/*printf("(%02d) ",GetPDataInTree(iter)->ptr);*/
		
		/*parcours à gauche*/
	if(iter->pLeft != NULL){
		__RecurPrefix(iter->pLeft);
	}
	
	/*parcours à droite*/
	if(iter->pRight != NULL){
		__RecurPrefix(iter->pRight);
	}
 }
 }
	 
	 
 void __RecurPostfix(_TPNode iter){
	 
	 if( iter != NULL){
	 /*parcours à gauche*/
	if(iter->pLeft != NULL){
		__RecurPostfix(iter->pLeft);
	}
	

	/*parcours à droite*/
	if(iter->pRight != NULL){
		__RecurPostfix(iter->pRight);
	}
	
	/*root*/
	/*printf("%s ",iter->value);*/
	/*printf("(%02d) ",GetPDataInTree(iter)->size);*/
	 __fCallbackPostfix(&iter->value);
	 }
 }
	 
	 
int __GetRecurDeep(_TPNode iter){
		
	 int deeplevelLeft, deeplevelRight;

    if(iter->pRight != NULL) {
        deeplevelRight = __GetRecurDeep(iter->pRight);
    } else {
        deeplevelRight = 0;
    }
	
	if(iter->pLeft != NULL) {
        deeplevelLeft = __GetRecurDeep(iter->pLeft);
    } else {
        deeplevelLeft = 0;
    }
	
    if(deeplevelLeft >= deeplevelRight) {
        return ++deeplevelLeft;
    } else {
        return ++deeplevelRight;
    }
	
	}
	 
	 
	
_TPNode  __RecurPrefixBIS(_TPNode iter, int level,int count,int countBis,int number){
	
	
			
	if( iter != NULL){
	 	printf("%s ",&iter->value);
		/*parcours à gauche*/
		if(iter->pLeft != NULL){
		  count++;
		  countBis++;
		__RecurPrefixBIS(iter->pLeft,level, count,countBis , number);
		}
	
	/*parcours à droite*/
	if(iter->pRight != NULL){
		count++;
		countBis++;
		__RecurPrefixBIS(iter->pRight, level, count,countBis , number);
	}
	
	if( countBis == number){
		return iter;
		}
 }
 }
 
 /*
_TPNode __GetNodeByLevelAndNumber(_TPNode iter, int level, int number){
		
	return __RecurPrefixBIS(iter,  level,0,0,number);
	}
*/
_TPNode __GetNodeByLevelAndNumber(_TPNode iter, int level, int number) {
    if(!iter)       return NULL;
    if(level == 0)  return iter;

    if (number / (1 << (level -1))==0)
        return __GetNodeByLevelAndNumber(iter->pLeft,level-1, number % (1<<(level -1)));
    else {
        if(iter->pRight && iter->pRight->pRight != iter)
            return __GetNodeByLevelAndNumber(iter->pRight,level-1, number % (1<<(level -1)));
        else
            return __GetNodeByLevelAndNumber(NULL,level-1, number % (1<<(level -1)));
    }
}

/* ...                                                                       */
/* ...                                                                       */
/* ...                                                                       */

void WalkTree(struct TTree* pTree, FCallbackOnValue fCallBack) {
	_fCallbackInfix = fCallBack;
	_isCallOnLeave = false;
	_RecurInfix(_Root(pTree));
}

void DestroyTree(struct TTree* pTree) {
	if (pTree && pTree->_header) {
		EraseSequenceInTree(pTree, BeginOfTree(pTree), EndOfTree(pTree));
		Deallocate(pTree->_pAllocator, pTree->_header);
		pTree->_header = NULL;
	}
	if (pTree) {
#if __DEBUG>0
		if (GetNumberAllocated(pTree->_pAllocator) != 0)
			printf("Some memory not deallocated");
#endif
		DestroyAllocator(pTree->_pAllocator);
		free(pTree);
	}
}
/* ------------------------------------------------------------------------- */
void __ShowPrefixTree(struct TTree* pTree, FCallbackOnValue fShowValue,
		int isCallOnLeave) {
	_isCallOnLeave = isCallOnLeave;
	__fCallbackPrefix = fShowValue;
	printf("__ShowPrefixTree -> ");
	__RecurPrefix(_Root(pTree));
	printf("\n");
}

void __ShowInfixTree(struct TTree* pTree, FCallbackOnValue fShowValue,
		int isCallOnLeave) {
	_isCallOnLeave = isCallOnLeave;
	_fCallbackInfix = fShowValue;
	printf("__ShowInfixTree -> ");
	_RecurInfix(_Root(pTree));
	printf("\n");
}

void __ShowPostfixTree(struct TTree* pTree, FCallbackOnValue fShowValue,
		int isCallOnLeave) {
	_isCallOnLeave = isCallOnLeave;
	__fCallbackPostfix = fShowValue;
	printf("__ShowPostfixTree -> ");
	__RecurPostfix(_Root(pTree));
	printf("\n");
}

void __ShowLevelTree(struct TTree* pTree, FCallbackOnValue fShowValue,
		int width) {
	int deep = __GetRecurDeep(pTree->_header->pParent);
	int nodesInLevel, level, number;
	int halfSpaceLength;
	int cc, chs;
	_TPNode pn;

	static char t1[] = "";
	static char t2[] = " ";
	const char * trailer;
	int halfWidth;
	char* halfSpace=NULL;
	if (width % 2 == 0) {
		halfWidth = (width + 2) / 2;
		trailer = t2;
	} else {
		halfWidth = (width + 1) / 2;
		trailer = t1;
	}
	halfSpace = calloc(halfWidth + 1, sizeof(char));
	if (!halfSpace)
		exit(1);
	for (cc = 0; cc < halfWidth; ++cc)
		halfSpace[cc] = ' ';
	halfSpace[cc] = '\0';

	puts("__ShowByLevels ->");

	for (level = 0, nodesInLevel = 1, halfSpaceLength = (1 << (deep - 1)) - 1; level
			< deep; ++level, nodesInLevel <<= 1, halfSpaceLength >>= 1) {
		for (number = 0; number < nodesInLevel; ++number) {
			pn = __GetNodeByLevelAndNumber(_Root(pTree), level, number);
			for (chs = 0; chs < halfSpaceLength; ++chs)
				printf(halfSpace);
			if (pn) {
				fShowValue(&pn->value);
				pn->color == _ctBlack ? printf("B") : printf("R");
			} else {
				fShowValue(NULL);
				printf(" ");
			}
			printf(trailer);
			for (chs = 0; chs < halfSpaceLength; ++chs)
				printf(halfSpace);
		}
		printf("\n");
	}
	free(halfSpace);
}
/* ------------------------------------------------------------------------- */
/* Definition of utilities funtions                                          */
/* ...                                                                       */
/* ...                                                                       */
/* ...                                                                       */

/* ------------------------------------------------------------------------- */

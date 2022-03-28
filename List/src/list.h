/*
 * list.h
 *
 * 
 * Author: mattens
 */

#ifndef LIST_H_
#define LIST_H_
/* ------------------------------------------------------------------------- */
#include <stddef.h>
#include "tforlist.h"
/* ------------------------------------------------------------------------- */
typedef void (*FCallbackOnValue)(TValueList*);
/* ------------------------------------------------------------------------- */
struct TList;
struct __TNodeList;
typedef struct __TNodeList* TIteratorList;
/* ------------------------------------------------------------------------- */
/* TODO ...  declaration de toute les methodes publiques*/
 TIteratorList BeginOfList(struct TList* pList);
TIteratorList EndOfList(struct TList* pList);

 TValueList* GetPDataInList(TIteratorList iter);
struct TList* CreateList();
TIteratorList PreviousInList(TIteratorList iter);
TIteratorList NextInList(TIteratorList iter);
void WalkSequenceList(void (*FCallbackOnValue)(TValueList*)
, TIteratorList iter1,TIteratorList iter2);
void  EraseSequenceInList(struct TList* pList, TIteratorList iter1, TIteratorList iter2);
int IsEmptyList(struct TList* pList);
int SizeOfList(struct TList* pList);
TIteratorList EraseInList(struct TList* List, TIteratorList ElementTodelete);
void DestroyList(struct TList* pList);
void InsertInList(struct TList* ListToAdd, TIteratorList NextElement, TValueList* s);
/* ------------------------------------------------------------------------- */
#endif /* LIST_H_ */

/*
 * tree.h
 *
 *  Created on: 19-févr.-2009
 *      Author: mattens
 */
/* ------------------------------------------------------------------------- */
#ifndef TREE_H_
#define TREE_H_
/* ------------------------------------------------------------------------- */
#include <stddef.h>
#include "tfortree.h"
#include "allocator.h"
/* ------------------------------------------------------------------------- */
typedef TKeyTree (*TKeyOf)(const TValueTree*);
typedef int (*TComp)(TKeyTree, TKeyTree);
typedef void (*FCallbackOnValue)(TValueTree*);
/* ------------------------------------------------------------------------- */
struct TTree;
struct __TNodeTree;
typedef struct __TNodeTree* TIteratorTree;
/* ------------------------------------------------------------------------- */

struct TTree* CreateTree(TKeyOf TkeyOf , TComp compare);
int IsEmptyTree(struct TTree* pTree);
TIteratorTree BeginOfTree(struct TTree* pTree);
TIteratorTree EndOfTree(struct TTree* pTree);


TIteratorTree NextInTree(TIteratorTree tree);
TIteratorTree PreviousInTree(TIteratorTree tree);
size_t SizeOfTree(struct TTree* pTree);

const void* GetkeyInTree( struct TTree* pTree, TIteratorTree it);
TValueTree* GetPDataInTree(TIteratorTree it);
void InsertInTree(struct TTree* pTree, TValueTree* data);
TIteratorTree LowerBoundInTree(struct TTree* pTree,TKeyTree  key);
TIteratorTree UpperBoundInTree(struct TTree* pTree,TKeyTree key);
void EraseKeysInTree(struct TTree* pTree, TKeyTree keys);
void ErasekeyInTree(struct TTree* pTree, TKeyTree key);
void WalkTree(struct TTree* pTree, FCallbackOnValue fCallBack);
void DestroyTree(struct TTree* pTree);
void EraseSequenceInTree(struct TTree* pTree, TIteratorTree iter1, TIteratorTree iter2);

TIteratorTree EraseInTree(struct TTree* pTree,TIteratorTree ElementTodelete);

/* TODO ...                                                                  */
/* ------------------------------------------------------------------------- */
void __ShowPrefixTree(struct TTree* pTree, FCallbackOnValue fShowValue,
		int isCallOnLeave);
void __ShowPostfixTree(struct TTree* pTree, FCallbackOnValue fShowValue,
		int isCallOnLeave);
void __ShowInfixTree(struct TTree* pTree, FCallbackOnValue fShowValue,
		int isCallOnLeave);
void __ShowLevelTree(struct TTree* pTree, FCallbackOnValue fShowValue,
		int width);
/* ------------------------------------------------------------------------- */
#endif /* TREE_H_ */

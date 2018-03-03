#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bstree.h"


/* debugg define */
#define DEBUG 1 
#ifdef DEBUG
#define dbprint printf
#else
#define dbprint printf
#endif

/* Class for creating the actual BSTree. */
 
/* Create a new tree head pointing to 0 */
BSTree *bstAlloc()
{
  BSTree *bst = (BSTree *)malloc(sizeof(BSTree));
  bst -> head =bst->cur = 0;

  return bst;
}

/* Add element and key to element in BSTree */
void bstAdd(BSTree *bst, char *i)
{
  dbprint("Name received is %s \n", i);
  /* Set up variables */
  BSTItem *treeN;           /* Local copy of the tree node to test with */
  char *icopy;              /* Local copy of the name passed in */
  BSTItem *b;               /* Bstree node that will be saved */
  int length;               /* Length of the name passed in */
  int cond;
  int loopExit = 0;        /* Int to indicate we need to exit the loop */

  /* Setting the head to begin at the top */
  treeN = bst->head;

  /* Find length of the name passed in */
  for(length=0; i[length]; length++)
    ;
  dbprint("Length of name is %d \n", length);

  /* Allocate size and copy the name passed into local variable */
  icopy = (char *)malloc(length+1);
  for(length=0; i[length]; length++)
    icopy[length]=i[length];
  icopy[length] = 0;
  dbprint("Name copied and allocated \n");

  b = (BSTItem *)malloc(sizeof(BSTItem));
  dbprint("B Node allocated. \n");
  b->info = icopy;
  b->leftc = b->rightc = 0;
  dbprint("Information saved into new node. \n");

  /* Check if the tree is empty */
  if(!bst->head){
    bst->head = b;
    dbprint("Empty tree, node added into it. \n");
    return;
  }

  dbprint("Begin the loop for entering name into tree. \n");
  while(!loopExit){
    cond = strcmp(icopy, treeN->info);
    dbprint("Comparing with %s \n", treeN->info);
    if(cond == 0){     /* repeated value */
      dbprint("Repeated value.  \n");
      loopExit++;
    }
    else if(cond<0){     /* Looking at the left of the tree */
      if(!treeN->leftc){ 
	/* No left child add the element there */
	treeN->leftc = b;
	loopExit++;
	dbprint("Added as a left child. \n");
      }
      else{ 
	/* It is not a leaf set the value of the left child to retest the loop. */
	treeN = treeN->leftc;
	dbprint("Moving left. \n");
      }}
    else{      /* Looking at the right side of the tree */
      if(!treeN->rightc){
	/*No right child add the element there. */
	treeN->rightc = b;
	loopExit++;
	dbprint("Added as a right child \n");
      }
      else{
	/* It is not a leaf set the value of the right child to retest the loop. */
	treeN = treeN->rightc;
	dbprint("Moving right. \n");
      }}}
  return;
}

/* Print Elements of the tree */
void bstPrint(BSTItem *b)
{
  return;
}

/* Remove an element from binary search tree */
void bstRemove(BSTree *bst, char *i)
{
  return;
}

/* Auxiliary to remove the element from a tree */
void removeAux(BSTree *bst, char *i)
{
  return;
}

/* Auxiliary to add various elements into a tree */
void addTwoc(BSTree *bst, BSTItem *b)
{
  return;
}

/* Write the names into a file */
void bstWrite(BSTree *bst, char *f)
{
  return;
}

/* Reading the names from a file into a tree */
void bstReadFile(BSTree *bst, char *f)
{
  return;
}

/* Auxiliar to write a file */
void writeAux(BSTItem *b, char *i)
{
  return;
}

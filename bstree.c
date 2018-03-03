#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "bstree.h"

/* Class for creating the actual BSTree. */
 
/* Create a new tree head pointing to 0 */
BSTree *bstAlloc();
{
  BSTree *bst = (BSTree *)malloc(sizeof(BSTree));
  bst -> head =bst->cur = 0;

  return bst;
}

/* Add element and key to element in BSTree */
void bstAdd(BSTree *bst, char *i);
{
  return;
}

/* Print Elements of the tree */
void bstPrint(BSTItem *b);
{
  return;
}

/* Remove an element from binary search tree */
void bstRemove(BSTree *bst, char *i);
{
  return;
}

/* Auxiliary to remove the element from a tree */
void removeAux(BSTree *bst, char *i);
{
  return;
}

/* Auxiliary to add various elements into a tree */
void addTwoc(BSTree *bst, BSTItem *b);
{
  return;
}

/* Write the names into a file */
void bstWrite(BSTree *bst, char *f);
{
  return;
}

/* Reading the names from a file into a tree */
void bstReadFile(BSTree *bst, char *f);
{
  return;
}

/* Auxiliar to write a file */
void writeAux(BSTItem *b, char *i);
{
  return;
}

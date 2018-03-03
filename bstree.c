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
  int cond;                 /* Int to do the comparision between names */
  int loopExit = 0;         /* Int to indicate we need to exit the loop */

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

/* Print Elements of the tree the current one and then goes left then right */
void bstPrint(BSTItem *b)
{
  if(b){     /* Test if the element is empty */
    printf("%s", b->info);
    bstPrint(b->leftc);
    bstPrint(b->rightc);
  }
}

/* Remove an element from binary search tree */
void bstRemove(BSTree *bst, char *i)
{
  dbprint("Name received to remove is %s \n", i);
  /* Set up variables */
  BSTItem *treeN;          /* Local copy of the tree node to test with */
  char *icopy;             /* Local copy of the name passed in */
  int length;              /* Length of the name passed in */
  int cond;                /* Condition to compare the name itself */
  int loopExit = 0;        /* Int to indicate we need to exit the loop */
  BSTree *temp;            /* Temporary tree to assist with deletion */

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

  /* Check if the tree is empty */
  if(!bst->head){
    dbprint("Empty tree, nothing to delete. \n");
    return;
  }

  dbprint("Begin the loop for deleting the name.\n");
  while(!loopExit){
    cond = strcmp(icopy, treeN->info);
    dbprint("Comparing with %s \n", treeN->info);
    if(cond == 0){     /* Found name! */
      dbprint("Found Value! \n");
      removeAux(bst, icopy);
      loopExit++;
    }
    else if(cond<0){     /* Looking at the left of the tree */
      dbprint("Looking at the left. \n");
      if(!treeN->leftc){ 
	/* No left child name not found */
	printf("Value is not foiund in tree. \n");
	loopExit++;
      }
      else{ 
	/* It is not a leaf set the value of the left child to retest the loop. */
	treeN = treeN->leftc;
	dbprint("Moving left. \n");
      }}
    else{      /* Looking at the right side of the tree */
      dbprint("Looking at the rigth. \n");
      if(!treeN->rightc){
	/*No right child name not found. */
	printf("Value is not found in tree. \n");
	loopExit++;
      }
      else{
	/* It is not a leaf set the value of the right child to retest the loop. */
	treeN = treeN->rightc;
	dbprint("Moving right. \n");
      }}}

 return;
}

/* Auxiliary to remove the element from a tree this one does the actual work */
void removeAux(BSTree *bst, char *i)
{
  dbprint("The name is in there and we will delete. \n");

  /* Set up variables */
  BSTItem *treeN;           /* Local copy of the tree node to test with */
  int cond;                 /* Condition to determine if the value is the same */
  int loopExit =  0;        /* Int to indicate we need to exit the loop */
  BSTItem *temp;            /* Bstree node to asssit in removing node */
  BSTItem *parent;          /* Temporary node for housing the parent of the node to delete */
  int twoC;                 /* Int to determine if the node ot be dleeted has two children */


  /* Setting the head to begin at the top */
  treeN = bst->head;

  /* Check the head for the special case */
  cond = strcmp(i, treeN->info);

  /* Special case head has the elemnt */
  if(cond == 0){
    loopExit++;    /* Making sure it does not go into loop after */
    dbprint("Element is found at the head.\n");
    /* Value is in the head checking for children */
    if(!treeN->leftc){
      /* No left child */
      dbprint("No Left child. \n");
      if(!treeN->rightc){
	/* Tree only has one element set to a zero value */
	bst->head = 0;
	dbprint("Head is also leaf deleting.\n");
      }
      else{
	/* Tree only has a right child set it to the new head. */
	dbprint("Tree only has a right child, it is the new head. \n");
	bst->head=treeN->rightc;
      }}
    else if (!treeN -> rightc){
      /* Tree only has a left child */
      dbprint("Tree only has a left child, it is the new head. \n");
      bst->head = treeN->leftc;
    }
    else {
      /* Tree has two children */
      dbprint("Tree has two children.\n");
      temp = treeN->rightc;
      bst->head = treeN->leftc;
      twoC++;
    }}

  /* It is not in the head, saving the parent and seting treeN to look at the correct side */
  parent = bst->head;
  if (cond < 0){
    dbprint("Looking at the left. \n");
    treeN = treeN -> leftc;
  }
  else{
    dbprint("Looking at the right. \n");
    treeN = treeN->rightc;
  }
  /* Beginning loop */
  while(!loopExit){
    /* set new condition */
    cond = strcmp(i, treeN->info);
    if(cond == 0){
      /* Found the correct value again */
      loopExit++;
      dbprint("Found value\n");
      cond = strcmp(i, parent->info);  // Find new cond for parent
      if(!treeN->leftc){
	/* No Left child */
	if(!treeN->rightc){
	  /* Found value is on a leaf */
	  dbprint("It is in a leaf.\n");
	  /* Find out what child of parent it was and set that one to 0. */
	  if (cond < 0){
	    parent->leftc = 0;
	    dbprint("Cleared left child of parent.\n");}
	  else {
	    parent->rightc = 0;
	    dbprint("Cleared right child of parent. \n");
	  }}
	else{
	  /* Node to delete only has a right */
	  if (cond < 0){
	    /* It was on parent left child */
	    parent->leftc=treeN->rightc;
	    dbprint("Set left child of treeN to parent right child. \n");
	  }
	  else{
	    /* It was on parent right child */
	    parent->rightc=treeN->rightc;
	    dbprint("Set right child of treeN to parent right child. \n");
	  }}}
      else if (!treeN -> rightc){
	/* Node to be deleted only has a left child */
	dbprint("Deleted node only had a left child. \n");
	if (cond < 0){    /* It was to the right of parent */
	  parent->rightc = treeN -> leftc;
	  dbprint("Set parent right child to deleted node left child. \n");
	}
	else {          /* It was to the left of parent */
	  parent->leftc = treeN -> leftc;
	  dbprint("Set parent left child to deleted node left child. \n");
	}}
      else{
	/* Found item has two children */
	twoC++;
	dbprint("Found item has twho children setting the correct parent side to left child. \n");
	temp =treeN->rightc;
	if (cond < 0)
	  parent->leftc = treeN->leftc;
	else
	  parent->rightc = treeN ->leftc;
      }}
    else{
      /* Have not found correct location */
      dbprint("Still Looking. \n");
      if(cond < 0){
	dbprint("We will look left.\n");
	treeN =treeN->leftc;}
      else{
	dbprint("We will look to the right. \n");
	treeN = treeN ->rightc;}

      /* Find the corrent parent to assign to it. */
      cond = strcmp(i, parent->info);
      if (cond < 0)
	parent = parent->leftc;
      else
	parent = parent->rightc;
    }}

  if(twoC){
    /* The element had two children */
    addTwoc(bst, temp);
  }

  return;
}




/* Auxiliary to add when there is two elements that needed to be added. */
void addTwoc(BSTree *bst, BSTItem *b)
{
  dbprint("Calling to add two elements. \n");
  if(b){
    bstAdd(bst, b->info);
    addTwoc(bst, b->leftc);
    addTwoc(bst, b->rightc);
  }
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

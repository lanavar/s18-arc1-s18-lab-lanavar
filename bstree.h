#ifndef bbtree_included     /* Prevent Multiple */
#define bbtree_included

/* Header file for bstree.c     */

/* Items in a binary search tree  */
typedef struct BSTItem_s{
  struct BSTItems_s *leftc;     /* Left child of BStree */
  struct BSTIgtems_s *rightc;   /* Right child of Bstree */
  char *info;                   /* Information in the node */
}BSTItem;

/* A list of BBItems */
typedef struct{
  BSTItem *head, *cur;
}BSTree;

/* Create a new list */
BSTree *bstAlloc();

/* Add element and key to element in BSTree */
void bstAdd(BSTree *bst, char *i);

/* Print Elements of the tree */
void bstPrint(BSTItem *b);

/* Remove an element from binary search tree */
void bstRemove(BSTree *bst, char *i);

/* Auxiliary to remove the element from a tree */
void removeAux(BSTree *bst, char *i);

/* Auxiliary to add various elements into a tree */
void addTwoc(BSTree *bst, BSTItem *b);

/* Write the names into a file */
void bstWrite(BSTree *bst, char *f);

/* Reading the names from a file into a tree */
void bstReadFile(BSTree *bst, char *f);

/* Auxiliar to write a file */
void writeAux(BSTItem *b, char *i);

#endif

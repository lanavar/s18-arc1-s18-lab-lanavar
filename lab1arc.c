#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

#define MAXBUF 100       /* Maximum size of the buffer */
#define MAXSTRING 1024   /* Maximum lenght of string */
#define DEBUG 1     /* Activating debug */
#ifdef DEBUG             /* Debugging print command */
#define dbprint printf
#else dbprint /
#endif


/* Main file for the program, this is the interface where the user will be asked to select what they want to do.
   this is part of lab1 for acr1 class written by Lenin Navar */
int main()
{
  char element;                // Element to find out what 
  int choice;                  // int for the choice entered by user
  char buf[MAXBUF];               // Buffer for receiving elements
  BSTree *bst = bstAlloc();     // Make an empty tree

  /* Loop for selecting the choice by the customer */
  while(choice!=9){

    /* Display the message of options to the user */
    printf("Please select the desired choice by entering the corresponding number.  \n");
    printf("1. Add a new employee name. \n");
    printf("2. Remove an employee name. \n");
    printf("3. List all of the employee names. \n");
    printf("4. Read employee information from a file. \n");
    printf("5. Write employee information into a file. \n");
    printf("9. Exit program. \n");
    printf("Please enter your choice: ");

    /* Get information from user */
    if(fgets(buf, sizeof(buf), stdin))
      choice = atoi(buf);
 
    dbprint("%d num choice for user \n", choice, choice);
    option(choice, bst);
  }
  return 0;
}
/* Method for processing the option selected by the user */
void option(int sel, BSTree *bst){
  char *value = malloc(MAXSTRING);
  printf("You chose: %d \n", sel);

  switch(sel){
  case 1:{
    printf("Please enter the name of the employee to add: ");
    fgets(value, MAXSTRING, stdin);
    bstAdd(bst, value);
    printf("%s entered into database. \n", value);
    dbprint("It was a valid choice. Name to be stored is %s \n", value);
    break;
  }
  case 2:{
    printf("Please enter the name of the employee to delete: ");
    fgets(value, MAXSTRING, stdin);
    //bstRemove(bst, value);
    //printf("%s removed from the database. \n", value);
    dbprint("It was a valid choice. Name to be removed is %s \n", value);
    break;
  }
  case 3:{
    printf("Here is the list of the employee names: ");
    bstPrint(bst -> head);
    printf(" \n");
    dbprint("It was a valid choice. List printed.\n", value);
    break;
  }
  case 4:{
    printf("Please enter the name of the file to read: ");
    fgets(value, MAXSTRING, stdin);
    //bstReadFile(bst, value);
    //printf("The information from file %s has been saved. \n", value);
    dbprint("It was a valid choice. File to be read from: %s \n", value);
    break;
  }
  case 5:{
    printf("Please enter the name of the file to save to: ");
    fgets(value, MAXSTRING, stdin);
    //bstWrite(bst, value);
    //printf("The database was saved into file: %s. \n", value);
    dbprint("It was a valid choice. File to be saved to %s \n", value);
    break;
  }
  case 9:{
    printf("Exiting program. Thank You. \n");
    dbprint("It was a valid choice. Exiting. \n");
    break;
  }
  default: {
    printf("%d is an invalid selection. Please enter a valid one. \n", sel);
    dbprint("Invalid selection. \n");
    break;
  }
  }
}






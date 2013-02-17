#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trees.h"

// Some things should be included in the header file
#define num_nodes (20)
#define length_string (10)
char* randomchar(const int length);
void freeTree(Tnode* T);

int main()
{
    srand(time(NULL)); // seed random function
    int i;
    Tnode* tree = add_tnode(tree,randomchar(length_string));  // initialize a tree

    for(i=0; i<num_nodes; i++)   //insert random elements
        insert(tree, randomchar(length_string) );

    printTree(tree); // print the tree once
    printf("--------free from now on-----------\n");
    freeTree(tree);  // go in the right order and free the tree

//    printTree(tree);  if this line added, it shows that the free function works
    return 0;
}
char* randomchar(const int length)
{
  char a[length];
  char* p=(char*) malloc(length*sizeof(char)) ; // save the adress to a in p
  int i;
  for(i=0; i<length-1; i++)
    a[i] = (char) (  rand() % 26 +65); // choose ASCII between 65 and 90
  a[length-1]=NULL;
  p=strdup(a);       // make a copy
  return p; // returns the adress of the new generated string
}

void freeTree(Tnode* T)
{
    if (T==NULL)
    {
        return;
    }
    freeTree(T->right);
    freeTree(T->left);
    printf("%s\n", T->value);
    free(T);
}

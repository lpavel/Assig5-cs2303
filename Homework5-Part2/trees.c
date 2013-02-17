#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"trees.h"


Tnode* create_tree()
{
    Tnode* T = (Tnode*) malloc(sizeof(Tnode)); // allocate memory first
    T->right = NULL;  // initialize with NULL
    T->left = NULL;   // initialize with NULL

    return T;
}

Tnode *add_tnode(Tnode* current_tnode, char* value)
{
    current_tnode=(Tnode*) malloc( sizeof(Tnode) ); // allocate memory first
    //strcpy( current_tnode->value, value ); // put the value in the node
    current_tnode->value=strdup(value);
    current_tnode->left = NULL;           // initialize left, right
    current_tnode->right= NULL;
    return current_tnode;
}

Tnode* insert(Tnode* T, char* value)
{
    if ( !T )
        return (add_tnode(T , value));  // create the node

    else
    {
        if( strcmp(value,T->value) < 0)   // recursion to add a smaller value
            T->left=insert( T->left, value );
        else                                             // recursion to add a bigger value
            T->right=insert( T->right, value);

        return T;
    }
}

void printTree(Tnode* T)
{
    if(T == NULL)
        return;

    printTree(T->right);
    printf("%s\n", T->value);
    printTree(T->left);
}



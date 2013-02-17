#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main()
{
    Tnode* tree = add_tnode(tree,"Father");  // initialize a tree
    Tnode* a; Tnode* b; Tnode* c; Tnode* d; Tnode* e;  // just put some values
    a = add_tnode( a, "Karl");
    b = add_tnode( b, "Josh");
    c = add_tnode( c, "Andrew");
    d = add_tnode( d, "Ben");
    e = add_tnode( e, "Charles");

    insert(tree, a->value);   // insert values and prints them for testing
    insert(tree, b->value);
    printTree(tree);
    printf("-----\n");
    insert(tree, c->value);
    insert(tree, d->value);
    printTree(tree);
    printf("-----\n");
    insert(tree, e->value);
    printTree(tree);

    return 0; // success
}

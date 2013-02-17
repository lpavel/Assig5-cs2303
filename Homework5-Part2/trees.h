#ifndef TREES_H
#define TREES_H

struct Tree
{
    char* value;                //data is a string
    struct Tree* left;          // left and right are also Tree
    struct Tree* right;
};

typedef struct Tree Tnode;


/** Initiates the tree
 *@return T - the tree created
*/
Tnode* create_tree();

/** insert a node into the tree
*@param T - the tree working with
*@param value - the value to be inserted in the tree
*@return T - the unchanged node
*/

Tnode* insert(Tnode* T, char* value);

/** Creates a node to be inserted - Put its value in
 *@param current_tnode - the current node
 *@param value - the value to be inserted
 *@return current_tnode - the created tnode
 */

Tnode *add_tnode(Tnode* current_tnode, char* value);

/** prints in the order right-node-left in a descending order
 *@param T - the node to be printed
 */

void printTree(Tnode* T);

#endif

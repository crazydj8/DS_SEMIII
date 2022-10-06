#include <stdio.h>
#include <stdlib.h>

//either have an array of nodes inside the structure whose size is n
/*struct treenode{
    int data;
    struct treenode *children[MAX];
    };
*/
//or have only the oldest child linked to parents and and all other nodes are linked to oldest child
//this converts n array tree into a binary tree
/*struct treenode{
    int data;
    struct treenode *parent;
    struct treenode *sibling;
    };
*/




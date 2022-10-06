#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node{
    char data;
	int flag;
    struct node *rlink;
    struct node *llink;
}node;

node *stk[20];


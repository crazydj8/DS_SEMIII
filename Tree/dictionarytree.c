#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
typedef struct node{
	char word[25];
    char meaning[50];
	struct node *llink, *rlink;
}node;

typedef struct tree{
	node *root;
}tree;

void init(tree *p){
	p->root = NULL;
}

node *getnode(char ele[], char mng[]){
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->word, ele);
    strcpy(temp->meaning, mng);
    temp->llink = NULL;
    temp->rlink = NULL;
	return temp;
}

void insert(tree *p, char ele[], char mng[]){
	node *newnode = getnode(ele, mng);
	if(p->root == NULL){
		p->root = newnode;
		return;
	}
	node *curr = p->root, *prev = NULL;
	while(curr != NULL){
		prev = curr;
        if(strcmp(newnode->word, curr->word) == 0){
            return;
        }
		else if(strcmp(newnode->word, curr->word) > 0){
			curr = curr->rlink;
		}
		else{
			curr = curr->llink;
		}
	}
	if(strcmp(newnode->word, prev->word) > 0){
		prev->rlink = newnode;
	}
	else{
		prev->llink = newnode;
	}
}   

void inorder(node* root){
	node* temp = root;
	if(temp != NULL){
		inorder(temp->llink);
		printf("%s: %s\n", temp->word, temp->meaning);
		inorder(temp->rlink);
	}
	else{
		return;
	}
}

int main(){
    int choice;
    tree t1;
    init(&t1);
    char name[25], mean[50];
    do{
        printf("1. Insert word 2.Display 3. Search 4. Exit | Enter choice:");
        fflush(stdin);
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the word:");
                fflush(stdin);
                //scanf("%s", name);
                gets(name);
                printf("Enter the meaning:");
                fflush(stdin);
                //scanf("%[^/n]s", mean);
                gets(mean);
                insert(&t1, name, mean);
                break;
            case 2:
                inorder(t1.root);
                break;
            case 3:
                break;
            case 4:
                break;
        }
    }while(choice != 4);
    return 0;
}


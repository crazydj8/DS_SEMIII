#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *llink, *rlink;
}node;

typedef struct tree{
	node *root;
}tree;

void init(tree *p){
	p->root = NULL;
}

node *getnode(int ele){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ele;
    temp->llink = NULL;
    temp->rlink = NULL;
	return temp;
} 

void insert(tree *p, int ele){
	node *newnode = getnode(ele);
	if(p->root == NULL){
		p->root = newnode;
		return;
	}
	node *curr = p->root, *prev = NULL;
	while(curr != NULL){
		prev = curr;
		if(newnode->data > curr->data){
			curr = curr->rlink;
		}
		else{
			curr = curr->llink;
		}
	}
	if(newnode->data > prev->data){
		prev->rlink = newnode;
	}
	else{
		prev->llink = newnode;
	}
}

node *delete_t(node *root, int key){
	node *prev = NULL, *curr = root, *next = NULL, *inprev = NULL, *insucc = NULL;
	while(curr != NULL && curr->data != key){
		prev = curr;
		if(key < curr->data){
			curr = curr->llink;
		}
		else{
			curr = curr->rlink;
		}
	}
	if(curr == NULL){
		printf("Element not found\n");
		return root;
	}
	if(curr->rlink == NULL || curr->llink == NULL){
		if(curr->rlink == NULL){
			next = curr->llink;
		}
		else{
			next = curr->rlink;
		}
		if(curr == root){
			free(curr);
			return next;
		}
		if(prev->rlink == curr){
			prev->rlink = next;
		}
		else if(prev->llink == curr){
			prev->llink = next;
		}
		free(curr);
		return root;
	}
	else{
		inprev = curr;
		insucc = curr->rlink;
		while(insucc->llink != NULL){
			inprev = insucc;
			insucc = insucc->llink;
		}
		if(inprev != curr){
			inprev->llink = insucc->rlink;
		}
		else{
			inprev->rlink = insucc->rlink;
		}
		curr->data = insucc->data;
		free(insucc);
		return root;
	}
}

int find_min(node* root){
	if (root == NULL){
		return -1;
	}
	else{
		while(root->llink != NULL){
			root = root->llink;
		}
		return root->data;
	}
}

int find_max(node* root){
	if (root == NULL){
		return -1;
	}
	else{
		while(root->rlink != NULL){
			root = root->rlink;
		}
		return root->data;
	}
}

int search(node* root, int ele){
	if (root = NULL){
		return 0;
	}
	else{
		if(root->data = ele){
			return 1;
		}
		else if(ele > root->data){
			search(root->rlink, ele);
		}
		else if(ele < root->data){
			search(root->llink, ele);
		}
	}
}

void display_inorder(node* root){
	node* temp = root;
	if(temp != NULL){
		display_inorder(temp->llink);
		printf("%d\t", temp->data);
		display_inorder(temp->rlink);
	}
	else{
		return;
	}
}

void display_preorder(node* root){
	node* temp = root;
	if(temp != NULL){
		printf("%d\t", temp->data);
		display_preorder(temp->llink);
		display_preorder(temp->rlink);
	}
	else{
		return;
	}
}

void display_postorder(node* root){
	node* temp = root;
	if(temp != NULL){
		display_postorder(temp->llink);
		display_postorder(temp->rlink);
		printf("%d\t", temp->data);
	}
	else{
		return;
	}
}



//recursive program to create an unordered binary tree
node *create_bin_tree(){
	int ele;
	printf("Enter the data of element(enter -1 for NULL):");
	scanf("%d", &ele);
	if(ele == -1){
		return NULL;
	}
	node *temp = getnode(ele);
	printf("Enter the left child of %d:", temp->data);
	temp->llink = create_bin_tree();
	printf("Enter the right child of %d:",  temp->data);
	temp->rlink = create_bin_tree();
	return temp;
}


int main(){
	tree t1, t2;
	init(&t1);
	init(&t1);
	insert(&t1, 300);
	insert(&t1, 100);
	insert(&t1, 50);
	insert(&t1, 55);
	insert(&t1, 20);
	printf("Your tree in-order:\n");
	display_inorder(t1.root);
	//t1.root = delete_t(t1.root, 100);
	printf("Your tree in-order:\n");
	display_inorder(t1.root);
	printf("\nYour tree pre-order:\n");
	display_preorder(t1.root);
	printf("\nYour tree post-order:\n");
	display_postorder(t1.root);
	printf("\n");
	printf("Max = %d\n", find_max(t1.root));
	printf("Min = %d\n", find_min(t1.root));
	t2.root = create_bin_tree();
	display_inorder(t2.root);
	return 0;
}
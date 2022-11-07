#include <stdio.h>
#include <stdlib.h>

#define MAXNODE 20

typedef struct node{
    int data;
    struct node *link;
}graph;

void initg(graph **nodep, int n){
    for(int i = 1; i <= n; i++){
        nodep[i] = NULL;
    }
}

void inits(int arr[], int n){
    for(int i = 1; i <= n; i++){
        arr[i] = 0;
    }
}

void insertnode(graph **nodep, int i, int j){
    graph *newnode = (graph *)malloc(sizeof(graph));
    newnode->data = j;
    newnode->link = NULL;
    graph *curr = nodep[i];
    if(curr == NULL){
        nodep[i] = newnode;
    }
    else{
        while(curr->link != NULL){
            curr = curr->link;
        }
        curr->link = newnode;
    }
}

void create(graph **nodep, int n){
    int i, j;
    while(1){
        printf("Enter the two nodes you want to link(Enter 0 0 to stop):");
        scanf("%d %d", &i, &j);
        if(i == 0 && j == 0){
            break;
        }
        else{
            insertnode(nodep, i, j);
        }
    }
}

void dfs(graph **nodep, int visited[], int source){
    visited[source] = 1;
    printf("%d\t", source);
    int adj;
    for(graph *curr = nodep[source]; curr != NULL; curr = curr->link){
        adj = curr->data;
        if(visited[adj] == 0){
            dfs(nodep, visited, adj);
        }
    }
} 

void bfs(graph **nodep, int visited[], int source){
    int q[20], f = 0, r = -1, adj;
    visited[source] = 1;
    printf("%d\t", source);
    q[++r] = source;
    while(f <= r){
        source = q[f++];
        for(graph *curr = nodep[source]; curr != NULL; curr = curr->link){
            adj = curr->data;
            if(visited[adj] == 0){
                q[++r] = adj;
                visited[adj] = 1;
                printf("%d\t", adj);
            }
        }
    }
}

void display(graph **nodep, int n){
    graph *curr;
    for(int i = 1; i <= n; i++){
        printf("Nodes adjacent to %d are: ", i);
        curr = nodep[i];
        while(curr != NULL){
            printf("%d\t", curr->data);
            curr = curr->link;
        }
        printf("\n");
    }
}

int main(){
    graph *listnode[MAXNODE];
    int ch, n, s, visited[MAXNODE];
    do{
        printf("Options: 1. Create 2. Display 3. DFS Traversal 4. BFS Traversal 5. Exit.\nEnter Option:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the number of nodes in graph:");
                scanf("%d", &n);
                initg(listnode, n);
                create(listnode, n); 
                break;
            case 2:
                display(listnode, n);
                break;
            case 3:
                printf("Enter the source node:");
                scanf("%d", &s);
                inits(visited, n);
                printf("Traversal:\n");
                dfs(listnode, visited, s);
                for(int i = 1; i <= n; i++){
                    if(visited[i] == 0){
                        dfs(listnode, visited, i);
                    }
                }
                printf("\n");
                break;
            case 4:
                printf("Enter the source node:");
                scanf("%d", &s);
                inits(visited, n);
                printf("Traversal:\n");
                bfs(listnode, visited, s);
                for(int i = 1; i <= n; i++){
                    if(visited[i] == 0){
                        bfs(listnode, visited, i);
                    }
                }
                printf("\n");
                break;
        }
    }while(ch != 5);
    return 0;
}
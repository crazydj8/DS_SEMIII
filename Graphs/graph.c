#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20

void initd(int adjmat[][MAXSIZE], int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            adjmat[i][j] = 0;
        }
    }
}

void inits(int arr[], int n){
for(int i = 1; i <= n; i++){
        arr[i] = 0;
    }
}

void create(int adjmat[][MAXSIZE], int n){
    int i, j;
    while(1){
        printf("Enter the two nodes you want to link(Enter 0 0 to stop):");
        scanf("%d %d", &i, &j);
        if(i == 0 && j == 0){
            break;
        }
        else{
            adjmat[i][j] = 1;
        }
    }
}

void display(int adjmat[][MAXSIZE], int n){
    for(int i = 0; i <= n; i++){
        if(i == 0){
            printf("  ");
        }
        else{
            printf("%d ", i);
        }
    }
    printf("\n");
    for(int i = 1; i <= n; i++){
        printf("%d ", i);
        for(int j = 1; j <= n; j++){
            printf("%d ", adjmat[i][j]);
        }
        printf("\n");
    }
}

void dfs(int adjmat[][MAXSIZE], int *visited, int n, int source){
    visited[source] = 1;
    printf("%d\t", source); 
    for(int i = 1; i <= n; i++){
        if(adjmat[source][i] == 1 && visited[i] == 0){
            dfs(adjmat, visited, n, i);
        }
    }
}

void bfs(int adjmat[][MAXSIZE], int *visited, int n, int source){
    
}

int main(){
    int adjmat[MAXSIZE][MAXSIZE], visited[MAXSIZE];
    int ch, n, s;
    do{
        printf("Options: 1. Create 2. Display 3. DFS Traversal 4. BFS Traversal 5. Exit.\nEnter Option:");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter the number of nodes in graph:");
                scanf("%d", &n);
                initd(adjmat, n);
                create(adjmat, n);
                break;
            case 2:
                display(adjmat, n);
                break;
            case 3:
                printf("Enter the source node:");
                scanf("%d", &s);
                inits(visited, n);
                printf("Traversal:\n");
                dfs(adjmat, visited, n, s);
                for(int i = 1; i <= n; i++){
                    if(visited[i] == 0){
                        dfs(adjmat, visited, n, i);
                    }
                }
                printf("\n");
                break;
            case 4:
                printf("Enter the source node:");
                scanf("%d", &s);
                inits(visited, n);
                printf("Traversal:\n");
                bfs(adjmat, visited, n, s);
                break;
        }
    }while(ch != 5);
    return 0;
}
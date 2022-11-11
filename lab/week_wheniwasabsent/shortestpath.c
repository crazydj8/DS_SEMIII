#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 50
#define INFINITY 9999

typedef struct graph {
int n; /* Number of vertices in graph */
int adj[MAX_NODES][MAX_NODES]; /* Adjacency matrix */
} Graph;

//creates the graph
void create_graph(Graph * adj_mat)
    {
        
        int i, j;
        for (int i = 0; i < adj_mat->n; ++i)
        {
            for (int j = 0; j < adj_mat->n; ++j)
            {
                adj_mat->adj[i][j] = 0;
            }
        }
        while (1)
        {
            //edge between two vertex
            scanf("%d %d\n", &i, &j);
            if (i < 0 && j <= 0 || i >= adj_mat->n || j >= adj_mat->n)
            {
                break;
            }
            adj_mat->adj[i][j] = 1;
        }
    }
//helper functions for inserting an element into a queue 
void append(int *queue, int v, int *pqr)
{
    ++(*pqr);
    queue[*pqr] = v;
}
//helper function to delete from a queue 
int delete (int *queue, int *pqr)
{
    int res = queue[0];
    for (int i = 0; i < *pqr; ++i)
    {
        queue[i] = queue[i + 1];
    }
    --(*pqr);
    return res;
}

//bfs function to calculate the minimum distance 
//You are required to complete this function
int find_dist(Graph * adj_mat, int source, int dest)
{
    int q[MAX_NODES];
    int end=-1;
    int* pqr=&end;
    int vis[adj_mat->n];
    for(int j=0;j<adj_mat->n;j++){
        vis[j]=0;
    }
    append(q,source,pqr);
    int i,k, b=0;
    while((*pqr)!=-1){
        k=(*pqr)+1;
        i=q[0];
        vis[i]=1;
        for(int c=0;c<k;c++){
            for(int j=0;j<adj_mat->n;j++){
                if(adj_mat->adj[i][j] && !vis[j]){
                    vis[j]=1;
                    append(q,j,pqr);
                }
            }
            if(delete(q,pqr)==dest)
                return b;
            i=q[0];
        }
        b++;
    }
    return -1;    
}

int main()
{
    Graph adj_mat;

    int source, dest;

    //number of vertex
    scanf("%d\n", &adj_mat.n);
    // creates adj matrix
    create_graph(&adj_mat);

    //source vertex
    scanf("%d\n", &source);

    //destination vertex
    scanf("%d", &dest);
    
    int result = find_dist(&adj_mat, source, dest);
    printf("%d",result);
    return 0;
}
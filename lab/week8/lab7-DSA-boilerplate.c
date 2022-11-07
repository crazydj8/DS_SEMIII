#include<stdlib.h>
#include<stdio.h>

/*edge list structure for each edge */
typedef struct{
    unsigned int first;
    unsigned int second;
}edge;

void init(int visited[], unsigned int order){
    for(int i = 0; i < order; i++){
        visited[i] = 0;
    }
}

unsigned int cycle_finder(const edge *edges , unsigned int n, unsigned int order, int i, int visited[])
{   
    visited[edges[i].first] = 1;
    int x = 0;
    for(int j = 0; j < n; j++){
        if(edges[i].second == edges[j].first){
            if(visited[edges[j].first] == 0){
                x = cycle_finder(edges, n, order, j, visited);
            }
            else{
                x = 1;
            }
        }
    }
    return x;
}

/* DO NOTE THAT THE GRAPH TRAVERSAL IN THIS QUESTION ALWAYS STARTS WITH NODE 0  so you need not take any input for starting node */
int main(void)
{
    unsigned int order;  /* number of vertices */
    unsigned int n; /* number of edges */
    scanf("%d", &n);
    scanf("%d", &order);
    int visited[order + 1];
    init(visited, order);
    edge *edges;
    unsigned int ans;
    edges = malloc(n*sizeof(edge));
    if(edges==NULL)
    {
        return 1;
    }
    for(int i=0;i<n;++i)
    {
        scanf("%d", &edges[i].first);
        scanf("%d", &edges[i].second);
    }
    ans = cycle_finder(edges, n, order, 0, visited);
    for(int i = 0; i < n; i++){
        if(visited[edges[i].first] = 0){
            ans = cycle_finder(edges, n, order, i, visited);
        }
    }
    printf("\n");
    printf(ans? "cyclic":"acyclic");
    free(edges);
    return 0;

}
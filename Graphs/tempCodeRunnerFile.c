    printf("Enter the source node:");
                scanf("%d", &s);
                inits(visited, n);
                printf("Traversal:\n");
                bfs(listnode, visited, n, s);
                for(int i = 1; i <= n; i++){
                    if(visited[i] == 0){
                        bfs(listnode, visited, n, i);
                    }
                }
                printf("\n");
                break;
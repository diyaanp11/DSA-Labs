#include <stdio.h>

int graph[4][4] = {
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,1},
    {0,1,1,0}
};

int visited[4];

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for(int i=0;i<4;i++) {
        if(graph[v][i] && !visited[i])
            dfs(i);
    }
}

int main() {
    dfs(0);
    return 0;
}
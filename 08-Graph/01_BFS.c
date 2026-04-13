#include <stdio.h>

int main() {
    int graph[4][4] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,0}
    };

    int visited[4] = {0};
    int queue[10], front = 0, rear = 0;

    queue[rear++] = 0;
    visited[0] = 1;

    while(front < rear) {
        int v = queue[front++];
        printf("%d ", v);

        for(int i=0;i<4;i++) {
            if(graph[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    return 0;
}
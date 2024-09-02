#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int adj[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                     {1, 0, 1, 0, 0, 0, 0},
                     {1, 1, 0, 1, 1, 0, 0},
                     {1, 0, 1, 0, 1, 0, 0},
                     {0, 0, 1, 1, 0, 1, 1},
                     {0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 1, 0, 0}};
    int ch;
    do
    {
        printf("\n");
        printf("1.BFS traversal\n");
        printf("2.DFS traversal\n");
        printf("enter choice : \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            bfs(adj, visited, 0);
            break;

        case 2:
            dfs(adj, visited, 4);
            break;

        default:
            printf("wrong choice");
            break;
        }
    } while (ch != 3);
}
void bfs(int adj[7][7], int visited[], int start)
{
    int i, j;
    int que[7], r = -1, f = -1;
    for (i = 0; i < 7; i++)
    {
        visited[i] = 0;
    }
    que[++r] = start;
    ++f;
    visited[start] = 1;

    while (r >= f)
    {
        start = que[f];
        f++;
        printf("%d ", start);
        for (j = 0; j < 7; j++)
        {
            if (adj[start][j] && visited[j] == 0)
            {
                que[++r] = j;
                visited[j] = 1;
            }
        }
    }
}
void dfs(int adj[7][7], int visited[], int start)
{
    int j;
    printf("%d ", start);
    visited[start] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (adj[start][j] == 1 && !visited[j])
        {
            dfs(adj, visited, j);
        }
    }
}
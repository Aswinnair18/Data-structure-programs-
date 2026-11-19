#include <stdio.h>

int main()
{
    int n, e;
    int graph[10][10] = {0};
    int indegree[10] = {0};
    int queue[10];
    int front = 0, rear = -1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");

    for (int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        indegree[v]++;
    }

   
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            queue[++rear] = i;
        }
    }

    printf("\nTopological Order: ");

    int count = 0;

    while (front <= rear)
    {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1)
            {
                indegree[i]--;

                if (indegree[i] == 0)
                {
                    queue[++rear] = i;
                }
            }
        }
    }

    if (count != n)
    {
        printf("\nGraph contains a cycle. Topological sorting is not possible.");
    }

    return 0;
}


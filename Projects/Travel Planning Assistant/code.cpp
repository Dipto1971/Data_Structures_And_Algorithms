#include <stdio.h>
#include <limits.h>
#include <string.h>

#define V 5               // Number of cities
#define MAX_ITEMS 10      // Maximum number of items for knapsack
#define MAX_ACTIVITIES 10 // Maximum number of activities

// City names
const char *cities[V] = {"Dhaka", "Chittagong", "Khulna", "Rajshahi", "Sylhet"};

// Function to find the vertex with the minimum distance
int minDistance(int dist[], int visited[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's algorithm for shortest path
void dijkstra(int graph[V][V], int src, int dest)
{
    int dist[V];
    int visited[V] = {0};

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distance from %s to %s: %d\n", cities[src], cities[dest], dist[dest]);
}

int getCityIndex(char city[])
{
    for (int i = 0; i < V; i++)
    {
        if (strcmp(city, cities[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

// 0/1 Knapsack for resource optimization
int knapsack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = (val[i - 1] + dp[i - 1][w - wt[i - 1]] > dp[i - 1][w]) ? (val[i - 1] + dp[i - 1][w - wt[i - 1]]) : dp[i - 1][w];
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}
// Sorts activities by finish time (ascending)
void sortActivities(int start[], int finish[], int n)
{
    // Bubble sort implementation
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (finish[j] > finish[j + 1])
            {
                // Swap finish times
                int temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                // Swap corresponding start times
                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }
}

// Activity Selection for scheduling tasks
void activitySelection(int start[], int finish[], int n)
{
    int i, j;
    printf("You can complete the following activities without overlapping:\n");
    i = 0;
    printf("Activity %d\n", i + 1);
    for (j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            printf("Activity %d\n", j + 1);
            i = j;
        }
    }
    printf("\n");
}

int main()
{
    int graph[V][V] = {
        {0, 200, 300, 0, 0},
        {200, 0, 150, 400, 0},
        {300, 150, 0, 250, 350},
        {0, 400, 250, 0, 500},
        {0, 0, 350, 500, 0}};

    char source[20], destination[20];
    printf("Available cities: Dhaka, Chittagong, Khulna, Rajshahi, Sylhet\n");
    printf("Enter your current city: ");
    scanf("%s", source);
    printf("Enter your destination city: ");
    scanf("%s", destination);

    int src = getCityIndex(source);
    int dest = getCityIndex(destination);

    if (src == -1 || dest == -1)
    {
        printf("Invalid city name. Please enter a valid city from the list.\n");
        return 1;
    }

    dijkstra(graph, src, dest);

    printf("\nSmart Packing System:\n");
    printf("Optimize the items you can carry in your trip.\n");
    int n, W;
    printf("Enter the number of items you want to carry: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &val[i], &wt[i]);
    }
    printf("Enter your bag's maximum weight capacity: ");
    scanf("%d", &W);
    printf("Optimal value of items to carry: %d\n", knapsack(W, wt, val, n));

    printf("\nSmart Activity Scheduler:\n");
    printf("Plan your activities efficiently to maximize your time.\n");
    int num_activities;
    printf("Enter the number of activities planned: ");
    scanf("%d", &num_activities);
    int start[num_activities], finish[num_activities];
    // Inside main():
    printf("Enter the start and finish times of each activity:\n");
    for (int i = 0; i < num_activities; i++)
    {
        scanf("%d %d", &start[i], &finish[i]);
    }

    // Sort activities by finish time before selection
    sortActivities(start, finish, num_activities);

    activitySelection(start, finish, num_activities);

    return 0;
}
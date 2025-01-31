#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define MAX_CITIES 20 // Increased to accommodate more cities
#define MAX_ITEMS 20
#define MAX_ACTIVITIES 20
#define FILENAME "travel_data.txt"

typedef struct
{
    char name[50];
    int value;
    int weight;
} Item;

typedef struct
{
    char name[50];
    int start;
    int end;
} Activity;

typedef struct
{
    char name[50];
    int distances[MAX_CITIES];
} City;

City cities[MAX_CITIES];
int cityCount = 0;
Item items[MAX_ITEMS];
int itemCount = 0;
Activity activities[MAX_ACTIVITIES];
int activityCount = 0;

// -------------------- Utility Functions --------------------
void clearInputBuffer()
{
    while (getchar() != '\n')
        ;
}

int readInt(const char *prompt)
{
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input. Please enter an integer: ");
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

void toLowerCase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}

// -------------------- City Management --------------------
int findCityIndex(const char *cityName)
{
    char lowerName[50];
    strcpy(lowerName, cityName);
    toLowerCase(lowerName);

    for (int i = 0; i < cityCount; i++)
    {
        char current[50];
        strcpy(current, cities[i].name);
        toLowerCase(current);
        if (strcmp(current, lowerName) == 0)
            return i;
    }
    return -1;
}

void printCities()
{
    printf("\nAvailable cities:\n");
    for (int i = 0; i < cityCount; i++)
    {
        printf("%d. %s\n", i + 1, cities[i].name);
    }
}

// -------------------- Dijkstra's Algorithm --------------------
void dijkstra(int src, int dest)
{
    int dist[MAX_CITIES], parent[MAX_CITIES], visited[MAX_CITIES] = {0};

    for (int i = 0; i < cityCount; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < cityCount - 1; count++)
    {
        int min = INT_MAX, u = -1;
        for (int v = 0; v < cityCount; v++)
        {
            if (!visited[v] && dist[v] < min)
            {
                min = dist[v];
                u = v;
            }
        }
        if (u == -1)
            break;

        visited[u] = 1;
        for (int v = 0; v < cityCount; v++)
        {
            if (!visited[v] && cities[u].distances[v] &&
                dist[u] + cities[u].distances[v] < dist[v])
            {
                dist[v] = dist[u] + cities[u].distances[v];
                parent[v] = u;
            }
        }
    }

    if (dist[dest] == INT_MAX)
    {
        printf("\nNo path exists between these cities!\n");
        return;
    }

    // Build path
    int path[MAX_CITIES], len = 0;
    for (int at = dest; at != -1; at = parent[at])
        path[len++] = at;

    printf("\nShortest path:\n");
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%s", cities[path[i]].name);
        if (i > 0)
            printf(" -> ");
    }
    printf("\nTotal distance: %d km\n", dist[dest]);
}

// -------------------- Knapsack Algorithm --------------------
void knapsack(int capacity)
{
    int dp[MAX_ITEMS + 1][capacity + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= itemCount; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (items[i - 1].weight > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                int include = items[i - 1].value + dp[i - 1][w - items[i - 1].weight];
                dp[i][w] = (include > dp[i - 1][w]) ? include : dp[i - 1][w];
            }
        }
    }

    // Backtrack to find selected items
    int selected[MAX_ITEMS], selCount = 0;
    int w = capacity;
    for (int i = itemCount; i > 0 && dp[i][w] > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            selected[selCount++] = i - 1;
            w -= items[i - 1].weight;
        }
    }

    printf("\nOptimal value: %d\nSelected items:\n", dp[itemCount][capacity]);
    for (int i = selCount - 1; i >= 0; i--)
    {
        printf("- %s (Value: %d, Weight: %d)\n",
               items[selected[i]].name,
               items[selected[i]].value,
               items[selected[i]].weight);
    }
}

// -------------------- Activity Scheduling --------------------
int compareActivities(const void *a, const void *b)
{
    return ((Activity *)a)->end - ((Activity *)b)->end;
}

void scheduleActivities()
{
    if (activityCount == 0)
    {
        printf("No activities to schedule!\n");
        return;
    }

    qsort(activities, activityCount, sizeof(Activity), compareActivities);

    printf("\nOptimal schedule:\n");
    int last = 0;
    printf("1. %s (%d-%d)\n", activities[0].name, activities[0].start, activities[0].end);

    int count = 2;
    for (int i = 1; i < activityCount; i++)
    {
        if (activities[i].start >= activities[last].end)
        {
            printf("%d. %s (%d-%d)\n", count++, activities[i].name,
                   activities[i].start, activities[i].end);
            last = i;
        }
    }
}

// -------------------- File Operations --------------------
void saveData()
{
    FILE *fp = fopen(FILENAME, "w");
    if (!fp)
    {
        printf("Error saving data!\n");
        return;
    }

    // Save cities
    fprintf(fp, "Cities %d\n", cityCount);
    for (int i = 0; i < cityCount; i++)
    {
        fprintf(fp, "%s", cities[i].name);
        for (int j = 0; j < cityCount; j++)
        {
            fprintf(fp, " %d", cities[i].distances[j]);
        }
        fprintf(fp, "\n");
    }

    // Save items
    fprintf(fp, "Items %d\n", itemCount);
    for (int i = 0; i < itemCount; i++)
    {
        fprintf(fp, "%s %d %d\n", items[i].name, items[i].value, items[i].weight);
    }

    // Save activities
    fprintf(fp, "Activities %d\n", activityCount);
    for (int i = 0; i < activityCount; i++)
    {
        fprintf(fp, "%s %d %d\n", activities[i].name, activities[i].start, activities[i].end);
    }

    fclose(fp);
    printf("Data saved successfully!\n");
}

void loadData()
{
    FILE *fp = fopen(FILENAME, "r");
    if (!fp)
    {
        // Initialize default Bangladesh cities
        cityCount = 5;
        strcpy(cities[0].name, "Dhaka");
        strcpy(cities[1].name, "Chittagong");
        strcpy(cities[2].name, "Khulna");
        strcpy(cities[3].name, "Rajshahi");
        strcpy(cities[4].name, "Sylhet");

        // Initialize all distances to 0
        for (int i = 0; i < cityCount; i++)
        {
            for (int j = 0; j < cityCount; j++)
            {
                cities[i].distances[j] = (i == j) ? 0 : INT_MAX;
            }
        }

        // Set example distances (hypothetical values)
        cities[0].distances[1] = 250; // Dhaka to Chittagong
        cities[1].distances[0] = 250;

        cities[0].distances[2] = 270; // Dhaka to Khulna
        cities[2].distances[0] = 270;

        cities[0].distances[3] = 260; // Dhaka to Rajshahi
        cities[3].distances[0] = 260;

        cities[0].distances[4] = 200; // Dhaka to Sylhet
        cities[4].distances[0] = 200;

        cities[1].distances[4] = 300; // Chittagong to Sylhet
        cities[4].distances[1] = 300;

        printf("Default Bangladesh cities loaded.\n");
        return;
    }

    char buffer[100];
    // Load cities
    fscanf(fp, "%s %d", buffer, &cityCount);
    for (int i = 0; i < cityCount; i++)
    {
        fscanf(fp, "%s", cities[i].name);
        for (int j = 0; j < cityCount; j++)
        {
            fscanf(fp, "%d", &cities[i].distances[j]);
        }
    }

    // Load items
    fscanf(fp, "%s %d", buffer, &itemCount);
    for (int i = 0; i < itemCount; i++)
    {
        fscanf(fp, "%s %d %d", items[i].name, &items[i].value, &items[i].weight);
    }

    // Load activities
    fscanf(fp, "%s %d", buffer, &activityCount);
    for (int i = 0; i < activityCount; i++)
    {
        fscanf(fp, "%s %d %d", activities[i].name, &activities[i].start, &activities[i].end);
    }

    fclose(fp);
    printf("Data loaded successfully!\n");
}

// -------------------- Main Menu System --------------------
void planTravel()
{
    printCities();
    char src[50], dest[50];

    printf("\nEnter source city: ");
    fgets(src, 50, stdin);
    src[strcspn(src, "\n")] = 0;

    printf("Enter destination city: ");
    fgets(dest, 50, stdin);
    dest[strcspn(dest, "\n")] = 0;

    int srcIndex = findCityIndex(src);
    int destIndex = findCityIndex(dest);

    if (srcIndex == -1 || destIndex == -1)
    {
        printf("Invalid city names!\n");
        return;
    }

    dijkstra(srcIndex, destIndex);
}

void optimizePacking()
{
    if (itemCount == 0)
    {
        printf("No items available! Add items first.\n");
        return;
    }

    printf("\nCurrent items:\n");
    for (int i = 0; i < itemCount; i++)
    {
        printf("%d. %s (Value: %d, Weight: %d)\n",
               i + 1, items[i].name, items[i].value, items[i].weight);
    }

    int capacity = readInt("\nEnter bag capacity: ");
    knapsack(capacity);
}

void manageSchedule()
{
    if (activityCount == 0)
    {
        printf("No activities available! Add activities first.\n");
        return;
    }

    printf("\nCurrent activities:\n");
    for (int i = 0; i < activityCount; i++)
    {
        printf("%d. %s (%d-%d)\n",
               i + 1, activities[i].name, activities[i].start, activities[i].end);
    }

    scheduleActivities();
}

int main()
{
    loadData();
    int choice;

    do
    {
        printf("\n===== Travel Planner =====\n");
        printf("1. Plan Travel Route\n");
        printf("2. Optimize Packing\n");
        printf("3. Manage Activities\n");
        printf("4. Save Data\n");
        printf("5. Exit\n");
        choice = readInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            planTravel();
            break;
        case 2:
            optimizePacking();
            break;
        case 3:
            manageSchedule();
            break;
        case 4:
            saveData();
            break;
        case 5:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
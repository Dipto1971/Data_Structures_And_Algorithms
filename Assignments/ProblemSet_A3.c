/*Write a program that will delete all negative number by using Pointer. You have to declare a
pointer array and dynamically allocate memory to input elements of array.*/

#include <stdio.h>
#include <stdlib.h>

void deleteEl(int n, int *a)
{
    int i, cnt=0;
    for (i = 0; i < n; i++)
    {
        if (*(a + i) > 0)
        {
            *(a + cnt) = *(a + i);
            cnt++;
        }
    }
    printf("after deleting negative values the array elements is:");

    for (i = 0; i < cnt; i++)
    {
        printf("%d, ", (*(a + i)));
    }
}

int main()
{
    int *a, n, i, pos;
    printf("enter the size of array:");
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    printf("enter the elements:");

    for (i = 0; i < n; i++)
    {
        scanf("%d", (a + i));
    }

    deleteEl(n, a);
    return 0;
}



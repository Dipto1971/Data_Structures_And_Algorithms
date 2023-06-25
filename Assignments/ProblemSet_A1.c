/*Write a program to find Largest Number Using Dynamic Memory Allocation from a list of
elements. You have to input total size of elements and depending upon the number of
elements, the required size has to be allocated using DMA.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, *element;
    printf("Input total number of elements: ");
    scanf("%d", &n);

    element = (int*)calloc(n,sizeof(int)); //calloc() function assigns multiple blocks of memory to a single variable.
    if(element == NULL){
        printf("No memory allocated\n");
        return 0;
    }
    for(int i=0;i<n;++i)  
    {
       printf("Number %d: ",i+1);
       scanf("%d",element+i);
    }
    
    int largest = *element;  // Initialize the largest with the first element
    for (int i = 1; i < n; ++i) {
        if (*(element + i) > largest) {  // Compare each element with the current largest
            largest = *(element + i);   // Update the largest value
        }
    }
    printf(" The Largest element is : %d", largest);
    return 0;

}
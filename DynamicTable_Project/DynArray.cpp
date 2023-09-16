#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10
#define MIN_CAPACITY 5

// Struct for the dynamic array
typedef struct {
    int *array;
    int length;
    int capacity;
} DynamicArray;

// Function to create a dynamic array
DynamicArray* createDynamicArray() {
    DynamicArray *dynArray = (DynamicArray*)malloc(sizeof(DynamicArray));
    dynArray->array = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    dynArray->length = 0;
    dynArray->capacity = INITIAL_CAPACITY;
    return dynArray;
}

// Function to insert an element into the dynamic array
void insert(DynamicArray *dynArray, int element) {
    if (dynArray->length == dynArray->capacity) {
        int newCapacity = dynArray->capacity * 2;
        int *newArray = (int*)malloc(newCapacity * sizeof(int));
        for (int i = 0; i < dynArray->length; i++) {
            newArray[i] = dynArray->array[i];
        }
        free(dynArray->array);
        dynArray->array = newArray;
        dynArray->capacity = newCapacity;
    }
    
    dynArray->array[dynArray->length] = element;
    dynArray->length++;
}

// Function to delete an element from the dynamic array
void deleteElement(DynamicArray *dynArray, int index) {
    if (index < 0 || index >= dynArray->length) {
        printf("Invalid index\n");
        return;
    }
    
    for (int i = index; i < dynArray->length - 1; i++) {
        dynArray->array[i] = dynArray->array[i + 1];
    }
    
    dynArray->length--;
    
    if (dynArray->length < dynArray->capacity / 2 && dynArray->capacity >= MIN_CAPACITY) {
        int newCapacity = dynArray->capacity / 2;
        int *newArray = (int*)malloc(newCapacity * sizeof(int));
        for (int i = 0; i < dynArray->length; i++) {
            newArray[i] = dynArray->array[i];
        }
        free(dynArray->array);
        dynArray->array = newArray;
        dynArray->capacity = newCapacity;
    }
}

// Function to show the elements in the dynamic array
void show(DynamicArray *dynArray) {
    printf("Dynamic Array Contents:\n");
    for (int i = 0; i < dynArray->length; i++) {
        printf("%d ", dynArray->array[i]);
    }
    printf("\n");
}

int main() {
    DynamicArray *dynArray = createDynamicArray();
    int choice;
    
    do {
        printf("Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Show Elements\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                int element;
                scanf("%d", &element);
                insert(dynArray, element);
                break;
            case 2:
                printf("Enter the index of the element to delete: ");
                int index;
                scanf("%d", &index);
                deleteElement(dynArray, index);
                break;
            case 3:
                show(dynArray);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    // Clean up memory
    free(dynArray->array);
    free(dynArray);
    
    return 0;
}

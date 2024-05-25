#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 10
#define PRIME 7

struct Data {
    int key;
    int value;
};

struct HashTable {
    int flag; // 0: Empty, 1: Occupied, 2: Previously occupied
    struct Data *item;
};

struct HashTable *hashTable;

int size = 0;

int hashFunction1(int key) {
    return key % TABLE_SIZE;
}

int hashFunction2(int key) {
    return PRIME - (key % PRIME);
}

void initializeHashTable() {
    hashTable = (struct HashTable *)malloc(TABLE_SIZE * sizeof(struct HashTable));

    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].item = NULL;
        hashTable[i].flag = 0;
    }
}

void insertItem(int key, int value) {
    int index = hashFunction1(key);
    int step = hashFunction2(key);

    while (hashTable[index].flag == 1) {
        if (hashTable[index].item->key == key) {
            printf("Key already present. Updating value.\n");
            hashTable[index].item->value = value;
            return;
        }
        index = (index + step) % TABLE_SIZE;
    }

    struct Data *newItem = (struct Data *)malloc(sizeof(struct Data));
    newItem->key = key;
    newItem->value = value;

    hashTable[index].item = newItem;
    hashTable[index].flag = 1;
    size++;
}

void insertMultipleItems() {
    int numItems;
    printf("Enter the number of key-value pairs to insert: ");
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++) {
        int key, value;
        printf("Enter key for item %d: ", i + 1);
        scanf("%d", &key);
        printf("Enter value for item %d: ", i + 1);
        scanf("%d", &value);

        insertItem(key, value);
        printf("Key %d has been inserted.\n", key);
    }
}

void deleteItem(int key) {
    int index = hashFunction1(key);
    int step = hashFunction2(key);

    while (hashTable[index].flag != 0) {
        if (hashTable[index].flag == 1 && hashTable[index].item->key == key) {
            free(hashTable[index].item);
            hashTable[index].item = NULL;
            hashTable[index].flag = 2; // Mark as previously occupied
            size--;
            printf("Key %d has been removed.\n", key);
            return;
        }
        index = (index + step) % TABLE_SIZE;
    }

    printf("Key %d does not exist.\n", key);
}

void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].flag != 1) {
            printf("Array %d has no elements.\n", i);
        } else {
            printf("Array %d has elements.\n", i);
            printf("Key: %d, Value: %d\n", hashTable[i].item->key, hashTable[i].item->value);
        }
        printf("\n");
    }
}

void searchKey() {
    int key;
    printf("Enter the key to search: ");
    scanf("%d", &key);

    int index = hashFunction1(key);
    int step = hashFunction2(key);

    while (hashTable[index].flag != 0) {
        if (hashTable[index].flag == 1 && hashTable[index].item->key == key) {
            printf("Key %d found at index %d.\n", key, index);
            return;
        }
        index = (index + step) % TABLE_SIZE;
    }

    printf("Key %d not found.\n", key);
}

void checkSize() {
    printf("Size of the hash table is: %d\n", size);
}

int main() {
    initializeHashTable();

    while (1) {
        printf("\nDouble Hash Table Operations\n");
        printf("1: Insert item\n");
        printf("2: Insert multiple items\n");
        printf("3: Delete item\n");
        printf("4: Check size\n");
        printf("5: Display hash table\n");
        printf("6: Search key\n");
        printf("7: Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int key, value;
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);

                insertItem(key, value);
                printf("Key %d has been inserted.\n", key);
                break;
            }
            case 2:
                insertMultipleItems();
                break;
            case 3: {
                int key;
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                deleteItem(key);
                break;
            }
            case 4:
                checkSize();
                break;
            case 5:
                displayHashTable();
                break;
            case 6:
                searchKey();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

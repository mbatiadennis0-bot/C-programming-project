#include <stdio.h>
#define CAPACITY 10

int hash_table[CAPACITY];

// 1. Hash Function (returns the index using modulo)
int hashFunction(int key) {
    return key % CAPACITY;
}

// 2. Insert Function (with Linear Probing to handle collisions like 23 & 33)
void insert(int value) {
    int index = hashFunction(value);
    int original_index = index;

    // If the slot is already taken (not 0), move to the next slot
    while (hash_table[index] != 0) {
        index = (index + 1) % CAPACITY;
        if (index == original_index) {
            printf("Hash table is full! Cannot insert %d\n", value);
            return;
        }
    }

    hash_table[index] = value;
    printf("%d inserted at index %d\n", value, index);
}

// 3. Display Function (completed from where your notes left off)
void display() {
    printf("\n--- Hash Table Contents ---\n");
    for (int i = 0; i < CAPACITY; i++) {
        if (hash_table[i] != 0) {
            printf("Index %d: %d\n", i, hash_table[i]);
        } else {
            printf("Index %d: [Empty]\n", i);
        }
    }
}

int main() {
    // Inserting the Given Student IDs from your notes:
    // 23, 45, 12, 67, 34, 89, 90, 33, 77
    insert(23);
    insert(45);
    insert(12);
    insert(67);
    insert(34);
    insert(89);
    insert(90);
    insert(33); // Collides at index 3 (same as 23), moves to index 4!
    insert(77); // Collides at index 7 (same as 67), moves to index 8!

    // Call display
    display();

    return 0;
}

#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// 1. INSERT (Enqueue) - Adds an element to the rear
void insert(int x) {
    if (rear == MAX - 1) {
        printf("Queue is Full!! Cannot insert %d\n", x);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = x;
        printf("Value %d has been inserted\n", x);
    }
}

// 2. DELETE (Dequeue) - Removes an element from the front
void deleteElement() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!! Nothing to delete\n");
    } else {
        int x = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1; // Reset queue when last element is removed
        }
        printf("%d has been deleted (dequeued)\n", x);
    }
}

// 3. TO JUMP - Lets an element at a given position jump to the front of the queue
void jumpToFront(int pos) {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!!\n");
        return;
    }
    int targetIndex = front + pos - 1; // 1-based position from the current front
    if (targetIndex <= front || targetIndex > rear) {
        printf("Invalid jump position! Choose a position between 2 and %d\n", (rear - front + 1));
        return;
    }

    int jumpedValue = queue[targetIndex];
    // Shift elements right to make room at the front
    for (int i = targetIndex; i > front; i--) {
        queue[i] = queue[i - 1];
    }
    queue[front] = jumpedValue;
    printf("Value %d jumped to the front of the queue!\n", jumpedValue);
}

// 4. UPDATE - Updates a value at a specific position (or searches for an old value)
void update(int oldVal, int newVal) {
    if (front == -1 || front > rear) {
        printf("Queue is Empty!!\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        if (queue[i] == oldVal) {
            queue[i] = newVal;
            printf("Updated %d to %d\n", oldVal, newVal);
            return;
        }
    }
    printf("Value %d not found in the queue\n", oldVal);
}

// Helper function to view the current queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Current Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n\n");
}

int main() {
    // Testing Insert
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    display();

    // Testing Update (change 20 to 25)
    update(20, 25);
    display();

    // Testing Jump (3rd item in line jumps to the front)
    jumpToFront(3);
    display();

    // Testing Delete (removes whoever is at the front)
    deleteElement();
    display();

    return 0;
}

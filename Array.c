#include <stdio.h>

int main() {
    int score[100] = {10, 20, 30, 40, 50};
    int new_number, position;
    int i, n = 5;

    // Step 1: Enter the new number
    printf("Enter the new number: ");
    scanf("%d", &new_number);

    // Step 2: Identify the position
    printf("Enter the position: ");
    scanf("%d", &position);

    // Check whether the position is valid
    if (position < 1 || position > n + 1) {
        printf("Invalid position!\n");
        return 0;
    }

    // Step 3: Move existing elements to the right
    for (i = n; i >= position; i--) {
        score[i] = score[i - 1];
    }

    // Step 4: Insert the new number
    score[position - 1] = new_number;
    n++;

    // Step 5: Traverse and display the array
    printf("\nArray elements after insertion:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", score[i]);
    }

    return 0;
}

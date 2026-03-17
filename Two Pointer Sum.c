#include <stdio.h>

void twoSumSorted(int numbers[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int current_sum = numbers[left] + numbers[right];

        if (current_sum == target) {
            printf("Indices: %d %d\n", left + 1, right + 1);
            return;
        }
        else if (current_sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    printf("No solution found\n");
}

int main() {
    int numbers[] = {2, 7, 11, 15};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 9;

    twoSumSorted(numbers, size, target);

    return 0;
}

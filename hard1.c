#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in each sliding window
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    if (nums == NULL || numsSize == 0 || k <= 0) {
        *returnSize = 0;
        return NULL;
    }

    // Allocate memory for the result array
    int* result = (int*)malloc((numsSize - k + 1) * sizeof(int));
    *returnSize = numsSize - k + 1;

    // Allocate memory for the deque to store indices
    int* deque = (int*)malloc(numsSize * sizeof(int));

    int front = 0, rear = -1;  // Pointers for the deque

    // Process the first window
    for (int i = 0; i < k; i++) {
        // Remove indices of elements smaller than the current element from the rear
        while (rear >= front && nums[i] >= nums[deque[rear]]) {
            rear--;
        }
        // Add the current index to the rear
        deque[++rear] = i;
    }

    // Process the remaining windows
    for (int i = k; i < numsSize; i++) {
        result[i - k] = nums[deque[front]];

        // Remove indices that are out of the current window from the front
        while (rear >= front && deque[front] <= i - k) {
            front++;
        }

        // Remove indices of elements smaller than the current element from the rear
        while (rear >= front && nums[i] >= nums[deque[rear]]) {
            rear--;
        }

        // Add the current index to the rear
        deque[++rear] = i;
    }

    // Add the maximum element of the last window to the result
    result[numsSize - k] = nums[deque[front]];

    // Free the allocated memory for the deque
    free(deque);

    return result;
}

// Main function
int main() {
    int numsSize, k;

    // Input the size of the array and the sliding window size
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);

    // Input the elements of the array
    int* nums = (int*)malloc(numsSize * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter the size of the sliding window: ");
    scanf("%d", &k);

    int returnSize;

    // Calculate the result
    int* result = maxSlidingWindow(nums, numsSize, k, &returnSize);

    // Display the input array and sliding window size
    printf("Input: nums = [");
    for (int i = 0; i < numsSize; i++) {
        printf("%d", nums[i]);
        if (i < numsSize - 1) {
            printf(", ");
        }
    }
    printf("], k = %d\n", k);

    // Display the calculated output
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    // Free the allocated memory for the arrays
    free(nums);
    free(result);

    return 0;
}
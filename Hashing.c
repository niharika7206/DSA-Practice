#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* hash = (int*)malloc(100000 * sizeof(int));
    
    // Initialize hash with -1
    for (int i = 0; i < 100000; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        if (complement >= 0 && complement < 100000 && hash[complement] != -1) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = hash[complement];
            result[1] = i;
            *returnSize = 2;
            free(hash);
            return result;
        }

        if (nums[i] >= 0 && nums[i] < 100000) {
            hash[nums[i]] = i;
        }
    }

    *returnSize = 0;
    free(hash);
    return NULL;
}

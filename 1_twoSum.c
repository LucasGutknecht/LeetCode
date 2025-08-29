#include <math.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *returnValues = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    int *hashmapValues = (int *)malloc(numsSize * sizeof(int));
    int *hashmapIndices = (int *)malloc(numsSize * sizeof(int));
    int hashmapSize = 0;

    int outer_counter = numsSize;

    while(outer_counter > 0) {
        int num = nums[outer_counter - 1];
        int difference = target - num;
        int inner_counter = hashmapSize;

        while(inner_counter > 0) {
            if(hashmapValues[inner_counter - 1] == difference) {

                returnValues[0] = hashmapIndices[inner_counter - 1];
                returnValues[1] = outer_counter - 1;

                return returnValues;
            }
            inner_counter--;
        }

        hashmapValues[hashmapSize] = num;
        hashmapIndices[hashmapSize] = outer_counter - 1;
        hashmapSize++;

        outer_counter--;
    }

    return returnValues;
}

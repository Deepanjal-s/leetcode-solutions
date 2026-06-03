/*Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for(int i = 0; i < numsSize - 1; i++) {
        if(nums[i] == nums[i + 1]) {
            return 1; // true
        }
    }
    return 0; // false
}

int main() {
    int arr[] = {1,2,4,3,5,3};
    int size = sizeof(arr)/sizeof(int);

    printf("%d", containsDuplicate(arr, size));
}


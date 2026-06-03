//Given an integer array nums, find the with the largest sum, and return its sum.

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int currentSum = nums[0];
    int maxSum = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(currentSum + nums[i] > nums[i]){
            currentSum += nums[i];
        }else{
            currentSum = nums[i];
        }

        if(currentSum > maxSum){
            maxSum = currentSum;
        }
    }
    return maxSum;
} 

int main(){
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int size = sizeof(arr)/sizeof(int);

    printf("%d", maxSubArray(arr,size));
    
}
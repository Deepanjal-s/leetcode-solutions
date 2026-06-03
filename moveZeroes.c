/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/

#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int lastPosition = numsSize - 1;
    int pivot = 0;
    for(int i = 0; i < numsSize - 1; i++){
      if(nums[pivot] == 0){
        for(int i = pivot; i < numsSize - 1; i++){
          nums[i] = nums[i+1];
        }
          nums[lastPosition--] = 0;
      }else{
          pivot++; 
      }
    }
}

//optimized 

void moveZeroes(int* nums, int numsSize) {
    int k = 0;  // position where next non-zero should go

    for(int i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            nums[k] = nums[i];
            k++;
        }
    }

    while(k < numsSize){
        nums[k] = 0;
        k++;
    }
}


int main(){
  int arr[] = {0,2,0,0,4,0,6};
  int size = sizeof(arr)/sizeof(int);
  moveZeroes(arr,size);
  for(int i = 0; i < size; i++){
    printf("%d", arr[i]);
  }
  return 0;
}
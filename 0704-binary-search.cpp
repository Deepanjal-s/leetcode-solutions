#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right)/2;

        while(left <= right){
            mid = (left + right)/2;
            if(target > nums[mid]){
                left = mid + 1;
            }
            if(target < nums[mid]){
                right = mid - 1;
            }
            if(target == nums[mid]){
                return mid;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1,3,5,6,7,8,9};
    int target = 9;
    Solution obj;
    
    int ans = obj.search(nums,target);

    cout << ans << "";

    return 0;
}
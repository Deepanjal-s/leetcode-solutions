#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void twosum2(vector<int>& nums, int i, vector<vector<int>>& result){
        int left = i + 1;
        int right = nums.size() - 1;

        while(left < right){
            
            int sum = nums[left] + nums[right] + nums[i];
            if(sum < 0){
                left++;
            }
            else if(sum > 0){
                right--;
            }
            else{
                result.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;

                while(left < right && nums[left] == nums[left-1]){
                    left++;
                }
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;

        for(int i = 0; i < nums.size() && nums[i] <= 0; i++){
            if(i == 0 || nums[i] != nums[i-1]){
                twosum2(nums,i,result);
            }
        }
        return result;
    }
};


int main(){
    vector<int> nums = {1,4,6,-1,0};
    Solution obj;
    vector<vector<int>> reslut = obj.threeSum(nums);
    for(auto &y : reslut){
        for(auto &x: y)
        cout << x << " ";
    }
    return 0;
}
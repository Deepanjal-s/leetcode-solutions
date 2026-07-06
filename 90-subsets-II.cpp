#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> current;
//         sort(nums.begin(),nums.end());
//         generateResult(0, nums, current, ans);

//         return ans;
//     }

//     void generateResult(int num, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans){
//         if(!current.empty() && !ans.empty()){
//             for(auto an: ans){
//                 if(current == an){
//                     return;
//                 }
//             }
//         }
//         ans.push_back(current);
//         for(int i = num; i < nums.size(); i++){
//             current.push_back(nums[i]);
//             generateResult(i+1, nums, current, ans);
//             current.pop_back();
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin(),nums.end());
        generateResult(0, nums, current, ans);

        return ans;
    }

    void generateResult(int num, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans){
        ans.push_back(current);
        for(int i = num; i < nums.size(); i++){
            if(i > num && nums[i] == nums[i-1]) continue;
            current.push_back(nums[i]);
            generateResult(i+1, nums, current, ans);
            current.pop_back();
        }
    }
};



int main() {
    vector<int> nums = {1,2,2};

    Solution obj;
    vector<vector<int>> ans = obj.subsetsWithDup(nums);

    for(auto an: ans){
        cout << "\n";
        for(auto a: an){
            cout << a << " ";
        }
    }
}
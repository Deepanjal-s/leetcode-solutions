#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        generateResult(0, nums, current, ans);

        return ans;
    }

    void generateResult(int num, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans){
        ans.push_back(current);
        for(int i = num; i < nums.size(); i++){
            current.push_back(nums[i]);
            generateResult(i+1, nums, current, ans);
            current.pop_back();
        }
    }
};



int main() {
    vector<int> nums = {1,2};

    Solution obj;
    vector<vector<int>> ans = obj.subsets(nums);

    for(auto an: ans){
        cout << "\n";
        for(auto a: an){
            cout << a << " ";
        }
    }
}
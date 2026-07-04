#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used;
        vector<int> current;
        generatepermute(current,nums,used,ans);

        return ans;
    }

    void generatepermute(vector<int>& current, vector<int>& nums, vector<bool>& used, vector<vector<int>>& ans){
        if(current.size() == nums.size()){
            ans.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!used[i]){
                current.push_back(nums[i]);
                used[i] = true;
                generatepermute(current,nums,used,ans);
                used[i] = false;
                current.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generatepermute(0,nums,ans);

        return ans;
    }

    void generatepermute(int index, vector<int>& nums,vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[index],nums[i]);

            generatepermute(index+1,nums,ans);

            swap(nums[i],nums[index]);
        }
    }
};
int main() {

}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(),1);
    int pre = 1;
    int post = 1;
    for(int i = 0; i < nums.size(); i++){
        result[i] = pre;
        pre = nums[i]*pre;
    }
    for(int i = nums.size() - 1; i >= 0; i--){
        result[i] = result[i]*post;
        post = nums[i]*post;
    }
    return result;
}

int main(){

    vector<int> nums = {1,1,1,2,2,3};
    vector<int> result = productExceptSelf(nums);
    for(auto num: result){
        std::cout << "" << num << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++){

            if(!dq.empty() && dq.front() == i - k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(i >= k - 1){
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

int main(){

    vector<int> nums = {2,4,5,6,2};
    int k = 2;

    Solution obj;
    vector<int> result = obj.maxSlidingWindow(nums, k);

    for(int x : result){
        cout << x << " ";
    }

    return 0;
}
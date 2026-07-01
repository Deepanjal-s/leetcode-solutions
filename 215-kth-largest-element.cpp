#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return -1;

        for(auto num: nums){
            pq.push(num);

            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};

int main(){
    vector<int> nums = {1,2,4,8,3,2};
    int k = 1;

    Solution obj;
    int ans = obj.findKthLargest(nums,k);

    cout << ans << " ";

    return 0;
}
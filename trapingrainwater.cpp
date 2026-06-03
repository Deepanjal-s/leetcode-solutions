#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int total = 0;
        int leftMax = height[0];
        int rightMax = height[right];
        while(left < right){
            if(height[left] < height[right]){
                leftMax = max(leftMax,height[left]);
                if(leftMax - height[left] > 0){
                    total = total + leftMax - height[left];
                }
                left++;
            }else{
                rightMax = max(rightMax,height[right]);
                if(rightMax - height[right] > 0){
                    total = total + rightMax - height[right];
                }
                right--;
            }
        }
        return total;
    }
};



int main(){
    vector<int> nums = {1,4,0,3,0};
    Solution obj;
    int reslut = obj.trap(nums);
    cout << reslut << " ";
    return 0;
}
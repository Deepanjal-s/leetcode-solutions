#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int maxarea = 0;

        while(left < right){
            int width = right - left;
            int area = min(height[left],height[right])*width;
            maxarea = max(area,maxarea);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxarea;
    }
};

int main(){
    vector<int> nums = {1,4,6,4,7,4};
    Solution obj;
    int reslut = obj.maxArea(nums);
    cout << reslut << " ";
    return 0;
}
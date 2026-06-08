#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }

        int x = nums1.size() - 1;
        int y = nums2.size() - 1;

        int start = 0;
        int end = x;

        while(start <= end){
            int partx = (start + end)/2;
            int party = ((x + y + 1)/2)- partx;

            int xleft = (partx == 0) ? INT_MIN : nums1[partx - 1];
            int xright = (partx == 0) ? INT_MAX : nums1[partx];
            int yleft = (party == 0) ? INT_MIN : nums2[party - 1];
            int yright = (d) 
            
        }
    }
};

int main(){
    vector<int> num1 = {1,2,3,5,6,9};
    vector<int> num2 = {};
    Solution obj;
    double ans = obj.findMedianSortedArrays(num1,num2);

    cout << ans;

    return 0;
}
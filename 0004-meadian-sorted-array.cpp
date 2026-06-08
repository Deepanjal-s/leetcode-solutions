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

        int x = nums1.size();
        int y = nums2.size();

        int start = 0;
        int end = x;

        while(start <= end){
            int partx = (start + end)/2;
            int party = ((x + y + 1)/2)- partx;

            int xleft = (partx == 0) ? INT_MIN : nums1[partx - 1];
            int xright = (partx == x) ? INT_MAX : nums1[partx];
            int yleft = (party == 0) ? INT_MIN : nums2[party - 1];
            int yright = (party == y) ? INT_MAX : nums2[party];

            if(xleft <= yright && yleft <= xright){
                if((x+y)%2 == 0){
                    return ((double) max(xleft,yleft) + min(xright,yright))/2;
                }else{
                    return max(xleft,yleft);
                }
            }else if(xleft > yright){
                end = partx - 1;
            }else{
                start = partx + 1;
            }
        }
        return 0;
    }
};

int main(){
    vector<int> num1 = {1,2,3,5,6,9};
    vector<int> num2 = {10};
    Solution obj;
    double ans = obj.findMedianSortedArrays(num1,num2);

    cout << ans;

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1; 
        int right = *max_element(piles.begin(), piles.end());
        
        while(right > left){
            int mid = left + (right - left)/2;
            if(cococaneat(piles,mid,h)){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
    bool cococaneat(vector<int>& piles, int speed, int h){
        int hours = 0;
        for(int pile : piles){
            hours += (speed + pile - 1)/speed;
        }
        return hours <= h;
    }
};

int main(){
    vector<int> arr = {1,4,5,2,6,23};
    int h = 7;
    Solution obj;
    int ans = obj.minEatingSpeed(arr,h);

    cout << ans << "";

    return 0;
}
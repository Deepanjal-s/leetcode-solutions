#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        int n = heights.size();
        stack<int> s;
        for(int j = 0; j <= n ; j++){
            int currentheight;
            if(j == n){
                currentheight = 0;
            }else{
                currentheight = heights[j];
            }
            while (!s.empty() && currentheight < heights[s.top()]){
                int idx = s.top();
                s.pop();
                int height = heights[idx];
                int weidth; 
                if(s.empty()){
                    weidth = j;
                }else{
                    weidth = j - s.top() - 1;
                }
                maxarea = max(maxarea,height*weidth);
            }
            s.push(j);
        }   
        return maxarea;
    }
};


int main(){
    vector<int> heights = {2,1,5,6,2,3};
    Solution obj;
    int ans = obj.largestRectangleArea(heights);

    cout << ans << "";

    return 0;
}
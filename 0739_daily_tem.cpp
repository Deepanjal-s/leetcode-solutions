#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dailytemprature(vector<int>& tem){
        int n = tem.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int j = 0; j < n; j++){
            while(!st.empty() && tem[j] > tem[st.top()]){
                int index = st.top();
                st.pop();
                ans[index] = j - index;
            }
            st.push(j);
        }

        return ans;
    }
};

int main(){
    vector<int> tem = {1,2,3,2,6,3,7,9,0};
    Solution obj;
    vector<int> ans = obj.dailytemprature(tem);
    for(auto n : ans){
        cout << n;
    }
    return 0;
}
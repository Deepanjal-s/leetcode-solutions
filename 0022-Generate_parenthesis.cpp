#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        backtrack(ans,cur,0,0,n);
        cout << ans.size();
        return ans;        
    }

    void backtrack(vector<string>& ans, string cur, int open, int close, int max){
        if(cur.size() == max*2){
            ans.push_back(cur);
            return;
        }
        if(open < max){
            cur += '(';
            backtrack(ans,cur,open+1,close,max);
            cur.pop_back();
        }
        if(close < open){
            cur += ')';
            backtrack(ans, cur, open, close + 1, max);
            cur.pop_back();
        }
    }
};


int main(){
    int n;
    cout << "Enter the number\n";
    cin >> n;
    Solution obj;
    vector<string> ans = obj.generateParenthesis(n);
    for(auto s : ans){
        cout << s;
    }
    return 0;
}

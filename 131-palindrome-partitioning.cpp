#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;

        backtrack(s,current,0,ans);
        return ans;
    }

    void backtrack(string& s, vector<string>& current,int start, vector<vector<string>>& ans){
        if(start == s.size()){
            ans.push_back(current);
            return;            
        }

        for(int end = start; end < s.size(); end++){
            if(validPalindrome(s,start,end)){
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s,current,end+1,ans);
                current.pop_back();
            }
        }
    }
    bool validPalindrome(string s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
};
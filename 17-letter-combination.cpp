#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> letterDigit = {"", "", "abc", "def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string current;
        if(digits.empty()){
            return ans;
        }
        backtrack(ans,current, digits,0);
        return ans;
    }

    void backtrack(vector<string>& ans, string& current, string& digits, int index){
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }

        string letters = letterDigit[digits[index] - '0'];
        for(auto letter : letters){
            current.push_back(letter);
            backtrack(ans,current,digits,index + 1);
            current.pop_back();
        }
    }
};
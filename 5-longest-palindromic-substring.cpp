#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string mainAns;
        int left = 0; 
        int right = 0;

        for(int i = 0; i < s.size(); i++){
            while(left != s.size() || right != s.size()){
                
            }
            
        }
        return "";
    }
    bool checkPalindrome(string s){
        int left = 0;
        int right = s.size()-1;

        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    string s = "sdmymds";

    Solution obj;
    
    cout << obj.checkPalindrome(s) << " ";

    return 0;
}
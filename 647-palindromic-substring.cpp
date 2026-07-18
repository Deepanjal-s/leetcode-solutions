#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        
        int ans = 0; 

        for(int i = 0; i < s.size(); i++){

            ans += checkSubstrings(s,i,i);
            ans += checkSubstrings(s,i,i+1);
        }

        return ans;
    }

    int checkSubstrings(string s, int i, int j){
        
        int count = 0;
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
            count++;
        }
        return count;
    }
};
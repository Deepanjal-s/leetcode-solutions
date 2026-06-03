#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        } 
        int chararr[26] = {0};
        for(int i = 0; i < s.length(); i++){
            chararr[s[i] - 'a']++;
            chararr[t[i] - 'a']--;
        }
        for(int count : chararr){
            if(count != 0){
                return false;
            }
        }
        return true;
    }
};


#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> need;
        for(char c : t){
            need[c]++;
        }

        int left = 0;
        int count = 0;
        int minLen = __INT_MAX__;
        int start = 0;

        unordered_map<char,int> window;

        for(int right = 0; right < s.size(); right++){

            char c = s[right];

            window[c]++;

            if(need.count(c) && window[c] <= need[c]){
                count++;
            }

            // when all characters matched
            while(count == t.size()){

                // update answer
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if(need.count(leftChar) && window[leftChar] < need[leftChar]){
                    count--;
                }

                left++;
            }
        }

        return minLen == __INT_MAX__ ? "" : s.substr(start, minLen);
    }
};

int main(){
    string s = "mynamea";
    string t = "nam";
    Solution obj; 
    
}
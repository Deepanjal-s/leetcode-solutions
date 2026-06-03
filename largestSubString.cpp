#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        if(s.empty() || s.size() == 0){
            return 0;
        }
        if(s.size() == 1){
            return 1;
        }

        int l = 0;
        int r = 0;
        int ans = 0;

        while(r < s.size()){
            char c = s[r];
            while(set.count(c)){
                set.erase(s[l]);
                l++;
            }
            set.insert(c);
            r++;
            ans = max(ans,r-l);
        }
        return ans;
    }
};



int main(){
    std::string mystr{"hi"};

    Solution obj;
    int ans = obj.lengthOfLongestSubstring(mystr);
    cout << ans << "";

    return 0;
}
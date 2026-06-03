#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int occ[26] {0};
        int left = 0;
        int right = 0; 
        int maxOcc = 0;
        int ans = 0;
        
        for(right ; right < s.size(); right++){
            maxOcc = max(++occ[s[right] - 'A'],maxOcc);
            if(right - left + 1 - maxOcc > k){
                occ[s[left] - 'A']--;
                left++;
            }
            ans = max(ans,right - left + 1);
        }
        return ans;
    }
};


int main(){
    std::string mystr{"hiihihhi"};

    Solution obj;
    int ans = obj.characterReplacement(mystr,2);
    cout << ans << "";

    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int longest = 0;
        if(s.empty()){
            return longest;
        }


        for(auto num : s){
            if(!s.count(num - 1)){

                int current = num;
                int length = 1;

                while(s.count(current + 1)){
                    current++;
                    length++;
                }

                longest = max(length,longest);
            }
        }
        return longest;
    }
};


// class OSolution {
// public:
//     bool isPalindrome(string s) {
//         int left = 0;
//         int right = s.length() - 1;
        
//         while(right >  left){

//             if((!isalnum(s[left]))){
//                 left++;
//                 continue;
//             }
//             if(!(isalnum(s[right]))){
//                 right--;
//                 continue;
//             }
//             if((tolower(s[left])) != tolower(s[right])){
//                 return false;
//             }else{
//                 left++;
//                 right--;
//             }
//         }
//         return true;
//     }
// };


int main(){
    vector<int> nums = {1,4,3,2,5,533,8,3};
    Solution obj;
    int length = obj.longestConsecutive(nums);
    std::cout << " " << length << std::endl;
    return 0; 
}



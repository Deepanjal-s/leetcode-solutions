#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }    

        int s1Map[26] = {0};
        int s2Map[26] = {0};

        // initial window
        for(int i = 0; i < s1.size(); i++){
            s1Map[s1[i] - 'a']++;
            s2Map[s2[i] - 'a']++;
        }

        // sliding window
        for(int i = 0; i <= s2.size() - s1.size(); i++){

            if(matches(s1Map, s2Map)){
                return true;
            }
            
            if(i + s1.size() < s2.size()){
                s2Map[s2[i + s1.size()] - 'a']++;
                s2Map[s2[i] - 'a']--;
            }
        } 

        return false;
    }

private: 
    bool matches(int s1Map[], int s2Map[]){
        for(int i = 0; i < 26; i++){
            if(s1Map[i] != s2Map[i]){
                return false;
            }
        }
        return true;
    }
};


int main(){
    string my {"my"};
    string name {"namem"};

    Solution obj;
    bool value = obj.checkInclusion(my, name);
    cout << value;
    return 0;
}
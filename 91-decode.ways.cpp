#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s.empty() || s[0] == '0') return 0;

        int one = 1;
        int tow = 1;
        for(int i = 1; i < s.size(); i++){
            int current;

            if(s[i] != '0'){
                current = one;
            }

            int value = stoi(s.substr(i-1,2));

            if(value >= 10 && value <= 26){
                current = current + tow;
            }

            tow = one;
            one = current;
        }

        return one;
    }
};
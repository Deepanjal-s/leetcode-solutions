#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>
#include <iomanip>
using namespace std;



class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char c : s){

            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }
            else{
                if(st.empty()) return false;

                if(c == ')' && st.top() != '(') return false;
                if(c == ']' && st.top() != '[') return false;
                if(c == '}' && st.top() != '{') return false;

                st.pop();
            }
        }

        return st.empty();
    }
};

int main(){
    string s = "{[([]])]}";
    Solution obj;
    bool result = obj.isValid(s);
    cout << boolalpha;
    cout << result << "" ;
    return 0;
}
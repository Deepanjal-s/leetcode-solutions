#include <iostream>
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        // if(tokens.size()){
        //     return 0;
        // }
        for(auto t : tokens){
            if(t == "+" || t == "-" || t == "/" || t == "*"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(t == "+"){
                    st.push(num1 + num2);
                }
                if(t == "-"){
                    st.push(num2 - num1);
                }
                if(t == "*"){
                    st.push(num1 * num2);
                }
                if(t == "/"){
                    st.push(num2/num1);
                }
            }
            else{
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};

int main(){
    vector<string> tokens = {"4","13","5","/","+"};
    Solution obj;
    int retValue = obj.evalRPN(tokens);
    cout << retValue << "";
    return 0;
}

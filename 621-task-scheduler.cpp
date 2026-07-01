#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<char> dt;
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty()) return -1;
        int count = tasks.size();
        for(int i = 0; i < tasks.size(); i++){
            char ch = tasks[i];
            dt.insert(ch);
        }

        int distCount = dt.size();

        while(n >= distCount){
            count += 2;
            
        }

    }
};

int main(){
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    Solution obj;
    int ans = obj.leastInterval(tasks,2);
    
}
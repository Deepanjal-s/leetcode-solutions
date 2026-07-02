#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    unordered_map<char, int> dt;
    priority_queue<int> pq;
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty()) return -1;
        
        for(auto task: tasks){
            dt[task]++;
        }

        for(auto& [task,freq] : dt){
            pq.push(freq);
        }

        int time = 0;
        while(!pq.empty()){
            vector<int> task;

            for(int i = 0; i < n + 1; i++){
                if(!pq.empty()){
                    task.push_back(pq.top());
                    pq.pop();
                }
            }

            for(auto freq: task){
                if(--freq > 0){
                    pq.push(freq);
                }
            }

            time += pq.empty() ? task.size() : n + 1;
        }

        return time;
    }
};

int main(){
    vector<char> tasks = {'A','A','A','B','B'};
    int n = 2;

    Solution obj;
    int ans = obj.leastInterval(tasks,2);
    
    cout << ans << " ";

    return 0;
}
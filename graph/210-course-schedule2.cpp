#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for(auto& pre : prerequisites){
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int> order;
        while(!q.empty()){
            int cc = q.front();
            q.pop();
            order.push_back(cc); 
            for(int next : graph[cc]){
                inDegree[next]--;
                if(inDegree[next] == 0){
                    q.push(next);
                }
            }
        }

        if(order.size() == numCourses){
            return order;
        }
        return {};   
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <limits.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> graph;
    
        for(auto time: times){
            graph[time[0]].push_back({time[1],time[2]});

        }
        int time = 0;
        vector<int> dist(n + 1,INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        q.push({0,k});
        
        while(!q.empty()){
            auto [curDist,node] = q.top();
            q.pop();
            if(curDist > dist[node]) continue;

            for(auto [neigh, weight]: graph[node]){
                int newDist = curDist + weight;
                if(newDist < dist[neigh]){
                    q.push({newDist,neigh});
                    dist[neigh] = newDist;
                }
            }
        }

        for(int i = 1; i < n + 1; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            time = max(time, dist[i]);
        }
        return time;
    }
};
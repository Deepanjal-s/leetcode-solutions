#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);

        // min-heap of {cost, pointIndex}, smallest cost on top
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});   // start at point 0 with cost 0

        int totalCost = 0;
        int edgesUsed = 0;

        while(edgesUsed < n){
            auto [cost, curr] = pq.top();
            pq.pop();

            if(visited[curr]) continue;   // stale entry, already connected via a cheaper path

            visited[curr] = true;
            totalCost += cost;
            edgesUsed++;

            for(int next = 0; next < n; next++){
                if(!visited[next]){
                    int dist = abs(points[curr][0] - points[next][0]) +
                               abs(points[curr][1] - points[next][1]);
                    pq.push({dist, next});
                }
            }
        }

        return totalCost;
    }
};
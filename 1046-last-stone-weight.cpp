#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.empty()) return 0;
        
        int size = stones.size() - 1;

        while(stones.size() > 1){
            sort(stones.begin(),stones.end());

            int y = stones.back();
            stones.pop_back();

            int x = stones.back();
            stones.pop_back();

            if(x != y){
                stones.push_back(y-x);
            }
        }
        return !stones.empty() ? stones[0] : 0;
    }
};


class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones) {
        if(stones.empty()) return 0;
        
        for(auto stone : stones){
            pq.push(stone);
        }

        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();

            int x = pq.top();
            pq.pop();

            if(x != y){
                pq.push(y-x);
            }
        }
        return !pq.empty() ? pq.top() : 0;
    }
};
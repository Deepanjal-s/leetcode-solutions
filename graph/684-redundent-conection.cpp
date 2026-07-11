#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DSU {
public: 
    vector<int> parent;
    vector<int> rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        int px = parent[x];
        int py = parent[y];

        if(px == py){
            return;
        }

        if(rank[px] > rank[py]){
            parent[py] = px;
        }else if(rank[px] < rank[py]){
            parent[px] = py;
        }else{
            parent[py] = px;
            rank[py]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int maxNode = 0;
        for(auto& e: edges){
            maxNode = max({maxNode,e[1],e[0]});
        }

        DSU obj(maxNode + 1);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            if(obj.find(u) == obj.find(v)){
                return edge;
            }
            obj.unite(u,v);
        }
        return {};
    }
};


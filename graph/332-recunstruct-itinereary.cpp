#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, vector<string>> graph;
        for(vector<string> ticket: tickets){
            string from = ticket[0];
            string to = ticket[1];
            graph[from].push_back(to);
        }

        for(auto &[first, destination] : graph){
            sort(destination.begin(), destination.end());
        }

        vector<string> itinenary;
        dfs("JFK",graph,itinenary);
        reverse(itinenary.begin(),itinenary.end());
        return itinenary;
    }

    void dfs(string airport, unordered_map<string, vector<string>>& graph, vector<string>& itinenary){
        vector<string>& destination = graph[airport];
        while(!destination.empty()){
            string next = destination[0];
            destination.erase(destination.begin());
            dfs(next,graph,itinenary);
        }
        itinenary.push_back(airport);
    }
};



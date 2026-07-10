#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()) return true;

        unordered_map<int,vector<int>> courseGraph;

        for(auto pre: prerequisites){
            courseGraph[pre[1]].push_back(pre[0]);
        }

        unordered_set<int> visited;
        unordered_set<int> done;

        for(int cc = 0; cc < numCourses; cc++){
            if(!courseSchedule(cc,visited,courseGraph,done)){
                return false;
            }
        }
        return true;
    }

    bool courseSchedule(int cc, unordered_set<int>& visited, unordered_map<int,vector<int>> & courseGraph,unordered_set<int>&done){
        if(done.count(cc)) return true;
        if(visited.find(cc) != visited.end()){
            return false;
        }

        visited.insert(cc);
        for(auto pre : courseGraph[cc]){
            if(!courseSchedule(pre,visited,courseGraph,done)){
                return false;
            }
        }
        visited.erase(cc);
        done.insert(cc);
        return true;
    }
};
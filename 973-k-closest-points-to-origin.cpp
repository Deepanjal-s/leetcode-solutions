#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:

    priority_queue<
    pair<float,int>, 
    vector<pair<float,int>>, 
    greater<pair<float,int>>> pq;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        for(int i = 0; i < points.size(); i++){
            pq.push({sqrt((points[i][0]*points[i][0]) + (points[i][1]*points[i][1])),i});
        }

        for(int i = 0; i < k && pq.size();i++){
            ans.push_back(points[pq.top().second]);
            pq.pop();           
        }

        return ans;
    }
};


int main() {
    vector<vector<int>> points = {{0,-2},{-2,0},{3,0},{5,5}};
    int k = 3;

    Solution obj;
    
    vector<vector<int>> ans = obj.kClosest(points,k);

    for(auto point: ans){
        cout << " \n";
        for(auto c: point){
            cout << c << " ,";
        }
    }
    
    return 0;
}
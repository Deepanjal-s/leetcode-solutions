#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        generateSum(0,candidates,ans,target,current);

        return ans;
    }

    void generateSum(int num, vector<int>& candidates, vector<vector<int>>& ans, int target, vector<int>& current){
        if(target == 0){
            ans.push_back(current);
            return;
        }
        if(target < 0){
            return;
        }
        
        for(int i = num; i < candidates.size(); i++){
            if(i > num && candidates[i] == candidates[i-1]) continue;
            current.push_back(candidates[i]);
            generateSum(i + 1, candidates, ans, target - candidates[i], current);
            
            current.pop_back();
        }
    }
};


int main(){
    vector<int> candidate = {1,3,6,0,2,4,5};
    int target = 6;

    Solution obj;

    vector<vector<int>> ans = obj.combinationSum2(candidate, target);

    for(auto an: ans){
        cout << "\n" ;
        for(auto a: an){
            cout << a << " ";
        }
    }

    return 0;
}
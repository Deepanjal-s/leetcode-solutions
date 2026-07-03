#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        generateSum(0,candidates,ans,target,current);

        return ans;
    }

    void generateSum(int num, vector<int>& candidates, vector<vector<int>>& ans, int target, vector<int>& current){
        if(target == 0){
            ans.push_back(current);
        }else if(target < 0){
            return;
        }

        for(int i = num; i < candidates.size(); i++){
            current.push_back(candidates[i]);
            generateSum(i, candidates, ans, target, current);
            current.pop_back();
        }
    }
};


int main(){
    vector<int> candidate = {1,2,4,5};
    int target = 3;

    Solution obj;

    vector<vector<int>> ans = obj.combinationSum(candidate, target);

    for(auto an: ans){
        cout << "\n" ;
        for(auto a: an){
            cout << a << " ";
        }
    }

    return 0;
}
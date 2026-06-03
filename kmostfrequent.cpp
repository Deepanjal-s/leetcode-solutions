#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> kmostfrequent(vector<int>& nums){
    sort(nums.begin(), nums.end());
    return nums;
}

int main(){

    vector<int> nums = {1,1,1,2,2,3};
    int key = 2;

    vector<int> result = kmostfrequent(nums);

    for(auto num : result){
        cout << num << endl;
    }


}
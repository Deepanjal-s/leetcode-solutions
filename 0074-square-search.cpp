#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target){
        int left = 0;
        int right = arr.size() - 1;
        int mid = (left + right)/2;

        while(left <= right){
            mid = (left + right)/2;
            if(target > arr[mid]){
                left = mid + 1;
            }else if( target < arr[mid]){
                right = mid - 1;
            }else {
                return 1;
            }
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr;
        int m = matrix.size();
        for(int i = 0; i < m; i++){
            int n = matrix[i].size();
            for(int j = 0; j < n; j++){
                arr.push_back(matrix[i][j]);
            }
        }
        if(search(arr,target) == 1){
            return true;
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,3,5,7},{10,11,16,20},{23,30,34,60}
    };

    Solution obj;
    int target = 50;

    int ans = obj.searchMatrix(matrix,target);

    cout << ans << "" ;
    return 0;

}
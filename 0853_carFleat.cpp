#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,double>> cars;

        for(int i = 0; i < n; i++){
            cars.push_back({
                position[i],
                (double)(target - position[i]) / speed[i]
            });
        }

        sort(cars.begin(), cars.end(),
        [](auto &a, auto &b){
            return a.first > b.first;
        });

        int count = 0;
        double prevcount = 0;

        for(auto car : cars){
            if(car.second > prevcount){
                count++;
                prevcount = car.second;
            }
        }

        return count;
    }
};

int main(){

    int target = 12;

    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};

    Solution obj;

    cout << obj.carFleet(target, position, speed) << endl;

    return 0;
}
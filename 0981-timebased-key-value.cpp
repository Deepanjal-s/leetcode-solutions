#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TimeMap {
public:

    unordered_map<string, vector<pair<int,string>>> mp; 

    TimeMap() {
           
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)){
            return "";
        }
        int left = 0;
        int right = mp[key].size() - 1;
        string ans = "";
        while(left <= right){
            int mid = (left + right)/2;
            if(mp[key][mid].first > timestamp){
                right = mid - 1;
            }else if(mp[key][mid].first == timestamp) {
                return mp[key][mid].second;
            }else{
                left = mid + 1;
                ans = mp[key][mid].second;
            }
        }
        return ans;
    }
};

int main(){
    TimeMap obj;
    obj.set("foo","hi",5);
    obj.set("foo","hello",6);
    obj.set("foo","hithere",8);
    
    cout << obj.get("foo",7) << "";

    return 0;
}
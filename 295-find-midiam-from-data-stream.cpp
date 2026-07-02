#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class MedianFinder {
public:
    priority_queue<int> pql;
    priority_queue<int, vector<int>, greater<int>> pqr;
    int left;
    MedianFinder() {
        left = 0;
    }
    
    void addNum(int num) {
        if(pql.empty() || num <= pql.top()){
            pql.push(num);
        }else{
            pqr.push(num);
        }

        if(pql.size() > pqr.size() + 1){
            pqr.push(pql.top());
            pql.pop();
        }

        if(pqr.size() > pql.size() + 1){
            pql.push(pqr.top());
            pqr.pop();
        }
    }
    
    double findMedian() {
        if(pqr.size() == pql.size()){
           return  (pql.top()+pqr.top())/2.0;
        }else if(pqr.size() > pql.size()) {
            return pqr.top();
        }
        return pql.top();
    }
};

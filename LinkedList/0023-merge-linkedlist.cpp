#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> pq;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        for(auto list : lists){
            while(list != NULL){
                pq.push(list->val);
                list = list->next;
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* merge = dummy;
        
        while(!pq.empty()){
            ListNode* node = new ListNode(pq.top());
            pq.pop();
            merge->next = node;
            merge = merge->next;
        }
        
        return dummy->next;
    }
};

int main(){

}
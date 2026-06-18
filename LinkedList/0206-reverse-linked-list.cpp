#include <iostream>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

int main(){
    ListNode* head = new ListNode(3);
    head->next = new ListNode(4);
    head->next->next = new ListNode(5);

    Solution obj;
    head = obj.reverseList(head);

    ListNode* curr = head;

    while(curr != NULL){
        cout << curr->val << "" ;
        curr = curr->next;
    }

    return 0;
    
}
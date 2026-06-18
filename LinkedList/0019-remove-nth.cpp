#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int removeNum;
        int count = 0;
        int i = 1;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        removeNum = count - n + 1;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* newTemp = dummy;
        while(i < removeNum && newTemp != NULL){
            i++;
            newTemp = newTemp->next;
        }
        newTemp->next = newTemp->next->next;

        return dummy->next;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    ListNode* ans = obj.removeNthFromEnd(head,3);

    while(ans != NULL){
        cout << ans->val << "";
        ans = ans->next;
    }
    return 0;
}
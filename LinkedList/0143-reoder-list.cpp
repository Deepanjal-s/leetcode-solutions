#include <iostream>

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
    void reorderList(ListNode* head) {
        ListNode* middle = findmiddle(head);
        ListNode* lefthead = head;
        ListNode* righthead = reversList(middle->next);
        middle->next = NULL;

        while(lefthead != NULL && righthead != NULL){
            ListNode* leftTemp = lefthead->next;
            ListNode* rightTemp = righthead->next;
            lefthead->next = righthead;
            righthead->next = leftTemp;
            lefthead = leftTemp;
            righthead = rightTemp;
        }
    }


    ListNode* findmiddle(ListNode* head){
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next!= NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reversList(ListNode* head){
        ListNode* prv = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prv;
            prv = curr;
            curr = temp;
        }
        return prv;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    obj.reorderList(head);

    ListNode* temp = head;

    while(temp != NULL){
        cout << temp->val << "";
        temp = temp->next;
    }

    return 0;
}
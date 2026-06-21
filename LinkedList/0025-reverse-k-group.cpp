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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* ktail = NULL;
        ListNode* newHead = NULL;

        while(ptr != NULL){
            int count = 0;
            ptr = head;

            while(count < k && ptr != NULL){
                ptr = ptr->next;
                count++;
            }
            if(count == k){
                ListNode* reversHead = reverseNode(head,k);

                if(newHead == NULL){
                    newHead = reversHead;
                }

                if(ktail != NULL){
                    ktail->next = reversHead;
                }

                ktail = head;
                head = ptr;
            }

            if(ktail != NULL){
                ktail->next = head;
            }
        }
        return newHead == NULL ? head: newHead;
    }

    ListNode* reverseNode(ListNode* node, int k){
        ListNode* ptr = node;
        ListNode* newHead = NULL;

        while(k > 0){
            ListNode* nextNode = ptr->next;
            ptr->next = newHead;
            newHead = ptr;
            ptr = nextNode;

            k--;
        }
        
        return newHead;
    }
};

int main(){

}
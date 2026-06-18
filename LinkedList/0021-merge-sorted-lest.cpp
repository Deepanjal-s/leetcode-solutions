#include <iostream>
#include <vector>

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dumy = new ListNode(-1);
        ListNode* merge = dumy;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                merge->next = list1;
                list1 = list1->next;
            }else{
                merge->next = list2;
                list2 = list2->next;
            }
            merge = merge->next;
        }

        if(list1 == NULL){
            merge->next = list2;
        }else{
            merge->next = list1;
        }

        return dumy->next;
    }
};



int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(8);

    ListNode* list2 = new ListNode(3);
    list2->next = new ListNode(5);
    list2->next->next = new ListNode(7);

    Solution obj;
    ListNode* ans = obj.mergeTwoLists(list1,list2);

    while(ans != NULL){
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}
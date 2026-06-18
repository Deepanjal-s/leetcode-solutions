#include <iostream>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummy = new ListNode(0);
        ListNode* tempdummy = dummy;
        while(temp1 != NULL || temp2 != NULL || carry != 0){
            
            int x = (temp1 != NULL) ? temp1->val : 0;
            int y = (temp2 != NULL) ? temp2->val : 0;
            int sum = (x + y) + carry;
            carry = sum/10;
            int digit = sum - carry*10;

            tempdummy->next = new ListNode(digit);
            tempdummy = tempdummy->next;
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        return dummy->next;
    }
};

int main(){
    ListNode *l1 = new ListNode(8);
    ListNode *l2 = new ListNode(9);

    Solution obj;
    ListNode* ans = obj.addTwoNumbers(l1,l2);

    while(ans != NULL){
        cout << ans->val << " ";
        ans = ans->next;
    }

    return 0;
}
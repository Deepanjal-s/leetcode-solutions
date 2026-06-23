#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right; 
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }

        if(p == NULL) return false;
        if(q == NULL) return false;

        if(p->val != q->val){
            return false;
        }

        bool leftNode = isSameTree(p->left,q->left);
        bool rightNode = isSameTree(p->right, q->right);

        return leftNode && rightNode;
    }
};

int main(){

}
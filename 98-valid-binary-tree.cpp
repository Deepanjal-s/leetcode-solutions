#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        return isValid(root,LLONG_MIN,LLONG_MAX);
        
    }

    bool isValid(TreeNode* root, long minval, long maxval){
        if(root == NULL){
            return true;
        }

        if(root->val >= maxval || root->val <= minval){
            return false;
        }

        return isValid(root->left,minval,root->val) && isValid(root->right, root->val, maxval);
    }
};


int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution obj;
    bool ans = obj.isValidBST(root);

    cout << ans << "";

    return 0;
}
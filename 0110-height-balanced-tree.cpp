#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

    int height(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int height = max(leftHeight, rightHeight) + 1;

        if(leftHeight == -1){
            return -1;
        }
        if(rightHeight == -1){
            return -1;
        }

        return abs(leftHeight - rightHeight) > 1 ? -1: height;
    }
};

int main(){

}

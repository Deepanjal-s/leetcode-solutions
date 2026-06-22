#include <iostream>
#include <vector>

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
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        radius(root);
        return maxDiameter;
    }

    int radius(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftMax = radius(root->left);
        int rightMax = radius(root->right);

        maxDiameter = max(maxDiameter,leftMax+rightMax);
        return max(leftMax,rightMax) + 1;
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    int ans = obj.diameterOfBinaryTree(root);

    cout << ans << " ";

    return 0;
}
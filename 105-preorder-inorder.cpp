#include <iostream>
#include <vector>
#include <unordered_map>

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
    int preoderIndex;
    unordered_map<int, int> inorderIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        preoderIndex = 0;
        for(int i = 0; i < inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }
        return tree(preorder,0,preorder.size()-1);
    }

    TreeNode* tree(vector<int>& preorder, int left, int right){
        if(left > right){
            return NULL;
        }

        int rootVal = preorder[preoderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        root->left = tree(preorder,left,inorderIndex[rootVal]-1);
        root->right = tree(preorder, inorderIndex[rootVal]+1,right);

        return root;
    }
};

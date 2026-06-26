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
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int maxsofar = root->val;
        return dfs(root,maxsofar);
    }

    int dfs(TreeNode* root, int maxsofar){
        if(root == NULL) return 0;
        int count = 0;

        if(root->val >= maxsofar){
            count = 1;
        }

        maxsofar = max(maxsofar,root->val);

        count += dfs(root->left,maxsofar);
        count += dfs(root->right,maxsofar);

        return count;
    }
};
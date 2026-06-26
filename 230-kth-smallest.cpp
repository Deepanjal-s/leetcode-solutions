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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inOrder(root,ans);

        return ans[k-1];
    }

    void inOrder(TreeNode* root, vector<int>& ans){
        if(root == NULL) {
            return;
        };

        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution obj;
    int ans = obj.kthSmallest(root,3);

    cout << ans << "";

    return 0;
}
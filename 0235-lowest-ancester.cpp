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

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root == NULL){
//             return NULL;
//         }

//         if(root == p || root == q){
//             return root;
//         }

//         TreeNode* leftNode = lowestCommonAncestor(root->left,p,q);
//         TreeNode* rightNode = lowestCommonAncestor(root->right,p,q);

//         if(leftNode != NULL && rightNode != NULL){
//             return root;
//         }

//         if(rightNode != NULL){
//             return rightNode;
//         }

//         return leftNode;
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
        int parentVal = root->val;
        int pval = p->val;
        int qval = q->val;

        if(pval < parentVal && qval < parentVal){
            return lowestCommonAncestor(root->left,p,q);
        }

        if(pval > parentVal && qval > parentVal){
            return lowestCommonAncestor(root->right,p,q);
        }
        
        return root;
    }
};

int main() {
    
}
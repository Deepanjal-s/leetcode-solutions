#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Codec {
public:
    vector<int> str;
    string s;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        preOrder(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        TreeNode* root = build(ss);

        return root;

    }

    TreeNode* build(stringstream& ss){
        string token;
        getline(ss,token,',');

        if(token == "N"){
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(token));

        root->left = build(ss);
        root->right = build(ss);

        return root;
    }

    void preOrder(TreeNode* root){
        if(root == NULL){
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";
        preOrder(root->left);
        preOrder(root->right);
    }
};

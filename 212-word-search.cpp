#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word = "";
};

class Solution {
public:
    vector<string> answer;

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        // Build Trie
        for (string word : words) {
            TrieNode* node = root;

            for (char ch : word) {
                if (node->children.find(ch) == node->children.end()) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }

            node->word = word;
        }

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return answer;
    }

    void dfs(vector<vector<char>>& board,
             int row,
             int col,
             TrieNode* node) {

        if (row < 0 || col < 0 ||
            row >= board.size() ||
            col >= board[0].size()) {
            return;
        }

        char ch = board[row][col];

        if (ch == '#') {
            return;
        }

        if (node->children.find(ch) == node->children.end()) {
            return;
        }

        node = node->children[ch];

        if (node->word != "") {
            answer.push_back(node->word);

            // avoid duplicates
            node->word = "";
        }

        board[row][col] = '#';

        dfs(board, row + 1, col, node);
        dfs(board, row - 1, col, node);
        dfs(board, row, col + 1, node);
        dfs(board, row, col - 1, node);

        board[row][col] = ch;
    }
};


int main(){

}
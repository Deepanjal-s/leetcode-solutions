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


class TrieNode {
public: 
    TrieNode** links;
    int R = 26;
    bool isEnd;

    TrieNode() {
        links = new TrieNode*[R];

        for(int i = 0; i < R; i++){
            links[i] = NULL;
        }
        isEnd = false;
    }

    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }

    TrieNode* get(char ch){
        return links[ch -'a'];
    }

    void put(char ch, TrieNode* node){
        links[ch-'a'] = node;
    }

    void setEnd(){
        isEnd = true;
    }

    bool getEnd(){
        return isEnd;
    }


};

class Trie {
public:

    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;

        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                node->put(ch,new TrieNode());
            }
            node =  node->get(ch);
        }
        node->setEnd();
    }
    
    TrieNode* searchPrefix(string word) {
        TrieNode* node = root;

        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(node->containsKey(ch)){
                node = node->get(ch);
            }else return NULL;
        }

        return node;
    }
    
   
    bool search(string word){
        TrieNode* node = searchPrefix(word);
        return node != NULL && node->getEnd();
    }

    bool startsWith(string prefix) {
        TrieNode* node = searchPrefix(prefix);
        return node != NULL;
    }

};
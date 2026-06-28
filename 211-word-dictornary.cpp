#include <iostream>

using namespace std;

class WordNode {
public:
    WordNode** links;
    int R = 26;
    bool isEnd = false;

    WordNode() {
        links = new WordNode*[R];

        for(int i = 0; i < R; i++){
            links[i] = NULL;
        }

        isEnd = false;
    }

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    WordNode* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, WordNode* node){
        links[ch - 'a'] = node;
    }

    void setEnd(){
        isEnd = true;
    }

    bool getEnd(){
        return isEnd;
    }
};

class WordDictionary {
public:
    WordNode* root;
    WordDictionary() {
        root = new WordNode();
    }
    
    void addWord(string word) {
        WordNode* node = root;

        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(!node->containsKey(ch)){
                node->put(ch, new WordNode());
            }
            node = node->get(ch);
        }

        node->setEnd();
    }
    
    bool dfs(string word, int index, WordNode* node){
        if(index == word.size()){
            return node->getEnd();
        }
        char ch = word[index];
        if(ch != '.'){
            if(!node->containsKey(ch)){
                return false;
            }
            return dfs(word,index+1,node->get(ch));
        }else {
            for(int i = 0; i < 26; i++){
                if(node->links[i] != NULL){
                    if(dfs(word,index + 1, node->links[i])){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool search(string word) {
        WordNode* node = root;


        return dfs(word,0,node);
    }
};
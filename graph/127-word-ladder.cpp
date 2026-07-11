#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> check(wordList.begin(), wordList.end());
        queue<string> q;

        if(check.find(endWord) == check.end()){
            return 0;
        }

        q.push(beginWord);
        int step = 1;
        while(!q.empty()){
            int size = q.size();
           
            for(int i = 0; i  < size; i++){
                string word = q.front();
                q.pop();

                if(word == endWord){
                    return step;
                }
                string newWord = word;
                for(int pos = 0; pos < word.size(); pos++){
                    for(int i = 'a'; i <= 'z'; i++){
                        newWord[pos] = i;
                        if(check.find(newWord) != check.end()){
                            check.erase(newWord);
                            q.push(newWord);
                            newWord = word;
                        }
                    }
                }
            }
            step++;
        }
        return 0;
    }
};
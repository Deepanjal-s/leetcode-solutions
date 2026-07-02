#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Twitter {
public:

    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int timeStamp;
    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp,tweetId});
        timeStamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        if(tweets.empty()) return {};
        vector<pair<int,int>> feed;
        vector<int> ans;

        if(tweets.find(userId) != tweets.end()){
            for(auto tweet: tweets[userId]){
                feed.push_back(tweet);
            }
        }
        
        if(following.find(userId) != following.end()){
            for(auto followId: following[userId]){
                for(auto tweet: tweets[followId]){
                    feed.push_back(tweet);
                }
            }
        }

        sort(feed.begin(),feed.end(), greater<pair<int,int>>());

        for(int i = 0; i < min(10, (int)feed.size()); i++){
            if(!feed.empty()){
                ans.push_back(feed[i].second);
            }
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};


int main() {

}
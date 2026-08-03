class Twitter {
public:

   vector<unordered_set<int>>follo;
    vector<vector<pair<int,int>>> tweet;
    int cnt = 0;
    Twitter() {
        follo.resize(501);
        for(int i=1;i<=500;i++)follo[i].insert(i);
        tweet.resize(501);
    }
    
    void postTweet(int userId, int tweetId) {
        cnt++;
        tweet[userId].push_back({cnt,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>>pq;
        for(auto it : follo[userId]){
            int sz = tweet[it].size();
            if(sz == 0) continue;
            auto rj = tweet[it][sz-1];
            vector<int>temp;
            temp.push_back(rj.first);
            temp.push_back(rj.second);
            temp.push_back(it);
            temp.push_back(sz-1);
            pq.push(temp);
        }
        vector<int>ans;
        int c = 0;
        while(c < 10 && !pq.empty()){
            vector<int>temp = pq.top();
            pq.pop();
            int w = temp[0];
            int x = temp[1];
            int y = temp[2];
            int z = temp[3];
            ans.push_back(x);
            if(z > 0){
             auto rj = tweet[y][z-1];
            vector<int>tem;
            tem.push_back(rj.first);
            tem.push_back(rj.second);
            tem.push_back(y);
            tem.push_back(z-1);
            pq.push(tem);
            }
            c++;
        }
        return ans;
    }
    
    void follow(int f1, int f2) {
        follo[f1].insert(f2);
    }
    
    void unfollow(int f1, int f2) {
        follo[f1].erase(f2);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
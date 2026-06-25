class Solution {
public:
    typedef pair<int,string>P;
    struct cmp{
        bool operator()(P &a, P &b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int>mp;
        for(auto &word:words){
            mp[word]++;
        }
        priority_queue<P,vector<P>,cmp>pq;
        for(auto it : mp){
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string>result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(),result.end());
        return result;

    }
};
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &num : nums){
            mp[num]++;
        }
        vector<int>result;
        for(auto it : mp){
            if(it.second>1){
                result.push_back(it.first);
            }
        }
        return result;
    }
};
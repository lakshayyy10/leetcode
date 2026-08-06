class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        int mx=0;
        int w=0,h=0;
        int area=0;
        while(i<j){
            h = min(nums[i],nums[j]);
            w = j-i;
            area = w*h;
            mx = max(area,mx);
            if(nums[i]>nums[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return mx;
    }
};
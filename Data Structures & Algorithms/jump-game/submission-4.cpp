class Solution {
public:
    bool solve(vector<int>& nums){
        vector<bool> dp(nums.size(),false);
        int n=nums.size();
        dp[nums.size()-1]=true;
        for(int curr=nums.size()-2;curr>=0;curr--){
            for(int i=1;i<=nums[curr];i++){
                if(curr + i < n && dp[curr + i]){
                    dp[curr] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
    bool canJump(vector<int>& nums) {
        return solve(nums);
    }
};

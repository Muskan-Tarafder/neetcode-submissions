class Solution {
public:
    bool solve(vector<int>& nums,int curr, vector<bool> &dp){
        if(curr>nums.size()){
            return false;
        }
        if(curr==nums.size()-1){
            return true;
        }
        if(nums[curr]==0){
            return false;
        }
        if(dp[curr]==true){
            return dp[curr];
        }
        // bool stat=false;
        for(int i=1;i<=nums[curr];i++){
            dp[curr]=solve(nums,curr+i,dp);
            if(dp[curr]){
                return dp[curr];
            }
        }
        return dp[curr];
    }
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size()+1,false);
        return solve(nums,0,dp);
    }
};

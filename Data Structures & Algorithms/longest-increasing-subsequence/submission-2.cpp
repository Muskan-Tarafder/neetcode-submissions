class Solution {
public:
    int solve(vector<int>& nums,int i,int prev,vector<vector<int>> &dp){
        if(i>=nums.size()){
            return 0;
        }
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int len=solve(nums,i+1,prev,dp);
        if(prev==-1 || nums[prev]<nums[i]){
            len=max(len,1+solve(nums,i+1,i,dp));
        }
        return dp[i][prev + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev=-1;
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return max(solve(nums,0,-1,dp),solve(nums,1,-1,dp));
    }
};

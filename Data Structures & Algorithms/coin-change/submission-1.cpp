class Solution {
public:
    int solve(vector<int>& coins,int amt,vector<int> &dp){
        if(amt<0){
            return INT_MAX;
        }
        if(amt==0){
            return 0;
        }
        if(dp[amt]!=-1){
            return dp[amt];
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solve(coins,amt-coins[i],dp);
            if(ans!=INT_MAX)
            mini=min(mini,1+ans);
        }
        dp[amt]=mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1,-1);
        int ans= solve(coins,amount,dp);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};

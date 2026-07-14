class Solution {
public:
    int solve(vector<int>& num,int idx,vector<int>& dp){
        if(idx>=num.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int inc=num[idx]+solve(num,idx+2,dp);
        int exl=solve(num,idx+1,dp);
        // cout<<"The values in check"<<endl;

        dp[idx]=max(inc,exl);
        return dp[idx];
    }
    int rob(vector<int>& nums) {
        int amt=0,idx=0;
        int n=nums.size();
        vector<int> dp(n+1);
        for(int i=0;i<n+1;i++){
            dp[i]=-1;
        }
        return solve(nums,idx,dp);
    }
};

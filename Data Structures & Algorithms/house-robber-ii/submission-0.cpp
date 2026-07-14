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

        dp[idx]=max(inc,exl);
        return dp[idx];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        if(n==1){
            return nums[0];
        }
        
        vector<int> first,sec;
        for(int i=0;i<n;i++){
            if(i!=n-1){
                first.push_back(nums[i]);
            }
            if(i!=0){
                sec.push_back(nums[i]);
            }
        }
        vector<int> dp1(first.size(),-1);
        vector<int> dp2(sec.size(),-1);
        return max(solve(first,idx,dp1),solve(sec,idx,dp2));
    }
};

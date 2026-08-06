class Solution {
public:
    int solve(int m, int n,int i,int j,vector<vector<int>> &dp){
        if(i<0 || i>=m ||j<0 || j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            cout<<i<<j;
            return 1;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int r=solve(m,n,i+1,j,dp);
        int l=solve(m,n,i,j+1,dp);
        dp[i][j]=r+l;
        return dp[i][j];

    }
    int uniquePaths(int m, int n) {
        int cnt=0;
        vector<vector<int>> dp(m,vector<int> (n,0));
        
        return solve(m,n,0,0,dp);
    }
};

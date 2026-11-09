class Solution:
    def solve(self,dp,text1,text2,i,j):
        if i>=len(text1) or j>=len(text2):
            return 0
        if(i<len(text1) and  j<len(text2) and dp[i][j]!=-1):
            return dp[i][j]
        if text1[i]==text2[j]:
            dp[i][j]=1+self.solve(dp,text1,text2,i+1,j+1)
            return dp[i][j]
        else:
            dp[i][j]=max(self.solve(dp,text1,text2,i+1,j),self.solve(dp,text1,text2,i,j+1))
            return dp[i][j]

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[-1] * len(text2) for _ in range(len(text1))]
        return self.solve(dp,text1,text2,0,0)
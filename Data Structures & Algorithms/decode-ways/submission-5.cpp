class Solution {
public:
    int solve(string s,int i){
        vector<int> dp(s.size()+1,-1);
        dp[s.size()]=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
            }
            else{
                dp[i]=dp[i+1];
                if(i+1<s.size()){
                    int sum=(s[i]-'0')*10+(s[i+1]-'0');
                    if(sum>=10 && sum<27){
                       dp[i]+=dp[i+2];
                    }
                }
            }
        }
        
        return dp[0];
    }
    int numDecodings(string s) {
        return solve(s,0);
    }
};

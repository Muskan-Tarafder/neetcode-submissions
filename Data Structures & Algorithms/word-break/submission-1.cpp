class Solution {
public:
    bool solve(string &s, vector<string>& wordDict, int i,vector<int> &dp) {
        if (i == s.size()) {
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for (int j = 0; j < wordDict.size(); j++) {
            string word = wordDict[j];

            if (i + word.size() <= s.size() &&
                s.substr(i, word.size()) == word) {

                if (solve(s, wordDict, i + word.size(),dp)){
                    dp[i]=true;
                    return true;
                }
            }
        }
        dp[i]=false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,-1);
        return solve(s, wordDict, 0,dp);
    }
};
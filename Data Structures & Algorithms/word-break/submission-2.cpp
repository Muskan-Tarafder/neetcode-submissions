class Solution {
public:
    bool solve(string &s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,false);
        dp[s.size()]=true;

        for(int i=s.size()-1;i>=0;i--){   
            for (int j = 0; j < wordDict.size(); j++) {
                string word = wordDict[j];

                if (i + word.size() <= s.size() &&
                    s.substr(i, word.size()) == word) {

                    if (dp[i + word.length()]){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, wordDict);
    }
};
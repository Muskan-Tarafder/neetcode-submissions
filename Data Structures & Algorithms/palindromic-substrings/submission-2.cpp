class Solution {
public:
    bool is_palin(string &s,int i,int j){
        if (s==""){
            return false;
        }
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(is_palin(s,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int i=0;
        string st="";
        return solve(s);
    }
};

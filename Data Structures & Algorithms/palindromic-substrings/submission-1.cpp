class Solution {
public:
    bool is_palin(string s,int i,int j){
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
    void ispalin(string s,int i,int j,int &cnt){
        if(j>=s.size()){
            return;
        }
        if(is_palin(s,i,j)){
            cnt++;
        }
        ispalin(s,i,j+1,cnt);

    }
    int solve(string s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            ispalin(s,i,i,cnt);
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int i=0;
        string st="";
        return solve(s);
    }
};

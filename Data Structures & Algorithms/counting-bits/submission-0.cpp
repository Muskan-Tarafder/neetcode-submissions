class Solution {
public:
    int hammingWeight(int n){
        int cnt=0;
        while(n){
            int i=n%2;
            n=n/2;
            if(i==1)
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<n+1;i++){
            ans[i]=hammingWeight(i);
        }
        return ans;
    }
};

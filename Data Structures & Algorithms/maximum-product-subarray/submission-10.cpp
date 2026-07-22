class Solution {
public:
    int maxP(vector<int>& nums,int i,int pprod,int nprod,int maxi){
        int maxEndingHere=nums[0];
        int minEndingHere=nums[0];
        int answer=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)
                swap(maxEndingHere, minEndingHere);

            maxEndingHere = max(nums[i], maxEndingHere * nums[i]);
            minEndingHere = min(nums[i], minEndingHere * nums[i]);
            answer = max(answer, maxEndingHere);
        }

        
        // return maxP(nums,i+1,pprod,nprod,maxi);
        return answer;
    }
    int maxProduct(vector<int>& nums) {
        // vector<int> dp(nums.size()+1,)
        int maxi=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        int ans=maxP(nums,1,nums[0],nums[0],maxi);
        maxi=max(ans,maxi);
        // }
        return maxi;
    }
};

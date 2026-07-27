class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum_=0;
        for(int i=0;i<nums.size();i++){
            if(sum_+nums[i]>nums[i]){
                sum_+=nums[i];
            }else{
                sum_=nums[i];
            }
            maxi=max(maxi,sum_);
            
        }
        if(maxi==INT_MIN){
            return nums[0];
        }
        return maxi;
    }
};

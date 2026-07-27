class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum_=0;
        for(int i=0;i<nums.size();i++){
            sum_=nums[i];
            maxi=max(sum_,maxi);
            for(int j=i+1;j<nums.size();j++){
                sum_+=nums[j];
                maxi=max(maxi,max(sum_,nums[j]));
                // cout<<maxi<<" "<<sum_<<" "<<nums[j]<<endl;
            }
            
        }
        if(maxi==INT_MIN){
            return nums[0];
        }
        return maxi;
    }
};

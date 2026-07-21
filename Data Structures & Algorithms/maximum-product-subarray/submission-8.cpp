class Solution {
public:
    int maxP(vector<int>& nums,int i,int pprod,int nprod,int maxi){
        maxi=max(maxi,max(nprod,pprod));
        if(i>=nums.size()){
            return maxi;
        }
        if(nums[i]<0){
            nprod=nums[i]*nprod;
        }else if(nprod>0){
            pprod=pprod*nums[i];
            nprod=nprod*nums[i];
        }else{
            nprod=nprod*nums[i];
        }
        return maxP(nums,i+1,pprod,nprod,maxi);
    }
    int maxProduct(vector<int>& nums) {
        // vector<int> dp(nums.size()+1,)
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++){
            int ans=maxP(nums,i+1,nums[i],nums[i],maxi);
            maxi=max(ans,maxi);
        }
        return maxi;
    }
};

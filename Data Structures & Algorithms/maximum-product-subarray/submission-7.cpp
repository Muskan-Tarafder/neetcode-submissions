class Solution {
public:
    int maxP(vector<int>& nums,int i,int pprod,int nprod,int maxi){
        // cout<<"Prod enter: "<<pprod<<" "<<nprod<<" maxi "<<maxi<<endl;
        maxi=max(maxi,max(nprod,pprod));
        if(i>=nums.size()){
            // return max(pprod,nprod);
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
        maxi=max(maxi,max(nprod,pprod));
        return maxP(nums,i+1,pprod,nprod,maxi);
    }
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++){
            int ans=maxP(nums,i+1,nums[i],nums[i],maxi);
            maxi=max(ans,maxi);
        }
        return maxi;
    }
};

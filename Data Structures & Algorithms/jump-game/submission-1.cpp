class Solution {
public:
    bool solve(vector<int>& nums,int curr){
        if(curr>nums.size()){
            return false;
        }
        if(curr==nums.size()-1){
            return true;
        }
        if(nums[curr]==0){
            return false;
        }
        bool stat=false;
        for(int i=1;i<=nums[curr];i++){
            stat=solve(nums,curr+i);
            if(stat){
                return stat;
            }
        }
        return stat;
    }
    bool canJump(vector<int>& nums) {
        return solve(nums,0);
    }
};

class Solution {
public:
    int maxP(vector<int>& nums){
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
        return answer;
    }
    int maxProduct(vector<int>& nums) {
        int ans=maxP(nums);
        return ans;
    }
};

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,n=heights.size();
        int j=n-1;
        int leftMax=i,rightMax=j,maxi=0;

        while (i<j){
            int area=min(heights[i],heights[j])*(j-i);
            maxi=max(maxi,area);
            if(heights[i]<=heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxi;
    }
};

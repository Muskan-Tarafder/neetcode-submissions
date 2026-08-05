class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int s=0;
        int e=intervals.size()-1;
        int larg=0;
        while(s<=e){
            int mid=(s+e)/2;
            if(intervals[mid][0]<=newInterval[0]){
                s=mid+1;
                larg=s;
                
            }else{
                e=mid-1;
            }
        }
        intervals.insert(intervals.begin() + larg, newInterval);
        int i=0,n=intervals.size();
        while(i<n){
            int j=i;
            int last=intervals[i][1];
            while(j<n && last>=intervals[j][0]){
                last=max(last,intervals[j][1]);
                j++;
            }
            // cout<<intervals[i][0]<<last<<endl;
            vector<int> temp={intervals[i][0],last};
            if(j!=i+1){
                intervals.erase(intervals.begin() + i , intervals.begin() + j);
                intervals.insert(intervals.begin() + i, temp);
            }
            n=intervals.size();
            i++;
            // cout<<" "<<(i<n)<<endl;
        }
        return intervals;
    }
};

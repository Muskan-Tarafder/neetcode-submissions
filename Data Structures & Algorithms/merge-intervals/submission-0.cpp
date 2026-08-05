class Solution {
public:
    int partition(vector<vector<int>>& intervals, int low, int high){
        int pv = intervals[low][0];

        int i = low + 1;
        int j = high;

        while(true){

            while(i <= high && intervals[i][0] <= pv){
                i++;
            }

            while(j >= low && intervals[j][0] > pv){
                j--;
            }

            if(i >= j)
                break;

            swap(intervals[i], intervals[j]);
        }

        swap(intervals[low], intervals[j]);

        return j;
    }
    void quickSort(vector<vector<int>>& intervals, int low,int high){
        if(low<high){
            int k=partition(intervals,low,high);

            quickSort(intervals,low,k-1);
            quickSort(intervals,k+1,high);
        }
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        quickSort(intervals,0,intervals.size()-1);
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++){
            int last=intervals[i][1];
            cout<<intervals[i][0]<<endl;
            int j=i;
            while(j<intervals.size() && last>=intervals[j][0]){
                last = max(last, intervals[j][1]);
                j++;
            }
            cout<<last<<endl;
            ans.push_back({intervals[i][0],last});
            i = j - 1;
        }
        return ans;
    }
};

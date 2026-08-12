class Solution {
public:
    void makeZero(vector<vector<int>>& matrix,int i,int j,vector<vector<bool>>& visited){
        if(i<0 ||j<0 ||i>=matrix.size()|| j>=matrix[0].size()){
            return;
        }
        
        for(int c=0;c<matrix[0].size();c++){
            if(matrix[i][c]!=0) visited[i][c]=true;
            matrix[i][c]=0;
        }
        for(int r=0;r<matrix.size();r++){
            if(matrix[r][j]!=0) visited[r][j]=true;
            matrix[r][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        // vector<vector<bool>> visited(matrix.size(),vector<bool> (matrix[0].size(),false));
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(matrix[i][j]==0 && visited[i][j]==false){
        //             makeZero(matrix,i,j,visited);
                    
        //         }
        //     }
        // }
        int m=matrix.size();
        int n=matrix[0].size();
        vector<bool> row(m,false);
        vector<bool> col(n,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] || col[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

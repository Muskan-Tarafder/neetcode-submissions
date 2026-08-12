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
        // vector<bool> row(m,false);
        // vector<bool> col(n,false);
        int col0=1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {

                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(matrix[0][0] == 0) {
            for(int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        if(col0 == 0) {
            for(int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

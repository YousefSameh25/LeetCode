class Solution {
public:
    vector<int> drow={0,1,0,-1};
    vector<int> dcol={1,0,-1,0};
    void dfs(vector<vector<int>> &vis,vector<vector<int>>& grid1,vector<vector<int>>& grid2,int row,int col,bool &flag){
        vis[row][col]=1;
        
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];

            if(0<=nrow && nrow<grid1.size() && 0<=ncol && ncol<grid1[0].size() && grid2[nrow][ncol]==1 && !vis[nrow][ncol]){
                if(grid1[nrow][ncol]==0){
                    flag=false;
                   
                }
                dfs(vis,grid1,grid2,nrow,ncol,flag);
            }
        }

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> vis(grid1.size(),vector<int>(grid1[0].size(),0));
        int cnt=0;
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[0].size();j++){
                bool flag=true;
                if(!vis[i][j] && grid1[i][j]==1 && grid2[i][j]==1){
                    dfs(vis,grid1,grid2,i,j,flag);
                    if(flag==true){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
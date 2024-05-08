class Solution {
public:
    vector<int> left={0,-1};
    vector<int> right={0,1};
    vector<int> top={-1,0};
    vector<int> down={1,0};


    bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int m=grid.size();
        int n=grid[0].size();

        if(r==m-1 && c==n-1) return true;
        vis[r][c]=1;

        //move Left
        if(grid[r][c]==1 || grid[r][c]==3 || grid[r][c]==5){
            int nr=r+left[0];
            int nc=c+left[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && (grid[nr][nc]==4 || grid[nr][nc]==6 || grid[nr][nc]==1) ){
                if(dfs(nr,nc,grid,vis)) return true;
            }
        }
        //move Right
        if(grid[r][c]==1 || grid[r][c]==4 || grid[r][c]==6){
            int nr=r+right[0];
            int nc=c+right[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && (grid[nr][nc]==1 || grid[nr][nc]==3 || grid[nr][nc]==5) ){
                if(dfs(nr,nc,grid,vis)) return true;
            }
        }
        //move Top
        if(grid[r][c]==2 || grid[r][c]==5 || grid[r][c]==6){
            int nr=r+top[0];
            int nc=c+top[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && (grid[nr][nc]==2 || grid[nr][nc]==3 || grid[nr][nc]==4) ){
                if(dfs(nr,nc,grid,vis)) return true;
            }
        }
        //move Down
        if(grid[r][c]==2 || grid[r][c]==3 || grid[r][c]==4){
            int nr=r+down[0];
            int nc=c+down[1];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && (grid[nr][nc]==2 || grid[nr][nc]==6 || grid[nr][nc]==5) ){
                if(dfs(nr,nc,grid,vis)) return true;
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m , vector<int>(n,0));

        return dfs(0,0,grid,vis);

    }
};
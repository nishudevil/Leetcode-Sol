class Solution {
public:
    int dp[71][71][71];
    int rec (int r, int c1, int c2, vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        if(c1<0 || c1>=n || c2<0 || c2>=n) return -1e9;

        int cherry;
        if(c1==c2) cherry=grid[r][c1];
        else cherry=grid[r][c1]+grid[r][c2];

        if(r==m-1){
            return cherry;
        }

        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        //total 9 possibilities of movement together 3x3
        vector<int> dir={-1,0,1};
        int temp=INT_MIN;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                temp=max(temp,cherry+rec(r+1,c1+dir[i],c2+dir[j],grid));
            }
        }

        return dp[r][c1][c2]=temp;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,n-1,grid);
    }
};
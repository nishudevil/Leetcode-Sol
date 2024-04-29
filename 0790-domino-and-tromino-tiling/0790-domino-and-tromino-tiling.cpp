class Solution {
public:
    //hD/vD=horizontalDomino/verticalDomino

    int mod=1e9+7;
    int dp[1001][1001];
    int rec(int i, int j, int n){
        if(i==n && j==n){
            return 1;
        }else if(i>=n || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int hD=0,vD=0,hT=0,vT=0;
        if(i==j){
            hD=rec(i+2,j+2,n);
            vD=rec(i+1,j+1,n);
            hT=rec(i+2,j+1,n);
            vT=rec(i+1,j+2,n);
        }
        if(i-j==1){
            vT=(vT+rec(i+1,j+2,n))%mod;
            hD=(hD+rec(i,j+2,n))%mod;
        }
        if(j-i==1){
            hT=(hT+rec(i+2,j+1,n))%mod;
            hD=(hD+rec(i+2,j,n))%mod;
        }        

        return dp[i][j]=( (hD+vD)%mod + (hT+vT)%mod )%mod;
    }

    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,n);
    }
};
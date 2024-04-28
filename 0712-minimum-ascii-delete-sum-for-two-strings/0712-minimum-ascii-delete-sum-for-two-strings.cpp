class Solution {
public:
    int dp[1001][1001];
    int rec(int i, int j, string& s1, string& s2){
        int m=s1.size();
        int n=s2.size();
        if(dp[i][j]!=-1) return dp[i][j];

        if(i>=m && j<n){
            int delScore=0;
            for(int k=j;k<n;k++){
                delScore+=(int)s2[k];
            }
            return delScore;
        }else if(i<m && j>=n){
            int delScore=0;
            for(int k=i;k<m;k++){
                delScore+=(int)s1[k];
            }
            return delScore;
        }else if(i>=m && j>=n){
            return 0;
        }

        if(s1[i]==s2[j]){
            return dp[i][j]=rec(i+1,j+1,s1,s2);
        }else{
            return dp[i][j]=min((int)s1[i]+rec(i+1,j,s1,s2), (int)s2[j]+rec(i,j+1,s1,s2) );
        }


    }


    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,s1,s2);
        
    }
};
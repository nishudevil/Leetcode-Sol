class Solution {
public:
    int dp[1001][2002];
    int rec(int ind, int prev, int n, vector<vector<int>>& pairs){
        if(ind>=n) return 0;
        if(dp[ind][prev]!=-1) return dp[ind][prev];
        int curr = pairs[ind][0]+1001;
        int p=0,np=0;
        if(curr>prev){
            p=1+rec(ind+1,pairs[ind][1]+1001,n,pairs);
        }
        np = rec(ind+1,prev,n,pairs);

        return dp[ind][prev]=max(p,np);

    }


    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,n,pairs);
    }
};
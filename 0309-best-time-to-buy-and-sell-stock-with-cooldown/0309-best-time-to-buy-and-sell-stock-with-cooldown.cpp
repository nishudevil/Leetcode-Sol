class Solution {
public:

    //0-buy,1-sell
    int rec(int ind, int n, int state, vector<int>& prices, vector<vector<int>>& dp){
        if(ind>=n){
            return 0;
        }

        if(dp[ind][state]!=-1) return dp[ind][state];

        int t,nt;
        if(state==0){
            t = rec(ind+1,n,1,prices,dp)-prices[ind];
            nt = rec(ind+1,n,0,prices,dp);
        }else{
            t = rec(ind+2,n,0,prices,dp)+prices[ind];
            nt = rec(ind+1,n,1,prices,dp);
        }

        return dp[ind][state]=max(t,nt);

    }


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp (n, vector<int> (2,-1));

        return rec(0,n,0,prices,dp);

    }
};
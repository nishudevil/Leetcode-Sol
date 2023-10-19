class Solution {
public:
    int rec(vector<int>& coins, int amt,int n, vector<vector<int>>& dp){
        if(amt == 0 || n==0 ){
          return (amt==0) ? 0 : INT_MAX-1;  
        } 

        if(dp[n][amt]!=-1) return dp[n][amt];

        if(coins[n-1]<=amt){
            return dp[n][amt] = min (1+rec(coins,amt-coins[n-1], n, dp), rec(coins,amt,n-1,dp)); 
              
        }else{
            return dp[n][amt] = rec(coins,amt,n-1,dp);
        }

    }

    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>> dp (n+1, vector<int>(amt+1,-1));

        int ans = rec(coins,amt,n,dp);

        return ans==INT_MAX-1 ? -1 : ans;
    }
};
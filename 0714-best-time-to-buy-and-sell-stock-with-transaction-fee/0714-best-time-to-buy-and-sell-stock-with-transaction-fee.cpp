class Solution {
public:
    int dp[50001][2];

    int rec(int ind, int turn, int n, vector<int>& prices, int fee){
        if(ind>=n) return 0;
        if(dp[ind][turn]!=-1) return dp[ind][turn];
        int temp=INT_MIN;
        if(turn==0){
            temp=max(rec(ind+1,0,n,prices,fee),-prices[ind]+rec(ind+1,1,n,prices,fee));
        }else{
            temp=max(rec(ind+1,1,n,prices,fee),prices[ind]-fee+rec(ind+1,0,n,prices,fee));
        }

        return dp[ind][turn]=temp;



    }

    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        int n=prices.size();
        return rec(0,0,n,prices,fee);
    }
};
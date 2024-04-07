class Solution {
public:
    long long dp[(int)1e5];

    //find next start_ind >= curr end_ind
    int getNextRide(int l, int h, int currEnd, vector<vector<int>>& rides){
        int ans=rides.size();

        while(l<=h){
            int mid = l+(h-l)/2;
            if(rides[mid][0]>=currEnd){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }

        }

        return ans;


    }

    long long rec(int ind, int n, vector<vector<int>>& rides){
        if(ind>=n) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int nextRide=getNextRide(ind+1,n-1,rides[ind][1],rides);

        long long p = rides[ind][1]-rides[ind][0]+rides[ind][2]+rec(nextRide,n,rides);
        long long np = rec(ind+1,n,rides);

        return dp[ind]=max(p,np);

    }

    long long maxTaxiEarnings(int points, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        int n=rides.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n,rides);
    }
};
class Solution {
public:
    int dp[366][400];
    int rec(int ind, int next, int n, vector<int>& days, vector<int>& costs){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][next]!=-1) return dp[ind][next];
        int one=INT_MAX,seven=INT_MAX,thirty=INT_MAX;

        if(days[ind]>=next){
            one=costs[0]+rec(ind+1,days[ind]+1,n,days,costs);
            seven=costs[1]+rec(ind+1,days[ind]+7,n,days,costs);
            thirty=costs[2]+rec(ind+1,days[ind]+30,n,days,costs);
            return dp[ind][next]=min({one,seven,thirty});
        }else{
            return dp[ind][next]=rec(ind+1,next,n,days,costs);
        }        

        

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,0,n,days,costs);
    }
};
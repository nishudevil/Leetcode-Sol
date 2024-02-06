class Solution {
public:
    int dp[50000][2];

    int rec(int ind, int turn, int n, vector<int>& stones){
        if (ind>=n) return 0;
        
        if(dp[ind][turn]!=-1) return dp[ind][turn];

        if(turn==0){
            int one=INT_MIN, two=INT_MIN, three=INT_MIN;
            one=stones[ind]+rec(ind+1,1,n,stones);
            if(ind+1<n) two=stones[ind]+stones[ind+1]+rec(ind+2,1,n,stones);
            if(ind+2<n) three=stones[ind]+stones[ind+1]+stones[ind+2]+rec(ind+3,1,n,stones);

            return dp[ind][turn]=max(one,max(two,three));
            
        }else{
            int one=INT_MAX, two=INT_MAX, three=INT_MAX;
            one=rec(ind+1,0,n,stones);
            if(ind+1<n) two=rec(ind+2,0,n,stones);
            if(ind+2<n) three=rec(ind+3,0,n,stones);           

            return dp[ind][turn]=min(one,min(two,three));
        }

    }

    string stoneGameIII(vector<int>& stones) {
        int n=stones.size();
        int totSum=0;
        for(auto it:stones) totSum+=it;
        memset(dp,-1,sizeof(dp));

        int alice=rec(0,0,n,stones);
        int bob=totSum-alice;
        if(alice>bob) return "Alice";
        else if(alice==bob) return "Tie";
        else return "Bob";

    }
};
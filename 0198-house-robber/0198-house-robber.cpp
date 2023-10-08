class Solution {
public:
    int rec(vector<int>& nums, int ind,int n, vector<int>& dp){
        if(ind>=n) return 0;
        if (dp[ind]!=-1) return dp[ind];
        return dp[ind]= max(nums[ind]+rec(nums,ind+2,n,dp), rec(nums,ind+1,n,dp));

    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        int res = rec(nums,0,n,dp);
        return res;
    }
};
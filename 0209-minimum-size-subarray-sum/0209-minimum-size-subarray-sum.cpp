class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int l=0,r=0,sum=0,n=nums.size();

        while(r<n){
            sum+=nums[r];
            r++;

            while(sum>=target){
                ans = min (ans,r-l);

                sum-=nums[l];
                l++;
            }

        }



        return ans==INT_MAX ? 0 : ans;

    }
};
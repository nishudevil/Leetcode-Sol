class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int total =accumulate(nums.begin(),nums.end(),0);

        int target=total-x;
        int ans = INT_MAX;
        if(target<0) return -1;

        if(target==0) return nums.size();


        int l=0,r=0,n=nums.size(),sum=0;

        while(r<n){
            sum+=nums[r];
            r++;

            while(sum>target){
                sum-=nums[l];
                l++;
            }

            if(sum==target){
                ans = min(ans, n- (r-l));
            }

        }


        
        return ans == INT_MAX? -1 : ans;
    }
};
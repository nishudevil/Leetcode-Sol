class Solution {
public:
    int dp[1002][1002];
    int rec(int ind, int prev, int n, vector<pair<int,int>>& arr){
        if(ind>=n) return 0;

        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        int p=0,np=0;
        if(prev==-1 || (prev!=-1 && arr[ind].first>arr[prev].first && arr[ind].second>=arr[prev].second) 
            || (prev!=-1 && arr[ind].first==arr[prev].first) ){
                p=arr[ind].second+rec(ind+1,ind,n,arr);
            }

        np=rec(ind+1,prev,n,arr);

        return dp[ind][prev+1]=max(p,np);

    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int n=scores.size();
        for(int i=0;i<n;i++){
            pq.push({ages[i],scores[i]});
        }
        vector<pair<int,int>> arr;
        while(!pq.empty()){
            arr.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        memset(dp,-1,sizeof(dp));

        return rec(0,-1,n,arr);
    }
};
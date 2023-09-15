class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        //{wt,node}
        priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >  pq;

        vector<int> vis(n,0);

        pq.push({0,0});
        int sum=0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int x = points[it.second][0];
            int y = points[it.second][1];
            int wt = it.first;

            if(vis[it.second]) continue;
            vis[it.second]=1;
            sum+=wt;

            for(int i =0; i<n ; i++){
                if(!vis[i]){
                    int nx = points[i][0];
                    int ny = points[i][1];
                    int nwt = abs(nx-x)+abs(ny-y);

                    pq.push({nwt,i});
                }
            }
            
        }

        return sum;
        
    }
};
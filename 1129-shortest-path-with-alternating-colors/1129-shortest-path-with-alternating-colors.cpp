class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //{node,color} -> Red/Blue = 0/1
        vector<pair<int,int>> adj[n];
        for(auto it: redEdges){
            adj[it[0]].push_back({it[1],0});
        }
        for(auto it: blueEdges){
            adj[it[0]].push_back({it[1],1});
        }


        vector<int> dist(n,-1);
        dist[0]=0;
        //vis[node][color];
        vector<vector<int>> vis(n,vector<int>(2,0));
        queue<pair<int,int>> q;
        q.push({0,-1});
        vis[0][0]=1;
        vis[0][1]=1;
        int steps=0;
        while(!q.empty()){
            int size=q.size();
            steps++;

            for(int i=0;i<size;i++){
                int node=q.front().first;
                int prevColor=q.front().second;
                q.pop();
                
                for(auto it:adj[node]){
                    int v=it.first;
                    int currColor=it.second;
                    if(prevColor!=currColor && !vis[v][currColor]){
                        if(dist[v]==-1) dist[v]=steps;
                        vis[v][currColor]=1;
                        q.push({v,currColor});
                    }
                }

            }
        }

        return dist;
    }
};
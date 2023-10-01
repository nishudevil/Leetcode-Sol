class DisjointSet {
    
public:

    vector<int>  parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

   
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        //consider each (x,y) as a node
        int n=stones.size();
        DisjointSet ds(n);

        //check if nodes in same row/column and then do union
        for(int i=0;i<n;i++){
            int x = stones[i][0];
            int y = stones[i][1];
            for(int j=0; j<n;j++){
                if(i!=j){
                    int nx = stones[j][0];
                    int ny = stones[j][1];

                    if(nx==x || ny==y){
                        ds.unionBySize(i,j);
                    }    

                }
            }

        }

        //different ultimate parent means differnt components
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[ds.findUPar(i)]++;
        }

        int res=0;
        for(auto it:mp){
            if(it.second > 1) res+=(it.second-1);
        }

        return res;       
    }
};
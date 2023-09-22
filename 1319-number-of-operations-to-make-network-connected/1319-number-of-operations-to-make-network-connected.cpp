class DisjointSet {
    
public:
    vector<int> parent, size;

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

    int makeConnected(int n, vector<vector<int>>& conn) {
        DisjointSet ds(n);
        int extraEdges=0;
        int comp =0;

        for(auto it : conn){
            int u= it[0];
            int v= it[1];

            //if same parent extar edge
            if (ds.findUPar(u) != ds.findUPar(v)) {
                ds.unionBySize(u, v);
            }else extraEdges++;
        }

        for(int i=0; i<ds.parent.size();i++){
            if(ds.parent[i]==i){ comp++; }
        }
        //cout<<extraEdges<<" comp "<<comp;

        return extraEdges >= comp-1 ? comp-1 : -1;
        
    }
};
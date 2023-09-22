class DisjointSet {
    vector<int>  parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //connect every email id to parent
        map<string,int> mailParent;
        int n=accounts.size();
        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(!mailParent.count(mail)){
                    mailParent[mail]=i;
                }else{
                    //link the parents
                    ds.unionBySize(i,mailParent[mail]);
                }
            }
        }

        vector<string> res[n];
        for (auto it : mailParent){
            string mail = it.first;
            int parent = it.second;
            res[ds.findUPar(parent)].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i =0;i<n;i++){
            if(res[i].size()!=0){
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                vector<string> mail = res[i];
                sort(mail.begin(),mail.end());
                for ( auto it :mail) temp.push_back(it);
                ans.push_back(temp);

            }
        }

        return ans;
        
    }
};
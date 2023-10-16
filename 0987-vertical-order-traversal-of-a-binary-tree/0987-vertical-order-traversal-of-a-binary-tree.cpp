/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
    void traverse(TreeNode* root, map<pair<int,int>,vector<int>>& mp, int x,int y){
        if(root==NULL) return;

        traverse(root->left,mp, x+1,y-1);
        mp[{y,x}].push_back(root->val);
        traverse(root->right,mp, x+1,y+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int,int>,vector<int>> mp;
        vector<vector<int>> ans;
        vector<int> temp;

        traverse(root,mp,0,0);
        int currCol=INT_MAX;
        for(auto it : mp){
            int r = it.first.second;
            int c = it.first.first;


            if(currCol!=c){
                currCol=c;
                if(!temp.empty()) ans.push_back(temp);
                temp.clear();

            }
            vector<int> rowVal = it.second;
            sort(rowVal.begin(),rowVal.end());
            for(int i =0;i<rowVal.size();i++) temp.push_back(rowVal[i]);

        }

        ans.push_back(temp);

        return ans;
                
    }
};
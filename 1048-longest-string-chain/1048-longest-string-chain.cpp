class Solution {
public:
    int dp[1001][1001];
    bool valid(string w1, string w2){
        int m=w1.size();
        int n=w2.size();
        int i=0,j=0,diff=0;
        while(i<m && j<n){
            if(w1[i]==w2[j]){
                i++;
                j++;
            }else{
                diff++;
                i++;
            }
        }
        diff+=(m-i)+(n-j);
        return diff==1;
    }

    int rec(int ind, int prev, vector<string>& words){
        if(ind==0){
            if(prev==-1 || (prev!=-1 && words[prev].size()-words[ind].size()==1 && valid(words[prev],words[ind]) ) )
                return 1;
            else 
                return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int nt=rec(ind-1,prev,words);
        int t=INT_MIN;
        if(prev==-1 || (prev!=-1 && words[prev].size()-words[ind].size()==1 && valid(words[prev],words[ind]) ) ){
            t=1+rec(ind-1,ind,words);
        }

        return dp[ind][prev+1]=max(t,nt);

    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string& a, const string& b) {
            return a.length() < b.length();
        });
        //for(auto it:words) cout<<it<<" - ";
        //cout<<valid("pcxbcf","pcxbc");
        int n=words.size();
        
        memset(dp,-1,sizeof(dp));
        return rec(n-1,-1,words);
    }
};
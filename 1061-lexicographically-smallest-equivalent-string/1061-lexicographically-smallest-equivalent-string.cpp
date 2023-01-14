class Solution {
public:
    void dfs(int i,int &temp,vector<int>&visit,vector<int>adj[])
    {
        visit[i]=0;
        for(auto it:adj[i])
        {
            if(visit[it]==-1)
            {
                if(temp>it)
                {
                    temp=it;
                }
                dfs(it,temp,visit,adj);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int>adj[26];
        int i,n=s1.length();
        for(i=0;i<n;i++)
        {
            adj[s1[i]-'a'].push_back(s2[i]-'a');
            adj[s2[i]-'a'].push_back(s1[i]-'a');
        }
        int m=baseStr.length();
        string res="";
        for(int i=0;i<m;i++)
        {
            vector<int>visit(26,-1);
            int temp=baseStr[i]-'a';
            dfs(temp,temp,visit,adj);
            res+=char('a'+temp);
        }
        return res;
    }
};
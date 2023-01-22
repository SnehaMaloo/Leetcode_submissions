class Solution {
public:
    int dp[301];
     bool f(int i, int j, string a ,unordered_set<string>&st){
        if(st.find(a.substr(i,j-i+1))!=st.end()){
            return dp[i]=true;
        }
         if(dp[i]!=-1)
         {
             return dp[i];
         }
        if(i==j){
            if(st.find(a.substr(i,j-i+1))!=st.end()){
                return dp[i]=true;
            }
            return false;
        }
        bool right=false;
        for(int k=i;k<a.length()-1;k++){
            // string g=a.substr(i,k-i+1);
            if(st.find(a.substr(i,k-i+1))!=st.end()){
                
                 right=f(k+1,j,a,st);
                 if(right){
                     return dp[i]=right;
                 }
            }
            
            else{
                continue;
            }
        }
        return dp[i]=right;
    }
    bool wordBreak(string A, vector<string>& wordDict) {
        int i=0;
        int j=A.size()-1;
        unordered_set<string>st;
        memset(dp,-1,sizeof(dp));
        for(auto it:wordDict)
        {
            st.insert(it);
        }
        return f(i,j,A,st);
    }
};
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    pair<int,int> solve(int start,int end,string &S,map<string,pair<int,int>>&mp)
    {
        if(start==end)
        {
            int cntt=0;
            int cntf=0;
            if(S[start]=='T')
            {
                cntt++;
            }
            else
            {
                cntf++;
            }
            return {cntt,cntf};
        }
        string curr=to_string(start)+"$"+to_string(end);
        if(mp.find(curr)!=mp.end())
        {
            return mp[curr];
        }
        else
        {
            int cntt=0;
            int cntf=0;
            for(int i=start+1;i<end;i++)
            {
                pair<int,int>pt1=solve(start,i-1,S,mp);
                pair<int,int>pt2=solve(i+1,end,S,mp);
                if(S[i]=='|')
                {
                    cntt+=pt1.first*pt2.first+pt1.second*pt2.first+pt1.first*pt2.second;
                    cntf+=pt1.second*pt2.second;
                }
                else if(S[i]=='&')
                {
                    cntt+=pt1.first*pt2.first;
                    cntf+=pt1.second*pt2.first+pt1.first*pt2.second+pt1.second*pt2.second;
                }
                else
                {
                    cntt+=pt1.second*pt2.first+pt1.first*pt2.second;
                    cntf+=pt1.first*pt2.first+pt1.second*pt2.second;
                }
                
            }
            cntt=cntt%(1003);
            cntf=cntf%(1003);
            return mp[curr]={cntt,cntf};
        }
    }
    int countWays(int N, string S){
        map<string,pair<int,int>>mp;
        return solve(0,N-1,S,mp).first;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
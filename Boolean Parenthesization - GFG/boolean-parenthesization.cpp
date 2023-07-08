//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int N, string S){
        map<string,pair<int,int>>mp;
        for(int i=0;i<N;i++)
        {
            string curr=to_string(i)+"$"+to_string(i);
            int cntt=0,cntf=0;
            if(S[i]=='T')
            {
                cntt++;
            }
            else if(S[i]=='F')
            {
                cntf++;
            }
            mp[curr]={cntt,cntf};
        }
        for(int start=N-2;start>=0;start--)
        {
            for(int end=start+2;end<N;end++)
            {
                 int cntt=0;
                int cntf=0;
                string curr=to_string(start)+"$"+to_string(end);
                for(int i=start+1;i<end;i++)
                {
                     string curr1=to_string(start)+"$"+to_string(i-1);
                     string curr2=to_string(i+1)+"$"+to_string(end);
                    pair<int,int>pt1=mp[curr1];
                    pair<int,int>pt2=mp[curr2];
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
                mp[curr]={cntt,cntf};
            }
        }
        string curr=to_string(0)+"$"+to_string(N-1);
        return mp[curr].first;
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
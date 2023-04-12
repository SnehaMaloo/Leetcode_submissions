//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    bool solve(string &A,unordered_set<string>&st,unordered_map<string,bool>&mp)
    {
        if(A.length()==0)
        {
            return mp[A]=true;
        }
        else if(mp.find(A)!=mp.end())
        {
            return mp[A];
        }
        else
        {
            int m=A.length();
            string curr="";
            bool ok=false;
            string temp="";
            for(int i=0;i<m;i++)
            {
                curr.push_back(A[i]);
                temp="";
                if(i!=m-1)
                {
                    temp=A.substr(i+1);
                }
                if(st.find(curr)!=st.end()&&solve(temp,st,mp))
                {
                    ok=true;
                    break;
                }
            }
            return mp[A]=ok?true:false;
        }
    }
    int wordBreak(string A, vector<string> &B) {
        unordered_set<string>st;
        int n=B.size();
        //  cout<<"yo"<<endl;
        for(int i=0;i<n;i++)
        {
            st.insert(B[i]);
        }
        unordered_map<string,bool>mp;
        return solve(A,st,mp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
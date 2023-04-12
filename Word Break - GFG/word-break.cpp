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
    bool f(string a,unordered_map<string ,bool>&mp,unordered_set<string>&s){
        if(a==""){
            return true;
        }
        if(mp.find(a)!=mp.end()){
            return mp[a];
        }
        string b="";
        for(int j=0;j<a.size();j++){
            b+=a[j];
            if(s.find(b)!=s.end()){
                string c=a.substr(j+1,a.size()-j);
                if(f(c,mp,s)==true){
                    return mp[a]=true;
                }
            }
            else{
                continue;
            }
        }
        return mp[a]=false;
    }
    int wordBreak(string A, vector<string> &B) {
        unordered_map<string ,bool>mp;
        unordered_set<string>s;
        for(auto i:B){
            s.insert(i);
            // mp[i]++;
        }
        return f(A,mp,s);
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
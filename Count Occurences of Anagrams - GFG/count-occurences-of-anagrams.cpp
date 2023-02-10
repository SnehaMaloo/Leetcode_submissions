//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char,int>mp;
	    int n=pat.size(),m=txt.size();
	    for(int i=0;i<n;i++)
	    {
	        mp[pat[i]]++;
	    }
	    int cnt=0;
	    int i=0,j=0,ans=0;
	    unordered_map<char,int>mp1;
	    while(j<m)
	    {
	        if(mp.find(txt[j])==mp.end())
	        {
	            mp1.clear();
	            cnt=0;
	            i=j+1;
	        }
	        else
	        {
	            mp1[txt[j]]++;
	            if(mp1[txt[j]]==mp[txt[j]])
	            {
	                cnt++;
	            }
	            while(i<j&&mp1[txt[j]]>mp[txt[j]])
	            {
	                if(mp1[txt[i]]==mp[txt[i]])
	                {
	                    cnt--;
	                }
	                mp1[txt[i]]--;
	                i++;
	            }
	            if(cnt==mp.size())
	            {
	                ans++;
	            }
	        }
	        j++;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
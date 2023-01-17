//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool count(string &s1,string &s2)
    {
        int j=0,i=0,n=s1.length();
        int cnt=0;
        while(j<n)
        {
            if(s1[i]!=s2[j])
            {
                cnt++;
            }
            i++;
            j++;
        }
        return cnt<=1;
    }
    int wordLadderLength(string sw, string tw, vector<string>& wordList) {
        unordered_map<string,unordered_set<string>>mp;
        wordList.push_back(sw);
        int n=wordList.size();
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(count(wordList[i],wordList[j]))
                {
                    mp[wordList[i]].insert(wordList[j]);
                    mp[wordList[j]].insert(wordList[i]);
                }
            }
        }
        unordered_map<string,int>dist;
        queue<string>q;
        q.push(sw);
        dist[sw]=1;
        while(!q.empty())
        {
            string curr=q.front();
            q.pop();
            if(curr==tw)
            {
                return dist[tw];
            }
            for(auto it:mp[curr])
            {
                if(dist.find(it)==dist.end()||(dist[curr]+1)<dist[it])
                {
                    dist[it]=dist[curr]+1;
                    q.push(it);
                }
            }
        }
        if(dist.find(tw)==dist.end())
        {
            return 0;
        }
        return dist[tw];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
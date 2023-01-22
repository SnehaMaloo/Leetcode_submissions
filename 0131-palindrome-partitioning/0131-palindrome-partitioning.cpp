class Solution {
public:
    bool ispalindrome(string &temp)
    {
        int i=0,j=temp.length()-1;
        while(i<j)
        {
            if(temp[i]!=temp[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int i,string&s,vector<vector<string>>&res,vector<string>&curr,int n)
    {
        if(i==n)
        {
            res.push_back(curr);
            return;
        }
        for(int k=i;k<n;k++)
        {
            string temp=s.substr(i,k-i+1);
            if(ispalindrome(temp))
            {
                curr.push_back(temp);
                solve(k+1,s,res,curr,n);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        int n=s.length();
        int i,j;
        vector<string>curr;
        solve(0,s,res,curr,n);
        return res;
    }
};
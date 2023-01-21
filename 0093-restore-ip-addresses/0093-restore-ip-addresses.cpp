class Solution {
public:
    void solve(int i,vector<string>&res,string&s,int x)
    {
        if(x==0)
        {
            string temp=s.substr(i);
            if((temp.length()>1&&temp[0]=='0')||stoi(temp)>255)
            {
                return;
            }
            else
            {
                res.push_back(s);
            }
            return;
        }
        if(i>=(s.length()-1))
        {
            return;
        }
        if(s[i]=='0')
        {
            s=s.substr(0,i+1)+"."+s.substr(i+1);
            solve(i+2,res,s,x-1);
            s=s.substr(0,i+1)+s.substr(i+2);
            return;
        }
        for(int j=i;j<s.length()-1;j++)
        {
            string temp=s.substr(i,j-i+1);
            if(stoi(temp)<=255)
            {
                s=s.substr(0,j+1)+"."+s.substr(j+1);
                solve(j+2,res,s,x-1);
                s=s.substr(0,j+1)+s.substr(j+2);
            }
            else
            {
                break;
            }
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        int n=s.length();
        if(n>12||n<4)
        {
            return res;
        }
        solve(0,res,s,3);
        return res;
    }
};
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        int n=s.length();
        int i,j,k,l;
        for(i=1;i<=3;i++)
        {
            for(j=1;j<=3;j++)
            {
                for(k=1;k<=3;k++)
                {
                    for(l=1;l<=3;l++)
                    {
                        if(i+j+k+l==n)
                        {
                            int a=stoi(s.substr(0,i));
                            int b=stoi(s.substr(i,j));
                            int c=stoi(s.substr(j+i,k));
                            int d=stoi(s.substr(k+j+i));
                            //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
                            if(a<=255&&b<=255&&c<=255&&d<=255)
                            {
                                string temp=to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d);
                                if(temp.length()==s.length()+3)
                                {
                                res.push_back(temp);
                                }
                            }
                            
                        }
                    }
                }
            }
        }
        return res;
    }
};
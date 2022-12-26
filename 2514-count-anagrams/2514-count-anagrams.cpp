#define ll long long
 ll int M=1e9+7;
struct triplet{
        ll int x,y;
    };
triplet extended_euclidean(ll int a,ll int b)
{
    if(b==0)
    {
        triplet ans;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    triplet small_ans=extended_euclidean(b,(a%b));
    triplet ans;
    ans.x=small_ans.y;
    ans.y=small_ans.x-(a/b)*(small_ans.y);
    return ans;
}
ll int mod_inverse(ll int a,ll int b)
{
    triplet ans=extended_euclidean(a,b);
    return ans.x;
}
class Solution {
public:
    int fact[100006];
    ll int get_fact(int n)
    {
        if(n==1)
        {
            return 1;
        }
        if(fact[n]!=0)
        {
            return fact[n];
        }
        return fact[n]=(n*get_fact(n-1))%M;
    }
    int countAnagrams(string s) {
        int n=s.length();
        ll int cnt=1,count=0;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                cnt=(cnt*(get_fact(count)))%M;
                ll int val=1;
                for(auto it:mp)
                {
                    if((it.second)>1)
                    {
                        val=(val*get_fact(it.second))%M;
                    }
                }
                val=mod_inverse(val,M);
                cnt=(cnt*(val))%M;
                mp.erase(mp.begin(),mp.end());
                count=0;
            }
            else {mp[s[i]]++;
                 count++;}
        }
        cnt=(cnt*(get_fact(count)))%M;
        ll int val=1;
        for(auto it:mp)
        {
            if((it.second)>1)
            {
                val=(val*get_fact(it.second))%M;
            }
        }
        val=mod_inverse(val,M);
        cnt=(cnt*(val))%M;
        return (cnt+M)%M;
    }
};
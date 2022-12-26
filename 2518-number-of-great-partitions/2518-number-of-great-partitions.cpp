#define ll long long 
class Solution {
public:
    int mod=1e9+7;
    ll int power(ll a, ll b)
{
	if (b == 0)
		return 1;
	ll x = power(a, b / 2);
	x = (x * x) % mod;
	if (b % 2)
	{
		x = (x * a) % mod;
	}
	return x;
}
   int solve(int i,vector<int>&nums,int k,vector<vector<long long>> &dp){
       if(i==nums.size())
       {
           return 1;
       }
       if(dp[i][k]!=-1)
       {
           return dp[i][k];
       }
       long long notpick=solve(i+1,nums,k,dp)%mod;
       long long pick=0;
       if(nums[i]<k)
       {
           pick=solve(i+1,nums,k-nums[i],dp)%mod;
       }
       return dp[i][k]=(pick+notpick)%mod;
}
public:
int countPartitions(vector<int>& nums, int k) {
int n=nums.size();
ll sum=0;
for(auto i:nums){
sum+=i;
}

      if(2*k>sum)
         return 0;

    vector<vector<long long>> dp(n,vector<long long>(k+1,-1));
    ll val=solve(0,nums,k,dp);
    ll totalval=power(2,n);   

    totalval-=(2*val);
    totalval=(totalval%mod+mod)%mod;
    return totalval;
}
};
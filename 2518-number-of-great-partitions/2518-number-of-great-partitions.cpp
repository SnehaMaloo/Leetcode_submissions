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
   int solve(int ind,vector<int>&nums,int k,vector<vector<long long>> &dp){

    if(ind==nums.size()){
            return 1;
    }
    
    long long ans=0;
    if(dp[ind][k]!=-1)
        return dp[ind][k];
    
    if( k>nums[ind])
        ans+=solve(ind+1,nums,k-nums[ind],dp)%mod;
    
    ans+=solve(ind+1,nums,k,dp)%mod;
    
    return dp[ind][k]=ans%mod;
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
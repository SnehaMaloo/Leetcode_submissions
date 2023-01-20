class Solution {
public:
    void solve(int i,int j,vector<int>&nums,int n,vector<int>&curr,set<vector<int>>&res)
    {
        if(j==n)
        {
            if(curr.size()==0||curr.size()==1||res.find(curr)!=res.end())
            {
                return ;
            }
            else
            {
                res.insert(curr);
                return;
            }
        }
        else if(i==-1||nums[i]<=nums[j])
        {
            curr.push_back(nums[j]);
            solve(j,j+1,nums,n,curr,res);
            curr.pop_back();
        }
        solve(i,j+1,nums,n,curr,res);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>res;
        vector<int>curr;
        int n=nums.size();
        solve(-1,0,nums,n,curr,res);
        vector<vector<int>>ans;
        for(auto it:res)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
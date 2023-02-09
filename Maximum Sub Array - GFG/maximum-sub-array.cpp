//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    int i=0,j=0,strt=0,end=-1;
	   // auto comp=[](pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b)
	   // {
	   //     int start1=a.first.first;
	   //     int start2=b.first.first;
	   //     int end1=a.first.second;
	   //     int end2=b.first.second;
	   //     int sum1=a.second;
	   //     int sum2=b.second;
	   //     int len1=end1-start1+1;
	   //     int len2=end2-start2+1;
	   //     if(len1==len2)
	   //     {
	   //         return sum1>sum2;
	   //     }
	   //     return len1>len2;
	   // };
	   // priotiy_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,decltype(comp)>pq(comp);
	    int sum=0,maxsum=INT_MIN;
	    while(j<n)
	    {
	        while(j<n&&a[j]<0)
	        {
	            j++;
	            i=j;
	            sum=0;
	        }
	        if(j>=n)
	        {
	            continue;
	        }
	        sum+=a[j];
	        if(maxsum<sum)
	        {
	            strt=i;
	            end=j;
	            maxsum=sum;
	        }
	        else if(maxsum==sum)
	        {
	            if(j-i+1>end-strt+1)
	            {
	                end=j;
	                strt=i;
	                maxsum=sum;
	            }
	        }
	        j++;
	    }
	    //cout<<strt<<" "<<end;
	    vector<int>res(a+strt,a+end+1);
	    return res;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
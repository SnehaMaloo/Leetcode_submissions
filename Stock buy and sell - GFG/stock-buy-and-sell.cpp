//{ Driver Code Starts
// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}

// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    int i=0,strt=-1,end=-1;
    int cnt=0;
    while(i<n)
    {
        while(i<n-1&&price[i]>=price[i+1])
        {
            i++;
        }
        if(i!=n-1)
        {
            strt=i;
        }
        else
        {
            break;
        }
        i++;
        while(i<n&&price[i]>=price[i-1])
        {
            i++;
        }
        end=i-1;
        if(strt==end)
        {
            continue;
        }
        cout<<"("<<strt<<" "<<end<<") ";
        strt=-1;
        end=-1;
        cnt++;
    }
    //cout<<strt<<end<<cnt;
    if(cnt==0)
    {
        cout<<"No Profit";
    }
    cout<<endl;
}
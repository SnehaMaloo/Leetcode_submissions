//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool ischeck(int nx,int ny,int n,int m)
    {
        if(nx>=0&&nx<n&&ny>=0&&ny<m)
        {
            return true;
        }
        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int dx[4]={1,0,0,-1};
        int dy[4]={0,1,-1,0};
        queue<pair<int,int>>q;
        int n=image.size(),m=image[0].size();
        int co=image[sr][sc];
        q.push({sr,sc});
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            image[x][y]=-1;
            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(ischeck(nx,ny,n,m)&&image[nx][ny]==co)
                {
                    image[nx][ny]=-1;
                    q.push({nx,ny});
                }
            }
            q.pop();
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(image[i][j]==-1)
                {image[i][j]=newColor;}
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int i,int x,int y,vector<vector<char>>&board,string &word)
    {
        if(i==word.length())
        {
            return true;
        }
        int n=board.size();
        int m=board[0].size();
        char ch=board[x][y];
        board[x][y]='&';
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        bool ok=false;
        for(int j=0;j<4;j++)
        {
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(nx<n&&ny<m&&nx>=0&&ny>=0&&board[nx][ny]!='&'&&board[nx][ny]==word[i])
            {
                if(dfs(i+1,nx,ny,board,word))
                {
                    ok=true;
                    break;
                }
            }
        }
        board[x][y]=ch;
        return ok;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(1,i,j,board,word))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends
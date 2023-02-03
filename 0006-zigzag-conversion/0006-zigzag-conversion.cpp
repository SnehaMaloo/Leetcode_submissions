class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>mat(numRows,vector<char>(1000,' '));
        int n=s.length();
        int i=0,row=0,col=0;
        while(i<n)
        {
            while(i<n&&row<numRows)
            {
                mat[row][col]=s[i];
                i++;
                row++;
            }
            col++;
            row=max(row-2,0);
            while(i<n&&row>0)
            {
                mat[row][col]=s[i];
                i++;
                row--;
                col++;
            }
        }
        int fcol=col;
        string res="";
        for(row=0;row<numRows;row++)
        {
            for(col=0;col<fcol;col++)
            {
                if(mat[row][col]==' ')
                {
                    continue;
                }
                res+=mat[row][col];
            }
        }
        return res;
    }
};
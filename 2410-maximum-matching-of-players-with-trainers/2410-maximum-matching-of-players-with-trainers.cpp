class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size();
        int m=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int cnt=0;
        for(int i=m-1;i>=0&&n>0;i--)
        {
            while(n!=0&&(trainers[i]<players[n-1]))
            {
                n--;
            }
            if(n==0)
            {
                return cnt;
            }
            else
            {
                cnt++;
                n--;
            }
        }
        return cnt;
    }
};
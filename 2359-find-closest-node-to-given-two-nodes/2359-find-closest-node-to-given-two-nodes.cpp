class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dist1(n,INT_MAX),dist2(n,INT_MAX);
        int i;
        int temp=node1;
        int cnt=0;
        while(temp!=-1)
        {
            if(dist1[temp]!=INT_MAX)
            {
                break;
            }
            dist1[temp]=cnt;
            temp=edges[temp];
            cnt++;
        }
        temp=node2;
        cnt=0;
        while(temp!=-1)
        {
            if(dist2[temp]!=INT_MAX)
            {
                break;
            }
            dist2[temp]=cnt;
            temp=edges[temp];
            cnt++;
        }
        int val=INT_MAX,idx=-1;
        for(int i=0;i<n;i++)
        {
            int curr=max(dist1[i],dist2[i]);
            if(curr<val)
            {
                val=curr;
                idx=i;
            }
        }
        return idx;
    }
};
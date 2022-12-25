class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        st.push(-1);
        int area=0;
        int n=heights.size();
        for(int i=0;i<heights.size();i++)
        {
            while((st.top()!=-1)&&heights[st.top()]>heights[i])
            {
                int x=st.top();
                st.pop();
                area=max(area,(i-st.top()-1)*heights[x]);
            }
            st.push(i);
        }
        while(st.top()!=-1)
        {
            int x=st.top();
            st.pop();
            area=max(area,(n-st.top()-1)*heights[x]);
        }
        return area;
    }
};
class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int t) {
        if(jug1+jug2<t)
        {
            return false;
        }
        if(((jug1%2==0&&jug2%2==0)&&(t%2!=0)))
        {
            return false;
        }
        queue<pair<int,int>>q;
        set<pair<int,int>>st;
        q.push({0,0});
        while(!q.empty())
        {
            auto curr=q.front();
            int a=curr.first;
            int b=curr.second;
            if(a+b==t)
            {
                return true;
            }
            st.insert({a,b});
            q.pop();
            //if x is filled up
            int newa=jug1;
            int newb=b;
             if(st.find({newa,newb})==st.end())
            {   q.push({newa,newb});
               st.insert({newa,newb});
            }
            //if y is filled up
            newa=a;
            newb=jug2;
             if(st.find({newa,newb})==st.end())
            {   q.push({newa,newb});
                st.insert({newa,newb});
            }
            //if x->poured to y
            newa=a-min(a,jug2-b);
            newb=b+min(a,jug2-b);
            if(st.find({newa,newb})==st.end())
            {   q.push({newa,newb});
                st.insert({newa,newb});
            }
            
            //if y is poured in x
            newa=a+min(b,jug1-a);
            newb=b-min(b,jug1-a);
            if(st.find({newa,newb})==st.end())
            {   q.push({newa,newb});
                st.insert({newa,newb});
            }
            
            //if x is emptied
            newa=0;
            newb=b;
            if(st.find({newa,newb})==st.end())
            {   q.push({newa,newb});
                st.insert({newa,newb});
            }
            //if y is emptied
            newa=a;
            newb=0;
            if(st.find({newa,newb})==st.end())
            {   q.push({newa,newb});
                st.insert({newa,newb});
            }
        }
        return false;
    }
};
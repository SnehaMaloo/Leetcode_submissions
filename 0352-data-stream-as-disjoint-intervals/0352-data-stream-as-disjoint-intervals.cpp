class SummaryRanges {
public:
    vector<int>arr;
    SummaryRanges() {
        arr.resize(10005,0);
    }
    
    void addNum(int value) {
        arr[value]++;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>res;
        int lo=-1,hi=-1;
        for(int i=0;i<=1e4;i++)
        {
            if(lo==-1&&arr[i]!=0)
            {
                lo=i;
            }
            if(arr[i]!=0)
            {
                hi=i;
            }
            if(arr[i]==0)
            {
                if(lo!=-1)
                {
                    res.push_back({lo,hi});
                }
                lo=-1;
                hi=-1;
            }
        }
        if(lo!=-1)
        {
            res.push_back({lo,hi});
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
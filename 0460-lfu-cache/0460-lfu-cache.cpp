class LFUCache {
public:
    //freq,key,value pair iterator
    map<int,list<pair<int,int>>>freq;
    //freq
    unordered_map<int,pair<int,list<pair<int,int>>::iterator>>mp;
    int max_cap;
    int mf;
    LFUCache(int capacity) {
        max_cap=capacity;
        mf=0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        else
        {
            // cout<<key<<endl;
            auto it=mp[key].second;
            int frequency=mp[key].first;
            int x=it->second;
            freq[frequency].erase(it);
            if(freq[frequency].size()==0)
            {
                freq.erase(frequency);
                if(frequency==mf)
                {
                    mf=frequency+1;
                }
            }
            freq[frequency+1].push_front({key,x});
            //cout<<frequency+1<<" "<<x<<" "<<key<<endl;
            mp.erase(key);
            mp[key]={frequency+1,freq[frequency+1].begin()};
            return x;
        }
    }
    
    void put(int key, int value) {
        if(max_cap==0)
        {
            return ;
        }
        if(mp.find(key)==mp.end())
        {
            if(mp.size()==max_cap)
            {
                auto it=freq.begin();
                auto val=(it->second).end();
                val--;
                mp.erase(val->first);
                freq[it->first].erase(val);
                if(freq[it->first].size()==0)
                {
                    freq.erase(it->first);
                }
            }
            freq[0].push_front({key,value});
            mp[key]={0,freq[0].begin()};
            mf=0;
        }
        else
        {
            int frequency=mp[key].first;
            auto loc=mp[key].second;
            freq[frequency].erase(loc);
            if(freq[frequency].size()==0)
            {
                if(frequency==mf)
                {
                    mf=mf+1;
                }
                freq.erase(frequency);
            }
            freq[frequency+1].push_front({key,value});
            auto it=freq[frequency+1].begin();
            mp[key]={frequency+1,it};
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
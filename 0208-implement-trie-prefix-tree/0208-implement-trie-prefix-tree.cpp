struct Node{
    Node*links[26];
    bool flag;
    Node()
    {
        memset(links,0,sizeof(links));
        flag=false;
    }
    bool containskey(char ch)
    {
        if(links[ch-'a']!=NULL)
        {
            return true;
        }
        return false;
    }
    Node*getlinks(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch,Node*temp)
    {
        links[ch-'a']=temp;
    }
};
class Trie {
    Node*root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        int n=word.length();
        Node*temp=root;
        for(int i=0;i<n;i++)
        {
            if(!(temp->containskey(word[i])))
            {
                temp->put(word[i],new Node());
            }
            temp=temp->getlinks(word[i]);
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        int n=word.length();
        int i;
        Node*temp=root;
        for(i=0;i<n;i++)
        {
            if(!(temp->containskey(word[i])))
            {
                return false;
            }
            temp=temp->getlinks(word[i]);
        }
        if(temp->flag)
        {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.length();
        int i;
        Node*temp=root;
        for(i=0;i<n;i++)
        {
            if(!(temp->containskey(prefix[i])))
            {
                return false;
            }
            temp=temp->getlinks(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
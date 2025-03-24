class DSU{
    private:
    vector<int>parent,size;
    public:
    void init(int n){
        size.resize(n,1);
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
    }
    int findPar(int node){
        if(node==parent[node])return node;
        return parent[node] = findPar(parent[node]);
    }
    void unite(int x,int y){
        x = findPar(x);
        y = findPar(y);
        if(x!=y){ 
            parent[y] = x;
            size[x]+=size[y];
        }
    }
};
struct TreeNodee{
    TreeNodee* prev;
    TreeNodee* next;
    int val;
    TreeNodee(int val) :prev(NULL),next(NULL),val(val) {}
};
class SummaryRanges {
public:
    DSU ds;
    map<int,pair<TreeNodee*,TreeNodee*>>mp;
    unordered_map<int,TreeNodee*>address;
    SummaryRanges() {
        ds.init(1e4+10);
    }
    
    void addNum(int value) {        
        if(address.find(value)==address.end()){
            TreeNodee* newNode = new TreeNodee(value); 
            address[value] = newNode;
            auto it1 = address.find(value-1),it2 = address.find(value+1);
            if(it1==address.end() && it2==address.end()){
                TreeNodee* head = new TreeNodee(-1);
                TreeNodee* tail = new TreeNodee(-1);
                head->next = newNode;
                newNode->prev = head;
                newNode->next = tail;
                tail->prev = newNode;
                mp[ds.findPar(value)] = {head,tail};
            }
            else if(it1!=address.end() && it2!=address.end()){
                int prevParent = ds.findPar(value-1);
                ds.unite(prevParent,value);
                pair<TreeNodee*,TreeNodee*>prev = mp[prevParent];
                TreeNodee* lastEl = prev.second->prev;
                lastEl->next = newNode;
                newNode->prev = lastEl; 
                int nextPar = ds.findPar(value+1);
                ds.unite(ds.findPar(value),nextPar);
                pair<TreeNodee*,TreeNodee*>nextNode = mp[nextPar];
                TreeNodee* firstNode = nextNode.first->next;
                TreeNodee* lNodeprev = nextNode.second->prev;
                newNode->next = firstNode;
                firstNode->prev = newNode;
                lNodeprev->next = prev.second;
                prev.second->prev = lNodeprev;
                mp.erase(value+1);
            }
            else if(it1!=address.end() && it2==address.end()){
                int prevParent = ds.findPar(value-1);
                ds.unite(prevParent,value);
                pair<TreeNodee*,TreeNodee*>prev = mp[prevParent];
                TreeNodee* lastEl = prev.second->prev;
                lastEl->next = newNode;
                newNode->prev = lastEl; 
                newNode->next = prev.second;
                prev.second->prev = newNode;
            }
            else if(it1==address.end() && it2!=address.end()){
                int nextParent = ds.findPar(value+1);
                pair<TreeNodee*,TreeNodee*>nextNode = mp[nextParent];
                ds.unite(value,nextParent);
                newNode->next = nextNode.first->next;
                nextNode.first->next->prev = newNode;
                mp.erase(nextParent);
                TreeNodee* head = new TreeNodee(-1);
                TreeNodee* tail = new TreeNodee(-1);
                head->next = newNode;
                newNode->prev = head;
                nextNode.second->prev->next = tail;
                tail->prev = nextNode.second->prev;
                mp[value] = {head,tail};
            }
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        for(auto &i:mp){
            TreeNodee* head = i.second.first;
            TreeNodee* tail = i.second.second;
            ans.push_back({head->next->val,tail->prev->val});
        }
        return ans;
    }
}; 
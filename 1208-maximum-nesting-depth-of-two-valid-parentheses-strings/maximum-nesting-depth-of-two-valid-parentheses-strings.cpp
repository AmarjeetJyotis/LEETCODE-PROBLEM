/*
vector<int>ans;
//storing depth in ans (if depth==even store 0 else store 1)
iterate over string if ch='(' store depth in ans and increment it
else if ch==')' decrement it first then store
*/
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
    vector<int>ans;
    int depth=0;
    for(auto ch:seq){
        if(ch=='('){
             ans.push_back(depth % 2); 
            depth++;
        }
        else if(ch==')'){
            depth--; 
            ans.push_back(depth % 2); 
            
        }
    }  
    return ans;  
    }
};
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int>ans;
        ans.push_back(label);
        int level = log2(label);

        if(label==1)  return ans;

        while(level>0) {
            int parent = label/2;
            int start = pow(2,level-1);
            int end = 2*start-1;
            int complement = start+end-parent;
            ans.push_back(complement);
            label = complement;
            level--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
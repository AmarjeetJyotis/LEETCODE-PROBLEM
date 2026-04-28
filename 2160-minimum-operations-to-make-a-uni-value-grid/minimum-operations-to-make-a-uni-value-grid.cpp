class Solution {
public:
	int minOperations(vector<vector<int>>& g, int x) {
		int m=g.size();
		int n=g[0].size();
		vector<int>a;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				a.push_back(g[i][j]);
				if(g[i][j]%x!=g[0][0]%x)return -1;
			}
		}
		sort(a.begin(),a.end());
		int y=a[a.size()/2];
		int op=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++) op+=(abs(g[i][j]-y)/x); 
		}
		return op;
	}
};

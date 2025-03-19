/*Concept Involved is-> Jab friends ko milna hota hai toh toh kisi aise friend ke ghar jane ki jagha we say ki let's go to X's friend's house
(X lives in the middle of the city) because woh X ka ghr sake ghr se paas padega so har ek individual ko comparatively kam 
distance cover karna padega. same goes here hum aise element ko lete hai which is in maximum possible middle among all and
that element obvo will be the **MEDIAN** of the **SORTED ARRAY** . Hence after making the uni value grid this is the element which
will be in each cell of the grid!!*/

/* Hope I am able to explain the concept of this question. Feel free to ask your doubts in the comment section. Have a good day!*/

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
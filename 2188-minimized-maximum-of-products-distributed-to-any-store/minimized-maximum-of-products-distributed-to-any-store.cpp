class Solution {
public:
int nofstores(vector<int>& quantities,int mid){
    int stores=0;
    for(int i=0;i<quantities.size();i++){
        stores+=ceil((double)quantities[i] / (double)mid);
    }
    return stores;
}
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nofstores(quantities,mid)<=n){
                ans=mid;
                high=mid-1;    
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
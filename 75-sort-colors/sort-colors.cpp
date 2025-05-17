class Solution {
public:
    void sortColors(vector<int>& arr) {
       int start=0;
       int end=arr.size()-1;
       int i=0;
       while(i <= end){
        if(arr[i]==0){
            swap(arr[start], arr[i]);
            start++;
            i++;
        }
        else if(arr[i]==1){
            i++;
        }
        else{
            swap(arr[end], arr[i]);
            end--;
        }
       }
    }
};
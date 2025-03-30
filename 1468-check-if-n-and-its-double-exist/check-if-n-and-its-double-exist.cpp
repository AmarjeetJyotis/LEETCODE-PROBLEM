class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0;i<arr.size();i++)
        {
            auto num=find(arr.begin(),arr.end(),arr[i]*2);
            if(num!=arr.end() && num!=arr.begin()+i)
            {
                return true;
            }
        }
        return false;
    }
};
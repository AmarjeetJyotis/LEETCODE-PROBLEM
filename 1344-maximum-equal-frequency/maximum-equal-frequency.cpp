class Solution {
public:
  int maxEqualFreq(vector<int>& nums) {
    int answer = 1;
    unordered_map<int,int>table;                //len of group, number of groups
    unordered_map<int,int>dis;                  //number, value of this number
    
    for(int i = 0; i != nums.size(); i++){
      if(dis.count(nums[i])){
        int len = dis[nums[i]];
        if(--table[len] == 0) table.erase(len);
      }
      ++table[++dis[nums[i]]];
      if(table.size() == 1 && (table.begin()->second == 1 || table.begin()->first == 1) ) answer = i+1;
      else if(table.size() == 2){
        auto it1 = table.begin();
        auto it2 = table.begin(); it2++;
        if( (it1->second == 1 && (it1->first == 1 || it1->first - it2->first == 1)) ||
            (it2->second == 1 && (it2->first == 1 || it2->first - it1->first == 1))  )    answer = i+1;
      }
    }
    
    return answer;
  }
};
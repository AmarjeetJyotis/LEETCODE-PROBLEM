class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int x = 0, y = 0;
        for (int i = 0; i < position.size(); i++)
            if (position[i] % 2 == 0)
                x++;
            else
                y++;
        return min(x, y);
    }
};
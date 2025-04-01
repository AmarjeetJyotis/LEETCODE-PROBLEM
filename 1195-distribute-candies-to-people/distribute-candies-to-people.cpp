class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> dis(num_people, 0);
        bool flag = false;

        int count = 0;
        while (true) {
            for (int i = 0; i < dis.size(); ++i) {
                count += 1;

                // check candies is available or not
                if (candies < count) {
                    dis[i] += candies;
                    flag = true;
                    break;
                }

                dis[i] += count;
                candies -= count;
            }

            if (flag) {
                break;
            }
        }

        return dis;
    }
};
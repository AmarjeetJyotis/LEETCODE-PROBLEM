class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int itemsLen = items.size();
        int queriesLen = queries.size();

        map<int, int> beautyMap;

        int i = 0;
        std::map<int, int>::iterator it;

        for (; i < itemsLen; ++i) {
            // We try to find in map element with lower price
            it = beautyMap.upper_bound(items[i][0]);
            it = (it != beautyMap.begin()) ? --it : it;

            // Then we add it to map if the price we found is bigger
            // might happen when there is only 1 element in map
            // or we add when the beauty is higher
            if (it->first > items[i][0] || it->second < items[i][1]) {
                beautyMap[items[i][0]] = items[i][1];

                // after adding the item to map we iterate over the 
                // map and update the beauty for higher prices
                // with higher beauties of lower prices
                for (it = std::next(beautyMap.begin()); it != beautyMap.end(); ++it) {
                    if (std::prev(it)->second > it->second)
                        it->second = std::prev(it)->second;
                }
            }
        }

        // we change the values in queries to beauties you can 
        // buy for those prices by ussing upper_bound and --it
        // to find the beauty we can get with that price
        for (i = 0; i < queriesLen; ++i) {
            if (queries[i] < beautyMap.begin()->first) queries[i] = 0;
            else {
                it = beautyMap.upper_bound(queries[i]);
                --it;
                queries[i] = it->second;
            }
        }

        return queries;
    }
};
class Solution 
{
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        // Step 1: Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Step 2: Initialize min-heap for free rooms (by room number)
        priority_queue<int, vector<int>, greater<>> freeRooms;
        for (int i = 0; i < n; ++i)
        {
            freeRooms.push(i);
        } 

        // Step 3: Min-heap for busy rooms: {end time, room id}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        // Step 4: Count how many meetings each room handled
        vector<int> count(n, 0);

        // Step 5: Process each meeting
        for (auto& mt : meetings) 
        {
            long long start = mt[0];
            long long end = mt[1];
            long long duration = end - start;

            // Free up rooms that are done before the current meeting starts
            while (!busy.empty() && busy.top().first <= start) 
            {
                freeRooms.push(busy.top().second);
                busy.pop();
            }

            if (!freeRooms.empty()) 
            {
                // Assign to lowest-numbered free room
                int room = freeRooms.top(); 
                freeRooms.pop();
                count[room]++;
                busy.emplace(end, room);
            } 
            else 
            {
                // Delay the meeting until the earliest room becomes available
                auto [freeTime, room] = busy.top(); 
                busy.pop();
                count[room]++;
                busy.emplace(freeTime + duration, room);
            }
        }

        // Step 6: Find the room with most meetings
        int res = 0;
        for (int i = 1; i < n; ++i) 
        {
            if (count[i] > count[res])
            {
                res = i;
            } 
        }

        return res;
    }
};
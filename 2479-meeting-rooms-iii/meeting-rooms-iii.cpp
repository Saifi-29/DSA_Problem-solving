class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // Min-heap of available rooms
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        // Min-heap of ongoing meetings: {end_time, room_number}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> ongoing;

        vector<int> count(n, 0);

        for (auto& m : meetings) {
            long long start = m[0];
            long long end = m[1];
            long long duration = end - start;

            // Free rooms that have completed their meetings
            while (!ongoing.empty() && ongoing.top().first <= start) {
                available.push(ongoing.top().second);
                ongoing.pop();
            }

            if (!available.empty()) {
                // Assign immediately
                int room = available.top();
                available.pop();
                ongoing.push({end, room});
                count[room]++;
            } else {
                // Delay meeting
                auto [earliestEnd, room] = ongoing.top();
                ongoing.pop();
                long long newEnd = earliestEnd + duration;
                ongoing.push({newEnd, room});
                count[room]++;
            }
        }

        // Find room with maximum meetings
        int result = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[result]) {
                result = i;
            }
        }

        return result;
    }
};
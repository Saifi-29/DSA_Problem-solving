class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    vector<int> mentions(numberOfUsers, 0);
    vector<bool> online(numberOfUsers, true);

    // Sort events: by timestamp, and OFFLINE before MESSAGE at same timestamp
    sort(events.begin(), events.end(), [](auto &a, auto &b) {
        int t1 = stoi(a[1]);
        int t2 = stoi(b[1]);
        if (t1 != t2) return t1 < t2;

        // tie-breaker: OFFLINE first
        if (a[0] == "OFFLINE" && b[0] == "MESSAGE") return true;
        if (a[0] == "MESSAGE" && b[0] == "OFFLINE") return false;
        return false;
    });

    // Min-heap to restore users online
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for (auto &e : events) {
        string type = e[0];
        int timestamp = stoi(e[1]);

        // Process restores before event
        while (!pq.empty() && pq.top().first <= timestamp) {
            int u = pq.top().second;
            pq.pop();
            online[u] = true;
        }

        if (type == "OFFLINE") {
            int u = stoi(e[2]);
            online[u] = false;
            pq.push({timestamp + 60, u});
        } 
        else { // MESSAGE
            string msg = e[2];

            if (msg == "ALL") {
                for (int i = 0; i < numberOfUsers; i++)
                    mentions[i]++;
            }
            else if (msg == "HERE") {
                for (int i = 0; i < numberOfUsers; i++)
                    if (online[i]) mentions[i]++;
            }
            else {
                stringstream ss(msg);
                string token;
                while (ss >> token) {
                    if (token.rfind("id", 0) == 0) {
                        int id = stoi(token.substr(2));
                        mentions[id]++;
                    }
                }
            }
        }
    }

    return mentions;
    }
};
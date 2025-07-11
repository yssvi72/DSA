class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // Очередь: {время_окончания, номер_комнаты}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        // Очередь свободных комнат по номеру
        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; ++i) free.push(i);

        // Словарь: ключ — номер комнаты, значение — сколько раз использовали
        unordered_map<int, int> rooms;

        for (auto& meet : meetings) {
            long long start = meet[0], end = meet[1];
            long long duration = end - start;

            // Освобождаем комнаты, если они уже освободились
            while (!pq.empty() && pq.top().first <= start) {
                free.push(pq.top().second);
                pq.pop();
            }

            if (!free.empty()) {
                int room = free.top(); free.pop();
                pq.emplace(end, room);
                rooms[room]++;
            } else {
                // Все комнаты заняты — берём ту, которая освободится раньше
                auto [avail_time, room] = pq.top(); pq.pop();
                pq.emplace(avail_time + duration, room);
                rooms[room]++;
            }
        }

        // Находим комнату с максимальным количеством использований
        int max_cnt = -1, ans = -1;
        for (int i = 0; i < n; ++i) {
            if (rooms[i] > max_cnt) {
                max_cnt = rooms[i];
                ans = i;
            }
        }
        return ans;
    }
};

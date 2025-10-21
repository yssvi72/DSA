class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        inters_o = sorted([(x - k ,x + k) for x in nums])

        # try overlaps
        heap = []
        max_overlap = -1
        for inter in inters_o:
            s, e = inter
            heapq.heappush(heap, e)
            while heap and heap[0] < s:
                heapq.heappop(heap)
            max_overlap = max(max_overlap, min(numOperations, len(heap)))

        # try centers
        events_s = defaultdict(int)
        events_e = defaultdict(int)
        events_m = defaultdict(int)
        for inter in inters_o:
            s, e = inter
            mid = (s + e) // 2
            events_s[s] += 1
            events_e[e + 1] += 1
            events_m[mid] += 1
        event_t = sorted(set(events_s.keys()) | set(events_e.keys()) | set(events_m.keys()))
        cur_overlap = 0
        max_possible_assign = -1
        for t in event_t:
            # print("at", t, events_s[t], events_e[t], events_m[t])
            cur_overlap += events_s[t]
            cur_overlap -= events_e[t]
            if events_m[t]:
                max_possible_assign = max(max_possible_assign, events_m[t] + min(cur_overlap - events_m[t], numOperations))
        # print(max_possible_assign, max_overlap)
        return max(max_possible_assign, max_overlap)


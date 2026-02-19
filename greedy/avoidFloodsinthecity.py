class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        full=set()
        result=[-1]*len(rains)

        next_lake_occurence=defaultdict(list)
        min_heap=[]

        for i,lake in enumerate(rains):
            next_lake_occurence[lake].append(i)
        
        for i,lake in enumerate(rains):
            if lake>0:
                if lake in full:
                    return []
                
                full.add(lake)
                next_lake_occurence[lake].pop(0)

                if next_lake_occurence[lake]:
                    heapq.heappush(min_heap,(next_lake_occurence[lake][0],lake))
                result[i]=-1

            else:
                if min_heap:
                    _,dry_lake=heapq.heappop(min_heap)
                    full.remove(dry_lake)
                    result[i]=dry_lake
                else:
                    result[i]=1
        
        return result

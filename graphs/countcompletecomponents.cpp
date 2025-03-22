class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        #union join

        parents = [i for i in range(n)]
        
        count_edge_vertex = {i:[1,0] for i in range(n)}

        def join(i1, i2):
            while parents[i1] != i1:
                i1 = parents[i1]
            while parents[i2] != i2:
                i2 = parents[i2]
            
            if i2 == i1:
                count_edge_vertex[i1][1] += 1
            else:
                v2, e2 = count_edge_vertex[i2]
                parents[i2] = i1            #i1 will hold everything
                
                count_edge_vertex[i1][0] += v2
                count_edge_vertex[i1][1] += e2 + 1

        
        for v1, v2 in edges:
            join(v1, v2)
        ans = 0

        for v in count_edge_vertex:
        
            count_v, count_e = count_edge_vertex[v]

            if parents[v] == v and count_e * 2 == (count_v * (count_v-1)):
                ans += 1
        return ans

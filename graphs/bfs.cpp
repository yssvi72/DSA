//The Breadth First Search (BFS) algorithm is used to search a graph data structure for a node that meets a set of criteria.
//It starts at the root of the graph and visits all nodes at the current depth level before moving on to the nodes at the next depth level.Traverse level-wise
//Breadth-First Traversal (or Search) for a graph is similar to the Breadth-First Traversal of a tree.The only catch here is, that, unlike trees:
//graphs may contain cycles, so we may come to the same node again. To avoid processing a node more than once, we divide the vertices into two categories:
//...Visited and
//...Not visited
//A boolean visited array is used to mark the visited vertices. For simplicity, it is assumed that all vertices are reachable from the starting vertex.
//BFS uses a queue data structure for traversal.
// Define the Graph class
class Graph {
    int V;  // Number of vertices
    list<int> *adj;  // Pointer to an array constituting adjacency lists

public:
    // Graph class constructor
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v].push_back(w);  // Add w to v’s list
    }

    // BFS traversal function starting from source vertex s
    void BFS(int s) {
        // Create a boolean array to mark all vertices as not visited
        bool *visited = new bool[V];
        for(int i = 0; i < V; i++) {
            visited[i] = false;
        }

        // Create a queue for BFS
        list<int> queue;

        // Mark the source node as visited and enqueue it
        visited[s] = true;
        queue.push_back(s);

        while(!queue.empty()) {
            // Dequeue a vertex from queue and output it
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            // Traverse all adjacent vertices of the dequeued vertex
            for(auto i = adj[s].begin(); i != adj[s].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
};

// Main function
int main() {
    Graph g(4);  // Construct a graph with 4 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Breadth First Traversal starting from vertex 2:" << endl;
    g.BFS(2);

    return 0;
}




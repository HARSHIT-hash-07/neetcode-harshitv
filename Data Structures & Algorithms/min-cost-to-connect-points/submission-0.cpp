class Solution {
public:

    int dist(vector<vector<int>>&points , int i , int j){
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        
        // Min-heap stores pairs of {edge_weight, node_index}
        // Using greater<> forces the priority_queue to put the smallest weight at the top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Keep track of nodes already added to our Minimum Spanning Tree
        vector<bool> visited(n, false);
        
        // Start from node 0. Cost to start is 0.
        pq.push({0, 0});
        
        int min_cost = 0;
        int connected_nodes = 0;

        while (connected_nodes < n) {
            auto [cost, curr_node] = pq.top();
            pq.pop();
            
            // If this node is already in the tree, skip it to avoid cycles
            if (visited[curr_node]) {
                continue;
            }
            
            // Mark as visited and add the edge cost to our total
            visited[curr_node] = true;
            min_cost += cost;
            connected_nodes++;
            
            // Expand the frontier: look at every other node in the complete graph
            for (int next_node = 0; next_node < n; next_node++) {
                if (!visited[next_node]) {
                    // Calculate Manhattan distance between curr_node and next_node
                    int dist = abs(points[curr_node][0] - points[next_node][0]) + 
                               abs(points[curr_node][1] - points[next_node][1]);
                    
                    // Push the potential edge into the min-heap
                    pq.push({dist, next_node});
                }
            }
        }
        
        return min_cost;

        

    }
};

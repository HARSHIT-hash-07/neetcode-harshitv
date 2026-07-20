class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        //BFS Queue -> stores {currentNode, currentCost}
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;
        
        int stops = 0;
        
        // BFS level by level
        // We can take up to k stops, which equals k + 1 levels of edges
        while (!q.empty() && stops <= k) {
            int size = q.size();
            
            // Process all nodes at the current stop level
            while (size--) {
                auto [node, cost] = q.front();
                q.pop();
                
                for (auto& [neighbor, price] : adj[node]) {
                    // Only explore this path if it's CHEAPER than a previously found path
                    if (cost + price < minCost[neighbor]) {
                        minCost[neighbor] = cost + price;
                        q.push({neighbor, cost + price});
                    }
                }
            }
            stops++; // Increment stops after finishing the current level
        }
        
        // Step 4: Return result
        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
        
    }
};

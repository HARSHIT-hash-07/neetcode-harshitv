

class Solution {
public:
    // Helper function: Finds the "boss" or "root" of a node's island
    int findRoot(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        // Path Compression: Make future lookups instantly fast
        return parent[node] = findRoot(parent, parent[node]); 
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        
        // 1. Initially, every node is its own boss (n separate components)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int components = n;

        // 2. Process each edge
        for (auto& edge : edges) {
            int root1 = findRoot(parent, edge[0]);
            int root2 = findRoot(parent, edge[1]);

            // 3. If they have different roots, they are separate islands!
            if (root1 != root2) {
                parent[root1] = root2; // Merge them (make one the boss of the other)
                components--;          // We now have 1 less island
            }
        }

        return components;
    }
};
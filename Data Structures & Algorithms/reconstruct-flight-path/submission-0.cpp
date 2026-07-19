class Solution {
public:

    void dfs(string airport, unordered_map<string, vector<string>>& graph, vector<string>& result) {
        // While there are outgoing flights from this airport
        while (!graph[airport].empty()) {
            // Grab the alphabetically smallest destination from the back
            string next_dest = graph[airport].back();
            graph[airport].pop_back();
            
            // Recursive call
            dfs(next_dest, graph, result);
        }
        
        // When we hit a dead end, add it to the result
        result.push_back(airport);
    }

    
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        unordered_map<string, vector<string>> graph;
        
        // Step 1: Build the adjacency list
        for (const auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }
        
        // Sort each destination list in descending (reverse alphabetical) order
        for (auto& [src, dests] : graph) {
            sort(dests.begin(), dests.end(), greater<string>());
        }
        
        vector<string> result;
        
        // Step 2: Call our DFS helper function starting from "JFK"
        dfs("JFK", graph, result);
        
        // Step 3: The result is in reverse order, so flip it
        reverse(result.begin(), result.end());
        
        return result;
        
    }
};

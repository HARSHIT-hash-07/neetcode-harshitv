class Solution {
public:

    
    string foreignDictionary(vector<string>& words) {

     unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> inDegree; // Tracks how many prerequisites a char has
        
        // 1. Initialize graph and in-degrees to 0 for ALL unique characters
        for (const string& word : words) {
            for (char c : word) {
                adj[c] = unordered_set<char>();
                inDegree[c] = 0;
            }
        }
        
        // 2. Build the graph and count in-degrees
        for (int i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());
            
            // Edge case: invalid prefix
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }
            
            for (int j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    char parent = w1[j];
                    char child = w2[j];
                    
                    // Only increment in-degree if this is a NEW unique edge
                    if (adj[parent].find(child) == adj[parent].end()) {
                        adj[parent].insert(child);
                        inDegree[child]++;
                    }
                    break;
                }
            }
        }
        
        // 3. Queue up all characters with 0 prerequisites
        queue<char> q;
        for (auto const& [c, count] : inDegree) {
            if (count == 0) {
                q.push(c);
            }
        }
        
        // 4. Process the queue
        string res = "";
        while (!q.empty()) {
            char current = q.front();
            q.pop();
            res += current;
            
            // Remove prerequisites for all neighbors
            for (char neighbor : adj[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor); // They are now free to be processed!
                }
            }
        }
        
        // 5. CYCLE DETECTION: Did we process every character?
        // If the result doesn't have all characters, some were stuck in a cycle.
        if (res.length() != inDegree.size()) {
            return "";
        }
        
        return res;

        
    }
};

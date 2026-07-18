class Solution {
public:
    bool check(string s1 , string s2){
        int count = 0;

        for(int i = 0 ; i < s1.size() ; i++){
            if(s1[i] != s2[i]) count++;
        }
        
        if(count == 1){
            return true;
        }
        else{
            return false;
        }
    }

    //there would be no cycles 

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        auto it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end()) {
            return 0;
        }
        
        // Find the target node's index BEFORE we add beginWord
        int endIndex = distance(wordList.begin(), it);

        // 2. Add beginWord to the end of the list so it gets its own node index
        wordList.push_back(beginWord);
        int n = wordList.size();
        int startIndex = n - 1; // It's the last element we just added

        // 3. Build your Explicit Graph exactly how you wanted! O(N^2)
        vector<vector<int>> adj(n);
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                if(check(wordList[i], wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // 4. Standard BFS for Shortest Path
        queue<pair<int, int>> q; // {current_node, steps}
        vector<int> vis(n, 0);

        q.push({startIndex, 1}); // We start at step 1 (the beginWord itself)
        vis[startIndex] = 1;

        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If we hit the endWord, return the steps!
            if (node == endIndex) {
                return steps;
            }

            for(int neighbor : adj[node]){
                if(vis[neighbor] == 0){
                    vis[neighbor] = 1;
                    q.push({neighbor, steps + 1});
                }
            }
        }

        return 0; 
        
    }
};

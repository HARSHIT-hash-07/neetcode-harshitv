class Solution {
public:

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& reachable, vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                // 1. Check bounds first!
                // 2. Check if already visited
                // 3. Check if water can flow "uphill" from current to neighbor
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || 
                    reachable[nr][nc] || 
                    heights[nr][nc] < heights[r][c]) {
                    continue;
                }

                // Mark as reachable and queue it up for further exploration
                reachable[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        // Two visited matrices to act as our "blue" and "red" dyes
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        
        queue<pair<int, int>> pacQueue;
        queue<pair<int, int>> atlQueue;

        // Load up the queues with the coastal cells
        for (int i = 0; i < rows; i++) {
            pacQueue.push({i, 0});           // Left edge (Pacific)
            pacific[i][0] = true;
            
            atlQueue.push({i, cols - 1});    // Right edge (Atlantic)
            atlantic[i][cols - 1] = true;
        }
        
        for (int j = 0; j < cols; j++) {
            pacQueue.push({0, j});           // Top edge (Pacific)
            pacific[0][j] = true;
            
            atlQueue.push({rows - 1, j});    // Bottom edge (Atlantic)
            atlantic[rows - 1][j] = true;
        }

        // Run BFS inwards from both oceans
        bfs(pacQueue, pacific, heights);
        bfs(atlQueue, atlantic, heights);

        // Find intersections: Cells reached by both oceans
        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
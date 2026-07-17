class Solution {
public:


    void bfs(vector<vector<int>>& grid){
        int rows = grid.size();
        int cols = grid[0].size();


        queue<pair<int , int>>q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                // If out of bounds, or it's a wall (-1), or it's already been visited 
                // (anything less than INT_MAX means it already found a closer treasure)
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] != INT_MAX) {
                    continue;
                }
                
                // The new distance is the current cell's distance + 1
                grid[nr][nc] = grid[r][c] + 1;
                
                // Push the newly reached empty room to the queue to explore its neighbors later
                q.push({nr, nc});
            }
        }


    }


    void islandsAndTreasure(vector<vector<int>>& grid) {
        bfs(grid);  
    }
};

class Solution {
public:

    int swimInWater(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;


        vector<vector<int>>visited(rows , vector<int>(cols , 0));

        pq.push({grid[0][0] , 0,0});
        visited[0][0] = 1;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!pq.empty()) {

            vector<int>v = pq.top();
            pq.pop();

            int maxlevel = v[0];
            int r = v[1];
            int c = v[2];

            if(r == rows - 1 && c == cols -1){
                return maxlevel;
            }

            for(auto p : dirs){
                int nr = r + p.first;
                int nc = c + p.second;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    int next_max = max(maxlevel, grid[nr][nc]);
                    pq.push({next_max, nr, nc});
                }
            }
        }

    }
};

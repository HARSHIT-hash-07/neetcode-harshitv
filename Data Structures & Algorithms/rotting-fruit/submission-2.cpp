class Solution {
public:

void bfs(vector<vector<int>>& grid){

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>>q;

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){

                if(grid[i][j] == 2){
                    // bfs(grid , i , j);
                    q.push({i,j});  
                }
            }
        }
        

        vector<pair<int , int>>dirs = {{1,0} , {-1,0} , {0,1} , {0,-1}};

        while(!q.empty()){
            int r , c;
            r = q.front().first;
            c = q.front().second;

            q.pop();

            for(auto dir : dirs){
                int nr , nc;
                nr = r + dir.first;
                nc = c + dir.second;

                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols || grid[nr][nc] != 1){
                    continue;
                }

                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr , nc});
            }

        }

    }
int orangesRotting(vector<vector<int>>& grid) 
{

        int rows = grid.size();
        int cols = grid[0].size();

        int a = 0;

        bfs(grid);

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){

                if(grid[i][j] == 1){
                    a = -1;
                    return -1;
                }
                a = max(a , grid[i][j] - 2);
            }
        }

    return a; 
}
    
};

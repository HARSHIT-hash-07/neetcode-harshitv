class Solution {
public:

    int dfs(vector<vector<int>>&grid , int i , int j , int &count){

        int rows = grid.size();
        int cols = grid[0].size();

        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0){
            return 0;
        }

        grid[i][j] = 0;
        count++;

        int a = dfs(grid , i , j+1 , count);
        int b = dfs(grid , i , j-1 , count);
        int c = dfs(grid , i+1 , j , count);
        int d = dfs(grid , i-1 , j , count);

        return count;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int area = 0;
        int ans = 0;
        int count = 0;

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(grid[i][j] == 1){
                    count = 0;
                    area = dfs(grid , i , j , count);
                    ans = max(ans , area);
                }
            }
        }


        return ans;
        
    }
};

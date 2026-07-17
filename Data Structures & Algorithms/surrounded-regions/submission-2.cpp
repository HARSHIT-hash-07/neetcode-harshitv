class Solution {
public:

    void dfs(vector<vector<char>>& board, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();

        // Base case: Out of bounds OR not an 'O'
        // Notice we use the letter 'O', not zero!
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O') {
            return;
        }

        // Mark as safe (temporarily change to 'T')
        // Because it's no longer 'O', we won't get stuck in infinite recursion!
        board[i][j] = 'T';

        // Check all 4 directions
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }


    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        if (rows == 0) return;

        // 1. Run DFS from the Left and Right borders
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][cols - 1] == 'O') dfs(board, i, cols - 1);
        }

        // 2. Run DFS from the Top and Bottom borders
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[rows - 1][j] == 'O') dfs(board, rows - 1, j);
        }

        // 3. Flip the board to its final state
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    // It was never reached by the border, so it's surrounded
                    board[i][j] = 'X'; 
                } else if (board[i][j] == 'T') {
                    // It was reached by the border, turn it back to safe 'O'
                    board[i][j] = 'O'; 
                }
            }
        }
    }
};

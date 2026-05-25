class Solution {
private:
    int ROWS, COLS;
    
    void dfs(int r, int c, vector<vector<bool>>& reachable, int prev_height, vector<vector<int>>& heights) {
        // Base cases: out of bounds, already visited, or cannot flow "up"
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || reachable[r][c] || heights[r][c] < prev_height) {
            return;
        }
        
        reachable[r][c] = true;
        
        // Explore 4 directions
        dfs(r + 1, c, reachable, heights[r][c], heights);
        dfs(r - 1, c, reachable, heights[r][c], heights);
        dfs(r, c + 1, reachable, heights[r][c], heights);
        dfs(r, c - 1, reachable, heights[r][c], heights);
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        ROWS = heights.size();
        COLS = heights[0].size();
        
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));
        
        // 1. Traversal from horizontal borders
        for (int c = 0; c < COLS; ++c) {
            dfs(0, c, pac, heights[0][c], heights);             // Top border (Pacific)
            dfs(ROWS - 1, c, atl, heights[ROWS - 1][c], heights); // Bottom border (Atlantic)
        }
        
        // 2. Traversal from vertical borders
        for (int r = 0; r < ROWS; ++r) {
            dfs(r, 0, pac, heights[r][0], heights);             // Left border (Pacific)
            dfs(r, COLS - 1, atl, heights[r][COLS - 1], heights); // Right border (Atlantic)
        }
        
        // 3. Find intersection
        vector<vector<int>> result;
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        
        return result;
    }
};
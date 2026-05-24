class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> que;
        int fresh_oranges = 0;

        // 1. Gather ALL rotten oranges first (Multi-source BFS setup)
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) {
                    que.push({j, i}); // push {x, y}
                } else if(grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }

        // If there's nothing to rot, we are done instantly
        if(fresh_oranges == 0) return 0;

        int minutes = 0;
        vector<int> xrow = {-1, 1, 0, 0};
        vector<int> yrow = {0, 0, -1, 1};

        // 2. Run the concurrent BFS
        while(!que.empty() && fresh_oranges > 0) {
            int size = que.size();
            minutes++; // Increment time for this layer of spreading

            for(int i = 0; i < size; i++) {
                pair<int, int> p = que.front();
                que.pop();

                for(int j = 0; j < 4; j++) {
                    int nextx = p.first + xrow[j];
                    int nexty = p.second + yrow[j];

                    // Boundary check
                    if(nexty < 0 || nexty >= rows || nextx < 0 || nextx >= cols) continue;

                    // CRITICAL: Only push and rot if it is FRESH (1)
                    if(grid[nexty][nextx] == 1) {
                        grid[nexty][nextx] = 2; // Mark as 2 immediately!
                        que.push({nextx, nexty});
                        fresh_oranges--; // Track how many are left
                    }
                }
            }
        }

        // 3. If fresh oranges are left, return -1; otherwise return the minutes
        return fresh_oranges == 0 ? minutes : -1;
    }
};
void dfs(int** grid, int r, int c, int rows, int cols) {
    // Base case: Out of bounds or current cell is a sea cell (0)
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
        return;
    }
    
    // Mark the current land cell as visited by sinking it (turning to 0)
    grid[r][c] = 0;
    
    // Visit all 4 adjacent directions
    dfs(grid, r + 1, c, rows, cols);
    dfs(grid, r - 1, c, rows, cols);
    dfs(grid, r, c + 1, rows, cols);
    dfs(grid, r, c - 1, rows, cols);
}

int numEnclaves(int** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0) return 0;
    
    int rows = gridSize;
    int cols = gridColSize[0];
    
    // Step 1: Perform DFS on the left and right boundaries (first and last columns)
    for (int i = 0; i < rows; i++) {
        if (grid[i][0] == 1) {
            dfs(grid, i, 0, rows, cols);
        }
        if (grid[i][cols - 1] == 1) {
            dfs(grid, i, cols - 1, rows, cols);
        }
    }
    
    // Step 2: Perform DFS on the top and bottom boundaries (first and last rows)
    for (int j = 0; j < cols; j++) {
        if (grid[0][j] == 1) {
            dfs(grid, 0, j, rows, cols);
        }
        if (grid[rows - 1][j] == 1) {
            dfs(grid, rows - 1, j, rows, cols);
        }
    }
    
    // Step 3: Count the remaining 1s in the grid
    int enclaveCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                enclaveCount++;
            }
        }
    }
    
    return enclaveCount;
}

class Solution {
public:

    int helper(vector<vector<int>>& grid, int row, int col) {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        grid[row][col] = 0;
        int area = 1;

        for(int i = 0; i < 4; i++) {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            if(newRow < 0 || newCol < 0 ||
               newRow >= grid.size() || newCol >= grid[0].size()) {
                continue;
            }

            if(grid[newRow][newCol] == 1) {
                area += helper(grid, newRow, newCol);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int maxArea = 0;

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {

                if(grid[row][col] == 1) {
                    int area = helper(grid, row, col);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
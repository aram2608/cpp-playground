#include <iostream>
#include <vector>

// Enum for cell states
enum CellState { DEAD, ALIVE };

// Function to count living neighbors
int countLivingNeighbors(
    const std::vector<std::vector<CellState>> &grid, int row, int col, int rows, int cols) {
    int livingNeighbors = 0;
    // Iterate through the 8 neighbors (Moore neighborhood)
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0)
                continue; // Skip the cell itself

            int neighborRow = (row + i + rows) % rows; // Wrap-around for row
            int neighborCol = (col + j + cols) % cols; // Wrap-around for col

            if (grid[neighborRow][neighborCol] == ALIVE) {
                livingNeighbors++;
            }
        }
    }
    return livingNeighbors;
}

// Function to update the grid for one generation
void updateGrid(std::vector<std::vector<CellState>> &currentGrid, int rows, int cols) {
    std::vector<std::vector<CellState>> nextGrid = currentGrid; // Create a copy for next generation

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int livingNeighbors = countLivingNeighbors(currentGrid, r, c, rows, cols);

            if (currentGrid[r][c] == ALIVE) {
                if (livingNeighbors < 2 || livingNeighbors > 3) {
                    nextGrid[r][c] = DEAD; // Underpopulation or Overpopulation
                }
            } else { // Current cell is DEAD
                if (livingNeighbors == 3) {
                    nextGrid[r][c] = ALIVE; // Reproduction
                }
            }
        }
    }
    currentGrid = nextGrid; // Update the current grid
}

// Function to print the grid
void printGrid(const std::vector<std::vector<CellState>> &grid, int rows, int cols) {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            std::cout << (grid[r][c] == ALIVE ? 'X' : ' ') << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int                                 rows = 10;
    int                                 cols = 10;
    std::vector<std::vector<CellState>> grid(rows, std::vector<CellState>(cols, DEAD));

    // Initialize with a simple pattern (e.g., a glider)
    grid[1][2] = ALIVE;
    grid[2][3] = ALIVE;
    grid[3][1] = ALIVE;
    grid[3][2] = ALIVE;
    grid[3][3] = ALIVE;

    for (int generation = 0; generation < 20; ++generation) {
        std::cout << "Generation " << generation << ":" << std::endl;
        printGrid(grid, rows, cols);
        updateGrid(grid, rows, cols);
    }

    return 0;
}
#include <iostream>
#include <vector>

int main() {
    int rows_count;
    int cols_count;
    std::cin >> rows_count >> cols_count;
    std::vector<std::vector<char>> grid(rows_count, std::vector<char>(cols_count));
    for (std::vector<char>& str : grid) {
        for (char& letter : str) {
            std::cin >> letter;
        }
    }
    const std::vector<std::pair<int, int>> kDirections{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
    for (int i = 0; i < rows_count; ++i) {
        for (int j = 0; j < cols_count; ++j) {
            if (grid[i][j] == '*') {
                continue;
            }
            grid[i][j] = '0';
            for (const auto& [row_offset, col_offset] : kDirections) {
                int new_row = i + row_offset;
                int new_col = j + col_offset;
                if (new_row >= 0 && new_col >= 0 && new_row < rows_count && new_col < cols_count &&
                    grid[new_row][new_col] == '*') {
                    ++grid[i][j];
                }
            }
        }
    }
    for (const std::vector<char>& str : grid) {
        for (const char& letter : str) {
            std::cout << letter;
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    return 0;
}

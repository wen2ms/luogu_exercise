#include <iostream>
#include <utility>
#include <vector>

int main() {
    int sides_count;
    int num_of_operations;
    std::cin >> sides_count >> num_of_operations;
    std::vector<std::vector<int>> grid(sides_count, std::vector<int>(sides_count));
    for (int i = 0; i < sides_count; ++i) {
        for (int j = 0; j < sides_count; ++j) {
            grid[i][j] = i * sides_count + j + 1;
        }
    }
    while (num_of_operations > 0) {
        --num_of_operations;
        int row;
        int col;
        int side;
        int clockwise;
        std::cin >> row >> col >> side >> clockwise;
        --row;
        --col;
        if (clockwise == 0) {
            for (int i = row - side; i < row; ++i) {
                for (int j = col - side; j <= col + side; ++j) {
                    std::swap(grid[i][j], grid[2 * row - i][j]);
                }
            }
        } else {
            for (int i = row - side; i <= row + side; ++i) {
                for (int j = col - side; j < col; ++j) {
                    std::swap(grid[i][j], grid[i][2 * col - j]);
                }
            }
        }
        for (int i = 0; i < 2 * side + 1; ++i) {
            for (int j = i + 1; j < 2 * side + 1; ++j) {
                std::swap(grid[row - side + i][col - side + j], grid[row - side + j][col - side + i]);
            }
        }
    }
    for (const std::vector<int>& row : grid) {
        for (const int num : row) {
            std::cout << num << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    return 0;
}
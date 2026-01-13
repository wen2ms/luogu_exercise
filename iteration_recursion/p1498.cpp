#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num;
    std::cin >> num;
    std::vector<std::vector<char>> grid(3000, std::vector<char>(3000, ' '));
    int width = 4;
    int height = 2;
    grid[0][1] = grid[1][0] = '/';
    grid[0][2] = grid[1][3] = '\\';
    grid[1][1] = grid[1][2] = '_';
    for (int i = 1; i < num; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int k = 0; k < width; ++k) {
                grid[j + height][k] = grid[j][k];
                grid[j + height][k + width] = grid[j][k];
                grid[j][k] = ' ';
            }
        }
        for (int j = 0; j < height; ++j) {
            for (int k = 0; k < width; ++k) {
                grid[j][k + width / 2] = grid[j + height][k];
            }
        }
        width *= 2;
        height *= 2;
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << grid[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}
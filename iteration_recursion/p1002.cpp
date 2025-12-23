#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::pair<int, int> destination;
    std::pair<int, int> horse;
    std::cin >> destination.first >> destination.second >> horse.first >> horse.second;
    int rows_count = destination.first + 1;
    int cols_count = destination.second + 1;
    std::vector<std::vector<int64_t>> methods(rows_count + 1, std::vector<int64_t>(cols_count + 1));
    std::set<std::pair<int, int>> obstacles;
    const std::vector<std::pair<int, int>> directions{{0, 0},   {2, 1},   {1, 2},  {-1, 2}, {-2, 1},
                                                      {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    for (const auto& [row_offset, col_offset] : directions) {
        obstacles.emplace(horse.first + row_offset, horse.second + col_offset);
    }
    if (!obstacles.contains({0, 1})) {
        methods[0][1] = 1;
    }
    for (int i = 1; i <= rows_count; ++i) {
        for (int j = 1; j <= cols_count; ++j) {
            if (!obstacles.contains({i - 1, j - 1})) {
                methods[i][j] = methods[i - 1][j] + methods[i][j - 1];
            }
        }
    }
    std::cout << methods[rows_count][cols_count] << '\n';

    return 0;
}
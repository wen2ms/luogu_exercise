#include <algorithm>
#include <cstdint>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int rows_count;
    int cols_count;
    std::cin >> rows_count >> cols_count;
    int64_t cubes_count = 0;
    int64_t rects_count = 0;
    for (int i = 1; i <= rows_count; ++i) {
        for (int j = 1; j <= cols_count; ++j) {
            cubes_count += std::min(i, j);
            rects_count += i * j;
        }
    }
    std::cout << cubes_count << ' ' << rects_count - cubes_count << '\n';

    return 0;
}
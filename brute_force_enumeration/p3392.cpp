#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int rows_count;
    int cols_count;
    std::cin >> rows_count >> cols_count;
    std::vector<int> white_counts(rows_count + 1);
    std::vector<int> blue_counts(rows_count + 1);
    std::vector<int> red_counts(rows_count + 1);
    for (int i = 1; i <= rows_count; ++i) {
        std::string str;
        std::cin >> str;
        white_counts[i] += white_counts[i - 1] + std::count_if(str.begin(), str.end(), [](char letter) { return letter != 'W'; });
        blue_counts[i] += blue_counts[i - 1] + std::count_if(str.begin(), str.end(), [](char letter) { return letter != 'B'; });
        red_counts[i] += red_counts[i - 1] + std::count_if(str.begin(), str.end(), [](char letter) { return letter != 'R'; });
    }
    int minimum_count = std::numeric_limits<int>::max();
    for (int i = 1; i < rows_count - 1; ++i) {
        for (int j = i + 1; j < rows_count; ++j) {
            minimum_count = std::min(minimum_count,
                                     white_counts[i] + blue_counts[j] - blue_counts[i] + red_counts[rows_count] - red_counts[j]);
        }
    }
    std::cout << minimum_count << '\n';

    return 0;
}
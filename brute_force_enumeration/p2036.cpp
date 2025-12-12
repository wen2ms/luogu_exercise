#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

void backtrack(int index, int first, int second, int& minimum_difference, const std::vector<std::pair<int, int>>& pairs) {
    int num_of_pairs = pairs.size();
    if (index >= num_of_pairs) {
        if (first != 0 && second != 0) {
            minimum_difference = std::min(minimum_difference, std::abs(first - second));
        }
        return;
    }
    backtrack(index + 1, first * pairs[index].first, second + pairs[index].second, minimum_difference, pairs);
    backtrack(index + 1, first, second, minimum_difference, pairs);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num_of_pairs;
    std::cin >> num_of_pairs;
    std::vector<std::pair<int, int>> pairs(num_of_pairs);
    for (auto& [first, second] : pairs) {
        std::cin >> first >> second;
    }
    int minimum_difference = std::numeric_limits<int>::max();
    backtrack(0, 1, 0, minimum_difference, pairs);
    std::cout << minimum_difference << '\n';

    return 0;
}
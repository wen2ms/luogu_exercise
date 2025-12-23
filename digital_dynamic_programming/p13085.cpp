#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

std::vector<std::vector<int64_t>> num_of_windies(19, std::vector<int64_t>(11, -1));
std::vector<int> digits;

int64_t dfs(int pos, int prev, bool is_tight) {
    if (pos == -1) {
        return 1;
    }
    if (!is_tight && num_of_windies[pos][prev] != -1) {
        return num_of_windies[pos][prev];
    }
    int upper_bound = (is_tight ? digits[pos] : 9);
    int64_t count = 0;
    for (int i = 0; i <= upper_bound; ++i) {
        if (prev == 10 || std::abs(prev - i) >= 2) {
            count += dfs(pos - 1, (i == 0 && prev == 10) ? 10 : i, is_tight && i == upper_bound);
        }
    }
    if (!is_tight) {
        num_of_windies[pos][prev] = count;
    }
    return count;
}

int64_t count_windy(int64_t num) {
    digits.clear();
    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    return dfs(digits.size() - 1, 10, true);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t left;
    int64_t right;
    std::cin >> left >> right;
    std::cout << count_windy(right) - count_windy(left - 1) << '\n';

    return 0;
}
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nums_count;
    std::cin >> nums_count;
    std::vector<std::string> nums(nums_count);
    for (std::string& num : nums) {
        std::cin >> num;
    }
    std::sort(nums.begin(), nums.end(),
              [](const std::string& left, const std::string& right) { return left + right > right + left; });
    std::string result;
    for (const std::string& num : nums) {
        result += num;
    }
    std::cout << result << '\n';

    return 0;
}
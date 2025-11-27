#include <cstdlib>
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nums_count;
    std::cin >> nums_count;
    std::vector<int> nums(nums_count);
    for (int& num : nums) {
        std::cin >> num;
    }
    std::unordered_set<int> exists;
    for (int i = 0; i < nums_count - 1; ++i) {
        exists.insert(std::abs(nums[i + 1] - nums[i]));
    }
    for (int i = 1; i <= nums_count - 1; ++i) {
        if (!exists.contains(i)) {
            std::cout << "Not jolly" << '\n';
            return 0;
        }
    }
    std::cout << "Jolly" << '\n';

    return 0;
}
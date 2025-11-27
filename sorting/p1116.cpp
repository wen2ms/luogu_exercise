#include <iostream>
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
    int swap_count = 0;
    for (int i = 0; i < nums_count - 1; ++i) {
        for (int j = 0; j < nums_count - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                ++swap_count;
            }
        }
    }
    std::cout << swap_count << '\n';

    return 0;
}
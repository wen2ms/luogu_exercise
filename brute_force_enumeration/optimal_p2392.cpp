#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int minimum_time(const std::vector<int>& nums) {
    int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
    int target = total_sum / 2;
    std::vector<bool> has_sums(target + 1);
    has_sums[0] = true;
    for (int num : nums) {
        for (int curr_sum = target; curr_sum >= num; --curr_sum) {
            has_sums[curr_sum] = has_sums[curr_sum] || has_sums[curr_sum - num];
        }
    }
    for (int curr_sum = target; curr_sum >= 0; --curr_sum) {
        if (has_sums[curr_sum]) {
            return std::max(curr_sum, total_sum - curr_sum);
        }
    }
    return total_sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> nums_counts(4);
    for (int& nums_count : nums_counts) {
        std::cin >> nums_count;
    }
    int result = 0;
    std::vector<std::vector<int>> nums(4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < nums_counts[i]; ++j) {
            int num;
            std::cin >> num;
            nums[i].push_back(num);
        }
        result += minimum_time(nums[i]);
    }
    std::cout << result << '\n';

    return 0;
}
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

void minimum_time(int index, int left_time, int right_time, int& time, const std::vector<int>& nums) {
    int nums_count = nums.size();
    if (index >= nums_count) {
        time = std::min(time, std::max(left_time, right_time));
        return;
    }
    minimum_time(index + 1, left_time + nums[index], right_time, time, nums);
    minimum_time(index + 1, left_time, right_time + nums[index], time, nums);
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
        nums[i].resize(nums_counts[i]);
        for (int& num : nums[i]) {
            std::cin >> num;
        }
        int time = std::numeric_limits<int>::max();
        minimum_time(0, 0, 0, time, nums[i]);
        result += time;
    }
    std::cout << result << '\n';

    return 0;
}
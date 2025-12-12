#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

void next_permutation(std::vector<int>& nums) {
    int nums_count = nums.size();
    int left = nums_count - 1;
    while (left > 0 && nums[left] <= nums[left - 1]) {
        --left;
    }
    if (left == 0) {
        return;
    }
    int right = nums_count - 1;
    while (right >= left && nums[right] <= nums[left - 1]) {
        --right;
    }
    std::swap(nums[left - 1], nums[right]);
    std::reverse(nums.begin() + left, nums.end());
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nums_count;
    int add;
    std::cin >> nums_count >> add;
    std::vector<int> nums(nums_count);
    for (int& num : nums) {
        std::cin >> num;
    }
    for (int i = 0; i < add; ++i) {
        next_permutation(nums);
    }
    for (const int num : nums) {
        std::cout << num << ' ';
    }

    return 0;
}
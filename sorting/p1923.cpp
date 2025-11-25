#include <iostream>
#include <utility>
#include <vector>

int quick_select(std::vector<int>& nums, int left, int right, int nth) {
    if (left == right) {
        return nums[left];
    }
    int pivot = nums[right];
    int i = left;
    for (int j = left; j < right; ++j) {
        if (nums[j] < pivot) {
            std::swap(nums[i], nums[j]);
            ++i;
        }
    }
    std::swap(nums[i], nums[right]);
    if (i == nth) {
        return nums[i];
    }
    if (i > nth) {
        return quick_select(nums, left, i - 1, nth);
    }
    return quick_select(nums, i + 1, right, nth);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int nums_count;
    int nth;
    std::cin >> nums_count >> nth;
    std::vector<int> nums(nums_count);
    for (int& num : nums) {
        std::cin >> num;
    }
    int nth_elemnt = quick_select(nums, 0, nums_count - 1, nth);

    std::cout << nth_elemnt << '\n';

    return 0;
}
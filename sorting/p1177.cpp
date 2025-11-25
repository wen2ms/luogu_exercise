#include <iostream>
#include <random>
#include <utility>
#include <vector>

std::random_device random_device;
std::mt19937 generator(random_device());

void quick_sort(int left, int right, std::vector<int>& nums) {
    if (left < right) {
        std::uniform_int_distribution<> distribution(left, right);
        int pivot_index = distribution(generator);
        int pivot = nums[pivot_index];
        int low = left;
        int mid = left;
        int high = right;
        while (mid <= high) {
            if (nums[mid] < pivot) {
                std::swap(nums[mid], nums[low]);
                ++mid;
                ++low;
            } else if (nums[mid] > pivot) {
                std::swap(nums[mid], nums[high]);
                --high;
            } else {
                ++mid;
            }
        }
        quick_sort(left, low - 1, nums);
        quick_sort(high + 1, right, nums);
    }
}

void quick_sort(std::vector<int>& nums) {
    quick_sort(0, nums.size() - 1, nums);
}

int main() {
    int nums_count;
    std::cin >> nums_count;
    std::vector<int> nums(nums_count);
    for (int& num : nums) {
        std::cin >> num;
    }
    quick_sort(nums);
    for (int num : nums) {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    return 0;
}
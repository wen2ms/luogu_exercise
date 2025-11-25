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
            if (nums[mid] > pivot) {
                std::swap(nums[mid], nums[low]);
                ++mid;
                ++low;
            } else if (nums[mid] < pivot) {
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int num_of_cows;
    int book_height;
    std::cin >> num_of_cows >> book_height;
    std::vector<int> heights(num_of_cows);
    for (int& height : heights) {
        std::cin >> height;
    }
    quick_sort(heights);
    int result = 0;
    for (int height : heights) {
        book_height -= height;
        ++result;
        if (book_height <= 0) {
            std::cout << result << '\n';
            break;
        }
    }

    return 0;
}
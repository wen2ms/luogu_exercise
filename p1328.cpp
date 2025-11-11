#include <iostream>
#include <vector>

int main() {
    int total_count;
    int nums1_count;
    int nums2_count;
    std::cin >> total_count >> nums1_count >> nums2_count;
    std::vector<int> nums1(nums1_count);
    std::vector<int> nums2(nums2_count);
    for (int& num : nums1) {
        std::cin >> num;
    }
    for (int& num : nums2) {
        std::cin >> num;
    }
    std::vector<std::vector<int>> table{{0, 0, 1, 1, 0}, {1, 0, 0, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 0, 1}, {1, 1, 0, 0, 0}};
    int score1 = 0;
    int score2 = 0;
    for (int i = 0; i < total_count; ++i) {
        score1 += table[nums1[i % nums1_count]][nums2[i % nums2_count]];
        score2 += table[nums2[i % nums2_count]][nums1[i % nums1_count]];
    }
    std::cout << score1 << ' ' << score2 << '\n';

    return 0;
}
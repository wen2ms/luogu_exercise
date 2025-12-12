#include <algorithm>
#include <iostream>
#include <vector>

const int kMod = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nums_count;
    std::cin >> nums_count;
    std::vector<int> nums(nums_count);
    for (int& num : nums) {
        std::cin >> num;
    }
    int maxmimum = *std::max_element(nums.begin(), nums.end());
    std::vector<int> counts(maxmimum + 1);
    for (int num : nums) {
        ++counts[num];
    }

    int num_of_triangles = 0;
    for (int i = 2; i <= maxmimum; ++i) {
        if (counts[i] >= 2) {
            int combinations_count = (counts[i] * (counts[i] - 1) / 2) % kMod;
            for (int j = 1; j <= i / 2; ++j) {
                if (j != i - j && counts[j] >= 1 && counts[i - j] >= 1) {
                    num_of_triangles += combinations_count * counts[j] * counts[i - j] % kMod;
                } else if (j == i - j && counts[j] >= 2) {
                    num_of_triangles += combinations_count * (counts[j] * (counts[j] - 1) / 2) % kMod;
                }
                num_of_triangles %= kMod;
            }
        }
    }
    std::cout << num_of_triangles << '\n';

    return 0;
}